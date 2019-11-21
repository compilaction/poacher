#include <array>
#include <cstddef>
#include <iostream>
#include <tuple>

#include <poacher/utility/ct_array.hpp>
#include <poacher/utility/ct_string.hpp>
#include <poacher/tokenizer/operators.hpp>
#include <poacher/tokenizer/token.hpp>
#include <poacher/tokenizer/tokenizer.hpp>

//-----------------------------------------------------------------------------
// tokenizer character

// User-defined namespace (ASCIImath)
namespace amath {

// User-defined tokens
namespace tokens {
struct paren      : poacher::Token<paren>     {};
struct number     : poacher::Token<number>    {};
struct op_plus    : poacher::Token<op_plus>   {};
struct op_minus   : poacher::Token<op_minus>  {};
}  // namespace tokens

// Token list
using token_type = std::variant< tokens::paren,
                                 tokens::number,
                                 tokens::op_plus,
                                 tokens::op_minus,
                              poacher::tokens::skip, poacher::tokens::error >;

template<typename Value>
using token_value = poacher::token_value< token_type, Value >;

}  // namespace amath


template < template<typename> typename TokenValType
         , typename String, typename Token >
constexpr auto tokenize_char( String const& str, int pos, char val, Token t )
{
   using array_t = poacher::ct_array<char, String::static_size>;

   array_t v;
   if( str[pos] == val ) {
      v.push_back(val);
      return TokenValType<array_t>{ t, v };
   }

   return TokenValType<array_t>{ poacher::tokens::error{}, v };
}


template<template<typename> typename TokenValType>
constexpr auto tokenize_char_gen = [] ( char c, auto tok ) {
   return [=] ( auto str, int pos ) constexpr {
      return tokenize_char<TokenValType>( str, pos, c, tok );
   };
};

constexpr auto tokenize_open_paren
   = tokenize_char_gen<amath::token_value>( '(', amath::tokens::paren{} );
constexpr auto tokenize_close_paren
   = tokenize_char_gen<amath::token_value>( ')', amath::tokens::paren{} );
constexpr auto tokenize_op_plus
   = tokenize_char_gen<amath::token_value>( '+', amath::tokens::op_plus{} );
constexpr auto tokenize_op_minus
   = tokenize_char_gen<amath::token_value>( '-', amath::tokens::op_minus{} );

constexpr auto skip_space
   = tokenize_char_gen<amath::token_value>( ' ', poacher::tokens::skip{} );
constexpr auto skip_tab
   = tokenize_char_gen<amath::token_value>( '\t', poacher::tokens::skip{} );
constexpr auto skip_cr
   = tokenize_char_gen<amath::token_value>( '\n', poacher::tokens::skip{} );

constexpr auto skip_whitespace
   = poacher::either( poacher::either( skip_space, skip_tab ), skip_cr );

constexpr auto tokenize_numbers = []( auto str, int pos ) constexpr
{
   return poacher::tokenize_check<amath::token_value> ( str, pos,
      [] ( auto c ) constexpr {
         return c >= '0' && c <= '9';
      }, amath::tokens::number{} );
};


constexpr auto s = poacher::ct_string( "(123 \t88(7 + 7 - 7)  \t\t\n+ \n45)" );

constexpr auto my_tokenizer = std::make_tuple ( skip_whitespace,
                                                tokenize_open_paren,
                                                tokenize_close_paren,
                                                tokenize_op_plus,
                                                tokenize_op_minus,
                                                tokenize_numbers );

int main()
{
   constexpr auto t = poacher::tokenize<amath::token_value>( s, my_tokenizer );

   for( auto tt : t )
   {
      //std::cout << int(tt::type) << " ";
      for( auto c : tt.value )
         std::cout << c;
      std::cout << "\n";
   }
   std::cout << "\n";
}
