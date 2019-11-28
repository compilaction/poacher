#pragma once

#include <poacher/tokenizer/token.hpp>
#include <poacher/utility/ct_string.hpp>

//-----------------------------------------------------------------------------
// ASCIImath symbols representation

// TODO: Arborescence

// http://asciimath.org/

// Operation symbols

//s "+",          "op_add"
//s "-",          "op_sub"
//s "*",          "op_cdot"
//s "**",         "op_ast"
//s "***",        "op_star"
//s "//",         "op_slash"
//s "\\",         "op_backslash"
//s "xx",         "op_times"
//s "-:",         "op_div"
//s "|><",        "op_ltimes"
//s "><|",        "op_rtimes"
//s "|><|",       "op_bowtie"
//s "@",          "op_circ"
//s "o+",         "op_oplus"
//s "ox",         "op_otimes"
//s "o.",         "op_odot"
//s "sum",        "op_sum"
//s "prod",       "op_prod"
//s "^^",         "op_wedge"
//s "^^^",        "op_bidwedge"
//s "vv",         "op_vee"
//s "vvv",        "op_bigvee"
//s "nn",         "op_cap"
//s "nnn",        "op_bigcap"
//s "uu",         "op_cup"
//s "uuu",        "op_bigcup"

// Miscellanous symbols

//s "/",          "misc_frac"
//s "^",          "misc_exp"
//s "sqrt",       "misc_sqrt"
//s "root",       "misc_root"
//s "int",        "misc_int"
//s "oint",       "misc_oint"
//s "del",        "misc_partial"
//s "grad",       "misc_nabla"
//s "+-",         "misc_pm"
//s "O/",         "misc_emptyset"
//s "oo",         "misc_infty"
//s "aleph",      "misc_aleph"
//s ":.",         "misc_therefore"
//s ":'",         "misc_because"
//s "|...|",      "misc_ldots"
//s "|cdots|",    "misc_cdots"
//s "vdots",      "misc_vdots"
//s "ddots",      "misc_ddots"
//s "|\ |",       "misc_smallquad"
//s "|quad|",     "misc_quad"
//s "/_",         "misc_angle"
//s "frown",      "misc_frown"
//s "/_\",        "misc_triangle"
//s "diamond",    "misc_diamond"
//s "square",     "misc_square"
//s "|__",        "misc_lfloor"
//s "__|",        "misc_rfloor"
//s "|~",         "misc_lceiling"
//s "~|",         "misc_rceiling"
//s "CC",         "misc_C"
//s "NN",         "misc_N"
//s "QQ",         "misc_Q"
//s "RR",         "misc_R"
//s "ZZ",         "misc_Z"

// Relation symbols

//o //s "=",          "rel_eq"
//o //s "!=",         "rel_ne"
//o //s "<",          "rel_lt"
//o //s ">",          "rel_gt"
//o //s "<=",         "rel_le"
//o //s ">=",         "rel_ge"
//o //s "-<",         "rel_prec"
//o //s "-<=",        "rel_preceq"
//o //s ">-",         "rel_succ"
//o //s ">-=",        "rel_succeq"
//o //s "in",         "rel_in"
//o //s "!in",        "rel_notin"
//o //s "sub",        "rel_subset"
//o //s "sup",        "rel_supset"
//o //s "sube",       "rel_subseteq"
//o //s "supe",       "rel_supseteq"
//o //s "-=",         "rel_equiv"
//o //s "~=",         "rel_cong"
//o //s "~~",         "rel_approx"
//o //s "prop",       "rel_propto"

// Logical symbols

//s "and",        "logic_and"
//s "or",         "logic_or"
//s "not",        "logic_neg"
//s "=>",         "logic_implies"
//s "if",         "logic_if"
//s "<=>",        "logic_iff"
//s "AA",         "logic_forall"
//s "EE",         "logic_exists"
//s "_|_",        "logic_bot"
//s "TT",         "logic_top"
//s "|--",        "logic_vdash"
//s "|==",        "logic_models"

// Grouping brackets

//s "(";          "grp_lpar"
//s ")";          "grp_rpar"
//s "[";          "grp_lsqbra"
//s "]";          "grp_rsqbra"
//s "{";          "grp_lcubra"
//s "}";          "grp_rcubra"
//s "(:";         "grp_langle"
//s ":)";         "grp_rangle"
//s "<<";         "grp_langle_"
//s ">>";         "grp_rangle_"
//s "{: x )";     "grp_lxpar"
//s "( x :}";     "grp_rxpar"
//s "abs";        "grp_abs"
//s "floor";      "grp_floor"
//s "ceil";       "grp_ceil"
//s "norm";       "grp_norm"


// Arrows

//o //s "uarr",       "arr_uparrow"
//o //s "darr",       "arr_downarrow"
//o //s "rarr",       "arr_rightarrow"
//o //s "->",         "arr_to"
//o //s ">->",        "arr_rightarrowtail"
//o //s "->>",        "arr_twoheadrightarrow"
//o //s ">->>",       "arr_twoheadrightarrowtail"
//o //s "|->",        "arr_mapsto"
//o //s "larr",       "arr_leftarrow"
//o //s "harr",       "arr_leftrightarrow"
//o //s "rArr",       "arr_Rightarrow"
//o //s "lArr",       "arr_Leftarrow"
//o //s "hArr",       "arr_Leftrightarrow"

// Accents

//o //s "hat",        "acc_hat"
//o //s "bar",        "acc_bar"
//o //s "ul",         "acc_ul"
//o //s "vec",        "acc_vec"
//o //s "dot",        "acc_dot"
//o //s "ddot",       "acc_ddot"
//o //s "overset",    "acc_overset"
//o //s "underset",   "acc_underset"
//o //s "ubrace",     "acc_ubrace"
//o //s "obrace",     "acc_obrace"
//o //s "color",      "acc_color"
//o //s "cancel",     "acc_cancel"

// Greek Letters

//o //s "alpha",      "gr_alpha"
//o //s "beta",       "gr_beta"
//o //s "gamma",      "gr_gamma"
//o //s "Gamma",      "gr_Gamma"
//o //s "delta",      "gr_delta"
//o //s "Delta",      "gr_Delta"
//o //s "epsilon",    "gr_epsilon"
//o //s "varepsilon", "gr_varepsilon"
//o //s "zeta",       "gr_zeta"
//o //s "eta",        "gr_eta"
//o //s "theta",      "gr_theta"
//o //s "Theta",      "gr_Theta"
//o //s "vartheta",   "gr_vartheta"
//o //s "iota",       "gr_iota"
//o //s "kappa",      "gr_kappa"
//o //s "lambda",     "gr_lambda"
//o //s "Lambda",     "gr_Lambda"
//o //s "mu",         "gr_mu"
//o //s "nu",         "gr_nu"
//o //s "xi",         "gr_xi"
//o //s "Xi",         "gr_Xi"
//o //s "pi",         "gr_pi"
//o //s "Pi",         "gr_Pi"
//o //s "rho",        "gr_rho"
//o //s "sigma",      "gr_sigma"
//o //s "Sigma",      "gr_Sigma"
//o //s "tau",        "gr_tau"
//o //s "upsilon",    "gr_upsilon"
//o //s "phi",        "gr_phi"
//o //s "Phi",        "gr_Phi"
//o //s "varphi",     "gr_varphi"
//o //s "chi",        "gr_chi"
//o //s "psi",        "gr_psi"
//o //s "Psi",        "gr_Psi"
//o //s "omega",      "gr_omega"
//o //s "Omega",      "gr_Omega"

// Font commands

//s "bb",         "ft_bb"
//s "bbb",        "ft_bbb"
//s "cc",         "ft_cc"
//s "tt",         "ft_tt"
//s "fr",         "ft_fr"
//s "sf",         "ft_sf"

// Standard Functions

//o //s "sin",        "fun_sin"
//o //s "cos",        "fun_cos"
//o //s "tan",        "fun_tan"
//o //s "sec",        "fun_sec"
//o //s "csc",        "fun_csc"
//o //s "cot",        "fun_cot"
//o //s "arcsin",     "fun_arcsin"
//o //s "arccos",     "fun_arccos"
//o //s "arctan",     "fun_arctan"
//o //s "sinh",       "fun_sinh"
//o //s "cosh",       "fun_cosh"
//o //s "tanh",       "fun_tanh"
//o //s "sech",       "fun_sech"
//o //s "csch",       "fun_csch"
//o //s "coth",       "fun_coth"
//o //s "exp",        "fun_exp"
//o //s "log",        "fun_log"
//o //s "ln",         "fun_ln"
//o //s "det",        "fun_det"
//o //s "dim",        "fun_dim"
//o //s "mod",        "fun_mod"
//o //s "gcd",        "fun_gcd"
//o //s "lcm",        "fun_lcm"
//o //s "lub",        "fun_lub"
//o //s "glb",        "fun_glb"
//o //s "min",        "fun_min"
//o //s "max",        "fun_max"
//o //s "f",          "fun_f"
//o //s "g",          "fun_g"

// Other tokens

//s "",           "spe_number"
//s "",           "spe_ident"

namespace amath::tokens {

struct op_add                    : poacher::Token<op_add>                   {};
struct op_sub                    : poacher::Token<op_sub>                   {};
struct op_cdot                   : poacher::Token<op_cdot>                  {};
struct op_ast                    : poacher::Token<op_ast>                   {};
struct op_star                   : poacher::Token<op_star>                  {};
struct op_slash                  : poacher::Token<op_slash>                 {};
struct op_backslash              : poacher::Token<op_backslash>             {};
struct op_times                  : poacher::Token<op_times>                 {};
struct op_div                    : poacher::Token<op_div>                   {};
struct op_ltimes                 : poacher::Token<op_ltimes>                {};
struct op_rtimes                 : poacher::Token<op_rtimes>                {};
struct op_bowtie                 : poacher::Token<op_bowtie>                {};
struct op_circ                   : poacher::Token<op_circ>                  {};
struct op_oplus                  : poacher::Token<op_oplus>                 {};
struct op_otimes                 : poacher::Token<op_otimes>                {};
struct op_odot                   : poacher::Token<op_odot>                  {};
struct op_sum                    : poacher::Token<op_sum>                   {};
struct op_prod                   : poacher::Token<op_prod>                  {};
struct op_wedge                  : poacher::Token<op_wedge>                 {};
struct op_bidwedge               : poacher::Token<op_bidwedge>              {};
struct op_vee                    : poacher::Token<op_vee>                   {};
struct op_bigvee                 : poacher::Token<op_bigvee>                {};
struct op_cap                    : poacher::Token<op_cap>                   {};
struct op_bigcap                 : poacher::Token<op_bigcap>                {};
struct op_cup                    : poacher::Token<op_cup>                   {};
struct op_bigcup                 : poacher::Token<op_bigcup>                {};

struct misc_frac                 : poacher::Token<misc_frac>                {};
struct misc_exp                  : poacher::Token<misc_exp>                 {};
struct misc_sqrt                 : poacher::Token<misc_sqrt>                {};
struct misc_root                 : poacher::Token<misc_root>                {};
struct misc_int                  : poacher::Token<misc_int>                 {};
struct misc_oint                 : poacher::Token<misc_oint>                {};
struct misc_partial              : poacher::Token<misc_partial>             {};
struct misc_nabla                : poacher::Token<misc_nabla>               {};
struct misc_pm                   : poacher::Token<misc_pm>                  {};
struct misc_emptyset             : poacher::Token<misc_emptyset>            {};
struct misc_infty                : poacher::Token<misc_infty>               {};
struct misc_aleph                : poacher::Token<misc_aleph>               {};
struct misc_therefore            : poacher::Token<misc_therefore>           {};
struct misc_because              : poacher::Token<misc_because>             {};
struct misc_ldots                : poacher::Token<misc_ldots>               {};
struct misc_cdots                : poacher::Token<misc_cdots>               {};
struct misc_vdots                : poacher::Token<misc_vdots>               {};
struct misc_ddots                : poacher::Token<misc_ddots>               {};
struct misc_smallquad            : poacher::Token<misc_smallquad>           {};
struct misc_quad                 : poacher::Token<misc_quad>                {};
struct misc_angle                : poacher::Token<misc_angle>               {};
struct misc_frown                : poacher::Token<misc_frown>               {};
struct misc_triangle             : poacher::Token<misc_triangle>            {};
struct misc_diamond              : poacher::Token<misc_diamond>             {};
struct misc_square               : poacher::Token<misc_square>              {};
struct misc_lfloor               : poacher::Token<misc_lfloor>              {};
struct misc_rfloor               : poacher::Token<misc_rfloor>              {};
struct misc_lceiling             : poacher::Token<misc_lceiling>            {};
struct misc_rceiling             : poacher::Token<misc_rceiling>            {};
struct misc_C                    : poacher::Token<misc_C>                   {};
struct misc_N                    : poacher::Token<misc_N>                   {};
struct misc_Q                    : poacher::Token<misc_Q>                   {};
struct misc_R                    : poacher::Token<misc_R>                   {};
struct misc_Z                    : poacher::Token<misc_Z>                   {};

//o struct rel_eq                    : poacher::Token<rel_eq>                   {};
//o struct rel_ne                    : poacher::Token<rel_ne>                   {};
//o struct rel_lt                    : poacher::Token<rel_lt>                   {};
//o struct rel_gt                    : poacher::Token<rel_gt>                   {};
//o struct rel_le                    : poacher::Token<rel_le>                   {};
//o struct rel_ge                    : poacher::Token<rel_ge>                   {};
//o struct rel_prec                  : poacher::Token<rel_prec>                 {};
//o struct rel_preceq                : poacher::Token<rel_preceq>               {};
//o struct rel_succ                  : poacher::Token<rel_succ>                 {};
//o struct rel_succeq                : poacher::Token<rel_succeq>               {};
//o struct rel_in                    : poacher::Token<rel_in>                   {};
//o struct rel_notin                 : poacher::Token<rel_notin>                {};
//o struct rel_subset                : poacher::Token<rel_subset>               {};
//o struct rel_supset                : poacher::Token<rel_supset>               {};
//o struct rel_subseteq              : poacher::Token<rel_subseteq>             {};
//o struct rel_supseteq              : poacher::Token<rel_supseteq>             {};
//o struct rel_equiv                 : poacher::Token<rel_equiv>                {};
//o struct rel_cong                  : poacher::Token<rel_cong>                 {};
//o struct rel_approx                : poacher::Token<rel_approx>               {};
//o struct rel_propto                : poacher::Token<rel_propto>               {};

struct logic_and                 : poacher::Token<logic_and>                {};
struct logic_or                  : poacher::Token<logic_or>                 {};
struct logic_neg                 : poacher::Token<logic_neg>                {};
struct logic_implies             : poacher::Token<logic_implies>            {};
struct logic_if                  : poacher::Token<logic_if>                 {};
struct logic_iff                 : poacher::Token<logic_iff>                {};
struct logic_forall              : poacher::Token<logic_forall>             {};
struct logic_exists              : poacher::Token<logic_exists>             {};
struct logic_bot                 : poacher::Token<logic_bot>                {};
struct logic_top                 : poacher::Token<logic_top>                {};
struct logic_vdash               : poacher::Token<logic_vdash>              {};
struct logic_models              : poacher::Token<logic_models>             {};

struct grp_lpar                  : poacher::Token<grp_lpar>                 {};
struct grp_rpar                  : poacher::Token<grp_rpar>                 {};
struct grp_lsqbra                : poacher::Token<grp_lsqbra>               {};
struct grp_rsqbra                : poacher::Token<grp_rsqbra>               {};
struct grp_lcubra                : poacher::Token<grp_lcubra>               {};
struct grp_rcubra                : poacher::Token<grp_rcubra>               {};
struct grp_langle                : poacher::Token<grp_langle>               {};
struct grp_rangle                : poacher::Token<grp_rangle>               {};
struct grp_langle_               : poacher::Token<grp_langle_>              {};
struct grp_rangle_               : poacher::Token<grp_rangle_>              {};
struct grp_lxpar                 : poacher::Token<grp_lxpar>                {};
struct grp_rxpar                 : poacher::Token<grp_rxpar>                {};
struct grp_abs                   : poacher::Token<grp_abs>                  {};
struct grp_floor                 : poacher::Token<grp_floor>                {};
struct grp_ceil                  : poacher::Token<grp_ceil>                 {};
struct grp_norm                  : poacher::Token<grp_norm>                 {};

//o struct arr_uparrow               : poacher::Token<arr_uparrow>              {};
//o struct arr_downarrow             : poacher::Token<arr_downarrow>            {};
//o struct arr_rightarrow            : poacher::Token<arr_rightarrow>           {};
//o struct arr_to                    : poacher::Token<arr_to>                   {};
//o struct arr_rightarrowtail        : poacher::Token<arr_rightarrowtail>       {};
//o struct arr_twoheadrightarrow     : poacher::Token<arr_twoheadrightarrow>    {};
//o struct arr_twoheadrightarrowtail : poacher::Token<arr_twoheadrightarrowtail>{};
//o struct arr_mapsto                : poacher::Token<arr_mapsto>               {};
//o struct arr_leftarrow             : poacher::Token<arr_leftarrow>            {};
//o struct arr_leftrightarrow        : poacher::Token<arr_leftrightarrow>       {};
//o struct arr_Rightarrow            : poacher::Token<arr_Rightarrow>           {};
//o struct arr_Leftarrow             : poacher::Token<arr_Leftarrow>            {};
//o struct arr_Leftrightarrow        : poacher::Token<arr_Leftrightarrow>       {};

//o struct acc_hat                   : poacher::Token<acc_hat>                  {};
//o struct acc_bar                   : poacher::Token<acc_bar>                  {};
//o struct acc_ul                    : poacher::Token<acc_ul>                   {};
//o struct acc_vec                   : poacher::Token<acc_vec>                  {};
//o struct acc_dot                   : poacher::Token<acc_dot>                  {};
//o struct acc_ddot                  : poacher::Token<acc_ddot>                 {};
//o struct acc_overset               : poacher::Token<acc_overset>              {};
//o struct acc_underset              : poacher::Token<acc_underset>             {};
//o struct acc_ubrace                : poacher::Token<acc_ubrace>               {};
//o struct acc_obrace                : poacher::Token<acc_obrace>               {};
//o struct acc_color                 : poacher::Token<acc_color>                {};
//o struct acc_cancel                : poacher::Token<acc_cancel>               {};

//o struct gr_alpha                  : poacher::Token<gr_alpha>                 {};
//o struct gr_beta                   : poacher::Token<gr_beta>                  {};
//o struct gr_gamma                  : poacher::Token<gr_gamma>                 {};
//o struct gr_Gamma                  : poacher::Token<gr_Gamma>                 {};
//o struct gr_delta                  : poacher::Token<gr_delta>                 {};
//o struct gr_Delta                  : poacher::Token<gr_Delta>                 {};
//o struct gr_epsilon                : poacher::Token<gr_epsilon>               {};
//o struct gr_varepsilon             : poacher::Token<gr_varepsilon>            {};
//o struct gr_zeta                   : poacher::Token<gr_zeta>                  {};
//o struct gr_eta                    : poacher::Token<gr_eta>                   {};
//o struct gr_theta                  : poacher::Token<gr_theta>                 {};
//o struct gr_Theta                  : poacher::Token<gr_Theta>                 {};
//o struct gr_vartheta               : poacher::Token<gr_vartheta>              {};
//o struct gr_iota                   : poacher::Token<gr_iota>                  {};
//o struct gr_kappa                  : poacher::Token<gr_kappa>                 {};
//o struct gr_lambda                 : poacher::Token<gr_lambda>                {};
//o struct gr_Lambda                 : poacher::Token<gr_Lambda>                {};
//o struct gr_mu                     : poacher::Token<gr_mu>                    {};
//o struct gr_nu                     : poacher::Token<gr_nu>                    {};
//o struct gr_xi                     : poacher::Token<gr_xi>                    {};
//o struct gr_Xi                     : poacher::Token<gr_Xi>                    {};
//o struct gr_pi                     : poacher::Token<gr_pi>                    {};
//o struct gr_Pi                     : poacher::Token<gr_Pi>                    {};
//o struct gr_rho                    : poacher::Token<gr_rho>                   {};
//o struct gr_sigma                  : poacher::Token<gr_sigma>                 {};
//o struct gr_Sigma                  : poacher::Token<gr_Sigma>                 {};
//o struct gr_tau                    : poacher::Token<gr_tau>                   {};
//o struct gr_upsilon                : poacher::Token<gr_upsilon>               {};
//o struct gr_phi                    : poacher::Token<gr_phi>                   {};
//o struct gr_Phi                    : poacher::Token<gr_Phi>                   {};
//o struct gr_varphi                 : poacher::Token<gr_varphi>                {};
//o struct gr_chi                    : poacher::Token<gr_chi>                   {};
//o struct gr_psi                    : poacher::Token<gr_psi>                   {};
//o struct gr_Psi                    : poacher::Token<gr_Psi>                   {};
//o struct gr_omega                  : poacher::Token<gr_omega>                 {};
//o struct gr_Omega                  : poacher::Token<gr_Omega>                 {};

struct ft_bb                     : poacher::Token<ft_bb>                    {};
struct ft_bbb                    : poacher::Token<ft_bbb>                   {};
struct ft_cc                     : poacher::Token<ft_cc>                    {};
struct ft_tt                     : poacher::Token<ft_tt>                    {};
struct ft_fr                     : poacher::Token<ft_fr>                    {};
struct ft_sf                     : poacher::Token<ft_sf>                    {};

//o struct fun_sin                   : poacher::Token<fun_sin>                  {};
//o struct fun_cos                   : poacher::Token<fun_cos>                  {};
//o struct fun_tan                   : poacher::Token<fun_tan>                  {};
//o struct fun_sec                   : poacher::Token<fun_sec>                  {};
//o struct fun_csc                   : poacher::Token<fun_csc>                  {};
//o struct fun_cot                   : poacher::Token<fun_cot>                  {};
//o struct fun_arcsin                : poacher::Token<fun_arcsin>               {};
//o struct fun_arccos                : poacher::Token<fun_arccos>               {};
//o struct fun_arctan                : poacher::Token<fun_arctan>               {};
//o struct fun_sinh                  : poacher::Token<fun_sinh>                 {};
//o struct fun_cosh                  : poacher::Token<fun_cosh>                 {};
//o struct fun_tanh                  : poacher::Token<fun_tanh>                 {};
//o struct fun_sech                  : poacher::Token<fun_sech>                 {};
//o struct fun_csch                  : poacher::Token<fun_csch>                 {};
//o struct fun_coth                  : poacher::Token<fun_coth>                 {};
//o struct fun_exp                   : poacher::Token<fun_exp>                  {};
//o struct fun_log                   : poacher::Token<fun_log>                  {};
//o struct fun_ln                    : poacher::Token<fun_ln>                   {};
//o struct fun_det                   : poacher::Token<fun_det>                  {};
//o struct fun_dim                   : poacher::Token<fun_dim>                  {};
//o struct fun_mod                   : poacher::Token<fun_mod>                  {};
//o struct fun_gcd                   : poacher::Token<fun_gcd>                  {};
//o struct fun_lcm                   : poacher::Token<fun_lcm>                  {};
//o struct fun_lub                   : poacher::Token<fun_lub>                  {};
//o struct fun_glb                   : poacher::Token<fun_glb>                  {};
//o struct fun_min                   : poacher::Token<fun_min>                  {};
//o struct fun_max                   : poacher::Token<fun_max>                  {};
//o struct fun_f                     : poacher::Token<fun_f>                    {};
//o struct fun_g                     : poacher::Token<fun_g>                    {};

struct spe_number                : poacher::Token<spe_number>               {};
struct spe_ident                 : poacher::Token<spe_ident>                {};

}  // namespace amath::tokens

namespace amath {

constexpr auto get_sym_token( tokens::op_add )                    { return poacher::ct_string( "+" ); }
constexpr auto get_sym_token( tokens::op_sub )                    { return poacher::ct_string( "-" ); }
constexpr auto get_sym_token( tokens::op_cdot )                   { return poacher::ct_string( "*" ); }
constexpr auto get_sym_token( tokens::op_ast )                    { return poacher::ct_string( "**" ); }
constexpr auto get_sym_token( tokens::op_star )                   { return poacher::ct_string( "***" ); }
constexpr auto get_sym_token( tokens::op_slash )                  { return poacher::ct_string( "//" ); }
constexpr auto get_sym_token( tokens::op_backslash )              { return poacher::ct_string( "\\\\" ); }
constexpr auto get_sym_token( tokens::op_times )                  { return poacher::ct_string( "xx" ); }
constexpr auto get_sym_token( tokens::op_div )                    { return poacher::ct_string( "-:" ); }
constexpr auto get_sym_token( tokens::op_ltimes )                 { return poacher::ct_string( "|><" ); }
constexpr auto get_sym_token( tokens::op_rtimes )                 { return poacher::ct_string( "><|" ); }
constexpr auto get_sym_token( tokens::op_bowtie )                 { return poacher::ct_string( "|><|" ); }
constexpr auto get_sym_token( tokens::op_circ )                   { return poacher::ct_string( "@" ); }
constexpr auto get_sym_token( tokens::op_oplus )                  { return poacher::ct_string( "o+" ); }
constexpr auto get_sym_token( tokens::op_otimes )                 { return poacher::ct_string( "ox" ); }
constexpr auto get_sym_token( tokens::op_odot )                   { return poacher::ct_string( "o." ); }
constexpr auto get_sym_token( tokens::op_sum )                    { return poacher::ct_string( "sum" ); }
constexpr auto get_sym_token( tokens::op_prod )                   { return poacher::ct_string( "prod" ); }
constexpr auto get_sym_token( tokens::op_wedge )                  { return poacher::ct_string( "^^" ); }
constexpr auto get_sym_token( tokens::op_bidwedge )               { return poacher::ct_string( "^^^" ); }
constexpr auto get_sym_token( tokens::op_vee )                    { return poacher::ct_string( "vv" ); }
constexpr auto get_sym_token( tokens::op_bigvee )                 { return poacher::ct_string( "vvv" ); }
constexpr auto get_sym_token( tokens::op_cap )                    { return poacher::ct_string( "nn" ); }
constexpr auto get_sym_token( tokens::op_bigcap )                 { return poacher::ct_string( "nnn" ); }
constexpr auto get_sym_token( tokens::op_cup )                    { return poacher::ct_string( "uu" ); }
constexpr auto get_sym_token( tokens::op_bigcup )                 { return poacher::ct_string( "uuu" ); }

constexpr auto get_sym_token( tokens::misc_frac )                 { return poacher::ct_string( "/" ); }
constexpr auto get_sym_token( tokens::misc_exp )                  { return poacher::ct_string( "^" ); }
constexpr auto get_sym_token( tokens::misc_sqrt )                 { return poacher::ct_string( "sqrt" ); }
constexpr auto get_sym_token( tokens::misc_root )                 { return poacher::ct_string( "root" ); }
constexpr auto get_sym_token( tokens::misc_int )                  { return poacher::ct_string( "int" ); }
constexpr auto get_sym_token( tokens::misc_oint )                 { return poacher::ct_string( "oint" ); }
constexpr auto get_sym_token( tokens::misc_partial )              { return poacher::ct_string( "del" ); }
constexpr auto get_sym_token( tokens::misc_nabla )                { return poacher::ct_string( "grad" ); }
constexpr auto get_sym_token( tokens::misc_pm )                   { return poacher::ct_string( "+-" ); }
constexpr auto get_sym_token( tokens::misc_emptyset )             { return poacher::ct_string( "O/" ); }
constexpr auto get_sym_token( tokens::misc_infty )                { return poacher::ct_string( "oo" ); }
constexpr auto get_sym_token( tokens::misc_aleph )                { return poacher::ct_string( "aleph" ); }
constexpr auto get_sym_token( tokens::misc_therefore )            { return poacher::ct_string( ":." ); }
constexpr auto get_sym_token( tokens::misc_because )              { return poacher::ct_string( ":'" ); }
constexpr auto get_sym_token( tokens::misc_ldots )                { return poacher::ct_string( "|...|" ); }
constexpr auto get_sym_token( tokens::misc_cdots )                { return poacher::ct_string( "|cdots|" ); }
constexpr auto get_sym_token( tokens::misc_vdots )                { return poacher::ct_string( "vdots" ); }
constexpr auto get_sym_token( tokens::misc_ddots )                { return poacher::ct_string( "ddots" ); }
constexpr auto get_sym_token( tokens::misc_smallquad )            { return poacher::ct_string( "|\\ |" ); }
constexpr auto get_sym_token( tokens::misc_quad )                 { return poacher::ct_string( "|quad|" ); }
constexpr auto get_sym_token( tokens::misc_angle )                { return poacher::ct_string( "/_" ); }
constexpr auto get_sym_token( tokens::misc_frown )                { return poacher::ct_string( "frown" ); }
constexpr auto get_sym_token( tokens::misc_triangle )             { return poacher::ct_string( "/_\\" ); }
constexpr auto get_sym_token( tokens::misc_diamond )              { return poacher::ct_string( "diamond" ); }
constexpr auto get_sym_token( tokens::misc_square )               { return poacher::ct_string( "square" ); }
constexpr auto get_sym_token( tokens::misc_lfloor )               { return poacher::ct_string( "|__" ); }
constexpr auto get_sym_token( tokens::misc_rfloor )               { return poacher::ct_string( "__|" ); }
constexpr auto get_sym_token( tokens::misc_lceiling )             { return poacher::ct_string( "|~" ); }
constexpr auto get_sym_token( tokens::misc_rceiling )             { return poacher::ct_string( "~|" ); }
constexpr auto get_sym_token( tokens::misc_C )                    { return poacher::ct_string( "CC" ); }
constexpr auto get_sym_token( tokens::misc_N )                    { return poacher::ct_string( "NN" ); }
constexpr auto get_sym_token( tokens::misc_Q )                    { return poacher::ct_string( "QQ" ); }
constexpr auto get_sym_token( tokens::misc_R )                    { return poacher::ct_string( "RR" ); }
constexpr auto get_sym_token( tokens::misc_Z )                    { return poacher::ct_string( "ZZ" ); }

//o constexpr auto get_sym_token( tokens::rel_eq )                    { return poacher::ct_string( "=" ); }
//o constexpr auto get_sym_token( tokens::rel_ne )                    { return poacher::ct_string( "!=" ); }
//o constexpr auto get_sym_token( tokens::rel_lt )                    { return poacher::ct_string( "<" ); }
//o constexpr auto get_sym_token( tokens::rel_gt )                    { return poacher::ct_string( ">" ); }
//o constexpr auto get_sym_token( tokens::rel_le )                    { return poacher::ct_string( "<=" ); }
//o constexpr auto get_sym_token( tokens::rel_ge )                    { return poacher::ct_string( ">=" ); }
//o constexpr auto get_sym_token( tokens::rel_prec )                  { return poacher::ct_string( "-<" ); }
//o constexpr auto get_sym_token( tokens::rel_preceq )                { return poacher::ct_string( "-<=" ); }
//o constexpr auto get_sym_token( tokens::rel_succ )                  { return poacher::ct_string( ">-" ); }
//o constexpr auto get_sym_token( tokens::rel_succeq )                { return poacher::ct_string( ">-=" ); }
//o constexpr auto get_sym_token( tokens::rel_in )                    { return poacher::ct_string( "in" ); }
//o constexpr auto get_sym_token( tokens::rel_notin )                 { return poacher::ct_string( "!in" ); }
//o constexpr auto get_sym_token( tokens::rel_subset )                { return poacher::ct_string( "sub" ); }
//o constexpr auto get_sym_token( tokens::rel_supset )                { return poacher::ct_string( "sup" ); }
//o constexpr auto get_sym_token( tokens::rel_subseteq )              { return poacher::ct_string( "sube" ); }
//o constexpr auto get_sym_token( tokens::rel_supseteq )              { return poacher::ct_string( "supe" ); }
//o constexpr auto get_sym_token( tokens::rel_equiv )                 { return poacher::ct_string( "-=" ); }
//o constexpr auto get_sym_token( tokens::rel_cong )                  { return poacher::ct_string( "~=" ); }
//o constexpr auto get_sym_token( tokens::rel_approx )                { return poacher::ct_string( "~~" ); }
//o constexpr auto get_sym_token( tokens::rel_propto )                { return poacher::ct_string( "prop" ); }

constexpr auto get_sym_token( tokens::logic_and )                 { return poacher::ct_string( "and" ); }
constexpr auto get_sym_token( tokens::logic_or )                  { return poacher::ct_string( "or" ); }
constexpr auto get_sym_token( tokens::logic_neg )                 { return poacher::ct_string( "not" ); }
constexpr auto get_sym_token( tokens::logic_implies )             { return poacher::ct_string( "=>" ); }
constexpr auto get_sym_token( tokens::logic_if )                  { return poacher::ct_string( "if" ); }
constexpr auto get_sym_token( tokens::logic_iff )                 { return poacher::ct_string( "<=>" ); }
constexpr auto get_sym_token( tokens::logic_forall )              { return poacher::ct_string( "AA" ); }
constexpr auto get_sym_token( tokens::logic_exists )              { return poacher::ct_string( "EE" ); }
constexpr auto get_sym_token( tokens::logic_bot )                 { return poacher::ct_string( "_|_" ); }
constexpr auto get_sym_token( tokens::logic_top )                 { return poacher::ct_string( "TT" ); }
constexpr auto get_sym_token( tokens::logic_vdash )               { return poacher::ct_string( "|--" ); }
constexpr auto get_sym_token( tokens::logic_models )              { return poacher::ct_string( "|==" ); }

constexpr auto get_sym_token( tokens::grp_lpar )                  { return poacher::ct_string( "(" ); }
constexpr auto get_sym_token( tokens::grp_rpar )                  { return poacher::ct_string( ")" ); }
constexpr auto get_sym_token( tokens::grp_lsqbra )                { return poacher::ct_string( "[" ); }
constexpr auto get_sym_token( tokens::grp_rsqbra )                { return poacher::ct_string( "]" ); }
constexpr auto get_sym_token( tokens::grp_lcubra )                { return poacher::ct_string( "{" ); }
constexpr auto get_sym_token( tokens::grp_rcubra )                { return poacher::ct_string( "}" ); }
constexpr auto get_sym_token( tokens::grp_langle )                { return poacher::ct_string( "(:" ); }
constexpr auto get_sym_token( tokens::grp_rangle )                { return poacher::ct_string( ":)" ); }
constexpr auto get_sym_token( tokens::grp_langle_ )               { return poacher::ct_string( "<<" ); }
constexpr auto get_sym_token( tokens::grp_rangle_ )               { return poacher::ct_string( ">>" ); }
constexpr auto get_sym_token( tokens::grp_lxpar )                 { return poacher::ct_string( "{: x )" ); }
constexpr auto get_sym_token( tokens::grp_rxpar )                 { return poacher::ct_string( "( x :}" ); }
constexpr auto get_sym_token( tokens::grp_abs )                   { return poacher::ct_string( "abs" ); }
constexpr auto get_sym_token( tokens::grp_floor )                 { return poacher::ct_string( "floor" ); }
constexpr auto get_sym_token( tokens::grp_ceil )                  { return poacher::ct_string( "ceil" ); }
constexpr auto get_sym_token( tokens::grp_norm )                  { return poacher::ct_string( "norm" ); }

//o constexpr auto get_sym_token( tokens::arr_uparrow )               { return poacher::ct_string( "uarr" ); }
//o constexpr auto get_sym_token( tokens::arr_downarrow )             { return poacher::ct_string( "darr" ); }
//o constexpr auto get_sym_token( tokens::arr_rightarrow )            { return poacher::ct_string( "rarr" ); }
//o constexpr auto get_sym_token( tokens::arr_to )                    { return poacher::ct_string( "->" ); }
//o constexpr auto get_sym_token( tokens::arr_rightarrowtail )        { return poacher::ct_string( ">->" ); }
//o constexpr auto get_sym_token( tokens::arr_twoheadrightarrow )     { return poacher::ct_string( "->>" ); }
//o constexpr auto get_sym_token( tokens::arr_twoheadrightarrowtail ) { return poacher::ct_string( ">->>" ); }
//o constexpr auto get_sym_token( tokens::arr_mapsto )                { return poacher::ct_string( "|->" ); }
//o constexpr auto get_sym_token( tokens::arr_leftarrow )             { return poacher::ct_string( "larr" ); }
//o constexpr auto get_sym_token( tokens::arr_leftrightarrow )        { return poacher::ct_string( "harr" ); }
//o constexpr auto get_sym_token( tokens::arr_Rightarrow )            { return poacher::ct_string( "rArr" ); }
//o constexpr auto get_sym_token( tokens::arr_Leftarrow )             { return poacher::ct_string( "lArr" ); }
//o constexpr auto get_sym_token( tokens::arr_Leftrightarrow )        { return poacher::ct_string( "hArr" ); }

//o constexpr auto get_sym_token( tokens::acc_hat )                   { return poacher::ct_string( "hat" ); }
//o constexpr auto get_sym_token( tokens::acc_bar )                   { return poacher::ct_string( "bar" ); }
//o constexpr auto get_sym_token( tokens::acc_ul )                    { return poacher::ct_string( "ul" ); }
//o constexpr auto get_sym_token( tokens::acc_vec )                   { return poacher::ct_string( "vec" ); }
//o constexpr auto get_sym_token( tokens::acc_dot )                   { return poacher::ct_string( "dot" ); }
//o constexpr auto get_sym_token( tokens::acc_ddot )                  { return poacher::ct_string( "ddot" ); }
//o constexpr auto get_sym_token( tokens::acc_overset )               { return poacher::ct_string( "overset" ); }
//o constexpr auto get_sym_token( tokens::acc_underset )              { return poacher::ct_string( "underset" ); }
//o constexpr auto get_sym_token( tokens::acc_ubrace )                { return poacher::ct_string( "ubrace" ); }
//o constexpr auto get_sym_token( tokens::acc_obrace )                { return poacher::ct_string( "obrace" ); }
//o constexpr auto get_sym_token( tokens::acc_color )                 { return poacher::ct_string( "color" ); }
//o constexpr auto get_sym_token( tokens::acc_cancel )                { return poacher::ct_string( "cancel" ); }

//o constexpr auto get_sym_token( tokens::gr_alpha )                  { return poacher::ct_string( "alpha" ); }
//o constexpr auto get_sym_token( tokens::gr_beta )                   { return poacher::ct_string( "beta" ); }
//o constexpr auto get_sym_token( tokens::gr_gamma )                  { return poacher::ct_string( "gamma" ); }
//o constexpr auto get_sym_token( tokens::gr_Gamma )                  { return poacher::ct_string( "Gamma" ); }
//o constexpr auto get_sym_token( tokens::gr_delta )                  { return poacher::ct_string( "delta" ); }
//o constexpr auto get_sym_token( tokens::gr_Delta )                  { return poacher::ct_string( "Delta" ); }
//o constexpr auto get_sym_token( tokens::gr_epsilon )                { return poacher::ct_string( "epsilon" ); }
//o constexpr auto get_sym_token( tokens::gr_varepsilon )             { return poacher::ct_string( "varepsilon" ); }
//o constexpr auto get_sym_token( tokens::gr_zeta )                   { return poacher::ct_string( "zeta" ); }
//o constexpr auto get_sym_token( tokens::gr_eta )                    { return poacher::ct_string( "eta" ); }
//o constexpr auto get_sym_token( tokens::gr_theta )                  { return poacher::ct_string( "theta" ); }
//o constexpr auto get_sym_token( tokens::gr_Theta )                  { return poacher::ct_string( "Theta" ); }
//o constexpr auto get_sym_token( tokens::gr_vartheta )               { return poacher::ct_string( "vartheta" ); }
//o constexpr auto get_sym_token( tokens::gr_iota )                   { return poacher::ct_string( "iota" ); }
//o constexpr auto get_sym_token( tokens::gr_kappa )                  { return poacher::ct_string( "kappa" ); }
//o constexpr auto get_sym_token( tokens::gr_lambda )                 { return poacher::ct_string( "lambda" ); }
//o constexpr auto get_sym_token( tokens::gr_Lambda )                 { return poacher::ct_string( "Lambda" ); }
//o constexpr auto get_sym_token( tokens::gr_mu )                     { return poacher::ct_string( "mu" ); }
//o constexpr auto get_sym_token( tokens::gr_nu )                     { return poacher::ct_string( "nu" ); }
//o constexpr auto get_sym_token( tokens::gr_xi )                     { return poacher::ct_string( "xi" ); }
//o constexpr auto get_sym_token( tokens::gr_Xi )                     { return poacher::ct_string( "Xi" ); }
//o constexpr auto get_sym_token( tokens::gr_pi )                     { return poacher::ct_string( "pi" ); }
//o constexpr auto get_sym_token( tokens::gr_Pi )                     { return poacher::ct_string( "Pi" ); }
//o constexpr auto get_sym_token( tokens::gr_rho )                    { return poacher::ct_string( "rho" ); }
//o constexpr auto get_sym_token( tokens::gr_sigma )                  { return poacher::ct_string( "sigma" ); }
//o constexpr auto get_sym_token( tokens::gr_Sigma )                  { return poacher::ct_string( "Sigma" ); }
//o constexpr auto get_sym_token( tokens::gr_tau )                    { return poacher::ct_string( "tau" ); }
//o constexpr auto get_sym_token( tokens::gr_upsilon )                { return poacher::ct_string( "upsilon" ); }
//o constexpr auto get_sym_token( tokens::gr_phi )                    { return poacher::ct_string( "phi" ); }
//o constexpr auto get_sym_token( tokens::gr_Phi )                    { return poacher::ct_string( "Phi" ); }
//o constexpr auto get_sym_token( tokens::gr_varphi )                 { return poacher::ct_string( "varphi" ); }
//o constexpr auto get_sym_token( tokens::gr_chi )                    { return poacher::ct_string( "chi" ); }
//o constexpr auto get_sym_token( tokens::gr_psi )                    { return poacher::ct_string( "psi" ); }
//o constexpr auto get_sym_token( tokens::gr_Psi )                    { return poacher::ct_string( "Psi" ); }
//o constexpr auto get_sym_token( tokens::gr_omega )                  { return poacher::ct_string( "omega" ); }
//o constexpr auto get_sym_token( tokens::gr_Omega )                  { return poacher::ct_string( "Omega" ); }

constexpr auto get_sym_token( tokens::ft_bb )                     { return poacher::ct_string( "bb" ); }
constexpr auto get_sym_token( tokens::ft_bbb )                    { return poacher::ct_string( "bbb" ); }
constexpr auto get_sym_token( tokens::ft_cc )                     { return poacher::ct_string( "cc" ); }
constexpr auto get_sym_token( tokens::ft_tt )                     { return poacher::ct_string( "tt" ); }
constexpr auto get_sym_token( tokens::ft_fr )                     { return poacher::ct_string( "fr" ); }
constexpr auto get_sym_token( tokens::ft_sf )                     { return poacher::ct_string( "sf" ); }

//o constexpr auto get_sym_token( tokens::fun_sin )                   { return poacher::ct_string( "sin" ); }
//o constexpr auto get_sym_token( tokens::fun_cos )                   { return poacher::ct_string( "cos" ); }
//o constexpr auto get_sym_token( tokens::fun_tan )                   { return poacher::ct_string( "tan" ); }
//o constexpr auto get_sym_token( tokens::fun_sec )                   { return poacher::ct_string( "sec" ); }
//o constexpr auto get_sym_token( tokens::fun_csc )                   { return poacher::ct_string( "csc" ); }
//o constexpr auto get_sym_token( tokens::fun_cot )                   { return poacher::ct_string( "cot" ); }
//o constexpr auto get_sym_token( tokens::fun_arcsin )                { return poacher::ct_string( "arcsin" ); }
//o constexpr auto get_sym_token( tokens::fun_arccos )                { return poacher::ct_string( "arccos" ); }
//o constexpr auto get_sym_token( tokens::fun_arctan )                { return poacher::ct_string( "arctan" ); }
//o constexpr auto get_sym_token( tokens::fun_sinh )                  { return poacher::ct_string( "sinh" ); }
//o constexpr auto get_sym_token( tokens::fun_cosh )                  { return poacher::ct_string( "cosh" ); }
//o constexpr auto get_sym_token( tokens::fun_tanh )                  { return poacher::ct_string( "tanh" ); }
//o constexpr auto get_sym_token( tokens::fun_sech )                  { return poacher::ct_string( "sech" ); }
//o constexpr auto get_sym_token( tokens::fun_csch )                  { return poacher::ct_string( "csch" ); }
//o constexpr auto get_sym_token( tokens::fun_coth )                  { return poacher::ct_string( "coth" ); }
//o constexpr auto get_sym_token( tokens::fun_exp )                   { return poacher::ct_string( "exp" ); }
//o constexpr auto get_sym_token( tokens::fun_log )                   { return poacher::ct_string( "log" ); }
//o constexpr auto get_sym_token( tokens::fun_ln )                    { return poacher::ct_string( "ln" ); }
//o constexpr auto get_sym_token( tokens::fun_det )                   { return poacher::ct_string( "det" ); }
//o constexpr auto get_sym_token( tokens::fun_dim )                   { return poacher::ct_string( "dim" ); }
//o constexpr auto get_sym_token( tokens::fun_mod )                   { return poacher::ct_string( "mod" ); }
//o constexpr auto get_sym_token( tokens::fun_gcd )                   { return poacher::ct_string( "gcd" ); }
//o constexpr auto get_sym_token( tokens::fun_lcm )                   { return poacher::ct_string( "lcm" ); }
//o constexpr auto get_sym_token( tokens::fun_lub )                   { return poacher::ct_string( "lub" ); }
//o constexpr auto get_sym_token( tokens::fun_glb )                   { return poacher::ct_string( "glb" ); }
//o constexpr auto get_sym_token( tokens::fun_min )                   { return poacher::ct_string( "min" ); }
//o constexpr auto get_sym_token( tokens::fun_max )                   { return poacher::ct_string( "max" ); }
//o constexpr auto get_sym_token( tokens::fun_f )                     { return poacher::ct_string( "f" ); }
//o constexpr auto get_sym_token( tokens::fun_g )                     { return poacher::ct_string( "g" ); }

constexpr auto get_sym_token( tokens::spe_number )                { return poacher::ct_string( "." ); }
constexpr auto get_sym_token( tokens::spe_ident )                 { return poacher::ct_string( "." ); }

}

namespace amath {

using token_type_list = poacher::token_type_list

   < tokens::op_add
   , tokens::op_sub
   , tokens::op_cdot
   , tokens::op_ast
   , tokens::op_star
   , tokens::op_slash
   , tokens::op_backslash
   , tokens::op_times
   , tokens::op_div
   , tokens::op_ltimes
   , tokens::op_rtimes
   , tokens::op_bowtie
   , tokens::op_circ
   , tokens::op_oplus
   , tokens::op_otimes
   , tokens::op_odot
   , tokens::op_sum
   , tokens::op_prod
   , tokens::op_wedge
   , tokens::op_bidwedge
   , tokens::op_vee
   , tokens::op_bigvee
   , tokens::op_cap
   , tokens::op_bigcap
   , tokens::op_cup
   , tokens::op_bigcup

   , tokens::misc_frac
   , tokens::misc_exp
   , tokens::misc_sqrt
   , tokens::misc_root
   , tokens::misc_int
   , tokens::misc_oint
   , tokens::misc_partial
   , tokens::misc_nabla
   , tokens::misc_pm
   , tokens::misc_emptyset
   , tokens::misc_infty
   , tokens::misc_aleph
   , tokens::misc_therefore
   , tokens::misc_because
   , tokens::misc_ldots
   , tokens::misc_cdots
   , tokens::misc_vdots
   , tokens::misc_ddots
   , tokens::misc_smallquad
   , tokens::misc_quad
   , tokens::misc_angle
   , tokens::misc_frown
   , tokens::misc_triangle
   , tokens::misc_diamond
   , tokens::misc_square
   , tokens::misc_lfloor
   , tokens::misc_rfloor
   , tokens::misc_lceiling
   , tokens::misc_rceiling
   , tokens::misc_C
   , tokens::misc_N
   , tokens::misc_Q
   , tokens::misc_R
   , tokens::misc_Z

   //o , tokens::rel_eq
   //o , tokens::rel_ne
   //o , tokens::rel_lt
   //o , tokens::rel_gt
   //o , tokens::rel_le
   //o , tokens::rel_ge
   //o , tokens::rel_prec
   //o , tokens::rel_preceq
   //o , tokens::rel_succ
   //o , tokens::rel_succeq
   //o , tokens::rel_in
   //o , tokens::rel_notin
   //o , tokens::rel_subset
   //o , tokens::rel_supset
   //o , tokens::rel_subseteq
   //o , tokens::rel_supseteq
   //o , tokens::rel_equiv
   //o , tokens::rel_cong
   //o , tokens::rel_approx
   //o , tokens::rel_propto

   , tokens::logic_and
   , tokens::logic_or
   , tokens::logic_neg
   , tokens::logic_implies
   , tokens::logic_if
   , tokens::logic_iff
   , tokens::logic_forall
   , tokens::logic_exists
   , tokens::logic_bot
   , tokens::logic_top
   , tokens::logic_vdash
   , tokens::logic_models

   , tokens::grp_lpar
   , tokens::grp_rpar
   , tokens::grp_lsqbra
   , tokens::grp_rsqbra
   , tokens::grp_lcubra
   , tokens::grp_rcubra
   , tokens::grp_langle
   , tokens::grp_rangle
   , tokens::grp_langle_
   , tokens::grp_rangle_
   , tokens::grp_lxpar
   , tokens::grp_rxpar
   , tokens::grp_abs
   , tokens::grp_floor
   , tokens::grp_ceil
   , tokens::grp_norm

   //o , tokens::arr_uparrow
   //o , tokens::arr_downarrow
   //o , tokens::arr_rightarrow
   //o , tokens::arr_to
   //o , tokens::arr_rightarrowtail
   //o , tokens::arr_twoheadrightarrow
   //o , tokens::arr_twoheadrightarrowtail
   //o , tokens::arr_mapsto
   //o , tokens::arr_leftarrow
   //o , tokens::arr_leftrightarrow
   //o , tokens::arr_Rightarrow
   //o , tokens::arr_Leftarrow
   //o , tokens::arr_Leftrightarrow

   //o , tokens::acc_hat
   //o , tokens::acc_bar
   //o , tokens::acc_ul
   //o , tokens::acc_vec
   //o , tokens::acc_dot
   //o , tokens::acc_ddot
   //o , tokens::acc_overset
   //o , tokens::acc_underset
   //o , tokens::acc_ubrace
   //o , tokens::acc_obrace
   //o , tokens::acc_color
   //o , tokens::acc_cancel

   //o , tokens::gr_alpha
   //o , tokens::gr_beta
   //o , tokens::gr_gamma
   //o , tokens::gr_Gamma
   //o , tokens::gr_delta
   //o , tokens::gr_Delta
   //o , tokens::gr_epsilon
   //o , tokens::gr_varepsilon
   //o , tokens::gr_zeta
   //o , tokens::gr_eta
   //o , tokens::gr_theta
   //o , tokens::gr_Theta
   //o , tokens::gr_vartheta
   //o , tokens::gr_iota
   //o , tokens::gr_kappa
   //o , tokens::gr_lambda
   //o , tokens::gr_Lambda
   //o , tokens::gr_mu
   //o , tokens::gr_nu
   //o , tokens::gr_xi
   //o , tokens::gr_Xi
   //o , tokens::gr_pi
   //o , tokens::gr_Pi
   //o , tokens::gr_rho
   //o , tokens::gr_sigma
   //o , tokens::gr_Sigma
   //o , tokens::gr_tau
   //o , tokens::gr_upsilon
   //o , tokens::gr_phi
   //o , tokens::gr_Phi
   //o , tokens::gr_varphi
   //o , tokens::gr_chi
   //o , tokens::gr_psi
   //o , tokens::gr_Psi
   //o , tokens::gr_omega
   //o , tokens::gr_Omega

   , tokens::ft_bb
   , tokens::ft_bbb
   , tokens::ft_cc
   , tokens::ft_tt
   , tokens::ft_fr
   , tokens::ft_sf

   //o , tokens::fun_sin
   //o , tokens::fun_cos
   //o , tokens::fun_tan
   //o , tokens::fun_sec
   //o , tokens::fun_csc
   //o , tokens::fun_cot
   //o , tokens::fun_arcsin
   //o , tokens::fun_arccos
   //o , tokens::fun_arctan
   //o , tokens::fun_sinh
   //o , tokens::fun_cosh
   //o , tokens::fun_tanh
   //o , tokens::fun_sech
   //o , tokens::fun_csch
   //o , tokens::fun_coth
   //o , tokens::fun_exp
   //o , tokens::fun_log
   //o , tokens::fun_ln
   //o , tokens::fun_det
   //o , tokens::fun_dim
   //o , tokens::fun_mod
   //o , tokens::fun_gcd
   //o , tokens::fun_lcm
   //o , tokens::fun_lub
   //o , tokens::fun_glb
   //o , tokens::fun_min
   //o , tokens::fun_max
   //o , tokens::fun_f
   //o , tokens::fun_g

   , tokens::spe_number
   , tokens::spe_ident
   >;

}
