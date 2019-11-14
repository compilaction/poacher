#pragma once

//---------------------------------------------------------------------------------------------
// ct_string

#include <cstddef>
#include <utility>

namespace poacher {

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

}  // namespace poacher
