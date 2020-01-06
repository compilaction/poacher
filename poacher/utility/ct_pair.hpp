#pragma once

//-----------------------------------------------------------------------------
// ct_pair

#include <cstddef>
#include <utility>

namespace poacher {

template <typename T, typename U>
struct ct_pair
{
   using first_type = T;
   using second_type = U;

   T first;
   U second;
};

template <typename T, typename U>
ct_pair(T const&, U const&) -> ct_pair<T,U>;

}  // namespace poacher
