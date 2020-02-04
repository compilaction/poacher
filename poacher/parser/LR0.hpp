#pragma once

#include <type_traits>
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

  template<typename Producer, typename... Symbols>
  struct production_t
  {
    using producer_t = Producer;
    using sequence_t = std::tuple<Symbols...>;

    static_assert( (std::is_same_v<Symbols, symbol_t> && ...),
      "Invalid symbol type!" );

    rule_t rule;
    sequence_t sequence;
    producer_t producer;
  };

  template<typename Producer, typename... Symbols>
  static constexpr
  production_t< Producer, decltype( symbol_t{ Symbols{} } ) ... >
  make_production ( rule_t const& rule
                  , std::tuple<Symbols...> sequence
                  , Producer producer )
  {
    return production_t< Producer, decltype( symbol_t{ Symbols{} } ) ... >
      { rule
      , std::apply( [] ( auto ... toks ) {
          return std::make_tuple( symbol_t{ toks } ... );
        }, sequence)
      , producer };
  }

  template<typename Final, typename... Productions>
  static constexpr auto make_grammar( Final const& final,
    Productions const&... productions ) {
    return std::tuple( final, productions... );
  }
};

}
