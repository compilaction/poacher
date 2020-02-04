#include <iostream>
#include <array>
#include <tuple>
#include <variant>

#include <poacher/parser/LR0.hpp>

enum tok_t  { open_v, close_v, zero_v, one_v, add_v, sub_v, mul_v, div_v };
enum rule_t { exp_v, id_v };

int main () {
  using desc = poacher::grammar_descriptor_t<rule_t, tok_t>;

  constexpr auto Final =
    desc::make_production
      ( exp_v
      , std::make_tuple( open_v )
      , [] () {} );

  (void)Final;
}
