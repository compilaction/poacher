#include <cstddef>

//---------------------------------------------------------------------------------------------
// ct_assert

#include <cassert>
#include <utility>

template<class Assert> inline void ct_assert_failed( Assert&& a ) noexcept {
   std::forward<Assert>(a)();
}

#define ct_assert(cond) ((void)((cond) ? 0 : (ct_assert_failed( [](){ assert(!#cond); } ), 0)))

//---------------------------------------------------------------------------------------------
// ct_array

template<typename T, int Capacity>
struct ct_array
{
   constexpr ct_array() noexcept : actual_size_(0), data_{} {}

   template<typename U, typename... Ts>
   constexpr ct_array(U v, Ts... vs) noexcept: actual_size_(1+sizeof...(Ts)), data_{v,vs...} { }

   constexpr int capacity()        const  noexcept { return Capacity; }
   constexpr int size()            const  noexcept { return actual_size_; }
   constexpr T&  operator[](int i)        noexcept
   {
      ct_assert(i<actual_size_);
      return data_[i];
   }

   constexpr T operator[](int i) const noexcept
   {
      ct_assert(i<actual_size_);
      return data_[i];
   }

   constexpr T const* begin() const { return &data_[0]; }
   constexpr T*       begin()       { return &data_[0]; }
   constexpr T const* end()   const { return begin() + actual_size_; }
   constexpr T*       end()         { return begin() + actual_size_; }

   constexpr void resize(int nsz)
   {
      ct_assert(nsz<capacity());
      actual_size_ = nsz;
   }

   constexpr void clear() { actual_size_ = 0;   }

   constexpr void insert(T v, int pos) noexcept
   {
      ct_assert(actual_size_<capacity());

      auto i0 = capacity() - 1;
      for( int i = i0; i > pos; i--) data_[i] = data_[i-1];
      data_[pos] = v;
      actual_size_++;
   }

   constexpr void push_back(T v) noexcept
   {
      ct_assert(actual_size_<capacity());
      data_[actual_size_] = v;
      actual_size_++;
   }

   constexpr void pop_back() noexcept
   {
      ct_assert(actual_size_);
      actual_size_--;
   }

private:
   int actual_size_;
   T   data_[Capacity];
};

template<typename T, typename... Ts>
ct_array(T v, Ts... vs) -> ct_array<T,1+sizeof...(Ts)>;

//---------------------------------------------------------------------------------------------
// ct_string

#include <cstddef>
#include <utility>

template <typename CharT, int N>
class ct_string
{
   CharT content[N];
public:
   using char_type = CharT;
   static constexpr auto static_size = N;

   constexpr ct_string() : content{} {}

   template <size_t... I>
   constexpr ct_string( const CharT (&input)[N], std::index_sequence<I...> ) noexcept
      : content{ input[I]... }
      { }

   constexpr ct_string(const CharT (&input)[N]) noexcept
      : ct_string( input, std::make_index_sequence<N>() )
      { }

   constexpr int size() const noexcept
   {
      // if it's zero terminated string (from const char * literal) then size N - 1
      if (content[N-1] == '\0') return N - 1;
      else return N;
   }

   constexpr CharT const& operator[](int i) const noexcept
   {
      return content[i];
   }

   constexpr const CharT * begin() const noexcept
   {
      return content;
   }

   constexpr const CharT * end() const noexcept
   {
      return content + size();
   }
};

template <typename CharT>
class ct_string<CharT, 0> {
public:
   using char_type = CharT;

   constexpr ct_string(const CharT *) noexcept { }

   constexpr int size() const noexcept {
      return 0;
   }

   constexpr const CharT * begin() const noexcept {
      return nullptr;
   }

   constexpr const CharT * end() const noexcept {
      return nullptr;
   }
};

template <typename CharT, int N>
ct_string(const CharT (&)[N]) -> ct_string<CharT, N>;

template <typename CharT, int N>
ct_string(ct_string<CharT, N>) -> ct_string<CharT, N>;


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
   using array_t = ct_array<char, String::static_size>;

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

   using array_t = ct_array<char, String::static_size>;
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

#include <array>
#include <tuple>

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
   using array_t = ct_array<char, String::static_size>;
   ct_array<token<array_t>, String::static_size> token_list;

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

#include <iostream>

constexpr auto s = ct_string("(123 88(7 + 7 - 7) + 45)");

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
