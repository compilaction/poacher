#include <iostream>
#include <array>
#include <tuple>
#include <variant>

#include <poacher/parser/LR0.hpp>

enum tok_t  { open_v, close_v, zero_v, one_v, add_v, sub_v, mul_v, div_v };
enum rule_t { exp_v, id_v };

int main () {
  //auto constexpr v = poacher::eval_to_array( [] () {
  //  return poacher::ct_vector<int>( { 1, 2, 3 } );
  //} );

  // auto constexpr v = poacher::ct_vector<int>( { 1, 2, 3 } );

  //for( auto const& val : v ) std::cout << val << '\n';
  using desc = poacher::grammar_descriptor_t<rule_t, tok_t>;

  constexpr auto Final =
    desc::make_production
      ( exp_v
      , std::make_tuple( open_v )
      , [] () {} );

  (void)Final;

  //constexpr auto grammar = desc::make_grammar(
  //  desc::make_production(exp_v, ),
  //  desc::make_production(exp_v, ),
  //  desc::make_production(),
  //  desc::make_production() );
}
