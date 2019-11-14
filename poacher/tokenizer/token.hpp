#pragma once

#include <variant>

namespace poacher {   //-----------------------------------------------------------------------

template<typename T>
struct Token {

   template<typename U> constexpr bool operator==( Token<U> const& ) noexcept {
      return std::is_same_v<T, U>;
   }

   template<typename U> constexpr bool operator!=( Token<U> const& ) noexcept {
      return !std::is_same_v<T, U>;
   }

};

template< typename Value, typename TokenList >
struct token_value
{
   Value value;
   TokenList type;
};

namespace tokens {   //------------------------------------------------------------------------

struct skip    : Token<skip>  {};
struct error   : Token<error> {};

}  // namespace poacher::tokens  //------------------------------------------------------------

}  // namespace poacher  //--------------------------------------------------------------------
