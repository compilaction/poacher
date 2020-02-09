#pragma once

#include <variant>
#include <tuple>

#include <poacher/utility/ct_vector.hpp>

namespace poacher {

// Contains lots of helpers to get types for productions,
// symbols, etc. for grammars
template<typename Rule, typename Token>
struct grammar_builder_t
{
  using rule_t      = Rule;
  using token_t     = Token;
  using symbol_t    = std::variant<rule_t, token_t>;

  template<typename T>
  struct grammar_t
  {
    using rule_t      = rule_t;
    using token_t     = token_t;
    using symbol_t    = symbol_t;

    T data;
  };

  template<typename Producer, typename... Symbols>
  struct production_t
  {
    using rule_t      = rule_t;
    using producer_t  = Producer;
    using sequence_t  = std::tuple<Symbols...>;

    static_assert( (std::is_same_v<Symbols, symbol_t> && ...),
      "Invalid symbol type!" );

    rule_t rule;
    producer_t producer;
    sequence_t sequence;
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
      , producer
      , std::apply( [] ( auto... e ) {
          return make_tuple( symbol_t { e } ... );
        }, sequence )
      };
  }

  template<typename Final, typename... Productions>
  static constexpr auto make_grammar( Final const& final,
    Productions const&... productions )
  {
    // Checking that arguments are indeed productions (TODO: Improve)
    static_assert
      ( std::is_same_v<typename Final::rule_t, rule_t> &&
        ( std::is_same_v<typename Productions::rule_t, rule_t> && ... )
      , "Invalid type for production!" );

    return grammar_t< std::tuple<Final, Productions...> >
      { std::tuple( final, productions... ) };
  }
};

  template<typename Descriptor, typename Grammar>
  static constexpr auto make_parser( Grammar )
  {
    // ಠ_ಠ
  }

}
