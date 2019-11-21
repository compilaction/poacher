#pragma once

#include <variant>

#include <poacher/utility/ct_array.hpp>
#include <poacher/utility/repeat.hpp>

namespace poacher {   //-------------------------------------------------------

template<typename T>
struct Token {

   template<typename U> constexpr bool operator==( Token<U> const& ) noexcept {
      return std::is_same_v<T, U>;
   }

   template<typename U> constexpr bool operator!=( Token<U> const& ) noexcept {
      return !std::is_same_v<T, U>;
   }

};

template< typename TokenType, typename Value >
struct token_value
{
   using type_t = TokenType;
   using value_t = Value;

   TokenType type;
   Value value;
};

namespace tokens {   //--------------------------------------------------------

   struct skip    : Token<skip>  {};
   struct error   : Token<error> {};

}  // namespace poacher::tokens  //--------------------------------------------

template<typename... Ts>
using token_type_list = std::variant<Ts..., tokens::skip, tokens::error>;

}  // namespace poacher  //----------------------------------------------------
