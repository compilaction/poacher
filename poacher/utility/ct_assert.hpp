#pragma once

//---------------------------------------------------------------------------------------------
// ct_assert

#include <cassert>
#include <utility>

namespace poacher::detail {

template<class A> inline void ct_assert_failed( A&& a ) noexcept { std::forward<A>(a)(); }

}  // namespace poacher::detail

#define POACHER_CT_ASSERT(cond) \
   ((void)((cond) ? 0 : (poacher::detail::ct_assert_failed( [](){ assert(!#cond); } ), 0)))
