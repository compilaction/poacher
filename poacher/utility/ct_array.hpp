#pragma once

//-----------------------------------------------------------------------------
// ct_array

#include <utility>

#include <poacher/utility/ct_assert.hpp>

namespace poacher {

template < typename T, std::size_t Capacity >
class ct_array
{

private:

   std::size_t actual_size_;
   T   data_[ Capacity ];

   //--------------------------------------------------------------------------
   // Constructors

public:

   constexpr ct_array() noexcept : actual_size_(0), data_{} {}

   template < typename U, typename... Ts >
   constexpr ct_array(U v, Ts... vs) noexcept
      : actual_size_(1 + sizeof...(Ts)), data_{v, vs...}
      {}

   constexpr std::size_t capacity() const  noexcept { return Capacity; }
   constexpr std::size_t size()     const  noexcept { return actual_size_; }

   constexpr T&  operator[](int i) noexcept
   {
      POACHER_CT_ASSERT( i < actual_size_ );
      return data_[i];
   }

   constexpr T operator[](int i) const noexcept
   {
      POACHER_CT_ASSERT( i < actual_size_ );
      return data_[i];
   }

   constexpr T const* begin() const { return &data_[0]; }
   constexpr T*       begin()       { return &data_[0]; }
   constexpr T const* end()   const { return begin() + actual_size_; }
   constexpr T*       end()         { return begin() + actual_size_; }

   constexpr void resize(int nsz)
   {
      POACHER_CT_ASSERT( nsz < capacity() );
      actual_size_ = nsz;
   }

   constexpr void clear() { actual_size_ = 0;   }

   constexpr void insert(T v, int pos) noexcept
   {
      POACHER_CT_ASSERT( actual_size_ < capacity() );

      auto i0 = capacity() - 1;
      for( int i = i0; i > pos; i--) data_[i] = data_[i-1];
      data_[pos] = v;
      actual_size_++;
   }

   constexpr void push_back(T v) noexcept
   {
      POACHER_CT_ASSERT( actual_size_ < capacity() );
      data_[ actual_size_ ] = v;
      actual_size_++;
   }

   constexpr void pop_back() noexcept
   {
      POACHER_CT_ASSERT( actual_size_ );
      actual_size_--;
   }
};

template <typename T, int Capacity>
ct_array(const T (&)[Capacity]) -> ct_array<T, Capacity>;

template< typename T, typename... Ts >
ct_array( T v, Ts... vs ) -> ct_array< T, 1 + sizeof...(Ts) >;

}  // namespace poacher
