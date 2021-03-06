#pragma once

#include <type_traits>

#include <poacher/tokenizer/token.hpp>

namespace poacher {   //-------------------------------------------------------

template < template<typename> typename TokenValTemplate
         , typename String, typename Token >
constexpr auto tokenize_char( String const& str, int pos, char val, Token t )
{
   using array_t = ct_array<char, String::static_size>;
   using TokenValType = TokenValTemplate<array_t>;

   array_t v;

   if( str[pos] == val ) {
      v.push_back(val);
      return TokenValType{ t, v };
   }

   return TokenValType{ tokens::error{}, v };
}

template < template<typename> typename TokenValTemplate
         , typename String, typename Check, typename TokType >
constexpr auto tokenize_check( String const& str, int pos, Check p, TokType t )
{
   auto c = str[pos];
   int consumed = 0;

   using array_t = ct_array<char, String::static_size>;
   using TokenValType = TokenValTemplate<array_t>;

   array_t value;

   if ( p(c) )
   {
      while ( c && p(c) ) {
         value.push_back(c);
         consumed++;
         c = str[pos+consumed];
      }

      return TokenValType{ t, value };
   }

   return TokenValType{ tokens::error{}, value };
}

template < template<typename> typename TokenValTemplate
         , typename String, typename String_, typename TokType >
constexpr auto tokenize_string( String const& str, int pos
                              , String_ s, TokType t )
{
   using array_t = ct_array<char, String::static_size>;
   using TokenValType = TokenValTemplate<array_t>;

   array_t value;
   int pos_s = 0;

   for(; pos < str.size() && pos_s < s.size(); pos++, pos_s++ )
      if( str[pos] != s[pos_s] ) break;
      else value.push_back( str[pos] );

   if( pos_s == s.size() )
      return TokenValType{ t, value };

   return TokenValType{ tokens::error{}, value };
}

template < template<typename> typename TokenValTemplate
         , typename String, typename Tokenizer >
constexpr auto tokenize( String str, Tokenizer tkz )
{
   using array_t = ct_array< char, String::static_size >;
   using TokenValType = TokenValTemplate<array_t>;

   int current = 0;

   ct_array< TokenValType, String::static_size > token_list;

   while( current < str.size() )
   {
      bool tokenized = false;

      auto tok = [&]( auto&& fn )
      {
         if( tokenized ) return;

         auto cur_token = fn( str, current );

         if( cur_token.value.size() != 0 ) {
            tokenized = true;
            current += cur_token.value.size();
         }

         std::visit( [&] ( auto param_t ) {
            if constexpr ( param_t != tokens::error{} && param_t != tokens::skip{} ) {
               token_list.push_back( cur_token );
            }
         }, cur_token.type );
      };

      detail::repeat( tkz, tok );

      if ( !tokenized ) throw "Invalid character";
   }

   return token_list;
}

}  // namespace poacher  //----------------------------------------------------
