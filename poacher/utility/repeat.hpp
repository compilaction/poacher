#pragma once

#include <utility>
#include <tuple>

namespace poacher::detail {

template< typename Tuple, typename Code, int... Idx >
constexpr void repeat( Tuple t, Code c, std::integer_sequence<int,Idx...> const& )
{
   ( c( std::get<Idx>(t) ), ... );
}

template< typename Tuple, typename Code >
constexpr void repeat( Tuple t, Code c )
{
   repeat( t, c,
      std::make_integer_sequence< int,
         std::tuple_size< std::decay_t<Tuple> >::value >{} );
}

}  // namespace poacher
