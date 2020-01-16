#include <cstddef>
#include <iostream>
#include <tuple>

#include <poacher/utility/ct_array.hpp>
#include <poacher/utility/ct_pair.hpp>

inline constexpr std::size_t production_not_found = std::size_t(-1);

template<typename P, typename Symbol>
constexpr std::size_t find_axiom( std::tuple<P> const& g, Symbol const& s) noexcept
{
  if (std::get<0>(g).first == s)
    return 0;
  else
    return production_not_found;
}

template<typename... Ps, typename Symbol>
constexpr std::size_t find_axiom( std::tuple<Ps...> const& g, Symbol const& s) noexcept
{
  if (std::get<0>(g).first == s)
    return 0;
  else
  {
    std::size_t i = find_axiom ( std::apply( [](auto const&, auto const&... ps) { return std::make_tuple(ps...); }
                                            , g
                                            )
                                , s
                                );
    return i == production_not_found ? production_not_found : 1+i;
  }
}

template<typename Symbol>
struct rule
{
  constexpr rule(Symbol const& sym) : value(sym) {}
  constexpr auto operator->() const noexcept { return this; }

  template<typename... Prod>
  constexpr auto produce(Prod const&... p) const noexcept
  {
    return poacher::ct_pair{rule{value},poacher::ct_array{p...}};
  }

  constexpr bool operator==(rule const& other) const noexcept { return value == other.value; }
  Symbol value;
};

#define grammar std::tuple

int main()
{
  using namespace poacher;

  constexpr auto S     = rule{10};
  constexpr auto f     = rule{100};
  constexpr auto a     = rule{200};
  constexpr auto empty = rule{300};
  constexpr auto END   = rule{9999};

  constexpr grammar g = { S -> produce(f,END)
                        , f -> produce(f,a)
                        , f -> produce(empty)
                        };

  constexpr auto axiom = find_axiom( g, S );

  if constexpr( axiom != production_not_found )
    std::cout << std::get<axiom>(g).first.value << "\n";
  else
    std::cout << "ERROR\n";
}
