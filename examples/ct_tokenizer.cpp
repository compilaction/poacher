#include <array>
#include <cstddef>
#include <iostream>
#include <tuple>

#include <poacher/tokenizer/operators.hpp>
#include <poacher/tokenizer/token.hpp>
#include <poacher/utility/ct_array.hpp>
#include <poacher/utility/ct_string.hpp>
#include <poacher/utility/repeat.hpp>

//-----------------------------------------------------------------------------
// tokenizer character


// User-defined namespace
namespace algebra {

// User-defined tokens
namespace tokens {
struct paren      : poacher::Token<paren>     {};
struct number     : poacher::Token<number>    {};
struct op_plus    : poacher::Token<op_plus>   {};
struct op_minus   : poacher::Token<op_minus>  {};
}  // namespace tokens

// Token list
using token_list = std::variant< tokens::paren,
                                 tokens::number,
                                 tokens::op_plus,
                                 tokens::op_minus,
                              poacher::tokens::skip, poacher::tokens::error >;

template<typename Value>
using token_value = poacher::token_value<Value, token_list>;

}  // namespace algebra


template< typename String, typename Check, typename Token >
constexpr auto tokenize_check( String const& str, int pos, Check p, Token t )
{
   auto c = str[pos];
   int consumed = 0;

   using array_t = poacher::ct_array<char, String::static_size>;
   array_t value;

   if ( p(c) )
   {
      while ( c && p(c) )
      {
         value.push_back(c);
         consumed++;
         c = str[pos+consumed];
      }
      return algebra::token_value<array_t>{ value, t };
   }

   return algebra::token_value<array_t>{ value, poacher::tokens::error{} };
}

template< typename String, typename Token >
constexpr auto tokenize_character( String const& str, int pos, char val, Token t )
{
   using array_t = poacher::ct_array<char, String::static_size>;

   array_t v;
   if( str[pos] == val ) { v.push_back(val); return algebra::token_value<array_t>{v, t}; }
   else                    return algebra::token_value<array_t>{ v, poacher::tokens::error{} };
}


constexpr auto tokenize_char_gen = [] ( char c, auto tok ) {
   return [=] ( auto str, int pos ) constexpr {
      return tokenize_character( str, pos, c, tok );
   };
};

constexpr auto tokenize_open_paren  = tokenize_char_gen( '(', algebra::tokens::paren{} );
constexpr auto tokenize_close_paren = tokenize_char_gen( ')', algebra::tokens::paren{} );
constexpr auto tokenize_op_plus     = tokenize_char_gen( '+', algebra::tokens::op_plus{} );
constexpr auto tokenize_op_minus    = tokenize_char_gen( '-', algebra::tokens::op_minus{} );

constexpr auto skip_space           = tokenize_char_gen( ' ', poacher::tokens::skip{} );
constexpr auto skip_tab             = tokenize_char_gen( '\t', poacher::tokens::skip{} );
constexpr auto skip_cr              = tokenize_char_gen( '\n', poacher::tokens::skip{} );

constexpr auto skip_whites          = poacher::either( poacher::either( skip_space, skip_tab ), skip_cr );


constexpr auto tokenize_numbers = []( auto str, int pos ) constexpr
{
   return tokenize_check ( str, pos,
      [] ( auto c ) constexpr {
         return c >= '0' && c <= '9';
      }, algebra::tokens::number{} );
};

template< typename String, typename Tokenizer >
constexpr auto tokenize(String str, Tokenizer tkz)
{
   int current = 0;
   using array_t = poacher::ct_array< char, String::static_size >;
   poacher::ct_array< algebra::token_value<array_t>, String::static_size > token_list;

   while( current < str.size() )
   {
      bool tokenized = false;

      auto tok = [&]( auto&& fn ) {
         if( tokenized ) return;
         auto cur_token = fn( str, current );

         if( cur_token.value.size() != 0)
         {
               tokenized = true;
               current += cur_token.value.size();
         }

         std::visit( [&] (auto t) {
            if constexpr ( t != poacher::tokens::error{} && t != poacher::tokens::skip{} )
               token_list.push_back(cur_token);
         }, cur_token.type );
      };

      poacher::detail::repeat( tkz, tok );

      if ( !tokenized ) throw "Invalid character";
   }

   return token_list;
}

constexpr auto s = poacher::ct_string( "(123 \t88(7 + 7 - 7)     \t\t\n+ \n45)" );

constexpr auto my_tokenizer = std::make_tuple ( skip_whites,
                                                tokenize_open_paren,
                                                tokenize_close_paren,
                                                tokenize_op_plus,
                                                tokenize_op_minus,
                                                tokenize_numbers );



int main()
{
   constexpr auto t = tokenize( s, my_tokenizer );

   for( auto tt : t )
   {
      //std::cout << int(tt::type) << " ";
      for( auto c : tt.value )
         std::cout << c;
      std::cout << "\n";
   }
   std::cout << "\n";
}
