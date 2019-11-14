#include <array>
#include <cstddef>
#include <iostream>
#include <tuple>

#include <poacher/utility/ct_array.hpp>
#include <poacher/utility/ct_string.hpp>

//---------------------------------------------------------------------------------------------
// tokenize character

enum class tokens { paren, number, op_plus, op_minus, error = -1 };

template<typename Value>
struct token
{
    Value value;
    tokens type;
};

template<typename String>
constexpr auto tokenize_character(String const& str, int pos, char value, tokens out)
{
   using array_t = poacher::ct_array<char, String::static_size>;

   array_t v;
   if( str[pos] == value ) { v.push_back(value); return token<array_t>{v, out}; }
   else                    return token<array_t>{ v,tokens::error };
}

constexpr auto tokenize_open_paren = [](auto str, int pos) constexpr
{
   return tokenize_character(str,pos,'(',tokens::paren);
};

constexpr auto tokenize_close_paren = [](auto str, int pos) constexpr
{
   return tokenize_character(str,pos,')',tokens::paren);
};

constexpr auto tokenize_op_plus = [](auto str, int pos) constexpr
{
   return tokenize_character(str,pos,'+',tokens::op_plus);
};

constexpr auto tokenize_op_minus = [](auto str, int pos) constexpr
{
   return tokenize_character(str,pos,'-',tokens::op_minus);
};

constexpr auto skip_space = [](auto str, int pos) constexpr
{
   return tokenize_character(str,pos,' ',tokens::error);
};

template<typename String, typename Check>
constexpr auto tokenize_check(String const& str, int pos, Check p, tokens out)
{
   auto c = str[pos];
   int consumed = 0;

   using array_t = poacher::ct_array<char, String::static_size>;
   array_t value;

   if ( p(c) )
   {
      while (c && p(c) )
      {
         value.push_back(c);
         consumed++;
         c = str[pos+consumed];
      }
      return token<array_t>{value,out};
   }

   return token<array_t>{value,tokens::error};
}

constexpr auto tokenize_numbers = [](auto str, int pos) constexpr
{
   return tokenize_check (str, pos,
      [](auto c) constexpr {
         return c >= '0' && c <= '9';
      }, tokens::number );
};


template<typename Tuple, typename Code, int... Idx>
constexpr void repeat( Tuple t, Code c, std::integer_sequence<int,Idx...> const& )
{
   ( c( std::get<Idx>(t) ), ... );
}

template<typename Tuple, typename Code>
constexpr void repeat(Tuple t, Code c)
{
   repeat(t, c,std::make_integer_sequence<int,std::tuple_size<std::decay_t<Tuple>>::value>{});
}


template<typename String, typename Tokenizer>
constexpr auto tokenize(String str, Tokenizer tkz)
{
   int current = 0;
   using array_t = poacher::ct_array<char, String::static_size>;
   poacher::ct_array<token<array_t>, String::static_size> token_list;

   while(current < str.size())
   {
      bool tokenized = false;

      auto tok = [&](auto&& fn) {
         if(tokenized) return;
         auto cur_token = fn(str, current);

         if( cur_token.value.size() != 0)
         {
               tokenized = true;
               current += cur_token.value.size();
         }

         if(cur_token.type != tokens::error)
         {
               token_list.push_back(cur_token);
         }
      };

      repeat(tkz, tok);
      if (!tokenized) throw "Invalid character";
   }

   return token_list;
}

constexpr auto s = poacher::ct_string("(123 88(7 + 7 - 7) + 45)");

constexpr auto my_tokenizer =
   std::make_tuple ( skip_space,
                     tokenize_open_paren, tokenize_close_paren,
                     tokenize_op_plus, tokenize_op_minus,
                     tokenize_numbers
                  );

int main()
{
   constexpr auto t = tokenize(s,my_tokenizer);

   for(auto tt : t)
   {
      std::cout << int(tt.type) << " ";
      for(auto c : tt.value) std::cout << c;
      std::cout << "\n";
   }
   std::cout << "\n";
}
