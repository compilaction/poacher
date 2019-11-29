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

// Other tokens

//s "",           "spe_number"
//s "",           "spe_ident"

namespace amath::tokens {

namespace op {
struct add_       : poacher::Token<add_>        {};
struct sub_       : poacher::Token<sub_>        {};
struct cdot_      : poacher::Token<cdot_>       {};
struct ast_       : poacher::Token<ast_>        {};
struct star_      : poacher::Token<star_>       {};
struct slash_     : poacher::Token<slash_>      {};
struct backslash_ : poacher::Token<backslash_>  {};
struct times_     : poacher::Token<times_>      {};
struct div_       : poacher::Token<div_>        {};
struct ltimes_    : poacher::Token<ltimes_>     {};
struct rtimes_    : poacher::Token<rtimes_>     {};
struct bowtie_    : poacher::Token<bowtie_>     {};
struct circ_      : poacher::Token<circ_>       {};
struct oplus_     : poacher::Token<oplus_>      {};
struct otimes_    : poacher::Token<otimes_>     {};
struct odot_      : poacher::Token<odot_>       {};
struct sum_       : poacher::Token<sum_>        {};
struct prod_      : poacher::Token<prod_>       {};
struct wedge_     : poacher::Token<wedge_>      {};
struct bidwedge_  : poacher::Token<bidwedge_>   {};
struct vee_       : poacher::Token<vee_>        {};
struct bigvee_    : poacher::Token<bigvee_>     {};
struct cap_       : poacher::Token<cap_>        {};
struct bigcap_    : poacher::Token<bigcap_>     {};
struct cup_       : poacher::Token<cup_>        {};
struct bigcup_    : poacher::Token<bigcup_>     {};
}

namespace misc {
struct frac_      : poacher::Token<frac_>       {};
struct exp_       : poacher::Token<exp_>        {};
struct sqrt_      : poacher::Token<sqrt_>       {};
struct root_      : poacher::Token<root_>       {};
struct int_       : poacher::Token<int_>        {};
struct oint_      : poacher::Token<oint_>       {};
struct partial_   : poacher::Token<partial_>    {};
struct nabla_     : poacher::Token<nabla_>      {};
struct pm_        : poacher::Token<pm_>         {};
struct emptyset_  : poacher::Token<emptyset_>   {};
struct infty_     : poacher::Token<infty_>      {};
struct aleph_     : poacher::Token<aleph_>      {};
struct therefore_ : poacher::Token<therefore_>  {};
struct because_   : poacher::Token<because_>    {};
struct ldots_     : poacher::Token<ldots_>      {};
struct cdots_     : poacher::Token<cdots_>      {};
struct vdots_     : poacher::Token<vdots_>      {};
struct ddots_     : poacher::Token<ddots_>      {};
struct smallquad_ : poacher::Token<smallquad_>  {};
struct quad_      : poacher::Token<quad_>       {};
struct angle_     : poacher::Token<angle_>      {};
struct frown_     : poacher::Token<frown_>      {};
struct triangle_  : poacher::Token<triangle_>   {};
struct diamond_   : poacher::Token<diamond_>    {};
struct square_    : poacher::Token<square_>     {};
struct lfloor_    : poacher::Token<lfloor_>     {};
struct rfloor_    : poacher::Token<rfloor_>     {};
struct lceiling_  : poacher::Token<lceiling_>   {};
struct rceiling_  : poacher::Token<rceiling_>   {};
struct C_         : poacher::Token<C_>          {};
struct N_         : poacher::Token<N_>          {};
struct Q_         : poacher::Token<Q_>          {};
struct R_         : poacher::Token<R_>          {};
struct Z_         : poacher::Token<Z_>          {};
}

namespace rel {
struct eq_        : poacher::Token<eq_>         {};
struct ne_        : poacher::Token<ne_>         {};
struct lt_        : poacher::Token<lt_>         {};
struct gt_        : poacher::Token<gt_>         {};
struct le_        : poacher::Token<le_>         {};
struct ge_        : poacher::Token<ge_>         {};
struct prec_      : poacher::Token<prec_>       {};
struct preceq_    : poacher::Token<preceq_>     {};
struct succ_      : poacher::Token<succ_>       {};
struct succeq_    : poacher::Token<succeq_>     {};
struct in_        : poacher::Token<in_>         {};
struct notin_     : poacher::Token<notin_>      {};
struct subset_    : poacher::Token<subset_>     {};
struct supset_    : poacher::Token<supset_>     {};
struct subseteq_  : poacher::Token<subseteq_>   {};
struct supseteq_  : poacher::Token<supseteq_>   {};
struct equiv_     : poacher::Token<equiv_>      {};
struct cong_      : poacher::Token<cong_>       {};
struct approx_    : poacher::Token<approx_>     {};
struct propto_    : poacher::Token<propto_>     {};
}

namespace logic {
struct and_       : poacher::Token<and_>     {};
struct or_        : poacher::Token<or_>      {};
struct neg_       : poacher::Token<neg_>     {};
struct implies_   : poacher::Token<implies_> {};
struct if_        : poacher::Token<if_>      {};
struct iff_       : poacher::Token<iff_>     {};
struct forall_    : poacher::Token<forall_>  {};
struct exists_    : poacher::Token<exists_>  {};
struct bot_       : poacher::Token<bot_>     {};
struct top_       : poacher::Token<top_>     {};
struct vdash_     : poacher::Token<vdash_>   {};
struct models_    : poacher::Token<models_>  {};
}

namespace grp {
struct lpar_      : poacher::Token<lpar_>    {};
struct rpar_      : poacher::Token<rpar_>    {};
struct lsqbra_    : poacher::Token<lsqbra_>  {};
struct rsqbra_    : poacher::Token<rsqbra_>  {};
struct lcubra_    : poacher::Token<lcubra_>  {};
struct rcubra_    : poacher::Token<rcubra_>  {};
struct langle_    : poacher::Token<langle_>  {};
struct rangle_    : poacher::Token<rangle_>  {};
struct langle__   : poacher::Token<langle__> {};
struct rangle__   : poacher::Token<rangle__> {};
struct lxpar_     : poacher::Token<lxpar_>   {};
struct rxpar_     : poacher::Token<rxpar_>   {};
struct abs_       : poacher::Token<abs_>     {};
struct floor_     : poacher::Token<floor_>   {};
struct ceil_      : poacher::Token<ceil_>    {};
struct norm_      : poacher::Token<norm_>    {};
}

namespace arr {
struct uparrow_               : poacher::Token<uparrow_>                {};
struct downarrow_             : poacher::Token<downarrow_>              {};
struct rightarrow_            : poacher::Token<rightarrow_>             {};
struct to_                    : poacher::Token<to_>                     {};
struct rightarrowtail_        : poacher::Token<rightarrowtail_>         {};
struct twoheadrightarrow_     : poacher::Token<twoheadrightarrow_>      {};
struct twoheadrightarrowtail_ : poacher::Token<twoheadrightarrowtail_>  {};
struct mapsto_                : poacher::Token<mapsto_>                 {};
struct leftarrow_             : poacher::Token<leftarrow_>              {};
struct leftrightarrow_        : poacher::Token<leftrightarrow_>         {};
struct Rightarrow_            : poacher::Token<Rightarrow_>             {};
struct Leftarrow_             : poacher::Token<Leftarrow_>              {};
struct Leftrightarrow_        : poacher::Token<Leftrightarrow_>         {};
}

namespace acc {
struct hat_       : poacher::Token<hat_>        {};
struct bar_       : poacher::Token<bar_>        {};
struct ul_        : poacher::Token<ul_>         {};
struct vec_       : poacher::Token<vec_>        {};
struct dot_       : poacher::Token<dot_>        {};
struct ddot_      : poacher::Token<ddot_>       {};
struct overset_   : poacher::Token<overset_>    {};
struct underset_  : poacher::Token<underset_>   {};
struct ubrace_    : poacher::Token<ubrace_>     {};
struct obrace_    : poacher::Token<obrace_>     {};
struct color_     : poacher::Token<color_>      {};
struct cancel_    : poacher::Token<cancel_>     {};
}

namespace gr {
struct alpha_        : poacher::Token<alpha_>      {};
struct beta_         : poacher::Token<beta_>       {};
struct gamma_        : poacher::Token<gamma_>      {};
struct Gamma_        : poacher::Token<Gamma_>      {};
struct delta_        : poacher::Token<delta_>      {};
struct Delta_        : poacher::Token<Delta_>      {};
struct epsilon_      : poacher::Token<epsilon_>    {};
struct varepsilon_   : poacher::Token<varepsilon_> {};
struct zeta_         : poacher::Token<zeta_>       {};
struct eta_          : poacher::Token<eta_>        {};
struct theta_        : poacher::Token<theta_>      {};
struct Theta_        : poacher::Token<Theta_>      {};
struct vartheta_     : poacher::Token<vartheta_>   {};
struct iota_         : poacher::Token<iota_>       {};
struct kappa_        : poacher::Token<kappa_>      {};
struct lambda_       : poacher::Token<lambda_>     {};
struct Lambda_       : poacher::Token<Lambda_>     {};
struct mu_           : poacher::Token<mu_>         {};
struct nu_           : poacher::Token<nu_>         {};
struct xi_           : poacher::Token<xi_>         {};
struct Xi_           : poacher::Token<Xi_>         {};
struct pi_           : poacher::Token<pi_>         {};
struct Pi_           : poacher::Token<Pi_>         {};
struct rho_          : poacher::Token<rho_>        {};
struct sigma_        : poacher::Token<sigma_>      {};
struct Sigma_        : poacher::Token<Sigma_>      {};
struct tau_          : poacher::Token<tau_>        {};
struct upsilon_      : poacher::Token<upsilon_>    {};
struct phi_          : poacher::Token<phi_>        {};
struct Phi_          : poacher::Token<Phi_>        {};
struct varphi_       : poacher::Token<varphi_>     {};
struct chi_          : poacher::Token<chi_>        {};
struct psi_          : poacher::Token<psi_>        {};
struct Psi_          : poacher::Token<Psi_>        {};
struct omega_        : poacher::Token<omega_>      {};
struct Omega_        : poacher::Token<Omega_>      {};
}

namespace ft {
struct bb_  : poacher::Token<bb_>   {};
struct bbb_ : poacher::Token<bbb_>  {};
struct cc_  : poacher::Token<cc_>   {};
struct tt_  : poacher::Token<tt_>   {};
struct fr_  : poacher::Token<fr_>   {};
struct sf_  : poacher::Token<sf_>   {};
}

namespace fun {
struct sin_    : poacher::Token<sin_>     {};
struct cos_    : poacher::Token<cos_>     {};
struct tan_    : poacher::Token<tan_>     {};
struct sec_    : poacher::Token<sec_>     {};
struct csc_    : poacher::Token<csc_>     {};
struct cot_    : poacher::Token<cot_>     {};
struct arcsin_ : poacher::Token<arcsin_>  {};
struct arccos_ : poacher::Token<arccos_>  {};
struct arctan_ : poacher::Token<arctan_>  {};
struct sinh_   : poacher::Token<sinh_>    {};
struct cosh_   : poacher::Token<cosh_>    {};
struct tanh_   : poacher::Token<tanh_>    {};
struct sech_   : poacher::Token<sech_>    {};
struct csch_   : poacher::Token<csch_>    {};
struct coth_   : poacher::Token<coth_>    {};
struct exp_    : poacher::Token<exp_>     {};
struct log_    : poacher::Token<log_>     {};
struct ln_     : poacher::Token<ln_>      {};
struct det_    : poacher::Token<det_>     {};
struct dim_    : poacher::Token<dim_>     {};
struct mod_    : poacher::Token<mod_>     {};
struct gcd_    : poacher::Token<gcd_>     {};
struct lcm_    : poacher::Token<lcm_>     {};
struct lub_    : poacher::Token<lub_>     {};
struct glb_    : poacher::Token<glb_>     {};
struct min_    : poacher::Token<min_>     {};
struct max_    : poacher::Token<max_>     {};
struct f_      : poacher::Token<f_>       {};
struct g_      : poacher::Token<g_>       {};
}

namespace spe {
struct number_ : poacher::Token<number_>  {};
struct ident_  : poacher::Token<ident_>   {};
}

}  // namespace amath::tokens

namespace amath {

constexpr auto get_sym_token( tokens::op::add_ )                    { return poacher::ct_string( "+" ); }
constexpr auto get_sym_token( tokens::op::sub_ )                    { return poacher::ct_string( "-" ); }
constexpr auto get_sym_token( tokens::op::cdot_ )                   { return poacher::ct_string( "*" ); }
constexpr auto get_sym_token( tokens::op::ast_ )                    { return poacher::ct_string( "**" ); }
constexpr auto get_sym_token( tokens::op::star_ )                   { return poacher::ct_string( "***" ); }
constexpr auto get_sym_token( tokens::op::slash_ )                  { return poacher::ct_string( "//" ); }
constexpr auto get_sym_token( tokens::op::backslash_ )              { return poacher::ct_string( "\\\\" ); }
constexpr auto get_sym_token( tokens::op::times_ )                  { return poacher::ct_string( "xx" ); }
constexpr auto get_sym_token( tokens::op::div_ )                    { return poacher::ct_string( "-:" ); }
constexpr auto get_sym_token( tokens::op::ltimes_ )                 { return poacher::ct_string( "|><" ); }
constexpr auto get_sym_token( tokens::op::rtimes_ )                 { return poacher::ct_string( "><|" ); }
constexpr auto get_sym_token( tokens::op::bowtie_ )                 { return poacher::ct_string( "|><|" ); }
constexpr auto get_sym_token( tokens::op::circ_ )                   { return poacher::ct_string( "@" ); }
constexpr auto get_sym_token( tokens::op::oplus_ )                  { return poacher::ct_string( "o+" ); }
constexpr auto get_sym_token( tokens::op::otimes_ )                 { return poacher::ct_string( "ox" ); }
constexpr auto get_sym_token( tokens::op::odot_ )                   { return poacher::ct_string( "o." ); }
constexpr auto get_sym_token( tokens::op::sum_ )                    { return poacher::ct_string( "sum" ); }
constexpr auto get_sym_token( tokens::op::prod_ )                   { return poacher::ct_string( "prod" ); }
constexpr auto get_sym_token( tokens::op::wedge_ )                  { return poacher::ct_string( "^^" ); }
constexpr auto get_sym_token( tokens::op::bidwedge_ )               { return poacher::ct_string( "^^^" ); }
constexpr auto get_sym_token( tokens::op::vee_ )                    { return poacher::ct_string( "vv" ); }
constexpr auto get_sym_token( tokens::op::bigvee_ )                 { return poacher::ct_string( "vvv" ); }
constexpr auto get_sym_token( tokens::op::cap_ )                    { return poacher::ct_string( "nn" ); }
constexpr auto get_sym_token( tokens::op::bigcap_ )                 { return poacher::ct_string( "nnn" ); }
constexpr auto get_sym_token( tokens::op::cup_ )                    { return poacher::ct_string( "uu" ); }
constexpr auto get_sym_token( tokens::op::bigcup_ )                 { return poacher::ct_string( "uuu" ); }

constexpr auto get_sym_token( tokens::misc::frac_ )                 { return poacher::ct_string( "/" ); }
constexpr auto get_sym_token( tokens::misc::exp_ )                  { return poacher::ct_string( "^" ); }
constexpr auto get_sym_token( tokens::misc::sqrt_ )                 { return poacher::ct_string( "sqrt" ); }
constexpr auto get_sym_token( tokens::misc::root_ )                 { return poacher::ct_string( "root" ); }
constexpr auto get_sym_token( tokens::misc::int_ )                  { return poacher::ct_string( "int" ); }
constexpr auto get_sym_token( tokens::misc::oint_ )                 { return poacher::ct_string( "oint" ); }
constexpr auto get_sym_token( tokens::misc::partial_ )              { return poacher::ct_string( "del" ); }
constexpr auto get_sym_token( tokens::misc::nabla_ )                { return poacher::ct_string( "grad" ); }
constexpr auto get_sym_token( tokens::misc::pm_ )                   { return poacher::ct_string( "+-" ); }
constexpr auto get_sym_token( tokens::misc::emptyset_ )             { return poacher::ct_string( "O/" ); }
constexpr auto get_sym_token( tokens::misc::infty_ )                { return poacher::ct_string( "oo" ); }
constexpr auto get_sym_token( tokens::misc::aleph_ )                { return poacher::ct_string( "aleph" ); }
constexpr auto get_sym_token( tokens::misc::therefore_ )            { return poacher::ct_string( ":." ); }
constexpr auto get_sym_token( tokens::misc::because_ )              { return poacher::ct_string( ":'" ); }
constexpr auto get_sym_token( tokens::misc::ldots_ )                { return poacher::ct_string( "|...|" ); }
constexpr auto get_sym_token( tokens::misc::cdots_ )                { return poacher::ct_string( "|cdots|" ); }
constexpr auto get_sym_token( tokens::misc::vdots_ )                { return poacher::ct_string( "vdots" ); }
constexpr auto get_sym_token( tokens::misc::ddots_ )                { return poacher::ct_string( "ddots" ); }
constexpr auto get_sym_token( tokens::misc::smallquad_ )            { return poacher::ct_string( "|\\ |" ); }
constexpr auto get_sym_token( tokens::misc::quad_ )                 { return poacher::ct_string( "|quad|" ); }
constexpr auto get_sym_token( tokens::misc::angle_ )                { return poacher::ct_string( "/_" ); }
constexpr auto get_sym_token( tokens::misc::frown_ )                { return poacher::ct_string( "frown" ); }
constexpr auto get_sym_token( tokens::misc::triangle_ )             { return poacher::ct_string( "/_\\" ); }
constexpr auto get_sym_token( tokens::misc::diamond_ )              { return poacher::ct_string( "diamond" ); }
constexpr auto get_sym_token( tokens::misc::square_ )               { return poacher::ct_string( "square" ); }
constexpr auto get_sym_token( tokens::misc::lfloor_ )               { return poacher::ct_string( "|__" ); }
constexpr auto get_sym_token( tokens::misc::rfloor_ )               { return poacher::ct_string( "__|" ); }
constexpr auto get_sym_token( tokens::misc::lceiling_ )             { return poacher::ct_string( "|~" ); }
constexpr auto get_sym_token( tokens::misc::rceiling_ )             { return poacher::ct_string( "~|" ); }
constexpr auto get_sym_token( tokens::misc::C_ )                    { return poacher::ct_string( "CC" ); }
constexpr auto get_sym_token( tokens::misc::N_ )                    { return poacher::ct_string( "NN" ); }
constexpr auto get_sym_token( tokens::misc::Q_ )                    { return poacher::ct_string( "QQ" ); }
constexpr auto get_sym_token( tokens::misc::R_ )                    { return poacher::ct_string( "RR" ); }
constexpr auto get_sym_token( tokens::misc::Z_ )                    { return poacher::ct_string( "ZZ" ); }

constexpr auto get_sym_token( tokens::rel::eq_ )                    { return poacher::ct_string( "=" ); }
constexpr auto get_sym_token( tokens::rel::ne_ )                    { return poacher::ct_string( "!=" ); }
constexpr auto get_sym_token( tokens::rel::lt_ )                    { return poacher::ct_string( "<" ); }
constexpr auto get_sym_token( tokens::rel::gt_ )                    { return poacher::ct_string( ">" ); }
constexpr auto get_sym_token( tokens::rel::le_ )                    { return poacher::ct_string( "<=" ); }
constexpr auto get_sym_token( tokens::rel::ge_ )                    { return poacher::ct_string( ">=" ); }
constexpr auto get_sym_token( tokens::rel::prec_ )                  { return poacher::ct_string( "-<" ); }
constexpr auto get_sym_token( tokens::rel::preceq_ )                { return poacher::ct_string( "-<=" ); }
constexpr auto get_sym_token( tokens::rel::succ_ )                  { return poacher::ct_string( ">-" ); }
constexpr auto get_sym_token( tokens::rel::succeq_ )                { return poacher::ct_string( ">-=" ); }
constexpr auto get_sym_token( tokens::rel::in_ )                    { return poacher::ct_string( "in" ); }
constexpr auto get_sym_token( tokens::rel::notin_ )                 { return poacher::ct_string( "!in" ); }
constexpr auto get_sym_token( tokens::rel::subset_ )                { return poacher::ct_string( "sub" ); }
constexpr auto get_sym_token( tokens::rel::supset_ )                { return poacher::ct_string( "sup" ); }
constexpr auto get_sym_token( tokens::rel::subseteq_ )              { return poacher::ct_string( "sube" ); }
constexpr auto get_sym_token( tokens::rel::supseteq_ )              { return poacher::ct_string( "supe" ); }
constexpr auto get_sym_token( tokens::rel::equiv_ )                 { return poacher::ct_string( "-=" ); }
constexpr auto get_sym_token( tokens::rel::cong_ )                  { return poacher::ct_string( "~=" ); }
constexpr auto get_sym_token( tokens::rel::approx_ )                { return poacher::ct_string( "~~" ); }
constexpr auto get_sym_token( tokens::rel::propto_ )                { return poacher::ct_string( "prop" ); }

constexpr auto get_sym_token( tokens::logic::and_ )                 { return poacher::ct_string( "and" ); }
constexpr auto get_sym_token( tokens::logic::or_ )                  { return poacher::ct_string( "or" ); }
constexpr auto get_sym_token( tokens::logic::neg_ )                 { return poacher::ct_string( "not" ); }
constexpr auto get_sym_token( tokens::logic::implies_ )             { return poacher::ct_string( "=>" ); }
constexpr auto get_sym_token( tokens::logic::if_ )                  { return poacher::ct_string( "if" ); }
constexpr auto get_sym_token( tokens::logic::iff_ )                 { return poacher::ct_string( "<=>" ); }
constexpr auto get_sym_token( tokens::logic::forall_ )              { return poacher::ct_string( "AA" ); }
constexpr auto get_sym_token( tokens::logic::exists_ )              { return poacher::ct_string( "EE" ); }
constexpr auto get_sym_token( tokens::logic::bot_ )                 { return poacher::ct_string( "_|_" ); }
constexpr auto get_sym_token( tokens::logic::top_ )                 { return poacher::ct_string( "TT" ); }
constexpr auto get_sym_token( tokens::logic::vdash_ )               { return poacher::ct_string( "|--" ); }
constexpr auto get_sym_token( tokens::logic::models_ )              { return poacher::ct_string( "|==" ); }

constexpr auto get_sym_token( tokens::grp::lpar_ )                  { return poacher::ct_string( "(" ); }
constexpr auto get_sym_token( tokens::grp::rpar_ )                  { return poacher::ct_string( ")" ); }
constexpr auto get_sym_token( tokens::grp::lsqbra_ )                { return poacher::ct_string( "[" ); }
constexpr auto get_sym_token( tokens::grp::rsqbra_ )                { return poacher::ct_string( "]" ); }
constexpr auto get_sym_token( tokens::grp::lcubra_ )                { return poacher::ct_string( "{" ); }
constexpr auto get_sym_token( tokens::grp::rcubra_ )                { return poacher::ct_string( "}" ); }
constexpr auto get_sym_token( tokens::grp::langle_ )                { return poacher::ct_string( "(:" ); }
constexpr auto get_sym_token( tokens::grp::rangle_ )                { return poacher::ct_string( ":)" ); }
constexpr auto get_sym_token( tokens::grp::langle__ )               { return poacher::ct_string( "<<" ); }
constexpr auto get_sym_token( tokens::grp::rangle__ )               { return poacher::ct_string( ">>" ); }
constexpr auto get_sym_token( tokens::grp::lxpar_ )                 { return poacher::ct_string( "{: x )" ); }
constexpr auto get_sym_token( tokens::grp::rxpar_ )                 { return poacher::ct_string( "( x :}" ); }
constexpr auto get_sym_token( tokens::grp::abs_ )                   { return poacher::ct_string( "abs" ); }
constexpr auto get_sym_token( tokens::grp::floor_ )                 { return poacher::ct_string( "floor" ); }
constexpr auto get_sym_token( tokens::grp::ceil_ )                  { return poacher::ct_string( "ceil" ); }
constexpr auto get_sym_token( tokens::grp::norm_ )                  { return poacher::ct_string( "norm" ); }

constexpr auto get_sym_token( tokens::arr::uparrow_ )               { return poacher::ct_string( "uarr" ); }
constexpr auto get_sym_token( tokens::arr::downarrow_ )             { return poacher::ct_string( "darr" ); }
constexpr auto get_sym_token( tokens::arr::rightarrow_ )            { return poacher::ct_string( "rarr" ); }
constexpr auto get_sym_token( tokens::arr::to_ )                    { return poacher::ct_string( "->" ); }
constexpr auto get_sym_token( tokens::arr::rightarrowtail_ )        { return poacher::ct_string( ">->" ); }
constexpr auto get_sym_token( tokens::arr::twoheadrightarrow_ )     { return poacher::ct_string( "->>" ); }
constexpr auto get_sym_token( tokens::arr::twoheadrightarrowtail_ ) { return poacher::ct_string( ">->>" ); }
constexpr auto get_sym_token( tokens::arr::mapsto_ )                { return poacher::ct_string( "|->" ); }
constexpr auto get_sym_token( tokens::arr::leftarrow_ )             { return poacher::ct_string( "larr" ); }
constexpr auto get_sym_token( tokens::arr::leftrightarrow_ )        { return poacher::ct_string( "harr" ); }
constexpr auto get_sym_token( tokens::arr::Rightarrow_ )            { return poacher::ct_string( "rArr" ); }
constexpr auto get_sym_token( tokens::arr::Leftarrow_ )             { return poacher::ct_string( "lArr" ); }
constexpr auto get_sym_token( tokens::arr::Leftrightarrow_ )        { return poacher::ct_string( "hArr" ); }

constexpr auto get_sym_token( tokens::acc::hat_ )                   { return poacher::ct_string( "hat" ); }
constexpr auto get_sym_token( tokens::acc::bar_ )                   { return poacher::ct_string( "bar" ); }
constexpr auto get_sym_token( tokens::acc::ul_ )                    { return poacher::ct_string( "ul" ); }
constexpr auto get_sym_token( tokens::acc::vec_ )                   { return poacher::ct_string( "vec" ); }
constexpr auto get_sym_token( tokens::acc::dot_ )                   { return poacher::ct_string( "dot" ); }
constexpr auto get_sym_token( tokens::acc::ddot_ )                  { return poacher::ct_string( "ddot" ); }
constexpr auto get_sym_token( tokens::acc::overset_ )               { return poacher::ct_string( "overset" ); }
constexpr auto get_sym_token( tokens::acc::underset_ )              { return poacher::ct_string( "underset" ); }
constexpr auto get_sym_token( tokens::acc::ubrace_ )                { return poacher::ct_string( "ubrace" ); }
constexpr auto get_sym_token( tokens::acc::obrace_ )                { return poacher::ct_string( "obrace" ); }
constexpr auto get_sym_token( tokens::acc::color_ )                 { return poacher::ct_string( "color" ); }
constexpr auto get_sym_token( tokens::acc::cancel_ )                { return poacher::ct_string( "cancel" ); }

constexpr auto get_sym_token( tokens::gr::alpha_ )                  { return poacher::ct_string( "alpha" ); }
constexpr auto get_sym_token( tokens::gr::beta_ )                   { return poacher::ct_string( "beta" ); }
constexpr auto get_sym_token( tokens::gr::gamma_ )                  { return poacher::ct_string( "gamma" ); }
constexpr auto get_sym_token( tokens::gr::Gamma_ )                  { return poacher::ct_string( "Gamma" ); }
constexpr auto get_sym_token( tokens::gr::delta_ )                  { return poacher::ct_string( "delta" ); }
constexpr auto get_sym_token( tokens::gr::Delta_ )                  { return poacher::ct_string( "Delta" ); }
constexpr auto get_sym_token( tokens::gr::epsilon_ )                { return poacher::ct_string( "epsilon" ); }
constexpr auto get_sym_token( tokens::gr::varepsilon_ )             { return poacher::ct_string( "varepsilon" ); }
constexpr auto get_sym_token( tokens::gr::zeta_ )                   { return poacher::ct_string( "zeta" ); }
constexpr auto get_sym_token( tokens::gr::eta_ )                    { return poacher::ct_string( "eta" ); }
constexpr auto get_sym_token( tokens::gr::theta_ )                  { return poacher::ct_string( "theta" ); }
constexpr auto get_sym_token( tokens::gr::Theta_ )                  { return poacher::ct_string( "Theta" ); }
constexpr auto get_sym_token( tokens::gr::vartheta_ )               { return poacher::ct_string( "vartheta" ); }
constexpr auto get_sym_token( tokens::gr::iota_ )                   { return poacher::ct_string( "iota" ); }
constexpr auto get_sym_token( tokens::gr::kappa_ )                  { return poacher::ct_string( "kappa" ); }
constexpr auto get_sym_token( tokens::gr::lambda_ )                 { return poacher::ct_string( "lambda" ); }
constexpr auto get_sym_token( tokens::gr::Lambda_ )                 { return poacher::ct_string( "Lambda" ); }
constexpr auto get_sym_token( tokens::gr::mu_ )                     { return poacher::ct_string( "mu" ); }
constexpr auto get_sym_token( tokens::gr::nu_ )                     { return poacher::ct_string( "nu" ); }
constexpr auto get_sym_token( tokens::gr::xi_ )                     { return poacher::ct_string( "xi" ); }
constexpr auto get_sym_token( tokens::gr::Xi_ )                     { return poacher::ct_string( "Xi" ); }
constexpr auto get_sym_token( tokens::gr::pi_ )                     { return poacher::ct_string( "pi" ); }
constexpr auto get_sym_token( tokens::gr::Pi_ )                     { return poacher::ct_string( "Pi" ); }
constexpr auto get_sym_token( tokens::gr::rho_ )                    { return poacher::ct_string( "rho" ); }
constexpr auto get_sym_token( tokens::gr::sigma_ )                  { return poacher::ct_string( "sigma" ); }
constexpr auto get_sym_token( tokens::gr::Sigma_ )                  { return poacher::ct_string( "Sigma" ); }
constexpr auto get_sym_token( tokens::gr::tau_ )                    { return poacher::ct_string( "tau" ); }
constexpr auto get_sym_token( tokens::gr::upsilon_ )                { return poacher::ct_string( "upsilon" ); }
constexpr auto get_sym_token( tokens::gr::phi_ )                    { return poacher::ct_string( "phi" ); }
constexpr auto get_sym_token( tokens::gr::Phi_ )                    { return poacher::ct_string( "Phi" ); }
constexpr auto get_sym_token( tokens::gr::varphi_ )                 { return poacher::ct_string( "varphi" ); }
constexpr auto get_sym_token( tokens::gr::chi_ )                    { return poacher::ct_string( "chi" ); }
constexpr auto get_sym_token( tokens::gr::psi_ )                    { return poacher::ct_string( "psi" ); }
constexpr auto get_sym_token( tokens::gr::Psi_ )                    { return poacher::ct_string( "Psi" ); }
constexpr auto get_sym_token( tokens::gr::omega_ )                  { return poacher::ct_string( "omega" ); }
constexpr auto get_sym_token( tokens::gr::Omega_ )                  { return poacher::ct_string( "Omega" ); }

constexpr auto get_sym_token( tokens::ft::bb_ )                     { return poacher::ct_string( "bb" ); }
constexpr auto get_sym_token( tokens::ft::bbb_ )                    { return poacher::ct_string( "bbb" ); }
constexpr auto get_sym_token( tokens::ft::cc_ )                     { return poacher::ct_string( "cc" ); }
constexpr auto get_sym_token( tokens::ft::tt_ )                     { return poacher::ct_string( "tt" ); }
constexpr auto get_sym_token( tokens::ft::fr_ )                     { return poacher::ct_string( "fr" ); }
constexpr auto get_sym_token( tokens::ft::sf_ )                     { return poacher::ct_string( "sf" ); }

constexpr auto get_sym_token( tokens::fun::sin_ )                   { return poacher::ct_string( "sin" ); }
constexpr auto get_sym_token( tokens::fun::cos_ )                   { return poacher::ct_string( "cos" ); }
constexpr auto get_sym_token( tokens::fun::tan_ )                   { return poacher::ct_string( "tan" ); }
constexpr auto get_sym_token( tokens::fun::sec_ )                   { return poacher::ct_string( "sec" ); }
constexpr auto get_sym_token( tokens::fun::csc_ )                   { return poacher::ct_string( "csc" ); }
constexpr auto get_sym_token( tokens::fun::cot_ )                   { return poacher::ct_string( "cot" ); }
constexpr auto get_sym_token( tokens::fun::arcsin_ )                { return poacher::ct_string( "arcsin" ); }
constexpr auto get_sym_token( tokens::fun::arccos_ )                { return poacher::ct_string( "arccos" ); }
constexpr auto get_sym_token( tokens::fun::arctan_ )                { return poacher::ct_string( "arctan" ); }
constexpr auto get_sym_token( tokens::fun::sinh_ )                  { return poacher::ct_string( "sinh" ); }
constexpr auto get_sym_token( tokens::fun::cosh_ )                  { return poacher::ct_string( "cosh" ); }
constexpr auto get_sym_token( tokens::fun::tanh_ )                  { return poacher::ct_string( "tanh" ); }
constexpr auto get_sym_token( tokens::fun::sech_ )                  { return poacher::ct_string( "sech" ); }
constexpr auto get_sym_token( tokens::fun::csch_ )                  { return poacher::ct_string( "csch" ); }
constexpr auto get_sym_token( tokens::fun::coth_ )                  { return poacher::ct_string( "coth" ); }
constexpr auto get_sym_token( tokens::fun::exp_ )                   { return poacher::ct_string( "exp" ); }
constexpr auto get_sym_token( tokens::fun::log_ )                   { return poacher::ct_string( "log" ); }
constexpr auto get_sym_token( tokens::fun::ln_ )                    { return poacher::ct_string( "ln" ); }
constexpr auto get_sym_token( tokens::fun::det_ )                   { return poacher::ct_string( "det" ); }
constexpr auto get_sym_token( tokens::fun::dim_ )                   { return poacher::ct_string( "dim" ); }
constexpr auto get_sym_token( tokens::fun::mod_ )                   { return poacher::ct_string( "mod" ); }
constexpr auto get_sym_token( tokens::fun::gcd_ )                   { return poacher::ct_string( "gcd" ); }
constexpr auto get_sym_token( tokens::fun::lcm_ )                   { return poacher::ct_string( "lcm" ); }
constexpr auto get_sym_token( tokens::fun::lub_ )                   { return poacher::ct_string( "lub" ); }
constexpr auto get_sym_token( tokens::fun::glb_ )                   { return poacher::ct_string( "glb" ); }
constexpr auto get_sym_token( tokens::fun::min_ )                   { return poacher::ct_string( "min" ); }
constexpr auto get_sym_token( tokens::fun::max_ )                   { return poacher::ct_string( "max" ); }
constexpr auto get_sym_token( tokens::fun::f_ )                     { return poacher::ct_string( "f" ); }
constexpr auto get_sym_token( tokens::fun::g_ )                     { return poacher::ct_string( "g" ); }

constexpr auto get_sym_token( tokens::spe::number_ )                { return poacher::ct_string( "." ); }
constexpr auto get_sym_token( tokens::spe::ident_ )                 { return poacher::ct_string( "." ); }

}

namespace amath {

using token_type_list = poacher::token_type_list

   < tokens::op::add_
   , tokens::op::sub_
   , tokens::op::cdot_
   , tokens::op::ast_
   , tokens::op::star_
   , tokens::op::slash_
   , tokens::op::backslash_
   , tokens::op::times_
   , tokens::op::div_
   , tokens::op::ltimes_
   , tokens::op::rtimes_
   , tokens::op::bowtie_
   , tokens::op::circ_
   , tokens::op::oplus_
   , tokens::op::otimes_
   , tokens::op::odot_
   , tokens::op::sum_
   , tokens::op::prod_
   , tokens::op::wedge_
   , tokens::op::bidwedge_
   , tokens::op::vee_
   , tokens::op::bigvee_
   , tokens::op::cap_
   , tokens::op::bigcap_
   , tokens::op::cup_
   , tokens::op::bigcup_

   , tokens::misc::frac_
   , tokens::misc::exp_
   , tokens::misc::sqrt_
   , tokens::misc::root_
   //o , tokens::misc::int_
   //o , tokens::misc::oint_
   //o , tokens::misc::partial_
   //o , tokens::misc::nabla_
   //o , tokens::misc::pm_
   //o , tokens::misc::emptyset_
   //o , tokens::misc::infty_
   //o , tokens::misc::aleph_
   //o , tokens::misc::therefore_
   //o , tokens::misc::because_
   //o , tokens::misc::ldots_
   //o , tokens::misc::cdots_
   //o , tokens::misc::vdots_
   //o , tokens::misc::ddots_
   //o , tokens::misc::smallquad_
   //o , tokens::misc::quad_
   //o , tokens::misc::angle_
   //o , tokens::misc::frown_
   //o , tokens::misc::triangle_
   //o , tokens::misc::diamond_
   //o , tokens::misc::square_
   //o , tokens::misc::lfloor_
   //o , tokens::misc::rfloor_
   //o , tokens::misc::lceiling_
   //o , tokens::misc::rceiling_
   //o , tokens::misc::C_
   //o , tokens::misc::N_
   //o , tokens::misc::Q_
   //o , tokens::misc::R_
   //o , tokens::misc::Z_

   , tokens::rel::eq_
   , tokens::rel::ne_
   , tokens::rel::lt_
   , tokens::rel::gt_
   , tokens::rel::le_
   , tokens::rel::ge_
   //o , tokens::rel::prec_
   //o , tokens::rel::preceq_
   //o , tokens::rel::succ_
   //o , tokens::rel::succeq_
   //o , tokens::rel::in_
   //o , tokens::rel::notin_
   //o , tokens::rel::subset_
   //o , tokens::rel::supset_
   //o , tokens::rel::subseteq_
   //o , tokens::rel::supseteq_
   //o , tokens::rel::equiv_
   //o , tokens::rel::cong_
   //o , tokens::rel::approx_
   //o , tokens::rel::propto_

   , tokens::logic::and_
   , tokens::logic::or_
   , tokens::logic::neg_
   , tokens::logic::implies_
   , tokens::logic::if_
   , tokens::logic::iff_
   , tokens::logic::forall_
   , tokens::logic::exists_
   , tokens::logic::bot_
   , tokens::logic::top_
   , tokens::logic::vdash_
   , tokens::logic::models_

   , tokens::grp::lpar_
   , tokens::grp::rpar_
   //o , tokens::grp::lsqbra_
   //o , tokens::grp::rsqbra_
   //o , tokens::grp::lcubra_
   //o , tokens::grp::rcubra_
   //o , tokens::grp::langle_
   //o , tokens::grp::rangle_
   //o , tokens::grp::langle__
   //o , tokens::grp::rangle__
   //o , tokens::grp::lxpar_
   //o , tokens::grp::rxpar_
   //o , tokens::grp::abs_
   //o , tokens::grp::floor_
   //o , tokens::grp::ceil_
   //o , tokens::grp::norm_

   //o , tokens::arr::uparrow_
   //o , tokens::arr::downarrow_
   //o , tokens::arr::rightarrow_
   //o , tokens::arr::to_
   //o , tokens::arr::rightarrowtail_
   //o , tokens::arr::twoheadrightarrow_
   //o , tokens::arr::twoheadrightarrowtail_
   //o , tokens::arr::mapsto_
   //o , tokens::arr::leftarrow_
   //o , tokens::arr::leftrightarrow_
   //o , tokens::arr::Rightarrow_
   //o , tokens::arr::Leftarrow_
   //o , tokens::arr::Leftrightarrow_

   //o , tokens::acc::hat_
   //o , tokens::acc::bar_
   //o , tokens::acc::ul_
   //o , tokens::acc::vec_
   //o , tokens::acc::dot_
   //o , tokens::acc::ddot_
   //o , tokens::acc::overset_
   //o , tokens::acc::underset_
   //o , tokens::acc::ubrace_
   //o , tokens::acc::obrace_
   //o , tokens::acc::color_
   //o , tokens::acc::cancel_

   //o , tokens::gr::alpha_
   //o , tokens::gr::beta_
   //o , tokens::gr::gamma_
   //o , tokens::gr::Gamma_
   //o , tokens::gr::delta_
   //o , tokens::gr::Delta_
   //o , tokens::gr::epsilon_
   //o , tokens::gr::varepsilon_
   //o , tokens::gr::zeta_
   //o , tokens::gr::eta_
   //o , tokens::gr::theta_
   //o , tokens::gr::Theta_
   //o , tokens::gr::vartheta_
   //o , tokens::gr::iota_
   //o , tokens::gr::kappa_
   //o , tokens::gr::lambda_
   //o , tokens::gr::Lambda_
   //o , tokens::gr::mu_
   //o , tokens::gr::nu_
   //o , tokens::gr::xi_
   //o , tokens::gr::Xi_
   //o , tokens::gr::pi_
   //o , tokens::gr::Pi_
   //o , tokens::gr::rho_
   //o , tokens::gr::sigma_
   //o , tokens::gr::Sigma_
   //o , tokens::gr::tau_
   //o , tokens::gr::upsilon_
   //o , tokens::gr::phi_
   //o , tokens::gr::Phi_
   //o , tokens::gr::varphi_
   //o , tokens::gr::chi_
   //o , tokens::gr::psi_
   //o , tokens::gr::Psi_
   //o , tokens::gr::omega_
   //o , tokens::gr::Omega_

   , tokens::ft::bb_
   , tokens::ft::bbb_
   , tokens::ft::cc_
   , tokens::ft::tt_
   , tokens::ft::fr_
   , tokens::ft::sf_

   , tokens::fun::sin_
   , tokens::fun::cos_
   , tokens::fun::tan_
   //o , tokens::fun::sec_
   //o , tokens::fun::csc_
   //o , tokens::fun::cot_
   //o , tokens::fun::arcsin_
   //o , tokens::fun::arccos_
   //o , tokens::fun::arctan_
   //o , tokens::fun::sinh_
   //o , tokens::fun::cosh_
   //o , tokens::fun::tanh_
   //o , tokens::fun::sech_
   //o , tokens::fun::csch_
   //o , tokens::fun::coth_
   //o , tokens::fun::exp_
   //o , tokens::fun::log_
   //o , tokens::fun::ln_
   //o , tokens::fun::det_
   //o , tokens::fun::dim_
   //o , tokens::fun::mod_
   //o , tokens::fun::gcd_
   //o , tokens::fun::lcm_
   //o , tokens::fun::lub_
   //o , tokens::fun::glb_
   //o , tokens::fun::min_
   //o , tokens::fun::max_
   //o , tokens::fun::f_
   //o , tokens::fun::g_

   , tokens::spe::number_
   , tokens::spe::ident_
   >;

}
