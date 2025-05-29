/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C

      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

   /* As a special exception, you may create a larger work that contains
      part or all of the Bison parser skeleton and distribute that work
      under terms of your choice, so long as that work isn't itself a
      parser generator using the skeleton or a modified version thereof
      as a parser skeleton.  Alternatively, if you modify or redistribute
      the parser skeleton itself, you may (at your option) remove this
      special exception, which will cause the skeleton and the resulting
      Bison output files to be licensed under the GNU General Public
      License without this special exception.

      This special exception was added by the Free Software Foundation in
      version 2.2 of Bison.  */

      /* C LALR(1) parser skeleton written by Richard Stallman, by
         simplifying the original so-called "semantic" parser.  */

         /* All symbols defined below should begin with yy or YY, to avoid
            infringing on user name space.  This should be done even for local
            variables, as they might otherwise be expanded by user macros.
            There are some unavoidable exceptions within include files to
            define necessary library symbols; they are noted "INFRINGES ON
            USER NAME SPACE" below.  */

            /* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "cute.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DEBUG	0

#define	 MAXSYM	100
#define	 MAXSYMLEN	20
#define	 MAXTSYMLEN	15
#define	 MAXTSYMBOL	MAXSYM/2

#define STMTLIST 500

typedef struct nodeType {
    int token;
    int tokenval;
    struct nodeType* son;
    struct nodeType* brother;
} Node;

#define YYSTYPE Node*

int tsymbolcnt = 0;
int errorcnt = 0;

FILE* yyin;
FILE* fp;

extern char symtbl[MAXSYM][MAXSYMLEN];
extern int maxsym;
extern int lineno;
void yyerror(char* c);
int yylex();
int cnt = 0;
int f_cnt = 0;
int cb_cnt = 0;
int fe_cnt = 0;
char str[50];
int w_cnt;
int for_cnt;
int tl_cnt;
int if_cnt;
int ife_cnt;
int inner_if_cnt;
int inner_w_cnt;
int inner_f_cnt;
int w_c_cnt;
int f_c_cnt;
int inner_e_cnt;
int case_cnt;
int s_cnt;

void DFSTree(Node*);
Node* MakeOPTree(int, Node*, Node*);
Node* MakeNode(int, int);
Node* MakeListTree(Node*, Node*);
void codegen(Node*);
void prtcode(int, int);

void	dwgen();
int	gentemp();
void	assgnstmt(int, int);
void	numassgn(int, int);
void	addstmt(int, int, int);
void	substmt(int, int, int);
int	insertsym(char*);
int	if_cond_check(int);
int	w_cond_check(int);
int	t_cond_check(int);
int	f_cond_check(int);
int 	count_if_nodes(Node*);
int	count_while_nodes(Node*);
int	count_f_nodes(Node*);
int 	count_e_nodes(Node*);


/* Line 371 of yacc.c  */
#line 145 "cute.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "cute.h".  */
#ifndef YY_YY_CUTE_H_INCLUDED
# define YY_YY_CUTE_H_INCLUDED
   /* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
enum yytokentype {
    ADD = 258,
    SUB = 259,
    ASSGN = 260,
    ID = 261,
    NUM = 262,
    STMTEND = 263,
    START = 264,
    END = 265,
    ID2 = 266,
    MUL = 267,
    DIV = 268,
    LB = 269,
    RB = 270,
    OPEN = 271,
    CLOSE = 272,
    IF = 273,
    ELSE = 274,
    LT = 275,
    GT = 276,
    LE = 277,
    GE = 278,
    EQ = 279,
    NE = 280,
    WHILE = 281,
    IF_ELSE = 282,
    REAL = 283,
    ID4 = 284,
    AA = 285,
    SA = 286,
    MA = 287,
    DA = 288,
    ID3 = 289,
    LOOPCON = 290,
    LOOPEND = 291,
    FUNC = 292,
    FSTMT = 293,
    FUNCEND = 294,
    CALLBACK = 295,
    FNAME = 296,
    FOR = 297,
    FORSTLI = 298,
    FORCON = 299,
    FORSTART = 300,
    QM = 301,
    COLON = 302,
    TLVAL = 303,
    TSTMT = 304,
    TERN = 305,
    TEX = 306,
    TCON = 307,
    SCANF = 308,
    COMMA = 309,
    PD = 310,
    SCAN = 311,
    UPC = 312,
    AND = 313,
    PRINTF = 314,
    PRINT = 315,
    WLOOPEND = 316,
    FLOOPEND = 317,
    IF_LT = 318,
    IF_GT = 319,
    IF_LE = 320,
    IF_GE = 321,
    IF_EQ = 322,
    IF_NE = 323,
    W_LT = 324,
    W_GT = 325,
    W_LE = 326,
    W_GE = 327,
    W_EQ = 328,
    W_NE = 329,
    T_LT = 330,
    T_GT = 331,
    T_LE = 332,
    T_GE = 333,
    T_EQ = 334,
    T_NE = 335,
    F_LT = 336,
    F_GT = 337,
    F_LE = 338,
    F_GE = 339,
    F_EQ = 340,
    F_NE = 341,
    SWAPS = 342,
    SWAPE = 343,
    SWAPM = 344,
    SWAPH = 345,
    ID5 = 346,
    SWAP = 347,
    DEFAULT = 348,
    CASES = 349,
    SWITCHH = 350,
    CASEL = 351,
    CASEM = 352,
    CASEH = 353,
    CASE = 354,
    SWITCH = 355,
    BREAK = 356,
    IS = 357,
    THEN = 358,
    WA = 359,
    THIS = 360,
    SAVE = 361,
    RUN = 362,
    ING = 363,
    LAST = 364,
    LOOP = 365,
    ID6 = 366,
    ID7 = 367,
    INC = 368,
    DEC = 369,
    NOW = 370,
    CALL = 371,
    IN = 372,
    CONTENT = 373,
    INIT = 374,
    FN = 375,
    VAL = 376
};
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse(void* YYPARSE_PARAM);
#else
int yyparse();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse(void);
#else
int yyparse();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_CUTE_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 332 "cute.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID(int yyi)
#else
static int
YYID(yyi)
int yyi;
#endif
{
    return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void* malloc(YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free(void*); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
    yytype_int16 yyss_alloc;
    YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

   /* Relocate STACK from its old location to the new one.  The
      local variables YYSIZE and YYSTACKSIZE give the old and new number of
      elements in the stack, and YYPTR gives the new location of the
      stack.  Advance YYPTR to a properly aligned location for the next
      stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
      /* Copy COUNT objects from SRC to DST.  The source and destination do
         not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

         /* YYFINAL -- State number of the termination state.  */
#define YYFINAL  26
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   231

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  122
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNRULES -- Number of states.  */
#define YYNSTATES  137

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   376

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     7,    10,    12,    14,    20,    26,    29,
      33,    37,    41,    45,    57,    61,    65,    69,    72,    75,
      77,    79,    81,    84,    87,    90,    95,    98,   100,   105,
     110,   114,   115,   118,   122,   123,   127,   132,   133,   137,
     145,   148,   151,   154,   155,   156,   160,   163,   164,   171,
     177,   183,   189,   195,   201,   207,   213,   217,   221,   223,
     227,   231,   233,   235
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     123,     0,    -1,     9,   124,    10,    -1,   124,   125,    -1,
     125,    -1,     1,    -1,     6,     5,   152,   105,   106,    -1,
     147,    14,   124,    15,   110,    -1,   136,   137,    -1,     6,
      30,   152,    -1,     6,    31,   152,    -1,     6,    32,   152,
      -1,     6,    33,   152,    -1,    37,    41,    58,   118,    14,
     143,    15,   117,   120,   105,   119,    -1,    42,   141,   140,
      -1,     6,   121,    53,    -1,     6,   121,    59,    -1,   133,
      92,    -1,   149,   150,    -1,   149,    -1,   126,    -1,   146,
      -1,   127,   129,    -1,     6,   113,    -1,     6,   114,    -1,
     100,     6,   102,   128,    -1,   128,   130,    -1,   130,    -1,
      93,    47,   124,   101,    -1,   131,    47,   124,   101,    -1,
       7,    99,   132,    -1,    -1,   134,     6,    -1,     6,   104,
     135,    -1,    -1,   139,   137,    19,    -1,   138,   152,   105,
     106,    -1,    -1,     6,     5,   151,    -1,   109,   125,   108,
      14,   124,    15,   110,    -1,   142,   151,    -1,   125,   144,
      -1,   124,   145,    -1,    -1,    -1,    41,   105,   116,    -1,
     151,   148,    -1,    -1,    18,   151,    14,   124,    15,   107,
      -1,    19,    14,   124,    15,   107,    -1,   152,   102,   152,
     104,    24,    -1,   152,   102,   152,   103,    20,    -1,   152,
     102,   152,   103,    21,    -1,   152,   102,   152,   103,    22,
      -1,   152,   102,   152,   103,    23,    -1,   152,   102,   152,
     104,    25,    -1,   152,     3,   153,    -1,   152,     4,   153,
      -1,   153,    -1,   153,    12,   154,    -1,   153,    13,   154,
      -1,   154,    -1,     6,    -1,     7,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    88,    88,    91,    92,    93,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   115,   116,   119,   122,   123,   126,   129,
     132,   135,   138,   140,   143,   146,   149,   152,   155,   157,
     160,   162,   165,   167,   169,   172,   175,   177,   180,   183,
     187,   188,   189,   190,   191,   192,   197,   198,   199,   203,
     204,   205,   210,   211
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char* const yytname[] =
{
  "$end", "error", "$undefined", "ADD", "SUB", "ASSGN", "ID", "NUM",
  "STMTEND", "START", "END", "ID2", "MUL", "DIV", "LB", "RB", "OPEN",
  "CLOSE", "IF", "ELSE", "LT", "GT", "LE", "GE", "EQ", "NE", "WHILE",
  "IF_ELSE", "REAL", "ID4", "AA", "SA", "MA", "DA", "ID3", "LOOPCON",
  "LOOPEND", "FUNC", "FSTMT", "FUNCEND", "CALLBACK", "FNAME", "FOR",
  "FORSTLI", "FORCON", "FORSTART", "QM", "COLON", "TLVAL", "TSTMT", "TERN",
  "TEX", "TCON", "SCANF", "COMMA", "PD", "SCAN", "UPC", "AND", "PRINTF",
  "PRINT", "WLOOPEND", "FLOOPEND", "IF_LT", "IF_GT", "IF_LE", "IF_GE",
  "IF_EQ", "IF_NE", "W_LT", "W_GT", "W_LE", "W_GE", "W_EQ", "W_NE", "T_LT",
  "T_GT", "T_LE", "T_GE", "T_EQ", "T_NE", "F_LT", "F_GT", "F_LE", "F_GE",
  "F_EQ", "F_NE", "SWAPS", "SWAPE", "SWAPM", "SWAPH", "ID5", "SWAP",
  "DEFAULT", "CASES", "SWITCHH", "CASEL", "CASEM", "CASEH", "CASE",
  "SWITCH", "BREAK", "IS", "THEN", "WA", "THIS", "SAVE", "RUN", "ING",
  "LAST", "LOOP", "ID6", "ID7", "INC", "DEC", "NOW", "CALL", "IN",
  "CONTENT", "INIT", "FN", "VAL", "$accept", "program", "stmt_list",
  "stmt", "inc_dec_stmt", "switch_stmt", "case_list", "default_stmt",
  "case_h", "case_m", "case_l", "swap_h", "swap_m", "swap_s", "t_stmt",
  "t_expr", "t_lval", "t_con", "for_stmt_list", "for_con", "for_start",
  "f_stmt_list", "floop_end", "f_end", "call_back", "loop_con",
  "wloop_end", "if_stmt", "else_stmt", "condition", "expr", "term",
  "factor", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   122,   123,   124,   124,   124,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   126,   126,   127,   128,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   151,   151,   151,   151,   151,   152,   152,   152,   153,
     153,   153,   154,   154
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     1,     1,     5,     5,     2,     3,
       3,     3,     3,    11,     3,     3,     3,     2,     2,     1,
       1,     1,     2,     2,     2,     4,     2,     1,     4,     4,
       3,     0,     2,     3,     0,     3,     4,     0,     3,     7,
       2,     2,     2,     0,     0,     3,     2,     0,     6,     5,
       5,     5,     5,     5,     5,     5,     3,     3,     1,     3,
       3,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     5,    62,    63,     0,     0,     0,     0,
       0,     0,     4,    20,     0,     0,     0,    37,    37,    21,
       0,    19,    47,     0,    58,    61,     1,     0,     0,     0,
       0,     0,    34,    23,    24,     0,    62,     0,     0,     0,
      43,     0,     0,     0,     2,     3,     0,    22,    17,    32,
       8,     0,     0,     0,     0,    18,    46,     0,     0,     0,
       0,     0,    38,     0,     9,    10,    11,    12,    33,    15,
      16,     0,     0,    45,    41,     0,    14,    40,     0,     0,
       0,    35,     0,     0,    56,    57,     0,    59,    60,     0,
       0,     0,     0,     0,    25,    27,     0,     0,     0,     0,
       0,     0,     0,     6,     0,     0,     0,    31,    26,     0,
      28,    36,     7,     0,    51,    52,    53,    54,    50,    55,
      48,    44,     0,     0,    30,     0,    49,    42,     0,     0,
      29,     0,     0,     0,    39,     0,    13
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    11,    12,    13,    14,    94,    47,    95,    96,
     124,    15,    16,    68,    17,    50,    51,    18,    76,    41,
      42,   122,    74,   127,    19,    20,    56,    21,    55,    22,
      23,    24,    25
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -58
static const yytype_int16 yypact[] =
{
       1,    15,    12,   -58,    -4,   -58,    24,   -18,   -57,   131,
      45,    35,   -58,   -58,   -39,   -28,    69,   -58,   -58,   -58,
      68,    64,   -58,     4,    25,   -58,   -58,    24,    24,    24,
      24,    24,   -58,   -58,   -58,   -44,   -58,    72,    29,   -27,
     -58,   -19,    24,   -10,   -58,   -58,    47,   -58,   -58,   -58,
     -58,    24,    76,    15,    82,   -58,   -58,    24,    24,    24,
      24,    24,   -58,     0,    36,    36,    36,    36,   -58,   -58,
     -58,    15,   -17,   -58,   -58,   131,   -58,   -58,    92,    15,
       2,   -58,    43,    15,    25,    25,    10,   -58,   -58,    -2,
      56,    89,     3,     9,    92,   -58,    74,    18,    20,    17,
     116,    -3,    19,   -58,    23,    15,   125,   -58,   -58,    15,
     -58,   -58,   -58,    33,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   131,   117,    15,   -58,    28,   -58,   -58,    30,   118,
     -58,    22,    31,    40,   -58,    27,   -58
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -58,   -58,    91,    -9,   -58,   -58,   -58,   -58,    54,   -58,
     -58,   -58,   -58,   -58,   -58,   132,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,     5,
     136,    21,     7
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      40,    27,    45,    57,    58,    57,    58,    57,    58,    69,
       1,    37,    26,    57,    58,    70,     3,   114,   115,   116,
     117,     4,     5,    38,     4,     5,    28,    29,    30,    31,
      36,     5,    62,     6,     4,     5,     6,    60,    61,    57,
      58,     4,     5,   118,   119,    44,     6,    77,    39,     4,
       5,    43,     7,     6,    46,     7,     8,     9,    99,     8,
       9,     6,     4,     5,    48,     7,    92,    87,    88,     8,
       9,   104,     7,    45,     6,    49,     8,     9,    84,    85,
       7,    45,    53,    54,     8,     9,    71,    72,    45,    73,
      75,    45,    78,     7,    79,    81,    83,     8,     9,    93,
      32,    91,    59,   105,   103,    89,    59,    98,   107,    33,
      34,   106,    45,   101,   102,    10,    45,    35,    10,   110,
      45,   109,     4,     5,     4,     5,   111,   112,    10,   130,
     120,   113,   128,   132,     6,    10,     6,     4,     5,   123,
     126,   134,   133,    10,    82,   135,   136,   131,   108,     6,
      52,     0,     0,     7,     0,     7,    10,     8,     9,     8,
       9,     0,    90,    63,    64,    65,    66,    67,     7,     0,
      97,     0,     8,     9,   100,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    80,     0,     0,
       0,     0,     0,     0,     0,    86,   121,     0,     0,     0,
     125,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   129,     0,    10,     0,    10,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-58)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       9,     5,    11,     3,     4,     3,     4,     3,     4,    53,
       9,     6,     0,     3,     4,    59,     1,    20,    21,    22,
      23,     6,     7,    41,     6,     7,    30,    31,    32,    33,
       6,     7,    27,    18,     6,     7,    18,    12,    13,     3,
       4,     6,     7,    24,    25,    10,    18,    42,   105,     6,
       7,     6,    37,    18,    93,    37,    41,    42,    15,    41,
      42,    18,     6,     7,    92,    37,    75,    60,    61,    41,
      42,    15,    37,    82,    18,     6,    41,    42,    57,    58,
      37,    90,    14,    19,    41,    42,    14,    58,    97,   116,
     109,   100,   102,    37,    47,    19,    14,    41,    42,     7,
     104,   118,   102,    14,   106,   105,   102,   105,    99,   113,
     114,   108,   121,   103,   104,   100,   125,   121,   100,   101,
     129,    47,     6,     7,     6,     7,   106,   110,   100,   101,
     107,    15,    15,    15,    18,   100,    18,     6,     7,    14,
     107,   110,   120,   100,    53,   105,   119,   117,    94,    18,
      18,    -1,    -1,    37,    -1,    37,   100,    41,    42,    41,
      42,    -1,    71,    27,    28,    29,    30,    31,    37,    -1,
      79,    -1,    41,    42,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,   105,    -1,    -1,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   123,    -1,   100,    -1,   100,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   100
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,   123,     1,     6,     7,    18,    37,    41,    42,
     100,   124,   125,   126,   127,   133,   134,   136,   139,   146,
     147,   149,   151,   152,   153,   154,     0,     5,    30,    31,
      32,    33,   104,   113,   114,   121,     6,   151,    41,   105,
     125,   141,   142,     6,    10,   125,    93,   129,    92,     6,
     137,   138,   137,    14,    19,   150,   148,     3,     4,   102,
      12,    13,   151,   152,   152,   152,   152,   152,   135,    53,
      59,    14,    58,   116,   144,   109,   140,   151,   102,    47,
     152,    19,   124,    14,   153,   153,   152,   154,   154,   105,
     124,   118,   125,     7,   128,   130,   131,   124,   105,    15,
     124,   103,   104,   106,    15,    14,   108,    99,   130,    47,
     101,   106,   110,    15,    20,    21,    22,    23,    24,    25,
     107,   124,   143,    14,   132,   124,   107,   145,    15,   124,
     101,   117,    15,   120,   110,   105,   119
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
   /* This is here to suppress warnings from the GCC cpp's
      -Wunused-macros.  Normally we don't worry about that warning, but
      some users do, and we want to make it easy for users to remove
      YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

      /* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print(FILE* yyoutput, int yytype, YYSTYPE const* const yyvaluep)
#else
static void
yy_symbol_value_print(yyoutput, yytype, yyvaluep)
FILE* yyoutput;
int yytype;
YYSTYPE const* const yyvaluep;
#endif
{
    FILE* yyo = yyoutput;
    YYUSE(yyo);
    if (!yyvaluep)
        return;
# ifdef YYPRINT
    if (yytype < YYNTOKENS)
        YYPRINT(yyoutput, yytoknum[yytype], *yyvaluep);
# else
    YYUSE(yyoutput);
# endif
    switch (yytype)
    {
    default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print(FILE* yyoutput, int yytype, YYSTYPE const* const yyvaluep)
#else
static void
yy_symbol_print(yyoutput, yytype, yyvaluep)
FILE* yyoutput;
int yytype;
YYSTYPE const* const yyvaluep;
#endif
{
    if (yytype < YYNTOKENS)
        YYFPRINTF(yyoutput, "token %s (", yytname[yytype]);
    else
        YYFPRINTF(yyoutput, "nterm %s (", yytname[yytype]);

    yy_symbol_value_print(yyoutput, yytype, yyvaluep);
    YYFPRINTF(yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print(yytype_int16* yybottom, yytype_int16* yytop)
#else
static void
yy_stack_print(yybottom, yytop)
yytype_int16* yybottom;
yytype_int16* yytop;
#endif
{
    YYFPRINTF(stderr, "Stack now");
    for (; yybottom <= yytop; yybottom++)
    {
        int yybot = *yybottom;
        YYFPRINTF(stderr, " %d", yybot);
    }
    YYFPRINTF(stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print(YYSTYPE* yyvsp, int yyrule)
#else
static void
yy_reduce_print(yyvsp, yyrule)
YYSTYPE* yyvsp;
int yyrule;
#endif
{
    int yynrhs = yyr2[yyrule];
    int yyi;
    unsigned long int yylno = yyrline[yyrule];
    YYFPRINTF(stderr, "Reducing stack by rule %d (line %lu):\n",
        yyrule - 1, yylno);
    /* The symbols being reduced.  */
    for (yyi = 0; yyi < yynrhs; yyi++)
    {
        YYFPRINTF(stderr, "   $%d = ", yyi + 1);
        yy_symbol_print(stderr, yyrhs[yyprhs[yyrule] + yyi],
            &(yyvsp[(yyi + 1) - (yynrhs)])
        );
        YYFPRINTF(stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
   /* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen(const char* yystr)
#else
static YYSIZE_T
yystrlen(yystr)
const char* yystr;
#endif
{
    YYSIZE_T yylen;
    for (yylen = 0; yystr[yylen]; yylen++)
        continue;
    return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char*
yystpcpy(char* yydest, const char* yysrc)
#else
static char*
yystpcpy(yydest, yysrc)
char* yydest;
const char* yysrc;
#endif
{
    char* yyd = yydest;
    const char* yys = yysrc;

    while ((*yyd++ = *yys++) != '\0')
        continue;

    return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr(char* yyres, const char* yystr)
{
    if (*yystr == '"')
    {
        YYSIZE_T yyn = 0;
        char const* yyp = yystr;

        for (;;)
            switch (*++yyp)
            {
            case '\'':
            case ',':
                goto do_not_strip_quotes;

            case '\\':
                if (*++yyp != '\\')
                    goto do_not_strip_quotes;
                /* Fall through.  */
            default:
                if (yyres)
                    yyres[yyn] = *yyp;
                yyn++;
                break;

            case '"':
                if (yyres)
                    yyres[yyn] = '\0';
                return yyn;
            }
    do_not_strip_quotes:;
    }

    if (!yyres)
        return yystrlen(yystr);

    return yystpcpy(yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error(YYSIZE_T* yymsg_alloc, char** yymsg,
    yytype_int16* yyssp, int yytoken)
{
    YYSIZE_T yysize0 = yytnamerr(YY_NULL, yytname[yytoken]);
    YYSIZE_T yysize = yysize0;
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    /* Internationalized format string. */
    const char* yyformat = YY_NULL;
    /* Arguments of yyformat. */
    char const* yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
    /* Number of reported tokens (one for the "unexpected", one per
       "expected"). */
    int yycount = 0;

    /* There are many possibilities here to consider:
       - Assume YYFAIL is not used.  It's too flawed to consider.  See
         <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
         for details.  YYERROR is fine as it does not invoke this
         function.
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yychar) is if
         this state is a consistent state with a default action.  Thus,
         detecting the absence of a lookahead is sufficient to determine
         that there is no unexpected or expected token to report.  In that
         case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is a
         consistent state with a default action.  There might have been a
         previous inconsistent state, consistent state with a non-default
         action, or user semantic action that manipulated yychar.
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
    if (yytoken != YYEMPTY)
    {
        int yyn = yypact[*yyssp];
        yyarg[yycount++] = yytname[yytoken];
        if (!yypact_value_is_default(yyn))
        {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            /* Stay within bounds of both yycheck and yytname.  */
            int yychecklim = YYLAST - yyn + 1;
            int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
            int yyx;

            for (yyx = yyxbegin; yyx < yyxend; ++yyx)
                if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                    && !yytable_value_is_error(yytable[yyx + yyn]))
                {
                    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                        yycount = 1;
                        yysize = yysize0;
                        break;
                    }
                    yyarg[yycount++] = yytname[yyx];
                    {
                        YYSIZE_T yysize1 = yysize + yytnamerr(YY_NULL, yytname[yyx]);
                        if (!(yysize <= yysize1
                            && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                            return 2;
                        yysize = yysize1;
                    }
                }
        }
    }

    switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

    {
        YYSIZE_T yysize1 = yysize + yystrlen(yyformat);
        if (!(yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
            return 2;
        yysize = yysize1;
    }

    if (*yymsg_alloc < yysize)
    {
        *yymsg_alloc = 2 * yysize;
        if (!(yysize <= *yymsg_alloc
            && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
            *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
        return 1;
    }

    /* Avoid sprintf, as that infringes on the user's name space.
       Don't have undefined behavior even if the translation
       produced a string with the wrong number of "%s"s.  */
    {
        char* yyp = *yymsg;
        int yyi = 0;
        while ((*yyp = *yyformat) != '\0')
            if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
            {
                yyp += yytnamerr(yyp, yyarg[yyi++]);
                yyformat += 2;
            }
            else
            {
                yyp++;
                yyformat++;
            }
    }
    return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct(const char* yymsg, int yytype, YYSTYPE* yyvaluep)
#else
static void
yydestruct(yymsg, yytype, yyvaluep)
const char* yymsg;
int yytype;
YYSTYPE* yyvaluep;
#endif
{
    YYUSE(yyvaluep);

    if (!yymsg)
        yymsg = "Deleting";
    YY_SYMBOL_PRINT(yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
    {

    default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse(void* YYPARSE_PARAM)
#else
int
yyparse(YYPARSE_PARAM)
void* YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse(void)
#else
int
yyparse()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

       /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16* yyss;
    yytype_int16* yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE* yyvs;
    YYSTYPE* yyvsp;

    YYSIZE_T yystacksize;

    int yyn;
    int yyresult;
    /* Lookahead token as an internal (translated) token number.  */
    int yytoken = 0;
    /* The variables used to return semantic value and location from the
       action routines.  */
    YYSTYPE yyval;

#if YYERROR_VERBOSE
    /* Buffer for error messages, and its allocated size.  */
    char yymsgbuf[128];
    char* yymsg = yymsgbuf;
    YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

    /* The number of symbols on the RHS of the reduced rule.
       Keep to zero when no symbol should be popped.  */
    int yylen = 0;

    yyssp = yyss = yyssa;
    yyvsp = yyvs = yyvsa;
    yystacksize = YYINITDEPTH;

    YYDPRINTF((stderr, "Starting parse\n"));

    yystate = 0;
    yyerrstatus = 0;
    yynerrs = 0;
    yychar = YYEMPTY; /* Cause a token to be read.  */
    goto yysetstate;

    /*------------------------------------------------------------.
    | yynewstate -- Push a new state, which is found in yystate.  |
    `------------------------------------------------------------*/
yynewstate:
    /* In all cases, when you get here, the value and location stacks
       have just been pushed.  So pushing a state here evens the stacks.  */
    yyssp++;

yysetstate:
    *yyssp = yystate;

    if (yyss + yystacksize - 1 <= yyssp)
    {
        /* Get the current used size of the three stacks, in elements.  */
        YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
        {
            /* Give user a chance to reallocate the stack.  Use copies of
               these so that the &'s don't force the real ones into
               memory.  */
            YYSTYPE* yyvs1 = yyvs;
            yytype_int16* yyss1 = yyss;

            /* Each stack pointer address is followed by the size of the
               data in use in that stack, in bytes.  This used to be a
               conditional around just the two extra args, but that might
               be undefined if yyoverflow is a macro.  */
            yyoverflow(YY_("memory exhausted"),
                &yyss1, yysize * sizeof(*yyssp),
                &yyvs1, yysize * sizeof(*yyvsp),
                &yystacksize);

            yyss = yyss1;
            yyvs = yyvs1;
        }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
        goto yyexhaustedlab;
# else
        /* Extend the stack our own way.  */
        if (YYMAXDEPTH <= yystacksize)
            goto yyexhaustedlab;
        yystacksize *= 2;
        if (YYMAXDEPTH < yystacksize)
            yystacksize = YYMAXDEPTH;

        {
            yytype_int16* yyss1 = yyss;
            union yyalloc* yyptr =
                (union yyalloc*)YYSTACK_ALLOC(YYSTACK_BYTES(yystacksize));
            if (!yyptr)
                goto yyexhaustedlab;
            YYSTACK_RELOCATE(yyss_alloc, yyss);
            YYSTACK_RELOCATE(yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
            if (yyss1 != yyssa)
                YYSTACK_FREE(yyss1);
        }
# endif
#endif /* no yyoverflow */

        yyssp = yyss + yysize - 1;
        yyvsp = yyvs + yysize - 1;

        YYDPRINTF((stderr, "Stack size increased to %lu\n",
            (unsigned long int) yystacksize));

        if (yyss + yystacksize - 1 <= yyssp)
            YYABORT;
    }

    YYDPRINTF((stderr, "Entering state %d\n", yystate));

    if (yystate == YYFINAL)
        YYACCEPT;

    goto yybackup;

    /*-----------.
    | yybackup.  |
    `-----------*/
yybackup:

    /* Do appropriate processing given the current state.  Read a
       lookahead token if we need one and don't already have one.  */

       /* First try to decide what to do without reference to lookahead token.  */
    yyn = yypact[yystate];
    if (yypact_value_is_default(yyn))
        goto yydefault;

    /* Not known => get a lookahead token if don't already have one.  */

    /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
    if (yychar == YYEMPTY)
    {
        YYDPRINTF((stderr, "Reading a token: "));
        yychar = YYLEX;
    }

    if (yychar <= YYEOF)
    {
        yychar = yytoken = YYEOF;
        YYDPRINTF((stderr, "Now at end of input.\n"));
    }
    else
    {
        yytoken = YYTRANSLATE(yychar);
        YY_SYMBOL_PRINT("Next token is", yytoken, &yylval, &yylloc);
    }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
        goto yydefault;
    yyn = yytable[yyn];
    if (yyn <= 0)
    {
        if (yytable_value_is_error(yyn))
            goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
    }

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus)
        yyerrstatus--;

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the shifted token.  */
    yychar = YYEMPTY;

    yystate = yyn;
    YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
        * ++yyvsp = yylval;
    YY_IGNORE_MAYBE_UNINITIALIZED_END

        goto yynewstate;


    /*-----------------------------------------------------------.
    | yydefault -- do the default action for the current state.  |
    `-----------------------------------------------------------*/
yydefault:
    yyn = yydefact[yystate];
    if (yyn == 0)
        goto yyerrlab;
    goto yyreduce;


    /*-----------------------------.
    | yyreduce -- Do a reduction.  |
    `-----------------------------*/
yyreduce:
    /* yyn is the number of a rule to reduce with.  */
    yylen = yyr2[yyn];

    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  Assigning to YYVAL
       unconditionally makes the parser a bit smaller, and it avoids a
       GCC warning that YYVAL may be used uninitialized.  */
    yyval = yyvsp[1 - yylen];


    YY_REDUCE_PRINT(yyn);
    switch (yyn)
    {
    case 2:
        /* Line 1792 of yacc.c  */
#line 88 "cute.y"
    { if (errorcnt == 0) { codegen((yyvsp[(2) - (3)])); dwgen(); } }
    break;

    case 3:
        /* Line 1792 of yacc.c  */
#line 91 "cute.y"
    { (yyval) = MakeListTree((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

    case 4:
        /* Line 1792 of yacc.c  */
#line 92 "cute.y"
    { (yyval) = MakeListTree(NULL, (yyvsp[(1) - (1)])); }
    break;

    case 5:
        /* Line 1792 of yacc.c  */
#line 93 "cute.y"
    { errorcnt++; yyerrok; }
    break;

    case 6:
        /* Line 1792 of yacc.c  */
#line 96 "cute.y"
    { (yyvsp[(1) - (5)])->token = ID2; (yyval) = MakeOPTree(ASSGN, (yyvsp[(1) - (5)]), (yyvsp[(3) - (5)])); }
    break;

    case 7:
        /* Line 1792 of yacc.c  */
#line 97 "cute.y"
    { (yyval) = MakeOPTree(WHILE, (yyvsp[(1) - (5)]), (yyvsp[(3) - (5)])); }
    break;

    case 8:
        /* Line 1792 of yacc.c  */
#line 98 "cute.y"
    { (yyval) = MakeOPTree(TERN, (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

    case 9:
        /* Line 1792 of yacc.c  */
#line 99 "cute.y"
    { (yyvsp[(1) - (3)])->token = ID3; (yyval) = MakeOPTree(AA, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

    case 10:
        /* Line 1792 of yacc.c  */
#line 100 "cute.y"
    { (yyvsp[(1) - (3)])->token = ID3; (yyval) = MakeOPTree(SA, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

    case 11:
        /* Line 1792 of yacc.c  */
#line 101 "cute.y"
    { (yyvsp[(1) - (3)])->token = ID3; (yyval) = MakeOPTree(MA, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

    case 12:
        /* Line 1792 of yacc.c  */
#line 102 "cute.y"
    { (yyvsp[(1) - (3)])->token = ID3; (yyval) = MakeOPTree(DA, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

    case 13:
        /* Line 1792 of yacc.c  */
#line 103 "cute.y"
    { (yyval) = MakeOPTree(FUNC, (yyvsp[(6) - (11)]), NULL); }
    break;

    case 14:
        /* Line 1792 of yacc.c  */
#line 104 "cute.y"
    { (yyval) = MakeOPTree(FOR, (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

    case 15:
        /* Line 1792 of yacc.c  */
#line 105 "cute.y"
    { (yyvsp[(1) - (3)])->token = ID2; (yyval) = MakeOPTree(SCAN, (yyvsp[(1) - (3)]), NULL); }
    break;

    case 16:
        /* Line 1792 of yacc.c  */
#line 106 "cute.y"
    { (yyval) = MakeOPTree(PRINT, (yyvsp[(1) - (3)]), NULL); }
    break;

    case 17:
        /* Line 1792 of yacc.c  */
#line 107 "cute.y"
    { (yyval) = MakeOPTree(SWAPE, (yyvsp[(1) - (2)]), NULL); }
    break;

    case 18:
        /* Line 1792 of yacc.c  */
#line 108 "cute.y"
    { (yyval) = MakeOPTree(IF_ELSE, (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

    case 22:
        /* Line 1792 of yacc.c  */
#line 112 "cute.y"
    { (yyval) = MakeOPTree(SWITCH, (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

    case 23:
        /* Line 1792 of yacc.c  */
#line 115 "cute.y"
    { (yyvsp[(1) - (2)])->token = ID6; (yyval) = MakeOPTree(INC, (yyvsp[(1) - (2)]), NULL); }
    break;

    case 24:
        /* Line 1792 of yacc.c  */
#line 116 "cute.y"
    { (yyvsp[(1) - (2)])->token = ID7; (yyval) = MakeOPTree(DEC, (yyvsp[(1) - (2)]), NULL); }
    break;

    case 25:
        /* Line 1792 of yacc.c  */
#line 119 "cute.y"
    { (yyvsp[(2) - (4)])->token = ID4; (yyval) = MakeOPTree(SWITCHH, (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)])); }
    break;

    case 26:
        /* Line 1792 of yacc.c  */
#line 122 "cute.y"
    { (yyval) = MakeListTree((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

    case 27:
        /* Line 1792 of yacc.c  */
#line 123 "cute.y"
    { (yyval) = MakeListTree(NULL, (yyvsp[(1) - (1)])); }
    break;

    case 28:
        /* Line 1792 of yacc.c  */
#line 126 "cute.y"
    { (yyval) = MakeOPTree(DEFAULT, (yyvsp[(3) - (4)]), NULL); }
    break;

    case 29:
        /* Line 1792 of yacc.c  */
#line 129 "cute.y"
    { (yyval) = MakeOPTree(CASEH, (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)])); }
    break;

    case 30:
        /* Line 1792 of yacc.c  */
#line 132 "cute.y"
    { (yyval) = MakeOPTree(CASEM, (yyvsp[(3) - (3)]), (yyvsp[(1) - (3)])); }
    break;

    case 31:
        /* Line 1792 of yacc.c  */
#line 135 "cute.y"
    { (yyval) = MakeNode(CASEL, CASEL); }
    break;

    case 32:
        /* Line 1792 of yacc.c  */
#line 138 "cute.y"
    { (yyvsp[(2) - (2)])->token = ID5; (yyval) = MakeOPTree(SWAPH, (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

    case 33:
        /* Line 1792 of yacc.c  */
#line 140 "cute.y"
    { (yyvsp[(1) - (3)])->token = ID5; (yyval) = MakeOPTree(SWAPM, (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)])); }
    break;

    case 34:
        /* Line 1792 of yacc.c  */
#line 143 "cute.y"
    { (yyval) = MakeNode(SWAPS, SWAPS); }
    break;

    case 35:
        /* Line 1792 of yacc.c  */
#line 146 "cute.y"
    { (yyval) = MakeOPTree(TSTMT, (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)])); }
    break;

    case 36:
        /* Line 1792 of yacc.c  */
#line 149 "cute.y"
    { (yyval) = MakeOPTree(TEX, (yyvsp[(1) - (4)]), (yyvsp[(2) - (4)])); }
    break;

    case 37:
        /* Line 1792 of yacc.c  */
#line 152 "cute.y"
    { (yyval) = MakeNode(TLVAL, TLVAL); }
    break;

    case 38:
        /* Line 1792 of yacc.c  */
#line 155 "cute.y"
    { (yyvsp[(3) - (3)])->token = t_cond_check((yyvsp[(3) - (3)])->token); (yyvsp[(1) - (3)])->token = ID4; (yyval) = MakeOPTree(TCON, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

    case 39:
        /* Line 1792 of yacc.c  */
#line 157 "cute.y"
    { (yyval) = MakeOPTree(FORSTLI, (yyvsp[(5) - (7)]), (yyvsp[(2) - (7)])); }
    break;

    case 40:
        /* Line 1792 of yacc.c  */
#line 160 "cute.y"
    { (yyvsp[(2) - (2)])->token = f_cond_check((yyvsp[(2) - (2)])->token); (yyval) = MakeOPTree(FORCON, (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

    case 41:
        /* Line 1792 of yacc.c  */
#line 162 "cute.y"
    { (yyval) = MakeOPTree(FORSTART, (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

    case 42:
        /* Line 1792 of yacc.c  */
#line 165 "cute.y"
    { (yyval) = MakeOPTree(FSTMT, (yyvsp[(2) - (2)]), (yyvsp[(1) - (2)])); }
    break;

    case 43:
        /* Line 1792 of yacc.c  */
#line 167 "cute.y"
    { (yyval) = MakeNode(FLOOPEND, FLOOPEND); }
    break;

    case 44:
        /* Line 1792 of yacc.c  */
#line 169 "cute.y"
    { (yyval) = MakeNode(FUNCEND, FUNCEND); }
    break;

    case 45:
        /* Line 1792 of yacc.c  */
#line 172 "cute.y"
    { (yyval) = MakeNode(CALLBACK, CALLBACK); }
    break;

    case 46:
        /* Line 1792 of yacc.c  */
#line 175 "cute.y"
    { (yyvsp[(1) - (2)])->token = w_cond_check((yyvsp[(1) - (2)])->token); (yyval) = MakeOPTree(LOOPCON, (yyvsp[(2) - (2)]), (yyvsp[(1) - (2)])); }
    break;

    case 47:
        /* Line 1792 of yacc.c  */
#line 177 "cute.y"
    { (yyval) = MakeNode(WLOOPEND, WLOOPEND); }
    break;

    case 48:
        /* Line 1792 of yacc.c  */
#line 180 "cute.y"
    { (yyvsp[(2) - (6)])->token = if_cond_check((yyvsp[(2) - (6)])->token); (yyval) = MakeOPTree(IF, (yyvsp[(2) - (6)]), (yyvsp[(4) - (6)])); }
    break;

    case 49:
        /* Line 1792 of yacc.c  */
#line 183 "cute.y"
    { (yyval) = MakeOPTree(ELSE, (yyvsp[(3) - (5)]), NULL); }
    break;

    case 50:
        /* Line 1792 of yacc.c  */
#line 187 "cute.y"
    { (yyval) = MakeOPTree(EQ, (yyvsp[(1) - (5)]), (yyvsp[(3) - (5)])); }
    break;

    case 51:
        /* Line 1792 of yacc.c  */
#line 188 "cute.y"
    { (yyval) = MakeOPTree(LT, (yyvsp[(1) - (5)]), (yyvsp[(3) - (5)])); }
    break;

    case 52:
        /* Line 1792 of yacc.c  */
#line 189 "cute.y"
    { (yyval) = MakeOPTree(GT, (yyvsp[(1) - (5)]), (yyvsp[(3) - (5)])); }
    break;

    case 53:
        /* Line 1792 of yacc.c  */
#line 190 "cute.y"
    { (yyval) = MakeOPTree(LE, (yyvsp[(1) - (5)]), (yyvsp[(3) - (5)])); }
    break;

    case 54:
        /* Line 1792 of yacc.c  */
#line 191 "cute.y"
    { (yyval) = MakeOPTree(GE, (yyvsp[(1) - (5)]), (yyvsp[(3) - (5)])); }
    break;

    case 55:
        /* Line 1792 of yacc.c  */
#line 192 "cute.y"
    { (yyval) = MakeOPTree(NE, (yyvsp[(1) - (5)]), (yyvsp[(3) - (5)])); }
    break;

    case 56:
        /* Line 1792 of yacc.c  */
#line 197 "cute.y"
    { (yyval) = MakeOPTree(ADD, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

    case 57:
        /* Line 1792 of yacc.c  */
#line 198 "cute.y"
    { (yyval) = MakeOPTree(SUB, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

    case 59:
        /* Line 1792 of yacc.c  */
#line 203 "cute.y"
    { (yyval) = MakeOPTree(MUL, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

    case 60:
        /* Line 1792 of yacc.c  */
#line 204 "cute.y"
    { (yyval) = MakeOPTree(DIV, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

    case 62:
        /* Line 1792 of yacc.c  */
#line 210 "cute.y"
    { /* ID node is created in lex */ }
    break;

    case 63:
        /* Line 1792 of yacc.c  */
#line 211 "cute.y"
    { /* NUM node is created in lex */ }
    break;


    /* Line 1792 of yacc.c  */
#line 2030 "cute.c"
    default: break;
    }
    /* User semantic actions sometimes alter yychar, and that requires
       that yytoken be updated with the new translation.  We take the
       approach of translating immediately before every use of yytoken.
       One alternative is translating here after every semantic action,
       but that translation would be missed if the semantic action invokes
       YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
       if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
       incorrect destructor might then be invoked immediately.  In the
       case of YYERROR or YYBACKUP, subsequent parser actions might lead
       to an incorrect destructor call or verbose syntax error message
       before the lookahead is translated.  */
    YY_SYMBOL_PRINT("-> $$ =", yyr1[yyn], &yyval, &yyloc);

    YYPOPSTACK(yylen);
    yylen = 0;
    YY_STACK_PRINT(yyss, yyssp);

    *++yyvsp = yyval;

    /* Now `shift' the result of the reduction.  Determine what state
       that goes to, based on the state we popped back to and the rule
       number reduced by.  */

    yyn = yyr1[yyn];

    yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
    if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
        yystate = yytable[yystate];
    else
        yystate = yydefgoto[yyn - YYNTOKENS];

    goto yynewstate;


    /*------------------------------------.
    | yyerrlab -- here on detecting error |
    `------------------------------------*/
yyerrlab:
    /* Make sure we have latest lookahead translation.  See comments at
       user semantic actions for why this is necessary.  */
    yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE(yychar);

    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus)
    {
        ++yynerrs;
#if ! YYERROR_VERBOSE
        yyerror(YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
        {
            char const* yymsgp = YY_("syntax error");
            int yysyntax_error_status;
            yysyntax_error_status = YYSYNTAX_ERROR;
            if (yysyntax_error_status == 0)
                yymsgp = yymsg;
            else if (yysyntax_error_status == 1)
            {
                if (yymsg != yymsgbuf)
                    YYSTACK_FREE(yymsg);
                yymsg = (char*)YYSTACK_ALLOC(yymsg_alloc);
                if (!yymsg)
                {
                    yymsg = yymsgbuf;
                    yymsg_alloc = sizeof yymsgbuf;
                    yysyntax_error_status = 2;
                }
                else
                {
                    yysyntax_error_status = YYSYNTAX_ERROR;
                    yymsgp = yymsg;
                }
            }
            yyerror(yymsgp);
            if (yysyntax_error_status == 2)
                goto yyexhaustedlab;
        }
# undef YYSYNTAX_ERROR
#endif
    }



    if (yyerrstatus == 3)
    {
        /* If just tried and failed to reuse lookahead token after an
       error, discard it.  */

        if (yychar <= YYEOF)
        {
            /* Return failure if at end of input.  */
            if (yychar == YYEOF)
                YYABORT;
        }
        else
        {
            yydestruct("Error: discarding",
                yytoken, &yylval);
            yychar = YYEMPTY;
        }
    }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


    /*---------------------------------------------------.
    | yyerrorlab -- error raised explicitly by YYERROR.  |
    `---------------------------------------------------*/
yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (/*CONSTCOND*/ 0)
        goto yyerrorlab;

    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    YYPOPSTACK(yylen);
    yylen = 0;
    YY_STACK_PRINT(yyss, yyssp);
    yystate = *yyssp;
    goto yyerrlab1;


    /*-------------------------------------------------------------.
    | yyerrlab1 -- common code for both syntax error and YYERROR.  |
    `-------------------------------------------------------------*/
yyerrlab1:
    yyerrstatus = 3;	/* Each real token shifted decrements this.  */

    for (;;)
    {
        yyn = yypact[yystate];
        if (!yypact_value_is_default(yyn))
        {
            yyn += YYTERROR;
            if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
                yyn = yytable[yyn];
                if (0 < yyn)
                    break;
            }
        }

        /* Pop the current state because it cannot handle the error token.  */
        if (yyssp == yyss)
            YYABORT;


        yydestruct("Error: popping",
            yystos[yystate], yyvsp);
        YYPOPSTACK(1);
        yystate = *yyssp;
        YY_STACK_PRINT(yyss, yyssp);
    }

    YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
        * ++yyvsp = yylval;
    YY_IGNORE_MAYBE_UNINITIALIZED_END


        /* Shift the error token.  */
        YY_SYMBOL_PRINT("Shifting", yystos[yyn], yyvsp, yylsp);

    yystate = yyn;
    goto yynewstate;


    /*-------------------------------------.
    | yyacceptlab -- YYACCEPT comes here.  |
    `-------------------------------------*/
yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /*-----------------------------------.
    | yyabortlab -- YYABORT comes here.  |
    `-----------------------------------*/
yyabortlab:
    yyresult = 1;
    goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
    /*-------------------------------------------------.
    | yyexhaustedlab -- memory exhaustion comes here.  |
    `-------------------------------------------------*/
yyexhaustedlab:
    yyerror(YY_("memory exhausted"));
    yyresult = 2;
    /* Fall through.  */
#endif

yyreturn:
    if (yychar != YYEMPTY)
    {
        /* Make sure we have latest lookahead translation.  See comments at
           user semantic actions for why this is necessary.  */
        yytoken = YYTRANSLATE(yychar);
        yydestruct("Cleanup: discarding lookahead",
            yytoken, &yylval);
    }
    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    YYPOPSTACK(yylen);
    YY_STACK_PRINT(yyss, yyssp);
    while (yyssp != yyss)
    {
        yydestruct("Cleanup: popping",
            yystos[*yyssp], yyvsp);
        YYPOPSTACK(1);
    }
#ifndef yyoverflow
    if (yyss != yyssa)
        YYSTACK_FREE(yyss);
#endif
#if YYERROR_VERBOSE
    if (yymsg != yymsgbuf)
        YYSTACK_FREE(yymsg);
#endif
    /* Make sure YYID is used.  */
    return YYID(yyresult);
}


/* Line 2055 of yacc.c  */
#line 215 "cute.y"

int main(int argc, char* argv[])
{
    printf("\nsample CBU compiler v3.0\n");
    printf("(C) Copyright by Jae Sung Lee (jasonlee@cbnu.ac.kr), 2025.\n");

    if (argc == 2)
        yyin = fopen(argv[1], "r");
    else {
        printf("Usage: cbc3 inputfile\noutput file is 'a.asm'\n");
        return(0);
    }

    fp = fopen("a.asm", "w");

    yyparse();

    fclose(yyin);
    fclose(fp);

    if (errorcnt == 0)
    {
        printf("Successfully compiled. Assembly code is in 'a.asm'.\n");
    }
}

void yyerror(char* s)
{
    printf("%s (line %d)\n", s, lineno);
}


Node* MakeOPTree(int op, Node* operand1, Node* operand2)
{
    Node* newnode;

    newnode = (Node*)malloc(sizeof(Node));
    newnode->token = op;
    newnode->tokenval = op;
    newnode->son = operand1;
    newnode->brother = NULL;
    operand1->brother = operand2;
    return newnode;
}

Node* MakeNode(int token, int operand)
{
    Node* newnode;

    newnode = (Node*)malloc(sizeof(Node));
    newnode->token = token;
    newnode->tokenval = operand;
    newnode->son = newnode->brother = NULL;
    return newnode;
}

Node* MakeListTree(Node* operand1, Node* operand2)
{
    Node* newnode;
    Node* node;

    if (operand1 == NULL) {
        newnode = (Node*)malloc(sizeof(Node));
        newnode->token = newnode->tokenval = STMTLIST;
        newnode->son = operand2;
        newnode->brother = NULL;
        return newnode;
    }
    else {
        node = operand1->son;
        while (node->brother != NULL) node = node->brother;
        node->brother = operand2;
        return operand1;
    }
}

void codegen(Node* root)
{
    DFSTree(root);
}

void DFSTree(Node* n)
{
    Node* brother;
    if (n == NULL) return;

    DFSTree(n->son);
    if (n->token == IF) {
        inner_if_cnt = count_if_nodes(n->son);
        if (n->brother != NULL) {
            if (n->brother->token == ELSE) {
                fprintf(fp, "GOTO ELSELABEL%d\n", (++ife_cnt));
            }
        }
    }

    if (n->token == WHILE)
        inner_w_cnt = count_while_nodes(n->son);

    if (n->token == FOR)
        inner_f_cnt = count_f_nodes(n->son);

    if (n->token == ELSE)
        inner_e_cnt = count_e_nodes(n->son);

    prtcode(n->token, n->tokenval);
    DFSTree(n->brother);

}

int if_cond_check(int token)
{
    if (token == EQ) return IF_EQ;
    if (token == LT) return IF_LT;
    if (token == LE) return IF_LE;
    if (token == GT) return IF_GT;
    if (token == GE) return IF_GE;
    if (token == NE) return IF_NE;
}

int w_cond_check(int token)
{
    if (token == EQ) return W_EQ;
    if (token == LT) return W_LT;
    if (token == LE) return W_LE;
    if (token == GT) return W_GT;
    if (token == GE) return W_GE;
    if (token == NE) return W_NE;
}

int f_cond_check(int token)
{
    if (token == EQ) return F_EQ;
    if (token == LT) return F_LT;
    if (token == LE) return F_LE;
    if (token == GT) return F_GT;
    if (token == GE) return F_GE;
    if (token == NE) return F_NE;
}

int t_cond_check(int token)
{
    if (token == EQ) return T_EQ;
    if (token == LT) return T_LT;
    if (token == LE) return T_LE;
    if (token == GT) return T_GT;
    if (token == GE) return T_GE;
    if (token == NE) return T_NE;
}

int count_if_nodes(Node* n) {
    if (n == NULL)
        return 0;

    int count = 0;

    if (n->token == IF)
        count++;

    count += count_if_nodes(n->son);
    count += count_if_nodes(n->brother);

    return count;
}

int count_while_nodes(Node* n) {
    if (n == NULL)
        return 0;

    int count = 0;

    if (n->token == WHILE)
        count++;

    count += count_while_nodes(n->son);
    count += count_while_nodes(n->brother);

    return count;
}

int count_f_nodes(Node* n) {
    if (n == NULL)
        return 0;


    int count = 0;

    if (n->token == FOR)
        count++;

    count += count_f_nodes(n->son);
    count += count_f_nodes(n->brother);

    return count;
}

int count_e_nodes(Node* n) {
    if (n == NULL)
        return 0;


    int count = 0;

    if (n->token == ELSE)
        count++;

    count += count_e_nodes(n->son);
    count += count_e_nodes(n->brother);

    return count;
}


void prtcode(int token, int val)
{

    switch (token) {
    case ID:
        fprintf(fp, "RVALUE %s\n", symtbl[val]);
        break;
    case ID2:
        fprintf(fp, "LVALUE %s\n", symtbl[val]);
        break;
    case ID3:
        fprintf(fp, "LVALUE %s\n", symtbl[val]);
        fprintf(fp, "RVALUE %s\n", symtbl[val]);
        break;
    case ID4:
        strcpy(str, symtbl[val]);
        break;
    case ID5:
        fprintf(fp, "RVALUE %s\n", symtbl[val]);
        fprintf(fp, ":=\n");
        fprintf(fp, "LVALUE %s\n", symtbl[val]);
        break;
    case ID6:
        fprintf(fp, "LVALUE %s\n", symtbl[val]);
        fprintf(fp, "RVALUE %s\n", symtbl[val]);
        fprintf(fp, "PUSH 1\n");
        fprintf(fp, "+\n");
        fprintf(fp, ":=\n");
        break;
    case ID7:
        fprintf(fp, "LVALUE %s\n", symtbl[val]);
        fprintf(fp, "RVALUE %s\n", symtbl[val]);
        fprintf(fp, "PUSH 1");
        fprintf(fp, "-\n");
        fprintf(fp, ":=\n");
        break;
    case NUM:
        fprintf(fp, "PUSH %d\n", val);
        break;
    case ADD:
        fprintf(fp, "+\n");
        break;
    case SUB:
        fprintf(fp, "-\n");
        break;
    case MUL:
        fprintf(fp, "*\n");
        break;
    case DIV:
        fprintf(fp, "/\n");
        break;
    case ASSGN:
        fprintf(fp, ":=\n");
        break;
    case IF:
        fprintf(fp, "LABEL IFLABEL%d\n", if_cnt - inner_if_cnt);
        break;
    case IF_ELSE:
        fprintf(fp, "LABEL ELSELABEL%d\n", ife_cnt - inner_e_cnt);
        break;
    case IF_EQ:
        fprintf(fp, "-\n");
        fprintf(fp, "GOTRUE IFLABEL%d\n", ++if_cnt);
        break;
    case IF_NE:
        fprintf(fp, "-\n");
        fprintf(fp, "GOFALSE IFLABEL%d\n", ++if_cnt);
        break;
    case IF_LT:
        fprintf(fp, "-\n");
        fprintf(fp, "COPY\n");
        fprintf(fp, "GOPLUS IFLABEL%d\n", ++if_cnt);
        fprintf(fp, "GOFALSE IFLABEL%d\n", if_cnt);
        break;
    case IF_GT:
        fprintf(fp, "-\n");
        fprintf(fp, "COPY\n");
        fprintf(fp, "GOMINUS IFLABEL%d\n", ++if_cnt);
        fprintf(fp, "GOFALSE IFLABEL%d\n", if_cnt);
        break;
    case IF_LE:
        fprintf(fp, "-\n");
        fprintf(fp, "GOPLUS IFLABEL%d\n", ++if_cnt);
        break;
    case IF_GE:
        fprintf(fp, "-\n");
        fprintf(fp, "GOMINUS WLABEL%d\n", ++if_cnt);
        break;
    case W_EQ:
        fprintf(fp, "-\n");
        fprintf(fp, "GOTRUE WLABEL%d\n", ++w_c_cnt);
        break;
    case W_NE:
        fprintf(fp, "-\n");
        fprintf(fp, "GOFALSE WLABEL%d\n", ++w_c_cnt);
        break;
    case W_LT:
        fprintf(fp, "-\n");
        fprintf(fp, "COPY\n");
        fprintf(fp, "GOPLUS WLABEL%d\n", ++w_c_cnt);
        fprintf(fp, "GOFALSE WLABEL%d\n", w_c_cnt);
        break;
    case W_GT:
        fprintf(fp, "-\n");
        fprintf(fp, "COPY\n");
        fprintf(fp, "GOMINUS WLABEL%d\n", ++w_c_cnt);
        fprintf(fp, "GOFALSE WLABEL%d\n", w_c_cnt);
        break;
    case W_LE:
        fprintf(fp, "-\n");
        fprintf(fp, "GOPLUS WLABEL%d\n", ++w_c_cnt);
        break;
    case W_GE:
        fprintf(fp, "-\n");
        fprintf(fp, "GOMINUS WLABEL%d\n", ++w_c_cnt);
        break;
    case F_EQ:
        fprintf(fp, "-\n");
        fprintf(fp, "GOTRUE FLABEL%d\n", ++f_c_cnt);
        break;
    case F_NE:
        fprintf(fp, "-\n");
        fprintf(fp, "GOFALSE FLABEL%d\n", ++f_c_cnt);
        break;
    case F_LT:
        fprintf(fp, "-\n");
        fprintf(fp, "COPY\n");
        fprintf(fp, "GOPLUS FLABEL%d\n", ++f_c_cnt);
        fprintf(fp, "GOFALSE FLABEL%d\n", f_c_cnt);
        break;
    case F_GT:
        fprintf(fp, "-\n");
        fprintf(fp, "COPY\n");
        fprintf(fp, "GOMINUS FLABEL%d\n", ++f_c_cnt);
        fprintf(fp, "GOFALSE FLABEL%d\n", f_c_cnt);
        break;
    case F_LE:
        fprintf(fp, "-\n");
        fprintf(fp, "GOPLUS FLABEL%d\n", ++f_c_cnt);
        break;
    case F_GE:
        fprintf(fp, "-\n");
        fprintf(fp, "GOMINUS FLABEL%d\n", ++f_c_cnt);
        break;
    case T_EQ:
        fprintf(fp, "-\n");
        fprintf(fp, "GOTRUE TL%d\n", ++tl_cnt);
        break;
    case T_NE:
        fprintf(fp, "-\n");
        fprintf(fp, "GOFALSE TL%d\n", ++tl_cnt);
        break;
    case T_LT:
        fprintf(fp, "-\n");
        fprintf(fp, "COPY\n");
        fprintf(fp, "GOPLUS TL%d\n", ++tl_cnt);
        fprintf(fp, "GOFALSE TL%d\n", tl_cnt);
        break;
    case T_GT:
        fprintf(fp, "-\n");
        fprintf(fp, "COPY\n");
        fprintf(fp, "GOMINUS TL%d\n", ++tl_cnt);
        fprintf(fp, "GOFALSE TL%d\n", tl_cnt);
        break;
    case T_LE:
        fprintf(fp, "-\n");
        fprintf(fp, "GOPLUS TL%d\n", ++tl_cnt);
        break;
    case T_GE:
        fprintf(fp, "-\n");
        fprintf(fp, "GOMINUS TL%d\n", ++tl_cnt);
        break;
    case AA:
        fprintf(fp, "+\n");
        fprintf(fp, ":=\n");
        break;
    case SA:
        fprintf(fp, "-\n");
        fprintf(fp, ":=\n");
        break;
    case MA:
        fprintf(fp, "*\n");
        fprintf(fp, ":=\n");
        break;
    case DA:
        fprintf(fp, "/\n");
        fprintf(fp, ":=\n");
        break;
    case WLOOPEND:
        fprintf(fp, "LABEL WLOOP%d\n", ++w_cnt);
        break;
    case FLOOPEND:
        fprintf(fp, "LABEL FLOOP%d\n", ++for_cnt);
        break;
    case FUNCEND:
        fprintf(fp, "GOTO FUNCLABEL%d\n", ++f_cnt);
        fprintf(fp, "LABEL CALLBACK%d\n", cb_cnt);
        cb_cnt--;
        break;
    case FUNC:
        fprintf(fp, "GOTO FUNCOUT%d\n", ++fe_cnt);
        fprintf(fp, "LABEL FUNCLABEL%d\n", f_cnt--);
        f_cnt--;
        break;
    case CALLBACK:
        fprintf(fp, "GOTO CALLBACK%d\n", cb_cnt + 1);
        fprintf(fp, "LABEL FUNCOUT%d\n", fe_cnt);
        fe_cnt--;
        break;
    case WHILE:
        fprintf(fp, "GOTO WLOOP%d\n", w_cnt - inner_w_cnt);
        fprintf(fp, "LABEL WLABEL%d\n", w_c_cnt - inner_w_cnt);
        break;
    case FOR:
        fprintf(fp, "GOTO FLOOP%d\n", for_cnt - inner_f_cnt);
        fprintf(fp, "LABEL FLABEL%d\n", f_c_cnt - inner_f_cnt);
        cnt--;
        break;
    case TEX:
        fprintf(fp, ":=\n");
        break;
    case TLVAL:
        fprintf(fp, "LVALUE %s\n", str);
        break;
    case TSTMT:
        fprintf(fp, "GOTO TOUT%d\n", tl_cnt);
        fprintf(fp, "LABEL TL%d\n", tl_cnt);
        break;
    case TERN:
        fprintf(fp, "LABEL TOUT%d\n", tl_cnt);
        break;
    case SCAN:
        fprintf(fp, "INNUM\n");
        fprintf(fp, ":=\n");
        break;
    case PRINT:
        fprintf(fp, "OUTNUM\n");
        break;
    case SWAPS:
        insertsym("TEMP");
        fprintf(fp, "LVALUE TEMP\n");
        break;
    case SWAPE:
        fprintf(fp, "RVALUE TEMP\n");
        fprintf(fp, ":=\n");
        break;
    case CASEL:
        fprintf(fp, "RVALUE %s\n", str);
        break;
    case CASEM:
        fprintf(fp, "-\n");
        fprintf(fp, "GOTRUE CLABEL%d\n", ++case_cnt);
        break;
    case CASEH:
        fprintf(fp, "GOTO SLABEL%d\n", s_cnt);
        fprintf(fp, "LABEL CLABEL%d\n", case_cnt);
        break;
    case SWITCH:
        fprintf(fp, "LABEL SLABEL%d\n", s_cnt++);
        break;
    case STMTLIST:
    default:
        break;
    };
}


/*
int gentemp()
{
char buffer[MAXTSYMLEN];
char tempsym[MAXSYMLEN]="TTCBU";

    tsymbolcnt++;
    if (tsymbolcnt > MAXTSYMBOL) printf("temp symbol overflow\n");
    itoa(tsymbolcnt, buffer, 10);
    strcat(tempsym, buffer);
    return( insertsym(tempsym) ); // Warning: duplicated symbol is not checked for lazy implementation
}
*/
void dwgen()
{
    int i;
    fprintf(fp, "HALT\n");
    fprintf(fp, "$ -- END OF EXECUTION CODE AND START OF VAR DEFINITIONS --\n");

    // Warning: this code should be different if variable declaration is supported in the language 
    for (i = 0; i < maxsym; i++)
        fprintf(fp, "DW %s\n", symtbl[i]);
    fprintf(fp, "END\n");
}
