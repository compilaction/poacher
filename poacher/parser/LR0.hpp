#pragma once

#include <array>

template< typename K, typename V >
struct ct_binding
{
  V val;
  constexpr auto operator()( K ) {}
};

template< typename Item >
struct ct_grammar
{

};
