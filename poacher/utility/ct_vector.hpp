#pragma once

#include <array>
#include <optional>

namespace poacher {

template<typename T>
class ct_vector
{
  //---------------------------------------------------------------------------
  //  MEMBERS

  T* data_;
  std::size_t size_;
  std::size_t capacity_;

  //---------------------------------------------------------------------------
  //  TYPES

  using element_t = T;
  using size_t = std::size_t;

public:

  //---------------------------------------------------------------------------
  //  CONSTRUCTORS & DESTRUCTOR

  constexpr ct_vector()
  : data_(nullptr), size_(0), capacity_(0)
  {}

  constexpr ct_vector ( std::size_t n )
  : data_( new element_t[n] ), size_( n ), capacity_( n ) {
    for( auto & e : *this ) e = element_t();
  }

  constexpr ct_vector ( std::size_t n, element_t const& val )
  : data_( new element_t[n] ), size_( n ), capacity_( n ) {
    for( auto & e : *this ) e = val;
  }

  constexpr ct_vector ( ct_vector const& other )
  : data_( new element_t[ other.size() ] ), size_( other.size_ ) {
    for( std::size_t i = 0; i < size_; i++ ) (*this)[i] = other[i];
  }

  constexpr ct_vector ( ct_vector && other )
  : data_( other.data_ ), size_( other.size_ ) {
    other.data_ = nullptr;
  }

  constexpr ct_vector ( auto begin, auto end )
  : data_( new element_t[ end - begin ] )
  , size_( end - begin )
  , capacity_( end - begin )
  {
    auto begin_ = this->begin();

    while( begin != end ) {
      *begin_++ = *begin++;
    }
  }

  constexpr ct_vector ( std::initializer_list<element_t> elmts )
  : ct_vector( elmts.begin(), elmts.end() ) {}

  constexpr ~ct_vector () {
    if( data_ ) delete[] data_;
    this->size_ = 0;
    this->capacity_ = 0;
  }

  //---------------------------------------------------------------------------
  //  ACCESSORS

  constexpr T&       operator[] ( size_t n )       { return data_[n]; }
  constexpr T const& operator[] ( size_t n ) const { return data_[n]; }

  constexpr T&        front ()        { return this->data_[0]; }
  constexpr T const&  front ()  const { return this->data_[0]; }
  constexpr T&        back ()         { return this->data_[ this->size_-1 ]; }
  constexpr T const&  back ()   const { return this->data_[ this->size_-1 ]; }
  constexpr T*        data ()         { return this->data_; }

  constexpr size_t size ()      const { return size_; }
  constexpr size_t capacity ()  const { return capacity_; }

  //---------------------------------------------------------------------------
  //  ITERATORS

  constexpr T*        begin ()        { return data_; }
  constexpr T*        end ()          { return data_ + size_; }
  constexpr const T*  begin ()  const { return data_; }
  constexpr const T*  end ()    const { return data_ + size_; }

  //---------------------------------------------------------------------------
  //  MODIFIERS

  constexpr ct_vector& push_back ( T const& elmt ) {
    if( this->size_ + 1 > this->capacity_ )
      this->reserve( capacity_ == 0 ? 512 : capacity_ * 2 );
    this->size_++;
    this->data_[this->size_ - 1] = elmt;
    return *this;
  }

  constexpr ct_vector& push_back ( T && elmt ) {
    if( this->size_ + 1 > this->capacity_ )
      this->reserve( capacity_ == 0 ? 512 : capacity_ * 2 );
    this->size_++;
    this->data_[this->size_ - 1] = std::move(elmt);
    return *this;
  }

  constexpr ct_vector& pop_back () {
    (*this)[this->size_ - 1].~T();
    this->size_--;
    return *this;
  }

  constexpr ct_vector& resize ( size_t size, T const& value = T() )
  {
    if( auto sz = this->size_; size > sz ) {
      this->reserve( size );
      this->size_ = size;
      for( ; sz < size; sz++ ) (*this)[sz] = value;
    }

    else if( size < sz ) {
      this->size_ = size;
      for( ; sz >= size; sz-- ) (*this)[sz].~T();
    }

    return *this;
  }

  constexpr ct_vector& reserve ( size_t n ) {
    if( n <= this->capacity_ ) return *this;
    T* new_data = new T[n];
    for( size_t i = 0; i < this->size_; i++ )
      new_data[i] = this->data_[i];
    delete[] this->data_;
    this->data_ = new_data;
    return *this;
  }

  constexpr ct_vector& swap ( ct_vector & other )
  {
    auto const data = other.data_;
    other.data_ = this->data_;
    this->data_ = data;

    auto const size = other.size_;
    other.size_ = this->size_;
    this->size_ = size;

    auto const capacity = other.capacity_;
    other.capacity_ = this->capacity_;
    this->capacity_ = capacity;

    return *this;
  }

  constexpr bool empty () const { return this->size_ == 0; }
};

template<typename T>
constexpr bool operator== ( ct_vector<T> const& a, ct_vector<T> const& b )
{
  if( a.size() != b.size() ) return false;
  if( a.size() == 0 ) return true;

  for( std::size_t i = 0; i < a.size(); i++ )
    if( a[i] != b[i] ) return false;
  return true;
}

template<typename T>
constexpr bool operator!= ( ct_vector<T> const& a, ct_vector<T> const& b )
{
  if( a.size() != b.size() ) return true;
  if( a.size() == 0 ) return false;

  for( std::size_t i = 0; i < a.size(); i++ )
    if( a[i] != b[i] ) return true;
  return false;
}

constexpr auto eval_to_array ( auto f ) {
  constexpr size_t size = f().size();
  auto const v = f();
  std::array<int, size> arr;
  for( size_t i = 0; i < v.size(); i++) arr[i] = v[i];
  return arr;
}

}
