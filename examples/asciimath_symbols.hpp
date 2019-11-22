#pragma once

#include <poacher/tokenizer/token.hpp>

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

//s "=",          "rel_eq"
//s "!=",         "rel_ne"
//s "<",          "rel_lt"
//s ">",          "rel_gt"
//s "<=",         "rel_le"
//s ">=",         "rel_ge"
//s "-<",         "rel_prec"
//s "-<=",        "rel_preceq"
//s ">-",         "rel_succ"
//s ">-=",        "rel_succeq"
//s "in",         "rel_in"
//s "!in",        "rel_notin"
//s "sub",        "rel_subset"
//s "sup",        "rel_supset"
//s "sube",       "rel_subseteq"
//s "supe",       "rel_supseteq"
//s "-=",         "rel_equiv"
//s "~=",         "rel_cong"
//s "~~",         "rel_approx"
//s "prop",       "rel_propto"

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

//s "uarr",       "arr_uparrow"
//s "darr",       "arr_downarrow"
//s "rarr",       "arr_rightarrow"
//s "->",         "arr_to"
//s ">->",        "arr_rightarrowtail"
//s "->>",        "arr_twoheadrightarrow"
//s ">->>",       "arr_twoheadrightarrowtail"
//s "|->",        "arr_mapsto"
//s "larr",       "arr_leftarrow"
//s "harr",       "arr_leftrightarrow"
//s "rArr",       "arr_Rightarrow"
//s "lArr",       "arr_Leftarrow"
//s "hArr",       "arr_Leftrightarrow"

// Accents

//s "hat",        "acc_hat"
//s "bar",        "acc_bar"
//s "ul",         "acc_ul"
//s "vec",        "acc_vec"
//s "dot",        "acc_dot"
//s "ddot",       "acc_ddot"
//s "overset",    "acc_overset"
//s "underset",   "acc_underset"
//s "ubrace",     "acc_ubrace"
//s "obrace",     "acc_obrace"
//s "color",      "acc_color"
//s "cancel",     "acc_cancel"

// Greek Letters

//s "alpha",      "gr_alpha"
//s "beta",       "gr_beta"
//s "gamma",      "gr_gamma"
//s "Gamma",      "gr_Gamma"
//s "delta",      "gr_delta"
//s "Delta",      "gr_Delta"
//s "epsilon",    "gr_epsilon"
//s "varepsilon", "gr_varepsilon"
//s "zeta",       "gr_zeta"
//s "eta",        "gr_eta"
//s "theta",      "gr_theta"
//s "Theta",      "gr_Theta"
//s "vartheta",   "gr_vartheta"
//s "iota",       "gr_iota"
//s "kappa",      "gr_kappa"
//s "lambda",     "gr_lambda"
//s "Lambda",     "gr_Lambda"
//s "mu",         "gr_mu"
//s "nu",         "gr_nu"
//s "xi",         "gr_xi"
//s "Xi",         "gr_Xi"
//s "pi",         "gr_pi"
//s "Pi",         "gr_Pi"
//s "rho",        "gr_rho"
//s "sigma",      "gr_sigma"
//s "Sigma",      "gr_Sigma"
//s "tau",        "gr_tau"
//s "upsilon",    "gr_upsilon"
//s "phi",        "gr_phi"
//s "Phi",        "gr_Phi"
//s "varphi",     "gr_varphi"
//s "chi",        "gr_chi"
//s "psi",        "gr_psi"
//s "Psi",        "gr_Psi"
//s "omega",      "gr_omega"
//s "Omega",      "gr_Omega"

// Font commands

//s "bb",         "ft_bb"
//s "bbb",        "ft_bbb"
//s "cc",         "ft_cc"
//s "tt",         "ft_tt"
//s "fr",         "ft_fr"
//s "sf",         "ft_sf"

// Standard Functions

//s "sin",        "fun_sin"
//s "cos",        "fun_cos"
//s "tan",        "fun_tan"
//s "sec",        "fun_sec"
//s "csc",        "fun_csc"
//s "cot",        "fun_cot"
//s "arcsin",     "fun_arcsin"
//s "arccos",     "fun_arccos"
//s "arctan",     "fun_arctan"
//s "sinh",       "fun_sinh"
//s "cosh",       "fun_cosh"
//s "tanh",       "fun_tanh"
//s "sech",       "fun_sech"
//s "csch",       "fun_csch"
//s "coth",       "fun_coth"
//s "exp",        "fun_exp"
//s "log",        "fun_log"
//s "ln",         "fun_ln"
//s "det",        "fun_det"
//s "dim",        "fun_dim"
//s "mod",        "fun_mod"
//s "gcd",        "fun_gcd"
//s "lcm",        "fun_lcm"
//s "lub",        "fun_lub"
//s "glb",        "fun_glb"
//s "min",        "fun_min"
//s "max",        "fun_max"
//s "f",          "fun_f"
//s "g",          "fun_g"

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
struct rel_eq                    : poacher::Token<rel_eq>                   {};
struct rel_ne                    : poacher::Token<rel_ne>                   {};
struct rel_lt                    : poacher::Token<rel_lt>                   {};
struct rel_gt                    : poacher::Token<rel_gt>                   {};
struct rel_le                    : poacher::Token<rel_le>                   {};
struct rel_ge                    : poacher::Token<rel_ge>                   {};
struct rel_prec                  : poacher::Token<rel_prec>                 {};
struct rel_preceq                : poacher::Token<rel_preceq>               {};
struct rel_succ                  : poacher::Token<rel_succ>                 {};
struct rel_succeq                : poacher::Token<rel_succeq>               {};
struct rel_in                    : poacher::Token<rel_in>                   {};
struct rel_notin                 : poacher::Token<rel_notin>                {};
struct rel_subset                : poacher::Token<rel_subset>               {};
struct rel_supset                : poacher::Token<rel_supset>               {};
struct rel_subseteq              : poacher::Token<rel_subseteq>             {};
struct rel_supseteq              : poacher::Token<rel_supseteq>             {};
struct rel_equiv                 : poacher::Token<rel_equiv>                {};
struct rel_cong                  : poacher::Token<rel_cong>                 {};
struct rel_approx                : poacher::Token<rel_approx>               {};
struct rel_propto                : poacher::Token<rel_propto>               {};
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
struct arr_uparrow               : poacher::Token<arr_uparrow>              {};
struct arr_downarrow             : poacher::Token<arr_downarrow>            {};
struct arr_rightarrow            : poacher::Token<arr_rightarrow>           {};
struct arr_to                    : poacher::Token<arr_to>                   {};
struct arr_rightarrowtail        : poacher::Token<arr_rightarrowtail>       {};
struct arr_twoheadrightarrow     : poacher::Token<arr_twoheadrightarrow>    {};
struct arr_twoheadrightarrowtail : poacher::Token<arr_twoheadrightarrowtail>{};
struct arr_mapsto                : poacher::Token<arr_mapsto>               {};
struct arr_leftarrow             : poacher::Token<arr_leftarrow>            {};
struct arr_leftrightarrow        : poacher::Token<arr_leftrightarrow>       {};
struct arr_Rightarrow            : poacher::Token<arr_Rightarrow>           {};
struct arr_Leftarrow             : poacher::Token<arr_Leftarrow>            {};
struct arr_Leftrightarrow        : poacher::Token<arr_Leftrightarrow>       {};
struct acc_hat                   : poacher::Token<acc_hat>                  {};
struct acc_bar                   : poacher::Token<acc_bar>                  {};
struct acc_ul                    : poacher::Token<acc_ul>                   {};
struct acc_vec                   : poacher::Token<acc_vec>                  {};
struct acc_dot                   : poacher::Token<acc_dot>                  {};
struct acc_ddot                  : poacher::Token<acc_ddot>                 {};
struct acc_overset               : poacher::Token<acc_overset>              {};
struct acc_underset              : poacher::Token<acc_underset>             {};
struct acc_ubrace                : poacher::Token<acc_ubrace>               {};
struct acc_obrace                : poacher::Token<acc_obrace>               {};
struct acc_color                 : poacher::Token<acc_color>                {};
struct acc_cancel                : poacher::Token<acc_cancel>               {};
struct gr_alpha                  : poacher::Token<gr_alpha>                 {};
struct gr_beta                   : poacher::Token<gr_beta>                  {};
struct gr_gamma                  : poacher::Token<gr_gamma>                 {};
struct gr_Gamma                  : poacher::Token<gr_Gamma>                 {};
struct gr_delta                  : poacher::Token<gr_delta>                 {};
struct gr_Delta                  : poacher::Token<gr_Delta>                 {};
struct gr_epsilon                : poacher::Token<gr_epsilon>               {};
struct gr_varepsilon             : poacher::Token<gr_varepsilon>            {};
struct gr_zeta                   : poacher::Token<gr_zeta>                  {};
struct gr_eta                    : poacher::Token<gr_eta>                   {};
struct gr_theta                  : poacher::Token<gr_theta>                 {};
struct gr_Theta                  : poacher::Token<gr_Theta>                 {};
struct gr_vartheta               : poacher::Token<gr_vartheta>              {};
struct gr_iota                   : poacher::Token<gr_iota>                  {};
struct gr_kappa                  : poacher::Token<gr_kappa>                 {};
struct gr_lambda                 : poacher::Token<gr_lambda>                {};
struct gr_Lambda                 : poacher::Token<gr_Lambda>                {};
struct gr_mu                     : poacher::Token<gr_mu>                    {};
struct gr_nu                     : poacher::Token<gr_nu>                    {};
struct gr_xi                     : poacher::Token<gr_xi>                    {};
struct gr_Xi                     : poacher::Token<gr_Xi>                    {};
struct gr_pi                     : poacher::Token<gr_pi>                    {};
struct gr_Pi                     : poacher::Token<gr_Pi>                    {};
struct gr_rho                    : poacher::Token<gr_rho>                   {};
struct gr_sigma                  : poacher::Token<gr_sigma>                 {};
struct gr_Sigma                  : poacher::Token<gr_Sigma>                 {};
struct gr_tau                    : poacher::Token<gr_tau>                   {};
struct gr_upsilon                : poacher::Token<gr_upsilon>               {};
struct gr_phi                    : poacher::Token<gr_phi>                   {};
struct gr_Phi                    : poacher::Token<gr_Phi>                   {};
struct gr_varphi                 : poacher::Token<gr_varphi>                {};
struct gr_chi                    : poacher::Token<gr_chi>                   {};
struct gr_psi                    : poacher::Token<gr_psi>                   {};
struct gr_Psi                    : poacher::Token<gr_Psi>                   {};
struct gr_omega                  : poacher::Token<gr_omega>                 {};
struct gr_Omega                  : poacher::Token<gr_Omega>                 {};
struct ft_bb                     : poacher::Token<ft_bb>                    {};
struct ft_bbb                    : poacher::Token<ft_bbb>                   {};
struct ft_cc                     : poacher::Token<ft_cc>                    {};
struct ft_tt                     : poacher::Token<ft_tt>                    {};
struct ft_fr                     : poacher::Token<ft_fr>                    {};
struct ft_sf                     : poacher::Token<ft_sf>                    {};
struct fun_sin                   : poacher::Token<fun_sin>                  {};
struct fun_cos                   : poacher::Token<fun_cos>                  {};
struct fun_tan                   : poacher::Token<fun_tan>                  {};
struct fun_sec                   : poacher::Token<fun_sec>                  {};
struct fun_csc                   : poacher::Token<fun_csc>                  {};
struct fun_cot                   : poacher::Token<fun_cot>                  {};
struct fun_arcsin                : poacher::Token<fun_arcsin>               {};
struct fun_arccos                : poacher::Token<fun_arccos>               {};
struct fun_arctan                : poacher::Token<fun_arctan>               {};
struct fun_sinh                  : poacher::Token<fun_sinh>                 {};
struct fun_cosh                  : poacher::Token<fun_cosh>                 {};
struct fun_tanh                  : poacher::Token<fun_tanh>                 {};
struct fun_sech                  : poacher::Token<fun_sech>                 {};
struct fun_csch                  : poacher::Token<fun_csch>                 {};
struct fun_coth                  : poacher::Token<fun_coth>                 {};
struct fun_exp                   : poacher::Token<fun_exp>                  {};
struct fun_log                   : poacher::Token<fun_log>                  {};
struct fun_ln                    : poacher::Token<fun_ln>                   {};
struct fun_det                   : poacher::Token<fun_det>                  {};
struct fun_dim                   : poacher::Token<fun_dim>                  {};
struct fun_mod                   : poacher::Token<fun_mod>                  {};
struct fun_gcd                   : poacher::Token<fun_gcd>                  {};
struct fun_lcm                   : poacher::Token<fun_lcm>                  {};
struct fun_lub                   : poacher::Token<fun_lub>                  {};
struct fun_glb                   : poacher::Token<fun_glb>                  {};
struct fun_min                   : poacher::Token<fun_min>                  {};
struct fun_max                   : poacher::Token<fun_max>                  {};
struct fun_f                     : poacher::Token<fun_f>                    {};
struct fun_g                     : poacher::Token<fun_g>                    {};

}  // namespace amath::tokens
