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
#line 1 "compiler.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// External functions and variables from lexer
extern int yylex(void);
extern int yylineno;
extern char* yytext; // For error reporting

void yyerror(const char* s);

// Forward declarations for symbol table and code generation (conceptual)
// These would be implemented in separate .c files
// --- Symbol Table (Illustrative) ---
typedef struct Symbol {
    char* name;
    int type; // e.g., TYPE_INT, TYPE_CHAR, TYPE_ARRAY, TYPE_FUNCTION
    int scope_level;
    int address; // e.g., stack offset or global address
    int size; // For arrays
    // For functions: list of param types, return type
    struct Symbol* next;
} Symbol;

Symbol* symbol_table_head = NULL;
int current_scope_level = 0;
int next_address_global = 0;
int next_address_local = 0; // Relative to frame pointer

void add_symbol(const char* name, int type, int size_or_val); // Simplified
Symbol* lookup_symbol(const char* name); // Simplified

// --- Code Generation (Illustrative labels/opcodes) ---
int label_count = 0;
char* new_label() {
    char* lbl = (char*)malloc(10);
    sprintf(lbl, "L%d", label_count++);
    return lbl;
}

// Placeholder for printf instructions (emitted to stdout for now)
#define EMIT(...) printf(__VA_ARGS__); printf("\n")

// Placeholder for function argument count tracking
int current_arg_count = 0;


/* Line 371 of yacc.c  */
#line 117 "compiler.c"

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
   by #include "compiler.h".  */
#ifndef YY_YY_COMPILER_H_INCLUDED
# define YY_YY_COMPILER_H_INCLUDED
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
    T_IDENTIFIER = 258,
    T_INTEGER_CONSTANT = 259,
    T_CHARACTER_CONSTANT = 260,
    T_STRING_LITERAL = 261,
    T_INT = 262,
    T_CHAR = 263,
    T_VOID = 264,
    T_IF = 265,
    T_ELSE = 266,
    T_WHILE = 267,
    T_FOR = 268,
    T_DO = 269,
    T_SWITCH = 270,
    T_CASE = 271,
    T_DEFAULT = 272,
    T_BREAK = 273,
    T_CONTINUE = 274,
    T_RETURN = 275,
    T_PRINT = 276,
    T_PRINTF = 277,
    T_SCANF = 278,
    T_ADD_ASSIGN = 279,
    T_SUB_ASSIGN = 280,
    T_MUL_ASSIGN = 281,
    T_DIV_ASSIGN = 282,
    T_MOD_ASSIGN = 283,
    T_INC = 284,
    T_DEC = 285,
    T_EQ = 286,
    T_NE = 287,
    T_LE = 288,
    T_GE = 289,
    T_AND = 290,
    T_OR = 291,
    T_LSHIFT = 292,
    T_RSHIFT = 293
};
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
    /* Line 387 of yacc.c  */
#line 51 "compiler.y"

    int ival;
    char* sval;
    // You might add nodes for an AST if building one
    struct { int type; char* name; } type_id; // For declarations
    struct { char* truelist; char* falselist; char* nextlist; } controllists; // For control flow backpatching


    /* Line 387 of yacc.c  */
#line 207 "compiler.c"
} YYSTYPE;
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

#endif /* !YY_YY_COMPILER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 235 "compiler.c"

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   306

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  70
/* YYNRULES -- Number of rules.  */
#define YYNRULES  152
/* YYNRULES -- Number of states.  */
#define YYNSTATES  264

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,     2,     2,    51,    44,     2,
      60,    61,    49,    47,    55,    48,     2,    50,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    41,    54,
      45,    39,    46,    40,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    56,     2,    57,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,    42,    59,    53,     2,     2,     2,
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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    18,    19,
      21,    23,    27,    29,    33,    38,    45,    47,    49,    53,
      58,    60,    64,    66,    68,    70,    77,    78,    80,    82,
      86,    89,    94,    95,   101,   102,   104,   106,   109,   110,
     112,   114,   117,   119,   121,   123,   125,   127,   129,   131,
     134,   135,   142,   143,   144,   154,   155,   156,   164,   165,
     166,   176,   177,   178,   179,   192,   193,   195,   198,   201,
     204,   208,   209,   219,   220,   222,   224,   227,   228,   234,
     235,   239,   241,   243,   245,   247,   251,   255,   259,   263,
     267,   271,   273,   279,   281,   285,   287,   291,   293,   297,
     299,   303,   305,   309,   311,   315,   319,   321,   325,   329,
     333,   337,   339,   343,   347,   349,   353,   357,   359,   363,
     367,   371,   373,   376,   379,   382,   385,   388,   391,   393,
     398,   403,   406,   409,   414,   420,   426,   427,   430,   432,
     436,   437,   440,   443,   448,   449,   451,   453,   457,   459,
     461,   463,   467
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      63,     0,    -1,    64,    -1,    65,    -1,    64,    65,    -1,
      75,    -1,    66,    -1,    74,    67,    54,    -1,    -1,    68,
      -1,    69,    -1,    68,    55,    69,    -1,    70,    -1,    70,
      39,    71,    -1,    70,    56,   131,    57,    -1,    70,    56,
     131,    57,    39,    72,    -1,     3,    -1,   109,    -1,    58,
      73,    59,    -1,    58,    73,    55,    59,    -1,    71,    -1,
      73,    55,    71,    -1,     9,    -1,     8,    -1,     7,    -1,
      74,    70,    60,    76,    61,    79,    -1,    -1,    77,    -1,
      78,    -1,    77,    55,    78,    -1,    74,     3,    -1,    74,
       3,    56,    57,    -1,    -1,    58,    80,    81,    83,    59,
      -1,    -1,    82,    -1,    66,    -1,    82,    66,    -1,    -1,
      84,    -1,    85,    -1,    84,    85,    -1,    86,    -1,    79,
      -1,    87,    -1,    91,    -1,   100,    -1,   101,    -1,    54,
      -1,   109,    54,    -1,    -1,    10,    60,   109,    61,    88,
      85,    -1,    -1,    -1,    10,    60,   109,    61,    89,    85,
      11,    90,    85,    -1,    -1,    -1,    12,    92,    60,   109,
      61,    93,    85,    -1,    -1,    -1,    14,    94,    85,    12,
      95,    60,   109,    61,    54,    -1,    -1,    -1,    -1,    13,
      60,    99,    54,    96,    99,    54,    97,    99,    61,    98,
      85,    -1,    -1,   109,    -1,    19,    54,    -1,    18,    54,
      -1,    20,    54,    -1,    20,   109,    54,    -1,    -1,    15,
      60,   109,    61,   102,    58,   103,   107,    59,    -1,    -1,
     104,    -1,   105,    -1,   104,   105,    -1,    -1,    16,   131,
      41,   106,    83,    -1,    -1,    17,    41,    83,    -1,     4,
      -1,     5,    -1,   110,    -1,   111,    -1,   122,    39,   110,
      -1,   122,    24,   110,    -1,   122,    25,   110,    -1,   122,
      26,   110,    -1,   122,    27,   110,    -1,   122,    28,   110,
      -1,   112,    -1,   112,    40,   109,    41,   111,    -1,   113,
      -1,   112,    36,   113,    -1,   114,    -1,   113,    35,   114,
      -1,   115,    -1,   114,    42,   115,    -1,   116,    -1,   115,
      43,   116,    -1,   117,    -1,   116,    44,   117,    -1,   118,
      -1,   117,    31,   118,    -1,   117,    32,   118,    -1,   119,
      -1,   118,    45,   119,    -1,   118,    46,   119,    -1,   118,
      33,   119,    -1,   118,    34,   119,    -1,   120,    -1,   119,
      37,   120,    -1,   119,    38,   120,    -1,   121,    -1,   120,
      47,   121,    -1,   120,    48,   121,    -1,   122,    -1,   121,
      49,   122,    -1,   121,    50,   122,    -1,   121,    51,   122,
      -1,   123,    -1,    29,   122,    -1,    30,   122,    -1,    47,
     122,    -1,    48,   122,    -1,    52,   122,    -1,    53,   122,
      -1,   130,    -1,   123,    56,   109,    57,    -1,     3,    60,
     128,    61,    -1,   123,    29,    -1,   123,    30,    -1,    21,
      60,   109,    61,    -1,    22,    60,     6,   124,    61,    -1,
      23,    60,     6,   126,    61,    -1,    -1,    55,   125,    -1,
     109,    -1,   125,    55,   109,    -1,    -1,    55,   127,    -1,
      44,     3,    -1,   127,    55,    44,     3,    -1,    -1,   129,
      -1,   110,    -1,   129,    55,   110,    -1,     3,    -1,   108,
      -1,     6,    -1,    60,   109,    61,    -1,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   105,   105,   109,   110,   114,   115,   119,   122,   124,
     128,   129,   133,   134,   135,   136,   139,   142,   146,   147,
     151,   152,   157,   158,   159,   163,   169,   171,   175,   176,
     180,   181,   185,   185,   190,   192,   196,   197,   200,   202,
     206,   207,   211,   212,   213,   214,   215,   216,   220,   221,
     225,   225,   226,   226,   226,   230,   231,   230,   234,   236,
     234,   238,   239,   240,   238,   245,   246,   250,   251,   252,
     253,   257,   257,   261,   263,   267,   268,   272,   272,   275,
     277,   281,   282,   287,   291,   292,   298,   299,   300,   301,
     302,   306,   307,   321,   322,   326,   327,   331,   332,   336,
     337,   341,   342,   346,   347,   348,   352,   353,   354,   355,
     356,   360,   361,   362,   366,   367,   368,   372,   373,   374,
     375,   379,   380,   381,   382,   383,   384,   385,   390,   391,
     400,   405,   406,   407,   408,   409,   413,   414,   418,   419,
     423,   424,   428,   429,   434,   435,   439,   440,   445,   452,
     453,   454,   458
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char* const yytname[] =
{
  "$end", "error", "$undefined", "T_IDENTIFIER", "T_INTEGER_CONSTANT",
  "T_CHARACTER_CONSTANT", "T_STRING_LITERAL", "T_INT", "T_CHAR", "T_VOID",
  "T_IF", "T_ELSE", "T_WHILE", "T_FOR", "T_DO", "T_SWITCH", "T_CASE",
  "T_DEFAULT", "T_BREAK", "T_CONTINUE", "T_RETURN", "T_PRINT", "T_PRINTF",
  "T_SCANF", "T_ADD_ASSIGN", "T_SUB_ASSIGN", "T_MUL_ASSIGN",
  "T_DIV_ASSIGN", "T_MOD_ASSIGN", "T_INC", "T_DEC", "T_EQ", "T_NE", "T_LE",
  "T_GE", "T_AND", "T_OR", "T_LSHIFT", "T_RSHIFT", "'='", "'?'", "':'",
  "'|'", "'^'", "'&'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'!'", "'~'", "';'", "','", "'['", "']'", "'{'", "'}'", "'('", "')'",
  "$accept", "program", "external_declaration_list",
  "external_declaration", "declaration", "declarator_list_opt",
  "declarator_list", "declarator", "identifier_declarator", "initializer",
  "initializer_list", "initializer_element_list", "type_specifier",
  "function_definition", "parameter_list_opt", "parameter_list",
  "parameter_declaration", "compound_statement", "$@1",
  "declaration_list_opt", "declaration_list", "statement_list_opt",
  "statement_list", "statement", "expression_statement",
  "selection_statement", "$@2", "$@3", "$@4", "iteration_statement", "$@5",
  "$@6", "$@7", "$@8", "$@9", "$@10", "$@11", "expression_opt",
  "jump_statement", "switch_statement", "$@12", "case_list_opt",
  "case_list", "case_statement", "$@13", "default_opt", "constant",
  "expression", "assignment_expression", "conditional_expression",
  "logical_or_expression", "logical_and_expression",
  "inclusive_or_expression", "exclusive_or_expression", "and_expression",
  "equality_expression", "relational_expression", "shift_expression",
  "additive_expression", "multiplicative_expression", "unary_expression",
  "postfix_expression", "argument_list_for_printf_opt",
  "argument_expression_list_printf", "argument_list_for_scanf_opt",
  "argument_expression_list_scanf", "argument_expression_list_opt",
  "argument_expression_list_general", "primary_expression",
  "constant_expression", YY_NULL
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,    61,
      63,    58,   124,    94,    38,    60,    62,    43,    45,    42,
      47,    37,    33,   126,    59,    44,    91,    93,   123,   125,
      40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    64,    65,    65,    66,    67,    67,
      68,    68,    69,    69,    69,    69,    70,    71,    72,    72,
      73,    73,    74,    74,    74,    75,    76,    76,    77,    77,
      78,    78,    80,    79,    81,    81,    82,    82,    83,    83,
      84,    84,    85,    85,    85,    85,    85,    85,    86,    86,
      88,    87,    89,    90,    87,    92,    93,    91,    94,    95,
      91,    96,    97,    98,    91,    99,    99,   100,   100,   100,
     100,   102,   101,   103,   103,   104,   104,   106,   105,   107,
     107,   108,   108,   109,   110,   110,   110,   110,   110,   110,
     110,   111,   111,   112,   112,   113,   113,   114,   114,   115,
     115,   116,   116,   117,   117,   117,   118,   118,   118,   118,
     118,   119,   119,   119,   120,   120,   120,   121,   121,   121,
     121,   122,   122,   122,   122,   122,   122,   122,   123,   123,
     123,   123,   123,   123,   123,   123,   124,   124,   125,   125,
     126,   126,   127,   127,   128,   128,   129,   129,   130,   130,
     130,   130,   131
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     0,     1,
       1,     3,     1,     3,     4,     6,     1,     1,     3,     4,
       1,     3,     1,     1,     1,     6,     0,     1,     1,     3,
       2,     4,     0,     5,     0,     1,     1,     2,     0,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     2,
       0,     6,     0,     0,     9,     0,     0,     7,     0,     0,
       9,     0,     0,     0,    12,     0,     1,     2,     2,     2,
       3,     0,     9,     0,     1,     1,     2,     0,     5,     0,
       3,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     1,     5,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     2,     2,     2,     2,     2,     2,     1,     4,
       4,     2,     2,     4,     5,     5,     0,     2,     1,     3,
       0,     2,     2,     4,     0,     1,     1,     3,     1,     1,
       1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    24,    23,    22,     0,     2,     3,     6,     8,     5,
       1,     4,    16,     0,     9,    10,    12,     7,     0,     0,
       0,    26,    11,    12,   148,    81,    82,   150,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,   149,
      17,    83,    84,    91,    93,    95,    97,    99,   101,   103,
     106,   111,   114,   117,   121,   128,   152,     0,     0,     0,
      27,    28,   144,     0,     0,     0,   122,   123,   124,   125,
     126,   127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   131,   132,
       0,    14,    30,     0,     0,   146,     0,   145,     0,   136,
     140,   151,    94,   117,     0,    96,    98,   100,   102,   104,
     105,   109,   110,   107,   108,   112,   113,   115,   116,   118,
     119,   120,    86,    87,    88,    89,    90,    85,     0,     0,
       0,    32,    25,    29,   130,     0,   133,     0,     0,     0,
       0,     0,   129,     0,    15,    31,    34,   147,   138,   137,
     134,     0,   141,   135,    92,    20,     0,    36,     8,    38,
      35,     0,   142,     0,     0,    18,     0,    55,     0,    58,
       0,     0,     0,     0,    48,    43,     0,    39,    40,    42,
      44,    45,    46,    47,     0,    37,   139,     0,    19,    21,
       0,     0,    65,     0,     0,    68,    67,    69,     0,    33,
      41,    49,   143,     0,     0,     0,    66,     0,     0,    70,
      50,     0,    61,    59,    71,     0,     0,    56,    65,     0,
       0,    51,     0,     0,     0,     0,    73,    53,    57,    62,
       0,     0,    79,    74,    75,     0,    65,     0,     0,     0,
       0,    76,    54,     0,    60,    77,    38,    72,    63,    38,
      80,     0,    78,    64
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    13,    14,    15,    23,    38,
     154,   166,     8,     9,    59,    60,    61,   185,   156,   169,
     170,   186,   187,   188,   189,   190,   225,   226,   245,   191,
     201,   233,   203,   229,   228,   246,   261,   215,   192,   193,
     230,   242,   243,   244,   259,   250,    39,   194,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,   148,   159,   150,   162,   106,   107,    55,    57
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -220
static const yytype_int16 yypact[] =
{
       6,  -220,  -220,  -220,     7,     6,  -220,  -220,    40,  -220,
    -220,  -220,  -220,    -2,     1,  -220,   -31,  -220,    40,   246,
      58,     6,  -220,   -28,    31,  -220,  -220,  -220,    39,    41,
      43,   246,   246,   246,   246,   246,   246,   246,  -220,  -220,
    -220,  -220,  -220,   -30,    65,    60,    61,    62,    28,    12,
      45,    42,    37,    14,   -26,  -220,  -220,    48,   104,    47,
      54,  -220,   246,   246,   105,   106,  -220,  -220,  -220,  -220,
    -220,  -220,    49,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,  -220,  -220,
     246,    74,    59,    56,     6,  -220,    55,    66,    68,    72,
      75,  -220,    65,  -220,    76,    60,    61,    62,    28,    12,
      12,    45,    45,    45,    45,    42,    42,    37,    37,  -220,
    -220,  -220,  -220,  -220,  -220,  -220,  -220,  -220,    63,    73,
      78,  -220,  -220,  -220,  -220,   246,  -220,   246,    71,    89,
      82,   246,  -220,   246,  -220,  -220,     6,  -220,  -220,    90,
    -220,   134,    91,  -220,  -220,  -220,   -43,  -220,    40,   184,
       6,   246,  -220,   100,   119,  -220,    87,  -220,    93,  -220,
      96,    97,   103,   218,  -220,  -220,    99,   184,  -220,  -220,
    -220,  -220,  -220,  -220,   107,  -220,  -220,   156,  -220,  -220,
     246,   102,   246,   184,   246,  -220,  -220,  -220,   109,  -220,
    -220,  -220,  -220,   108,   246,   111,  -220,   148,   112,  -220,
    -220,   113,  -220,  -220,  -220,   184,   184,  -220,   246,   110,
     117,  -220,   157,   184,   122,   246,   161,  -220,  -220,  -220,
     121,    58,   163,   161,  -220,   184,   246,   130,   145,   150,
     133,  -220,  -220,   132,  -220,  -220,   184,  -220,  -220,   184,
    -220,   184,  -220,  -220
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -220,  -220,  -220,   195,  -139,  -220,  -220,   183,   200,  -148,
    -220,  -220,   -20,  -220,  -220,  -220,   114,   116,  -220,  -220,
    -220,  -205,  -220,  -107,  -220,  -220,  -220,  -220,  -220,  -220,
    -220,  -220,  -220,  -220,  -220,  -220,  -220,  -219,  -220,  -220,
    -220,  -220,  -220,   -33,  -220,  -220,  -220,   -19,   -60,    64,
    -220,   138,   137,   141,   143,   147,    13,   -34,     9,    10,
     -12,  -220,  -220,  -220,  -220,  -220,  -220,  -220,  -220,   -15
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      40,    58,   105,    98,    99,   165,    73,    10,    19,   234,
      74,    19,   174,     1,     2,     3,   175,   167,    72,    66,
      67,    68,    69,    70,    71,    20,   199,   253,    20,    21,
     100,   195,   132,   133,   134,   135,   136,   137,    92,    93,
      94,    95,    96,    12,   108,    81,    82,   121,   122,   123,
     124,   260,    17,    97,   262,   114,    18,    83,    84,    79,
      80,   113,    56,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   129,   130,   131,
     210,   138,    85,    86,    58,   157,    89,    90,    91,    87,
      88,    62,   119,   120,   125,   126,   217,   127,   128,    63,
      75,    64,    76,    65,    77,   101,    78,   102,   103,   104,
     111,   109,   110,   139,   141,   140,   144,   151,   231,   232,
     152,   145,    24,    25,    26,    27,   238,   147,   158,   146,
     149,   153,   160,   161,    40,   155,   168,   172,   252,   113,
      28,    29,    30,   163,   197,   171,   173,   200,    31,    32,
     168,   205,   196,   202,   263,    40,   204,   206,   209,   212,
     223,   211,   214,   219,   208,   222,    33,    34,   237,   220,
     235,    35,    36,   224,   227,   236,   239,   241,   198,    37,
     249,   213,   247,   216,   254,   218,   255,    24,    25,    26,
      27,   256,   257,   258,   176,   221,   177,   178,   179,   180,
      11,    22,   181,   182,   183,    28,    29,    30,    16,   216,
     251,   112,   115,    31,    32,   164,   240,   116,   143,   142,
     117,    24,    25,    26,    27,   118,   248,   216,     0,     0,
       0,    33,    34,     0,     0,     0,    35,    36,   184,    28,
      29,    30,   141,     0,    37,     0,     0,    31,    32,    24,
      25,    26,    27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    28,    29,    30,
      35,    36,   207,     0,     0,    31,    32,     0,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,     0,     0,     0,    35,    36,
       0,     0,     0,     0,     0,     0,    37
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-220)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      19,    21,    62,    29,    30,   153,    36,     0,    39,   228,
      40,    39,    55,     7,     8,     9,    59,   156,    37,    31,
      32,    33,    34,    35,    36,    56,   174,   246,    56,    60,
      56,   170,    92,    93,    94,    95,    96,    97,    24,    25,
      26,    27,    28,     3,    63,    33,    34,    81,    82,    83,
      84,   256,    54,    39,   259,    74,    55,    45,    46,    31,
      32,    73,     4,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
     187,   100,    37,    38,   104,   145,    49,    50,    51,    47,
      48,    60,    79,    80,    85,    86,   203,    87,    88,    60,
      35,    60,    42,    60,    43,    57,    44,     3,    61,    55,
      61,     6,     6,    39,    58,    56,    61,    41,   225,   226,
      57,    55,     3,     4,     5,     6,   233,    55,   147,    61,
      55,    58,    61,    44,   153,    57,   156,     3,   245,   151,
      21,    22,    23,    61,    44,    55,    55,    60,    29,    30,
     170,    54,   171,    60,   261,   174,    60,    54,    59,     3,
      12,    54,    60,    54,   183,    54,    47,    48,    11,    61,
      60,    52,    53,    61,    61,    58,    54,    16,    59,    60,
      17,   200,    61,   202,    54,   204,    41,     3,     4,     5,
       6,    41,    59,    61,    10,   214,    12,    13,    14,    15,
       5,    18,    18,    19,    20,    21,    22,    23,     8,   228,
     243,    73,    75,    29,    30,   151,   235,    76,   104,   103,
      77,     3,     4,     5,     6,    78,   241,   246,    -1,    -1,
      -1,    47,    48,    -1,    -1,    -1,    52,    53,    54,    21,
      22,    23,    58,    -1,    60,    -1,    -1,    29,    30,     3,
       4,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    21,    22,    23,
      52,    53,    54,    -1,    -1,    29,    30,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    -1,    -1,    -1,    52,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    60
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,     9,    63,    64,    65,    66,    74,    75,
       0,    65,     3,    67,    68,    69,    70,    54,    55,    39,
      56,    60,    69,    70,     3,     4,     5,     6,    21,    22,
      23,    29,    30,    47,    48,    52,    53,    60,    71,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   130,     4,   131,    74,    76,
      77,    78,    60,    60,    60,    60,   122,   122,   122,   122,
     122,   122,   109,    36,    40,    35,    42,    43,    44,    31,
      32,    33,    34,    45,    46,    37,    38,    47,    48,    49,
      50,    51,    24,    25,    26,    27,    28,    39,    29,    30,
      56,    57,     3,    61,    55,   110,   128,   129,   109,     6,
       6,    61,   113,   122,   109,   114,   115,   116,   117,   118,
     118,   119,   119,   119,   119,   120,   120,   121,   121,   122,
     122,   122,   110,   110,   110,   110,   110,   110,   109,    39,
      56,    58,    79,    78,    61,    55,    61,    55,   124,    55,
     126,    41,    57,    58,    72,    57,    80,   110,   109,   125,
      61,    44,   127,    61,   111,    71,    73,    66,    74,    81,
      82,    55,     3,    55,    55,    59,    10,    12,    13,    14,
      15,    18,    19,    20,    54,    79,    83,    84,    85,    86,
      87,    91,   100,   101,   109,    66,   109,    44,    59,    71,
      60,    92,    60,    94,    60,    54,    54,    54,   109,    59,
      85,    54,     3,   109,    60,    99,   109,    85,   109,    54,
      61,   109,    54,    12,    61,    88,    89,    61,    96,    95,
     102,    85,    85,    93,    99,    60,    58,    11,    85,    54,
     109,    16,   103,   104,   105,    90,    97,    61,   131,    17,
     107,   105,    85,    99,    54,    41,    41,    59,    61,   106,
      83,    98,    83,    85
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
    case 7:
        /* Line 1792 of yacc.c  */
#line 119 "compiler.y"
    { EMIT("// End of global/local var declaration"); }
    break;

    case 12:
        /* Line 1792 of yacc.c  */
#line 133 "compiler.y"
    { EMIT("// Declared var %s", (yyvsp[(1) - (1)].sval)); /* add_symbol($1, type, 0 for scalar); */ }
    break;

    case 13:
        /* Line 1792 of yacc.c  */
#line 134 "compiler.y"
    { EMIT("// Declared and initialized var %s", (yyvsp[(1) - (3)].sval)); /* add_symbol($1, type, 0); EMIT("POP %s", $1); (after initializer code) */ }
    break;

    case 14:
        /* Line 1792 of yacc.c  */
#line 135 "compiler.y"
    { EMIT("// Declared array %s[%d]", (yyvsp[(1) - (4)].sval), (yyvsp[(3) - (4)].ival)); /* add_symbol($1, type, $3 as size); */ }
    break;

    case 15:
        /* Line 1792 of yacc.c  */
#line 136 "compiler.y"
    { EMIT("// Declared and initialized array %s[%d]", (yyvsp[(1) - (6)].sval), (yyvsp[(3) - (6)].ival)); /* add_symbol, then code for init list */ }
    break;

    case 16:
        /* Line 1792 of yacc.c  */
#line 139 "compiler.y"
    { (yyval.sval) = (yyvsp[(1) - (1)].sval); }
    break;

    case 17:
        /* Line 1792 of yacc.c  */
#line 142 "compiler.y"
    { EMIT("// Code for initializer expression"); /* Code to evaluate expr, result on stack */ }
    break;

    case 18:
        /* Line 1792 of yacc.c  */
#line 146 "compiler.y"
    { EMIT("// End array initializer list"); }
    break;

    case 19:
        /* Line 1792 of yacc.c  */
#line 147 "compiler.y"
    { EMIT("// End array initializer list (with trailing comma)"); }
    break;

    case 20:
        /* Line 1792 of yacc.c  */
#line 151 "compiler.y"
    { EMIT("// Array element init"); }
    break;

    case 21:
        /* Line 1792 of yacc.c  */
#line 152 "compiler.y"
    { EMIT("// Array element init"); }
    break;

    case 22:
        /* Line 1792 of yacc.c  */
#line 157 "compiler.y"
    { (yyval.ival) = T_VOID; EMIT("// Type: void"); }
    break;

    case 23:
        /* Line 1792 of yacc.c  */
#line 158 "compiler.y"
    { (yyval.ival) = T_CHAR; EMIT("// Type: char"); }
    break;

    case 24:
        /* Line 1792 of yacc.c  */
#line 159 "compiler.y"
    { (yyval.ival) = T_INT;  EMIT("// Type: int"); }
    break;

    case 25:
        /* Line 1792 of yacc.c  */
#line 163 "compiler.y"
    {
        EMIT("LABEL FUNC_%s // Start of function %s", (yyvsp[(2) - (6)].sval), (yyvsp[(2) - (6)].sval));
        EMIT("// END_FUNC %s", (yyvsp[(2) - (6)].sval)); /* $2 is function name from declarator */
    }
    break;

    case 30:
        /* Line 1792 of yacc.c  */
#line 180 "compiler.y"
    { EMIT("// Param: %s type %d", (yyvsp[(2) - (2)].sval), (yyvsp[(1) - (2)].ival)); /* Add to symbol table as param */ }
    break;

    case 31:
        /* Line 1792 of yacc.c  */
#line 181 "compiler.y"
    { EMIT("// Param: array %s[] type %d", (yyvsp[(2) - (4)].sval), (yyvsp[(1) - (4)].ival)); /* Add as array param */ }
    break;

    case 32:
        /* Line 1792 of yacc.c  */
#line 185 "compiler.y"
    { EMIT("// BEGIN_SCOPE"); /* current_scope_level++; next_address_local = 0; */ }
    break;

    case 33:
        /* Line 1792 of yacc.c  */
#line 187 "compiler.y"
    { EMIT("// END_SCOPE"); /* current_scope_level--; */ }
    break;

    case 48:
        /* Line 1792 of yacc.c  */
#line 220 "compiler.y"
    { EMIT("// Empty statement"); }
    break;

    case 49:
        /* Line 1792 of yacc.c  */
#line 221 "compiler.y"
    { EMIT("// Expression statement, result potentially discarded or used by POP"); /* If expression has value on stack, might need POP if not used */ }
    break;

    case 50:
        /* Line 1792 of yacc.c  */
#line 225 "compiler.y"
    { char* l_false = new_label(); EMIT("FJMP %s // if false jump", l_false); }
    break;

    case 51:
        /* Line 1792 of yacc.c  */
#line 225 "compiler.y"
    { char* l_end = new_label(); EMIT("LABEL %s // after if-true block", l_false); }
    break;

    case 52:
        /* Line 1792 of yacc.c  */
#line 226 "compiler.y"
    { char* l_else = new_label(); char* l_end = new_label(); EMIT("FJMP %s // if false jump to else", l_else); }
    break;

    case 53:
        /* Line 1792 of yacc.c  */
#line 226 "compiler.y"
    { EMIT("JMP %s // jump to end after then", l_end); EMIT("LABEL %s // else block", l_else); }
    break;

    case 54:
        /* Line 1792 of yacc.c  */
#line 226 "compiler.y"
    { EMIT("LABEL %s // end if-else", l_end); }
    break;

    case 55:
        /* Line 1792 of yacc.c  */
#line 230 "compiler.y"
    { char* l_cond = new_label(); char* l_body_end = new_label(); EMIT("LABEL %s // while condition", l_cond); /* Store l_cond as continue_target, l_body_end as break_target */ }
    break;

    case 56:
        /* Line 1792 of yacc.c  */
#line 231 "compiler.y"
    { EMIT("FJMP %s // while false, jump to end", l_body_end); }
    break;

    case 57:
        /* Line 1792 of yacc.c  */
#line 232 "compiler.y"
    { EMIT("JMP %s // back to while condition", l_cond); EMIT("LABEL %s // end while", l_body_end); }
    break;

    case 58:
        /* Line 1792 of yacc.c  */
#line 234 "compiler.y"
    { char* l_start = new_label(); char* l_cond_check = new_label(); char* l_break_target = new_label(); /* Store l_cond_check as continue_target, l_break_target as break_target */ EMIT("LABEL %s // do-while start", l_start); }
    break;

    case 59:
        /* Line 1792 of yacc.c  */
#line 236 "compiler.y"
    { EMIT("LABEL %s // do-while condition check", l_cond_check); }
    break;

    case 60:
        /* Line 1792 of yacc.c  */
#line 236 "compiler.y"
    { EMIT("TJMP %s // do-while true, jump to start", l_start); EMIT("LABEL %s // end do-while", l_break_target); }
    break;

    case 61:
        /* Line 1792 of yacc.c  */
#line 238 "compiler.y"
    { char* l_cond = new_label(); char* l_inc = new_label(); char* l_body = new_label(); char* l_end = new_label(); /* Store l_inc as continue_target, l_end as break_target */ EMIT("LABEL %s // for condition", l_cond); }
    break;

    case 62:
        /* Line 1792 of yacc.c  */
#line 239 "compiler.y"
    { EMIT("FJMP %s // for false, jump to end", l_end); EMIT("JMP %s // jump to body", l_body); EMIT("LABEL %s // for increment", l_inc); }
    break;

    case 63:
        /* Line 1792 of yacc.c  */
#line 240 "compiler.y"
    { EMIT("JMP %s // back to for condition", l_cond); EMIT("LABEL %s // for body start", l_body); }
    break;

    case 64:
        /* Line 1792 of yacc.c  */
#line 241 "compiler.y"
    { EMIT("JMP %s // jump to for increment", l_inc); EMIT("LABEL %s // end for", l_end); }
    break;

    case 65:
        /* Line 1792 of yacc.c  */
#line 245 "compiler.y"
    { /* No code if empty */ }
    break;

    case 67:
        /* Line 1792 of yacc.c  */
#line 250 "compiler.y"
    { EMIT("JMP <continue_label> // Continue"); /* Needs loop context for actual label */ }
    break;

    case 68:
        /* Line 1792 of yacc.c  */
#line 251 "compiler.y"
    { EMIT("JMP <break_label> // Break");    /* Needs loop/switch context for actual label */ }
    break;

    case 69:
        /* Line 1792 of yacc.c  */
#line 252 "compiler.y"
    { EMIT("RET // Return void"); }
    break;

    case 70:
        /* Line 1792 of yacc.c  */
#line 253 "compiler.y"
    { EMIT("// Code for return expression on stack"); EMIT("RET_VAL // Return with value on stack"); }
    break;

    case 71:
        /* Line 1792 of yacc.c  */
#line 257 "compiler.y"
    { char* l_end_switch = new_label(); /* Store l_end_switch for break */ EMIT("// Switch on expression (value on stack)"); }
    break;

    case 72:
        /* Line 1792 of yacc.c  */
#line 258 "compiler.y"
    { EMIT("POP // Pop switch expression value if no case matched or after last case without break"); EMIT("LABEL %s // end_switch", l_end_switch); }
    break;

    case 77:
        /* Line 1792 of yacc.c  */
#line 272 "compiler.y"
    { char* l_next_case = new_label(); EMIT("DUP // duplicate switch expr"); EMIT("PUSH_CONST %d // case value", (yyvsp[(2) - (3)].ival)); EMIT("EQ"); EMIT("FJMP %s // if not equal, jump to next case logic", l_next_case); EMIT("POP // pop switch expr value (now matched)"); EMIT("POP // pop case value (constant)"); /* Begin case block statements */ }
    break;

    case 78:
        /* Line 1792 of yacc.c  */
#line 272 "compiler.y"
    { EMIT("LABEL %s // for fall-through or next case test", l_next_case); }
    break;

    case 80:
        /* Line 1792 of yacc.c  */
#line 277 "compiler.y"
    { EMIT("LABEL <default_label>"); /* POP switch expr val if not already done */ }
    break;

    case 81:
        /* Line 1792 of yacc.c  */
#line 281 "compiler.y"
    { (yyval.ival) = (yyvsp[(1) - (1)].ival); }
    break;

    case 82:
        /* Line 1792 of yacc.c  */
#line 282 "compiler.y"
    { (yyval.ival) = (yyvsp[(1) - (1)].ival); }
    break;

    case 83:
        /* Line 1792 of yacc.c  */
#line 287 "compiler.y"
    { (yyval.ival) = (yyvsp[(1) - (1)].ival); }
    break;

    case 84:
        /* Line 1792 of yacc.c  */
#line 291 "compiler.y"
    { (yyval.ival) = (yyvsp[(1) - (1)].ival); }
    break;

    case 85:
        /* Line 1792 of yacc.c  */
#line 292 "compiler.y"
    {
        EMIT("// Assignment: Rvalue ($3) is on stack. Lvalue ($1) address is needed.");
        EMIT("// Code for $1 to ensure its address is on stack (if it's an identifier or array element)");
        EMIT("// (assignment_expression $3 already pushed its value)");
        EMIT("STORE_INDIRECT // Store value from top of stack into address below it"); (yyval.ival) = (yyvsp[(3) - (3)].ival);
    }
    break;

    case 86:
        /* Line 1792 of yacc.c  */
#line 298 "compiler.y"
    { EMIT("// Code for LVAL addr ($1), then RVAL ($3)"); EMIT("DUP_ADDR"); EMIT("LOAD_INDIRECT"); EMIT("ADD"); EMIT("STORE_INDIRECT"); }
    break;

    case 87:
        /* Line 1792 of yacc.c  */
#line 299 "compiler.y"
    { EMIT("// Code for LVAL addr ($1), then RVAL ($3)"); EMIT("DUP_ADDR"); EMIT("LOAD_INDIRECT"); EMIT("SUB"); EMIT("STORE_INDIRECT"); }
    break;

    case 88:
        /* Line 1792 of yacc.c  */
#line 300 "compiler.y"
    { EMIT("// Code for LVAL addr ($1), then RVAL ($3)"); EMIT("DUP_ADDR"); EMIT("LOAD_INDIRECT"); EMIT("MUL"); EMIT("STORE_INDIRECT"); }
    break;

    case 89:
        /* Line 1792 of yacc.c  */
#line 301 "compiler.y"
    { EMIT("// Code for LVAL addr ($1), then RVAL ($3)"); EMIT("DUP_ADDR"); EMIT("LOAD_INDIRECT"); EMIT("DIV"); EMIT("STORE_INDIRECT"); }
    break;

    case 90:
        /* Line 1792 of yacc.c  */
#line 302 "compiler.y"
    { EMIT("// Code for LVAL addr ($1), then RVAL ($3)"); EMIT("DUP_ADDR"); EMIT("LOAD_INDIRECT"); EMIT("MOD"); EMIT("STORE_INDIRECT"); }
    break;

    case 91:
        /* Line 1792 of yacc.c  */
#line 306 "compiler.y"
    { (yyval.ival) = (yyvsp[(1) - (1)].ival); }
    break;

    case 92:
        /* Line 1792 of yacc.c  */
#line 307 "compiler.y"
    {
        char* l_false = new_label();
        char* l_end = new_label();
        EMIT("FJMP %s // If logical_or_expr ($1) is false, jump to false part", l_false);
        // $3 is true expression (value will be on stack)
        EMIT("JMP %s // Jump to end", l_end);
        EMIT("LABEL %s // False part", l_false);
        // $5 is false expression (value will be on stack)
        EMIT("LABEL %s // End conditional", l_end);
        // Result is on stack
    }
    break;

    case 93:
        /* Line 1792 of yacc.c  */
#line 321 "compiler.y"
    { (yyval.ival) = (yyvsp[(1) - (1)].ival); }
    break;

    case 94:
        /* Line 1792 of yacc.c  */
#line 322 "compiler.y"
    { char* l_true = new_label(); char* l_end = new_label(); EMIT("DUP"); EMIT("TJMP %s // Short-circuit if first is true", l_true); EMIT("POP"); /* $3 is second expression */ EMIT("TJMP %s", l_true); EMIT("PUSH_CONST 0"); EMIT("JMP %s", l_end); EMIT("LABEL %s", l_true); EMIT("PUSH_CONST 1"); EMIT("LABEL %s", l_end); }
    break;

    case 95:
        /* Line 1792 of yacc.c  */
#line 326 "compiler.y"
    { (yyval.ival) = (yyvsp[(1) - (1)].ival); }
    break;

    case 96:
        /* Line 1792 of yacc.c  */
#line 327 "compiler.y"
    { char* l_false = new_label(); char* l_end = new_label(); EMIT("DUP"); EMIT("FJMP %s // Short-circuit if first is false", l_false); EMIT("POP"); /* $3 is second expression */ EMIT("FJMP %s", l_false); EMIT("PUSH_CONST 1"); EMIT("JMP %s", l_end); EMIT("LABEL %s", l_false); EMIT("PUSH_CONST 0"); EMIT("LABEL %s", l_end); }
    break;

    case 97:
        /* Line 1792 of yacc.c  */
#line 331 "compiler.y"
    { (yyval.ival) = (yyvsp[(1) - (1)].ival); }
    break;

    case 98:
        /* Line 1792 of yacc.c  */
#line 332 "compiler.y"
    { EMIT("OR_BITWISE"); }
    break;

    case 99:
        /* Line 1792 of yacc.c  */
#line 336 "compiler.y"
    { (yyval.ival) = (yyvsp[(1) - (1)].ival); }
    break;

    case 100:
        /* Line 1792 of yacc.c  */
#line 337 "compiler.y"
    { EMIT("XOR_BITWISE"); }
    break;

    case 101:
        /* Line 1792 of yacc.c  */
#line 341 "compiler.y"
    { (yyval.ival) = (yyvsp[(1) - (1)].ival); }
    break;

    case 102:
        /* Line 1792 of yacc.c  */
#line 342 "compiler.y"
    { EMIT("AND_BITWISE"); }
    break;

    case 103:
        /* Line 1792 of yacc.c  */
#line 346 "compiler.y"
    { (yyval.ival) = (yyvsp[(1) - (1)].ival); }
    break;

    case 104:
        /* Line 1792 of yacc.c  */
#line 347 "compiler.y"
    { EMIT("EQ"); }
    break;

    case 105:
        /* Line 1792 of yacc.c  */
#line 348 "compiler.y"
    { EMIT("NE"); }
    break;

    case 106:
        /* Line 1792 of yacc.c  */
#line 352 "compiler.y"
    { (yyval.ival) = (yyvsp[(1) - (1)].ival); }
    break;

    case 107:
        /* Line 1792 of yacc.c  */
#line 353 "compiler.y"
    { EMIT("LT"); }
    break;

    case 108:
        /* Line 1792 of yacc.c  */
#line 354 "compiler.y"
    { EMIT("GT"); }
    break;

    case 109:
        /* Line 1792 of yacc.c  */
#line 355 "compiler.y"
    { EMIT("LE"); }
    break;

    case 110:
        /* Line 1792 of yacc.c  */
#line 356 "compiler.y"
    { EMIT("GE"); }
    break;

    case 111:
        /* Line 1792 of yacc.c  */
#line 360 "compiler.y"
    { (yyval.ival) = (yyvsp[(1) - (1)].ival); }
    break;

    case 112:
        /* Line 1792 of yacc.c  */
#line 361 "compiler.y"
    { EMIT("SHL"); }
    break;

    case 113:
        /* Line 1792 of yacc.c  */
#line 362 "compiler.y"
    { EMIT("SHR"); }
    break;

    case 114:
        /* Line 1792 of yacc.c  */
#line 366 "compiler.y"
    { (yyval.ival) = (yyvsp[(1) - (1)].ival); }
    break;

    case 115:
        /* Line 1792 of yacc.c  */
#line 367 "compiler.y"
    { EMIT("ADD"); }
    break;

    case 116:
        /* Line 1792 of yacc.c  */
#line 368 "compiler.y"
    { EMIT("SUB"); }
    break;

    case 117:
        /* Line 1792 of yacc.c  */
#line 372 "compiler.y"
    { (yyval.ival) = (yyvsp[(1) - (1)].ival); }
    break;

    case 118:
        /* Line 1792 of yacc.c  */
#line 373 "compiler.y"
    { EMIT("MUL"); }
    break;

    case 119:
        /* Line 1792 of yacc.c  */
#line 374 "compiler.y"
    { EMIT("DIV"); }
    break;

    case 120:
        /* Line 1792 of yacc.c  */
#line 375 "compiler.y"
    { EMIT("MOD"); }
    break;

    case 121:
        /* Line 1792 of yacc.c  */
#line 379 "compiler.y"
    { (yyval.ival) = (yyvsp[(1) - (1)].ival); }
    break;

    case 122:
        /* Line 1792 of yacc.c  */
#line 380 "compiler.y"
    { EMIT("// Pre-Increment: code for $2 (LVAL address)"); EMIT("DUP_ADDR"); EMIT("LOAD_INDIRECT"); EMIT("PUSH_CONST 1"); EMIT("ADD"); EMIT("STORE_INDIRECT_NOPOP"); /* leaves new value on stack */ }
    break;

    case 123:
        /* Line 1792 of yacc.c  */
#line 381 "compiler.y"
    { EMIT("// Pre-Decrement: code for $2 (LVAL address)"); EMIT("DUP_ADDR"); EMIT("LOAD_INDIRECT"); EMIT("PUSH_CONST 1"); EMIT("SUB"); EMIT("STORE_INDIRECT_NOPOP"); }
    break;

    case 124:
        /* Line 1792 of yacc.c  */
#line 382 "compiler.y"
    { /* No actual op, value is $2 */ EMIT("// Unary plus (no-op)"); }
    break;

    case 125:
        /* Line 1792 of yacc.c  */
#line 383 "compiler.y"
    { EMIT("NEG // Negate value from $2"); }
    break;

    case 126:
        /* Line 1792 of yacc.c  */
#line 384 "compiler.y"
    { EMIT("NOT_LOGICAL"); }
    break;

    case 127:
        /* Line 1792 of yacc.c  */
#line 385 "compiler.y"
    { EMIT("NOT_BITWISE"); }
    break;

    case 128:
        /* Line 1792 of yacc.c  */
#line 390 "compiler.y"
    { (yyval.ival) = (yyvsp[(1) - (1)].ival); }
    break;

    case 129:
        /* Line 1792 of yacc.c  */
#line 391 "compiler.y"
    {
        EMIT("// Array access: $1 (base addr), $3 (index expr on stack)");
        EMIT("PUSH_CONST <element_size>"); // e.g. 4 for int
        EMIT("MUL // index * element_size");
        EMIT("ADD // base_addr + offset");
        // Result on stack is the ADDRESS of the element.
        // If used as RVALUE, it needs a LOAD_INDIRECT. This is handled by how it's used.
        // Example: if (a[i] == 0), after this, a LOAD_INDIRECT is needed before EQ
    }
    break;

    case 130:
        /* Line 1792 of yacc.c  */
#line 400 "compiler.y"
    { // Function call
        EMIT("CALL %s, %d // Call function", (yyvsp[(1) - (4)].sval), current_arg_count);
        current_arg_count = 0; // Reset for next call
        // Result of function call (if any) is on stack
    }
    break;

    case 131:
        /* Line 1792 of yacc.c  */
#line 405 "compiler.y"
    { EMIT("// Post-Increment: code for $1 (LVAL address)"); EMIT("DUP_ADDR"); EMIT("LOAD_INDIRECT"); EMIT("DUP_VAL"); EMIT("ROT_THREE"); /* old_val, addr, old_val -> addr, old_val, old_val */ EMIT("PUSH_CONST 1"); EMIT("ADD"); EMIT("STORE_INDIRECT"); /* consumes addr & new_val, leaves old_val */ }
    break;

    case 132:
        /* Line 1792 of yacc.c  */
#line 406 "compiler.y"
    { EMIT("// Post-Decrement: code for $1 (LVAL address)"); EMIT("DUP_ADDR"); EMIT("LOAD_INDIRECT"); EMIT("DUP_VAL"); EMIT("ROT_THREE"); EMIT("PUSH_CONST 1"); EMIT("SUB"); EMIT("STORE_INDIRECT"); }
    break;

    case 133:
        /* Line 1792 of yacc.c  */
#line 407 "compiler.y"
    { EMIT("// Code for print's expression ($3) on stack"); EMIT("PRINT_INT"); }
    break;

    case 134:
        /* Line 1792 of yacc.c  */
#line 408 "compiler.y"
    { EMIT("PUSH_STRING_CONST \"%s\"", (yyvsp[(3) - (5)].sval)); EMIT("PRINTF %d", current_arg_count + 1); current_arg_count = 0; }
    break;

    case 135:
        /* Line 1792 of yacc.c  */
#line 409 "compiler.y"
    { EMIT("PUSH_STRING_CONST \"%s\"", (yyvsp[(3) - (5)].sval)); EMIT("SCANF %d", current_arg_count + 1); current_arg_count = 0; }
    break;

    case 136:
        /* Line 1792 of yacc.c  */
#line 413 "compiler.y"
    { current_arg_count = 0; }
    break;

    case 137:
        /* Line 1792 of yacc.c  */
#line 414 "compiler.y"
    { /* current_arg_count set by list */ }
    break;

    case 138:
        /* Line 1792 of yacc.c  */
#line 418 "compiler.y"
    { current_arg_count = 1; EMIT("// Arg 1 for printf"); }
    break;

    case 139:
        /* Line 1792 of yacc.c  */
#line 419 "compiler.y"
    { current_arg_count++; EMIT("// Arg %d for printf", current_arg_count); }
    break;

    case 140:
        /* Line 1792 of yacc.c  */
#line 423 "compiler.y"
    { current_arg_count = 0; }
    break;

    case 141:
        /* Line 1792 of yacc.c  */
#line 424 "compiler.y"
    { /* current_arg_count set by list */ }
    break;

    case 142:
        /* Line 1792 of yacc.c  */
#line 428 "compiler.y"
    { current_arg_count = 1; EMIT("PUSH_ADDR %s // Arg 1 for scanf", (yyvsp[(2) - (2)].sval)); }
    break;

    case 143:
        /* Line 1792 of yacc.c  */
#line 429 "compiler.y"
    { current_arg_count++; EMIT("PUSH_ADDR %s // Arg %d for scanf", (yyvsp[(4) - (4)].sval), current_arg_count); }
    break;

    case 144:
        /* Line 1792 of yacc.c  */
#line 434 "compiler.y"
    { current_arg_count = 0; }
    break;

    case 146:
        /* Line 1792 of yacc.c  */
#line 439 "compiler.y"
    { current_arg_count = 1; EMIT("// User func Arg 1"); }
    break;

    case 147:
        /* Line 1792 of yacc.c  */
#line 440 "compiler.y"
    { current_arg_count++; EMIT("// User func Arg %d", current_arg_count); }
    break;

    case 148:
        /* Line 1792 of yacc.c  */
#line 445 "compiler.y"
    {
        EMIT("PUSH_VAR_OR_ADDR %s // If LVAL context -> ADDR, if RVAL context -> VAL", (yyvsp[(1) - (1)].sval));
        // This is tricky. The context (LHS of assign, arg to scanf(&arg), array index operation vs. RHS) matters.
        // A common approach is to always push address for identifiers, and then explicitly LOAD if value is needed.
        // Or, have different rules/flags. For now, assume RVALUE use:
        EMIT("PUSH_VAL %s // Push value of variable", (yyvsp[(1) - (1)].sval));
    }
    break;

    case 149:
        /* Line 1792 of yacc.c  */
#line 452 "compiler.y"
    { EMIT("PUSH_CONST %d", (yyvsp[(1) - (1)].ival)); (yyval.ival) = (yyvsp[(1) - (1)].ival); }
    break;

    case 150:
        /* Line 1792 of yacc.c  */
#line 453 "compiler.y"
    { EMIT("PUSH_STRING_ADDR \"%s\"", (yyvsp[(1) - (1)].sval)); /* Store string in data segment, push address */ }
    break;

    case 151:
        /* Line 1792 of yacc.c  */
#line 454 "compiler.y"
    { (yyval.ival) = (yyvsp[(2) - (3)].ival); /* Value is that of inner expression */ }
    break;

    case 152:
        /* Line 1792 of yacc.c  */
#line 458 "compiler.y"
    { (yyval.ival) = (yyvsp[(1) - (1)].ival); }
    break;


    /* Line 1792 of yacc.c  */
#line 2443 "compiler.c"
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
#line 461 "compiler.y"


// Error reporting function
void yyerror(const char* s) {
    fprintf(stderr, "Error: %s at line %d near token '%s'\n", s, yylineno, yytext);
}

// Symbol table / code gen stubs (if not defined above or elsewhere)
void add_symbol(const char* name, int type, int size_or_val) {
    // Basic implementation
    EMIT("// SYMBOL_ADD: %s, type %d, size/val %d", name, type, size_or_val);
}
Symbol* lookup_symbol(const char* name) {
    EMIT("// SYMBOL_LOOKUP: %s", name);
    return NULL; // Placeholder
}


// Main function to drive the parser
// (Often in a separate file, but can be here for self-contained yacc file)
/*
int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            perror(argv[1]);
            return 1;
        }
        yyin = file; // Direct yylex to read from this file
    } else {
        yyin = stdin; // Default to standard input
    }

    EMIT("// --- BEGIN STACK CODE ---");
    EMIT("CALL main"); // Standard entry point
    EMIT("HALT");

    // Initialize symbol table, etc. if needed

    if (yyparse() == 0) { // yyparse returns 0 on success
        EMIT("// --- PARSING SUCCESSFUL ---");
    } else {
        EMIT("// --- PARSING FAILED ---");
    }


    EMIT("// --- END STACK CODE ---");
    return 0;
}
*/