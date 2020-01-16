#include <cstddef>
#include <iostream>
#include <tuple>

#include <poacher/utility/ct_array.hpp>
#include <poacher/utility/ct_pair.hpp>

inline constexpr std::size_t production_not_found_v = std::size_t( -1 );

template<typename P, typename Symbol>
constexpr std::size_t find_axiom( std::tuple<P> const& g, Symbol const& s )
  noexcept {
  if ( std::get<0>(g).first == s ) return 0;
  else return production_not_found_v;
}

template<typename... Ps, typename Symbol>
constexpr std::size_t find_axiom( std::tuple<Ps...> const& g, Symbol const& s )
  noexcept
{
  if ( std::get<0>(g).first == s ) return 0;
  else {
    std::size_t i = find_axiom
      ( std::apply( []( auto const&, auto const&... ps ) {
          return std::make_tuple(ps...);
        }, g )
      , s
      );
    return i == production_not_found_v ? production_not_found_v : 1 + i;
  }
}

template<typename Symbol>
struct rule_t
{
  using symbol_t = Symbol;

  constexpr rule_t( Symbol const& sym ) : value( sym ) {}

  constexpr auto operator->() const noexcept {
    return this;
  }

  template<typename... Prod>
  constexpr auto production( Prod const&... p ) const noexcept {
    return poacher::ct_pair{ rule_t{ value }, poacher::ct_array{ p... } };
  }

  constexpr bool operator==( rule_t const& other ) const noexcept {
    return value == other.value;
  }

  symbol_t value;
};


int main()
{
  using namespace poacher;

  constexpr auto S     = rule_t{ 10 };
  constexpr auto f     = rule_t{ 100 };
  constexpr auto a     = rule_t{ 200 };
  constexpr auto empty = rule_t{ 300 };
  constexpr auto END   = rule_t{ 9999 };

  constexpr auto g = std::tuple { S -> production( f, END )
                                , f -> production( f, a )
                                , f -> production( empty )
                                };

  constexpr auto axiom = find_axiom( g, S );

  if constexpr( axiom != production_not_found_v )
    std::cout << std::get<axiom>(g).first.value << "\n";
  else
    std::cout << "ERROR\n";
}
