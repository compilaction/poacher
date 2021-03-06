#pragma once

#include <array>
#include <tuple>
#include <type_traits>
#include <variant>

namespace poacher {

template<typename T>
class ct_vector
{
  //---------------------------------------------------------------------------
  //  MEMBERS

  T* data_;
  std::size_t size_;
  std::size_t capacity_;

public:

  //---------------------------------------------------------------------------
  //  TYPES

  using element_t = T;
  using size_t = std::size_t;

  //---------------------------------------------------------------------------
  //  CONSTRUCTORS & DESTRUCTOR

  // Default constructor
  constexpr ct_vector()
  : data_( nullptr )
  , size_( 0 )
  , capacity_( 0 )
  {}

  // Constructs a vector with n initialized values
  constexpr ct_vector ( std::size_t n )
  : data_( new element_t[n] )
  , size_( n )
  , capacity_( n )
  {
    for( auto & e : *this ) e = element_t();
  }

  constexpr ct_vector ( std::size_t n, element_t const& val )
  : data_( new element_t[n] )
  , size_( n )
  , capacity_( n )
  {
    for( auto & e : *this ) e = val;
  }

  constexpr ct_vector ( ct_vector const& other )
  : data_( new element_t[ other.size() ] )
  , size_( other.size_ )
  , capacity_( other.size_ )
  {
    for( std::size_t i = 0; i < size_; i++ ) (*this)[i] = other[i];
  }

  constexpr ct_vector ( ct_vector && other )
  : data_( other.data_ )
  , size_( other.size_ )
  , capacity_ ( other.capacity_ )
  {
    other.data_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
  }

  constexpr ct_vector ( std::initializer_list<element_t> list )
  : data_( new element_t[ list.size() ] )
  , size_( 0 )
  , capacity_( list.size() )
  {
    for( auto const& e : list ) this->push_back( e );
  }

  template<auto N>
  constexpr ct_vector ( std::array<element_t, N> elmts )
  : ct_vector( elmts.begin(), elmts.end() )
  {}

  template<typename... Ts>
  constexpr ct_vector ( std::tuple<Ts...> const& tup )
  : data_( new element_t[ sizeof...( Ts ) ] )
  , size_ ( 0 )
  , capacity_ ( sizeof...( Ts ) )
  {
    std::apply( [this]( auto... Vs ) {
      ( this->push_back(Vs), ... );
    }, tup );
  }

  constexpr ~ct_vector ()
  {
    if( data_ ) delete[] data_;
    this->size_ = 0;
    this->capacity_ = 0;
  }

  //---------------------------------------------------------------------------
  //  ASSIGNMENT

  ct_vector& operator= ( ct_vector const& other )
  {
    this->~ct_vector();
    this->ct_vector( other );
    return *this;
  }

  ct_vector& operator= ( ct_vector && other )
  {
    this->~ct_vector();
    this->ct_vector( std::move(other) );
    return *this;
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

  constexpr ct_vector& push_back ( T const& elmt )
  {
    if( this->size_ + 1 > this->capacity_ )
      this->reserve( capacity_ == 0 ? 512 : capacity_ * 2 );
    this->size_++;
    this->data_[this->size_ - 1] = elmt;
    return *this;
  }


  constexpr ct_vector& push_back ( T && elmt )
  {
    if( this->size_ + 1 > this->capacity_ )
      this->reserve( capacity_ == 0 ? 512 : capacity_ * 2 );
    this->size_++;
    this->data_[this->size_ - 1] = std::move(elmt);
    return *this;
  }


  constexpr ct_vector& pop_back ()
  {
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


  constexpr ct_vector& reserve ( size_t n )
  {
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


constexpr auto eval_as_tuple ( auto f )
{
  constexpr size_t size = f().size();
  auto res = f();
  return [&] <std::size_t... Vs> ( std::integer_sequence<std::size_t, Vs...> )
  {
    return std::make_tuple( res[Vs] ... );
  } ( std::make_integer_sequence<std::size_t, size>{} );
}


constexpr auto eval_as_array ( auto f )
{
  using elmt_t = typename decltype(f())::element_t;
  constexpr size_t size = f().size();
  auto const v = f();
  std::array<elmt_t, size> arr;
  for( size_t i = 0; i < v.size(); i++) arr[i] = v[i];
  return arr;
}


namespace detail_eval_as_unvarianted_tuple {

template<typename ... Ts>
constexpr auto args ( Ts && ... vs ) {
  return std::forward_as_tuple( vs ... );
}

template<typename F, typename... Ts>
constexpr auto operator>>( std::tuple<Ts...> args, F f )
-> std::invoke_result_t<F, Ts...> {
  return std::apply( f, args );
}

template<typename T, bool V> struct type_reduce { using type = T; };

template<typename T1, bool V1, typename T2, bool V2>
constexpr auto operator | ( type_reduce<T1, V1>, type_reduce<T2, V2> )
  -> std::conditional_t<V1, type_reduce<T1, V1>, type_reduce<T2, V2>> {
  return std::conditional_t< V1, type_reduce<T1, V1>, type_reduce<T2, V2> >{};
}

}


constexpr auto eval_as_unvarianted_tuple ( auto f )
{
  using namespace std;
  using namespace detail_eval_as_unvarianted_tuple;

  constexpr size_t size = f().size();

  // Getting a pack of size_t from size
  return args( make_integer_sequence<size_t, size>{} )
  >> [&] <size_t... Vs> ( integer_sequence<size_t, Vs...> ) {

    // Returns the value contained in the constexpr variant of index I
    auto unvariant = [&] ( auto I )
    {
      // Storing val as a *constexpr* variable
      constexpr auto val = f()[I];

      // Extracting val's underlying type
      auto constexpr type_holder = args ( val )
      >> [&] <typename... Ts> ( variant<Ts...> const& ) {
        // Reducing type
        return ( type_reduce<Ts, holds_alternative<Ts>( val )>{} | ... );
      };
      using typ = typename decltype(type_holder)::type;


      return get<typ>(val);
    };

    // For each index: unvariant
    return tuple( unvariant( integral_constant<size_t, Vs>{} ) ... );
  };
}

template<typename... TupTs>
constexpr auto unvariant_tuple ( std::tuple<TupTs...> f )
{
  using namespace std;
  using namespace detail_eval_as_unvarianted_tuple;

  constexpr size_t size = sizeof...(TupTs);

  return args( make_integer_sequence<size_t, size>{} )
  >> [&] <size_t... Vs> ( integer_sequence<size_t, Vs...> )
  {
    return make_tuple( args( integral_constant<size_t, Vs>{} ) ... )
    >> [&] ( auto I )
    {
      constexpr auto val = f()[I];

      auto constexpr type_holder = args( val )
      >> [&] <typename... VarTs> ( variant<VarTs...> )
      {
        return ( type_reduce<VarTs, holds_alternative<VarTs>(val)>{} | ... );
      };
      using typ = typename decltype(type_holder)::type;

      return get<typ>(val);
    };
  };
}


} //  namespace poacher
