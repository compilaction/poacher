#include <iostream>
#include <array>
#include <tuple>
#include <variant>
#include <type_traits>

#include <poacher/parser/LR0.hpp>

enum tok_t  { open_v, close_v, zero_v, one_v, add_v, sub_v, mul_v, div_v };
enum rule_t { exp_v, id_v };

struct test_t {};

int main ()
{
  using gb = poacher::grammar_builder_t<rule_t, tok_t>;

  constexpr auto Gram =
    gb::make_grammar
      ( gb::make_production( exp_v, std::make_tuple( open_v, exp_v, close_v ), [] ( auto exp ) { return exp; } )
      , gb::make_production( exp_v, std::make_tuple( open_v, exp_v, close_v ), [] ( auto exp ) { return exp; } )
    );

  (void)Gram;
}
