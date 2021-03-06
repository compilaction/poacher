# poacher

The Library That Hunts Bisons - A C++ constexpr LR(1) parser generator

## Objectives

`constexpr` computation is all the rage in post-C++17 world. Works by
[Hana Dusikova](https://github.com/hanickadot) on compile-time regular
expressions and some great pioneering by [Jason Turner and Ben Deane](https://github.com/lefticus/constexpr_all_the_things/tree/master/src/include) show that parsing arbitrary data or langages from
compile-time available strings is a very valuable technique.

Poacher has the goal to provide an extensible framework to easily define such
constexpr parsers for arbitrary langages and to provide some well known
langages ready-to-use compile time parsers.

Our goal is to implement a constexpr parser generator for LR(1) grammars.
Such grammars can express complex languages such as OCaml, Haskell, or any
other language recognized by a parser generated by programs such as Yacc,
Menhir, or Happy.

## How to use poacher ?

>TBD

## Examples

See [`examples/`](examples/readme.md)

## References

- [Constexpr All The Things](https://github.com/lefticus/constexpr_all_the_things)
- [Jean Privat's courses on compiling & LR(1) parsing](https://info.uqam.ca/~privat/INF5000/)

## Licensing
