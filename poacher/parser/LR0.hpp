#pragma once

#include <variant>

#include <poacher/utility/ct_vector.hpp>

namespace poacher {

// Contains lots of helpers to get types for productions,
// symbols, etc. for grammars
template<typename Rule, typename Token>
struct grammar_descriptor_t
{
  using rule_t      = Rule;
  using token_t     = Token;
  using symbol_t    = std::variant<rule_t, token_t>;
  using sequence_t  = ct_vector<symbol_t>;

  template<typename Producer>
  struct production_t
  {
    using producer_t = Producer;

    rule_t rule;
    sequence_t sequence;
    producer_t producer;
  };

  template<typename Producer>
  static constexpr production_t<Producer> make_production( rule_t const& rule,
    sequence_t const& sequence, Producer producer ) {
    return production_t<Producer>{ rule, sequence, producer };
  }

  template<typename Final, typename... Productions>
  static constexpr auto make_grammar( Final const& final,
    Productions const&... productions ) {
    return std::tuple( final, productions... );
  }
};

}
