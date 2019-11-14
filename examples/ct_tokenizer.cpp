#include <array>
#include <cstddef>
#include <iostream>
#include <tuple>
#include <variant>

#include <poacher/utility/ct_array.hpp>
#include <poacher/utility/ct_string.hpp>
#include <poacher/utility/repeat.hpp>

//---------------------------------------------------------------------------------------------
// tokenize character

namespace poacher::tokens {

template<typename T> struct token {

   template<typename U> constexpr bool operator==( token<U> const& ) noexcept {
      return std::is_same_v<T, U>;
   }

   template<typename U> constexpr bool operator!=( token<U> const& ) noexcept {
      return !std::is_same_v<T, U>;
   }

};

struct skip       : token<skip>     {};
struct error      : token<error>    {};

}  // namespace poacher::tokens

namespace tokens {

struct paren      : poacher::tokens::token<paren>    {};
struct number     : poacher::tokens::token<number>   {};
struct op_plus    : poacher::tokens::token<op_plus>  {};
struct op_minus   : poacher::tokens::token<op_minus> {};

using token_list = std::variant< paren, number, op_plus, op_minus,
poacher::tokens::skip, poacher::tokens::error >;

}  // namespace tokens

template< typename Value >
struct token
{
   Value value;
   tokens::token_list type;
};

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
      return token<array_t>{ value, t };
   }

   return token<array_t>{ value, poacher::tokens::error{} };
}

template< typename String, typename Token >
constexpr auto tokenize_character( String const& str, int pos, char value, Token t )
{
   using array_t = poacher::ct_array<char, String::static_size>;

   array_t v;
   if( str[pos] == value ) { v.push_back(value); return token<array_t>{v, t}; }
   else                    return token<array_t>{ v, poacher::tokens::error{} };
}

template<typename T1, typename T2>
constexpr auto either( T1 v1, T2 v2 ) {
   return [=] ( auto str, int pos ) constexpr {
      auto r = v1( str, pos );
      if ( !std::holds_alternative<poacher::tokens::error>(r.type) )
         return r;
      return v2( str, pos );
   };
}

template<typename T1, typename T2>
constexpr auto then( T1 v1, T2 v2 ) {
   return [=] ( auto str, int pos ) constexpr {
      auto r = v1( str, pos );
      if ( std::holds_alternative<poacher::tokens::error>(r.type) )
         return r;
      return v2( str, pos );
   };
}

constexpr auto tokenize_char_gen = [] ( char c, auto tok ) {
   return [=] ( auto str, int pos ) constexpr {
      return tokenize_character( str, pos, c, tok );
   };
};

constexpr auto tokenize_open_paren  = tokenize_char_gen( '(', tokens::paren{} );
constexpr auto tokenize_close_paren = tokenize_char_gen( ')', tokens::paren{} );
constexpr auto tokenize_op_plus     = tokenize_char_gen( '+', tokens::op_plus{} );
constexpr auto tokenize_op_minus    = tokenize_char_gen( '-', tokens::op_minus{} );

constexpr auto skip_space           = tokenize_char_gen( ' ', poacher::tokens::skip{} );
constexpr auto skip_tab             = tokenize_char_gen( '\t', poacher::tokens::skip{} );
constexpr auto skip_cr              = tokenize_char_gen( '\n', poacher::tokens::skip{} );

constexpr auto skip_whites          = either( either( skip_space, skip_tab ), skip_cr );


constexpr auto tokenize_numbers = []( auto str, int pos ) constexpr
{
   return tokenize_check ( str, pos,
      [] ( auto c ) constexpr {
         return c >= '0' && c <= '9';
      }, tokens::number{} );
};

template< typename String, typename Tokenizer >
constexpr auto tokenize(String str, Tokenizer tkz)
{
   int current = 0;
   using array_t = poacher::ct_array< char, String::static_size >;
   poacher::ct_array< token<array_t>, String::static_size > token_list;

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
