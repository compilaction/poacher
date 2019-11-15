#pragma once

#include <variant>

#include <poacher/tokenizer/token.hpp>

namespace poacher {   //-------------------------------------------------------

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

}  // namespace poacher  //----------------------------------------------------
