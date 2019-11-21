#pragma once

#include <poacher/tokenizer/token.hpp>

namespace poacher {   //-------------------------------------------------------

template < template<typename> typename TokenValType
         , typename String, typename Check, typename Token >
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
      return TokenValType<array_t>{ t, value };
   }

   return TokenValType<array_t>{ poacher::tokens::error{}, value };
}


template < template<typename> typename TokenValType
         , typename String, typename Tokenizer >
constexpr auto tokenize( String str, Tokenizer tkz )
{
   int current = 0;

   using array_t = poacher::ct_array< char, String::static_size >;
   poacher::ct_array< TokenValType<array_t>, String::static_size > token_list;

   while( current < str.size() )
   {
      bool tokenized = false;

      auto tok = [&]( auto&& fn )
      {
         if( tokenized ) return;

         auto cur_token = fn( str, current );

         if( cur_token.value.size() != 0) {
            tokenized = true;
            current += cur_token.value.size();
         }

         std::visit( [&] ( auto t ) {
            if constexpr ( t != poacher::tokens::error{}
                        && t != poacher::tokens::skip{} ) {
               token_list.push_back( cur_token );
            }
         }, cur_token.type );
      };

      poacher::detail::repeat( tkz, tok );

      if ( !tokenized ) throw "Invalid character";
   }

   return token_list;
}

}  // namespace poacher  //----------------------------------------------------
