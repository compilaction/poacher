#include <array>
#include <cstddef>
#include <iostream>
#include <tuple>

#include <poacher/utility/ct_array.hpp>
#include <poacher/utility/ct_string.hpp>
#include <poacher/tokenizer/operators.hpp>
#include <poacher/tokenizer/token.hpp>
#include <poacher/tokenizer/tokenizer.hpp>

#include "asciimath_symbols.hpp"

//-----------------------------------------------------------------------------
// Tokenizer rules definition

// User-defined namespace (ASCIImath)
namespace amath {

template<typename Value>
using token_value = poacher::token_value< token_type_list, Value >;

constexpr auto tokenize_char_gen = [] ( char c, auto tok ) {
   return [=] ( auto str, int pos ) constexpr {
      return poacher::tokenize_char<token_value>( str, pos, c, tok );
   };
};

constexpr auto tokenize_str_gen = [] ( auto s, auto tok ) {
   return [=] ( auto str, int pos ) constexpr {
      return poacher::tokenize_string< token_value > ( str, pos, s, tok );
   };
};

constexpr auto tokenize_ident
   = tokenize_str_gen( poacher::ct_string("ident"), tokens::grp::lpar_{} );

constexpr auto tokenize_open_paren
   = tokenize_char_gen( '(', tokens::grp::lpar_{} );
constexpr auto tokenize_close_paren
   = tokenize_char_gen( ')', tokens::grp::rpar_{} );
constexpr auto tokenize_op_mul
   = tokenize_char_gen( '*', tokens::op::times_{} );
constexpr auto tokenize_op_div
   = tokenize_char_gen( '/', tokens::op::div_{} );
constexpr auto tokenize_op_add
   = tokenize_char_gen( '+', tokens::op::add_{} );
constexpr auto tokenize_op_sub
   = tokenize_char_gen( '-', tokens::op::sub_{} );

constexpr auto skip_space
   = tokenize_char_gen( ' ', poacher::tokens::skip{} );
constexpr auto skip_tab
   = tokenize_char_gen( '\t', poacher::tokens::skip{} );
constexpr auto skip_cr
   = tokenize_char_gen( '\n', poacher::tokens::skip{} );

constexpr auto skip_whitespace
   = poacher::either( poacher::either( skip_space, skip_tab ), skip_cr );

constexpr auto tokenize_numbers = []( auto str, int pos ) constexpr {
   return poacher::tokenize_check<token_value> ( str, pos,
      [] ( auto c ) constexpr {
         return c >= '0' && c <= '9';
      }, tokens::spe::number_{} );
};

constexpr auto tokenizer
   = std::make_tuple ( skip_whitespace
                     , tokenize_ident
                     , tokenize_open_paren
                     , tokenize_close_paren
                     , tokenize_op_mul
                     , tokenize_op_div
                     , tokenize_op_add
                     , tokenize_op_sub
                     , tokenize_numbers
                     );

}  // namespace amath

//-----------------------------------------------------------------------------
// Tokenizer usage

constexpr auto s = poacher::ct_string( "( ident 123 88(7 + 7 - 7) \t\t\n+ \n45)" );
constexpr auto t = poacher::tokenize<amath::token_value>( s, amath::tokenizer );

int main()
{
   for( auto tt : t )
   {
      //std::cout << int(tt::type) << " ";
      for( auto c : tt.value )
         std::cout << c;
      std::cout << "\n";
   }
   std::cout << "\n";
}
