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
#line 1 "ymini_c.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern int line_no;

void yyerror(const char *s);
void emit(const char *op);
void emit_num(const char *op, int num);
void emit_str(const char *op, const char *str);

// Symbol table structures
typedef struct symbol {
    char *name;
    int type;        // 0: int, 1: array, 2: function
    int offset;      // stack offset for variables
    int size;        // array size or function param count
    struct symbol *next;
} Symbol;

Symbol *symbol_table = NULL;
int stack_offset = 0;
int label_counter = 0;
int current_func_params = 0;

// Function prototypes
Symbol* lookup_symbol(const char *name);
void add_symbol(const char *name, int type, int size);
void enter_scope();
void exit_scope();
char* new_label();
void emit_label(const char *label);
void emit_jump(const char *op, const char *label);

// Label stack for nested control structures
char *label_stack[100];
int label_stack_ptr = 0;

void push_label(const char *label) {
    if (label_stack_ptr < 100) {
        label_stack[label_stack_ptr++] = strdup(label);
    }
}

char* pop_label() {
    if (label_stack_ptr > 0) {
        return label_stack[--label_stack_ptr];
    }
    return NULL;
}


/* Line 371 of yacc.c  */
#line 125 "ymini_c.c"

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
   by #include "ymini_c.h".  */
#ifndef YY_YY_YMINI_C_H_INCLUDED
# define YY_YY_YMINI_C_H_INCLUDED
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
     NUMBER = 258,
     IDENTIFIER = 259,
     STRING = 260,
     INT = 261,
     VOID = 262,
     CHAR = 263,
     IF = 264,
     ELSE = 265,
     WHILE = 266,
     FOR = 267,
     DO = 268,
     SWITCH = 269,
     CASE = 270,
     DEFAULT = 271,
     BREAK = 272,
     CONTINUE = 273,
     RETURN = 274,
     PRINTF = 275,
     SCANF = 276,
     PRINT = 277,
     INCREMENT = 278,
     DECREMENT = 279,
     PLUS_ASSIGN = 280,
     MINUS_ASSIGN = 281,
     MUL_ASSIGN = 282,
     DIV_ASSIGN = 283,
     MOD_ASSIGN = 284,
     LEFT_SHIFT = 285,
     RIGHT_SHIFT = 286,
     LE = 287,
     GE = 288,
     EQ = 289,
     NE = 290,
     AND = 291,
     OR = 292,
     UPLUS = 293,
     UMINUS = 294
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 58 "ymini_c.y"

    int number;
    char *string;


/* Line 387 of yacc.c  */
#line 213 "ymini_c.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_YMINI_C_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 241 "ymini_c.c"

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
YYID (int yyi)
#else
static int
YYID (yyi)
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
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   359

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNRULES -- Number of states.  */
#define YYNSTATES  217

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,     2,     2,    50,    43,     2,
      57,    58,    48,    46,    60,    47,     2,    49,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    40,    59,
      44,    38,    45,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,    42,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,    41,    62,    52,     2,     2,     2,
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
      35,    36,    37,    53,    54
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    18,    25,
      31,    34,    40,    45,    49,    51,    54,    59,    61,    63,
      65,    70,    73,    74,    77,    78,    80,    82,    84,    86,
      88,    90,    93,    95,   103,   109,   115,   124,   132,   140,
     143,   145,   150,   154,   157,   161,   164,   167,   169,   171,
     175,   179,   183,   187,   191,   195,   197,   203,   205,   209,
     211,   215,   217,   221,   223,   227,   229,   233,   235,   239,
     243,   245,   249,   253,   257,   261,   263,   267,   271,   273,
     277,   281,   283,   287,   291,   295,   297,   300,   303,   306,
     309,   312,   315,   317,   322,   326,   331,   334,   337,   342,
     347,   354,   361,   363,   367,   369,   371,   373
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      64,     0,    -1,    65,    -1,    65,    66,    -1,    66,    -1,
      67,    -1,    68,    -1,    72,     4,    59,    -1,    72,     4,
      55,     3,    56,    59,    -1,    72,     4,    38,    84,    59,
      -1,    69,    73,    -1,    72,     4,    57,    70,    58,    -1,
      72,     4,    57,    58,    -1,    70,    60,    71,    -1,    71,
      -1,    72,     4,    -1,    72,     4,    55,    56,    -1,     6,
      -1,     7,    -1,     8,    -1,    61,    74,    75,    62,    -1,
      74,    67,    -1,    -1,    75,    76,    -1,    -1,    77,    -1,
      73,    -1,    78,    -1,    79,    -1,    83,    -1,    80,    -1,
      84,    59,    -1,    59,    -1,     9,    57,    84,    58,    76,
      10,    76,    -1,     9,    57,    84,    58,    76,    -1,    11,
      57,    84,    58,    76,    -1,    12,    57,    77,    84,    59,
      84,    58,    76,    -1,    13,    76,    11,    57,    84,    58,
      59,    -1,    14,    57,    84,    58,    61,    81,    62,    -1,
      81,    82,    -1,    82,    -1,    15,     3,    40,    75,    -1,
      16,    40,    75,    -1,    19,    59,    -1,    19,    84,    59,
      -1,    17,    59,    -1,    18,    59,    -1,    85,    -1,    86,
      -1,    97,    38,    85,    -1,    97,    25,    85,    -1,    97,
      26,    85,    -1,    97,    27,    85,    -1,    97,    28,    85,
      -1,    97,    29,    85,    -1,    87,    -1,    87,    39,    84,
      40,    86,    -1,    88,    -1,    87,    37,    88,    -1,    89,
      -1,    88,    36,    89,    -1,    90,    -1,    89,    41,    90,
      -1,    91,    -1,    90,    42,    91,    -1,    92,    -1,    91,
      43,    92,    -1,    93,    -1,    92,    34,    93,    -1,    92,
      35,    93,    -1,    94,    -1,    93,    44,    94,    -1,    93,
      45,    94,    -1,    93,    32,    94,    -1,    93,    33,    94,
      -1,    95,    -1,    94,    30,    95,    -1,    94,    31,    95,
      -1,    96,    -1,    95,    46,    96,    -1,    95,    47,    96,
      -1,    97,    -1,    96,    48,    97,    -1,    96,    49,    97,
      -1,    96,    50,    97,    -1,    98,    -1,    23,    97,    -1,
      24,    97,    -1,    46,    97,    -1,    47,    97,    -1,    51,
      97,    -1,    52,    97,    -1,   100,    -1,    98,    55,    84,
      56,    -1,    98,    57,    58,    -1,    98,    57,    99,    58,
      -1,    98,    23,    -1,    98,    24,    -1,    22,    57,    84,
      58,    -1,    20,    57,     5,    58,    -1,    20,    57,     5,
      60,    99,    58,    -1,    21,    57,     5,    60,    99,    58,
      -1,    85,    -1,    99,    60,    85,    -1,     4,    -1,     3,
      -1,     5,    -1,    57,    84,    58,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    96,    96,   100,   101,   105,   106,   110,   115,   120,
     130,   140,   148,   158,   161,   167,   171,   178,   179,   180,
     184,   190,   191,   195,   196,   200,   201,   202,   203,   204,
     205,   209,   212,   216,   226,   235,   245,   259,   268,   276,
     277,   281,   291,   297,   300,   303,   306,   312,   316,   317,
     320,   323,   326,   329,   332,   338,   339,   345,   346,   352,
     353,   359,   360,   366,   367,   373,   374,   380,   381,   384,
     390,   391,   394,   397,   400,   406,   407,   410,   416,   417,
     420,   426,   427,   430,   433,   439,   440,   443,   446,   449,
     452,   455,   461,   462,   465,   468,   471,   474,   477,   480,
     484,   488,   495,   496,   500,   513,   516,   520
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "IDENTIFIER", "STRING", "INT",
  "VOID", "CHAR", "IF", "ELSE", "WHILE", "FOR", "DO", "SWITCH", "CASE",
  "DEFAULT", "BREAK", "CONTINUE", "RETURN", "PRINTF", "SCANF", "PRINT",
  "INCREMENT", "DECREMENT", "PLUS_ASSIGN", "MINUS_ASSIGN", "MUL_ASSIGN",
  "DIV_ASSIGN", "MOD_ASSIGN", "LEFT_SHIFT", "RIGHT_SHIFT", "LE", "GE",
  "EQ", "NE", "AND", "OR", "'='", "'?'", "':'", "'|'", "'^'", "'&'", "'<'",
  "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'~'", "UPLUS",
  "UMINUS", "'['", "']'", "'('", "')'", "';'", "','", "'{'", "'}'",
  "$accept", "program", "declaration_list", "declaration",
  "var_declaration", "function_declaration", "function_header",
  "parameter_list", "parameter", "type", "compound_statement",
  "local_declarations", "statement_list", "statement",
  "expression_statement", "selection_statement", "iteration_statement",
  "switch_statement", "case_list", "case_statement", "jump_statement",
  "expression", "assignment_expression", "conditional_expression",
  "logical_or_expression", "logical_and_expression",
  "inclusive_or_expression", "exclusive_or_expression", "and_expression",
  "equality_expression", "relational_expression", "shift_expression",
  "additive_expression", "multiplicative_expression", "unary_expression",
  "postfix_expression", "argument_expression_list", "primary_expression", YY_NULL
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
     285,   286,   287,   288,   289,   290,   291,   292,    61,    63,
      58,   124,    94,    38,    60,    62,    43,    45,    42,    47,
      37,    33,   126,   293,   294,    91,    93,    40,    41,    59,
      44,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    65,    65,    66,    66,    67,    67,    67,
      68,    69,    69,    70,    70,    71,    71,    72,    72,    72,
      73,    74,    74,    75,    75,    76,    76,    76,    76,    76,
      76,    77,    77,    78,    78,    79,    79,    79,    80,    81,
      81,    82,    82,    83,    83,    83,    83,    84,    85,    85,
      85,    85,    85,    85,    85,    86,    86,    87,    87,    88,
      88,    89,    89,    90,    90,    91,    91,    92,    92,    92,
      93,    93,    93,    93,    93,    94,    94,    94,    95,    95,
      95,    96,    96,    96,    96,    97,    97,    97,    97,    97,
      97,    97,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    99,    99,   100,   100,   100,   100
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     5,
       2,     5,     4,     3,     1,     2,     4,     1,     1,     1,
       4,     2,     0,     2,     0,     1,     1,     1,     1,     1,
       1,     2,     1,     7,     5,     5,     8,     7,     7,     2,
       1,     4,     3,     2,     3,     2,     2,     1,     1,     3,
       3,     3,     3,     3,     3,     1,     5,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     2,     2,     2,     2,
       2,     2,     1,     4,     3,     4,     2,     2,     4,     4,
       6,     6,     1,     3,     1,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    17,    18,    19,     0,     2,     4,     5,     6,     0,
       0,     1,     3,    22,    10,     0,    24,     0,     0,     0,
       7,    21,     0,     0,   105,   104,   106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,    48,
      55,    57,    59,    61,    63,    65,    67,    70,    75,    78,
      81,    85,    92,     0,    12,     0,    14,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32,    20,    26,
      23,    25,    27,    28,    30,    29,     0,     0,     0,     0,
      86,    87,    88,    89,    90,    91,     0,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    96,    97,     0,     0,     0,    11,     0,
      15,     0,     0,     0,     0,     0,    45,    46,    43,     0,
      31,     0,     0,     0,   107,    58,    81,     0,    60,    62,
      64,    66,    68,    69,    73,    74,    71,    72,    76,    77,
      79,    80,    82,    83,    84,    50,    51,    52,    53,    54,
      49,     0,    94,   102,     0,     8,    13,     0,     0,     0,
       0,     0,     0,    44,    99,     0,     0,    98,     0,    93,
      95,     0,    16,     0,     0,     0,     0,     0,     0,     0,
      56,   103,    34,    35,     0,     0,     0,   100,   101,     0,
       0,     0,     0,     0,     0,    40,    33,     0,    37,     0,
      24,    38,    39,    36,    24,    42,    41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,     9,    55,    56,    10,
      69,    16,    23,    70,    71,    72,    73,    74,   204,   205,
      75,    76,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,   164,    52
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -198
static const yytype_int16 yypact[] =
{
      48,  -198,  -198,  -198,     2,    48,  -198,  -198,  -198,   -49,
      14,  -198,  -198,  -198,  -198,    12,    48,   302,    45,     8,
    -198,  -198,    36,   138,  -198,  -198,  -198,    43,    46,    68,
     302,   302,   302,   302,   302,   302,   302,    17,  -198,  -198,
      22,   108,   104,   106,   111,    -3,    84,    79,    80,    25,
      86,   -16,  -198,   107,  -198,    10,  -198,   160,     5,   109,
     110,   113,   198,   114,   116,   117,     6,  -198,  -198,  -198,
    -198,  -198,  -198,  -198,  -198,  -198,   119,   167,   168,   302,
    -198,  -198,  -198,  -198,  -198,  -198,   121,  -198,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,  -198,  -198,   302,   257,   122,  -198,    48,
     125,   302,   302,   243,   154,   302,  -198,  -198,  -198,   123,
    -198,    19,   126,   129,  -198,   108,  -198,   134,   104,   106,
     111,    -3,    84,    84,    79,    79,    79,    79,    80,    80,
      25,    25,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,
    -198,   127,  -198,  -198,    39,  -198,  -198,   132,   133,   135,
     302,   137,   140,  -198,  -198,   302,   302,  -198,   302,  -198,
    -198,   302,  -198,   198,   198,   145,   302,   131,    60,    61,
    -198,  -198,   186,  -198,   302,   147,   115,  -198,  -198,   198,
     148,   149,   210,   174,   -11,  -198,  -198,   198,  -198,   183,
    -198,  -198,  -198,  -198,  -198,   198,   198
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -198,  -198,  -198,   219,   209,  -198,  -198,  -198,   112,   -13,
     217,  -198,  -197,   -61,   105,  -198,  -198,  -198,  -198,    23,
    -198,   -17,   -74,    51,  -198,   142,   143,   141,   144,   146,
      38,   -52,    34,    37,   -10,  -198,   -39,  -198
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      37,   124,    11,    22,   202,   203,    57,   113,   114,    24,
      25,    26,    13,   215,     1,     2,     3,   216,    15,    86,
      80,    81,    82,    83,    84,    85,    27,    28,    29,    30,
      31,    94,    95,   155,   156,   157,   158,   159,   160,   115,
      58,   116,   163,    17,   144,   145,   146,   147,    53,   129,
      17,   211,    32,    33,     1,     2,     3,    34,    35,    88,
      18,    89,   133,    36,    20,   128,    54,    18,   118,    19,
     119,    20,   137,   104,   105,   106,    87,   174,   136,   175,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   152,   153,   154,   180,   161,   181,
      77,   163,   163,    78,   168,   169,    57,   191,   172,   100,
     101,   107,   108,   109,   110,   111,    96,    97,   197,   198,
     181,   181,   192,   193,   112,    79,   102,   103,    98,    99,
     202,   203,   142,   143,   148,   149,   188,   189,   206,   150,
     151,    24,    25,    26,    90,    91,   213,    59,    92,    60,
      61,    62,    63,   185,    93,    64,    65,    66,    27,    28,
      29,    30,    31,   117,   120,   171,   121,   122,   136,   195,
     123,   125,   131,   132,   178,   126,   127,   200,   130,   134,
     167,   165,   173,   179,    32,    33,   176,   177,   182,    34,
      35,   183,   196,   184,   186,    36,   199,    67,   187,    13,
      68,    24,    25,    26,   194,   201,   207,    59,   208,    60,
      61,    62,    63,   209,   210,    64,    65,    66,    27,    28,
      29,    30,    31,   214,    12,    21,    14,   212,   170,   190,
     135,   166,   139,   138,     0,     0,   140,     0,     0,   141,
       0,     0,     0,     0,    32,    33,    24,    25,    26,    34,
      35,     0,     0,     0,     0,    36,     0,    67,     0,    13,
      24,    25,    26,    27,    28,    29,    30,    31,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,    28,    29,
      30,    31,     0,     0,     0,     0,     0,     0,     0,    32,
      33,     0,     0,     0,    34,    35,     0,     0,     0,     0,
      36,     0,    67,    32,    33,    24,    25,    26,    34,    35,
       0,     0,     0,     0,    36,   162,     0,     0,     0,     0,
       0,     0,    27,    28,    29,    30,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    32,    33,
       0,     0,     0,    34,    35,     0,     0,     0,     0,    36
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-198)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      17,    62,     0,    16,    15,    16,    19,    23,    24,     3,
       4,     5,    61,   210,     6,     7,     8,   214,     4,    36,
      30,    31,    32,    33,    34,    35,    20,    21,    22,    23,
      24,    34,    35,   107,   108,   109,   110,   111,   112,    55,
       4,    57,   116,    38,    96,    97,    98,    99,     3,    66,
      38,    62,    46,    47,     6,     7,     8,    51,    52,    37,
      55,    39,    79,    57,    59,    59,    58,    55,    58,    57,
      60,    59,    89,    48,    49,    50,    59,    58,    88,    60,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,    58,   115,    60,
      57,   175,   176,    57,   121,   122,   119,   181,   125,    30,
      31,    25,    26,    27,    28,    29,    32,    33,    58,    58,
      60,    60,   183,   184,    38,    57,    46,    47,    44,    45,
      15,    16,    94,    95,   100,   101,   175,   176,   199,   102,
     103,     3,     4,     5,    36,    41,   207,     9,    42,    11,
      12,    13,    14,   170,    43,    17,    18,    19,    20,    21,
      22,    23,    24,    56,     4,    11,    57,    57,   178,   186,
      57,    57,     5,     5,    40,    59,    59,   194,    59,    58,
      55,    59,    59,    56,    46,    47,    60,    58,    56,    51,
      52,    58,    61,    58,    57,    57,    10,    59,    58,    61,
      62,     3,     4,     5,    59,    58,    58,     9,    59,    11,
      12,    13,    14,     3,    40,    17,    18,    19,    20,    21,
      22,    23,    24,    40,     5,    16,     9,   204,   123,   178,
      88,   119,    91,    90,    -1,    -1,    92,    -1,    -1,    93,
      -1,    -1,    -1,    -1,    46,    47,     3,     4,     5,    51,
      52,    -1,    -1,    -1,    -1,    57,    -1,    59,    -1,    61,
       3,     4,     5,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    -1,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,
      57,    -1,    59,    46,    47,     3,     4,     5,    51,    52,
      -1,    -1,    -1,    -1,    57,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      -1,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    57
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,     8,    64,    65,    66,    67,    68,    69,
      72,     0,    66,    61,    73,     4,    74,    38,    55,    57,
      59,    67,    72,    75,     3,     4,     5,    20,    21,    22,
      23,    24,    46,    47,    51,    52,    57,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,   100,     3,    58,    70,    71,    72,     4,     9,
      11,    12,    13,    14,    17,    18,    19,    59,    62,    73,
      76,    77,    78,    79,    80,    83,    84,    57,    57,    57,
      97,    97,    97,    97,    97,    97,    84,    59,    37,    39,
      36,    41,    42,    43,    34,    35,    32,    33,    44,    45,
      30,    31,    46,    47,    48,    49,    50,    25,    26,    27,
      28,    29,    38,    23,    24,    55,    57,    56,    58,    60,
       4,    57,    57,    57,    76,    57,    59,    59,    59,    84,
      59,     5,     5,    84,    58,    88,    97,    84,    89,    90,
      91,    92,    93,    93,    94,    94,    94,    94,    95,    95,
      96,    96,    97,    97,    97,    85,    85,    85,    85,    85,
      85,    84,    58,    85,    99,    59,    71,    55,    84,    84,
      77,    11,    84,    59,    58,    60,    60,    58,    40,    56,
      58,    60,    56,    58,    58,    84,    57,    58,    99,    99,
      86,    85,    76,    76,    59,    84,    61,    58,    58,    10,
      84,    58,    15,    16,    81,    82,    76,    58,    59,     3,
      40,    62,    82,    76,    40,    75,    75
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

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
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

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
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
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
      if (!yypact_value_is_default (yyn))
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
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
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
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

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
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

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
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

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
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
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
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
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
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 7:
/* Line 1792 of yacc.c  */
#line 110 "ymini_c.y"
    {
        add_symbol((yyvsp[(2) - (3)].string), 0, 1);
        emit("ALLOC");
        if ((yyvsp[(2) - (3)].string)) free((yyvsp[(2) - (3)].string));
    }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 115 "ymini_c.y"
    {
        add_symbol((yyvsp[(2) - (6)].string), 1, (yyvsp[(4) - (6)].number));
        emit_num("ALLOC", (yyvsp[(4) - (6)].number));
        if ((yyvsp[(2) - (6)].string)) free((yyvsp[(2) - (6)].string));
    }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 120 "ymini_c.y"
    {
        add_symbol((yyvsp[(2) - (5)].string), 0, 1);
        emit("ALLOC");
        Symbol *sym = lookup_symbol((yyvsp[(2) - (5)].string));
        if (sym) emit_num("STORE", sym->offset);
        if ((yyvsp[(2) - (5)].string)) free((yyvsp[(2) - (5)].string));
    }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 130 "ymini_c.y"
    {
        emit("RET");
        if ((yyvsp[(1) - (2)].string)) {
            emit_label((yyvsp[(1) - (2)].string));
            free((yyvsp[(1) - (2)].string));
        }
    }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 140 "ymini_c.y"
    {
        (yyval.string) = strdup((yyvsp[(2) - (5)].string));
        add_symbol((yyvsp[(2) - (5)].string), 2, current_func_params);
        emit_str("FUNC", (yyvsp[(2) - (5)].string));
        current_func_params = 0;
        enter_scope();
        if ((yyvsp[(2) - (5)].string)) free((yyvsp[(2) - (5)].string));
    }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 148 "ymini_c.y"
    {
        (yyval.string) = strdup((yyvsp[(2) - (4)].string));
        add_symbol((yyvsp[(2) - (4)].string), 2, 0);
        emit_str("FUNC", (yyvsp[(2) - (4)].string));
        enter_scope();
        if ((yyvsp[(2) - (4)].string)) free((yyvsp[(2) - (4)].string));
    }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 158 "ymini_c.y"
    {
        current_func_params++;
    }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 161 "ymini_c.y"
    {
        current_func_params = 1;
    }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 167 "ymini_c.y"
    {
        add_symbol((yyvsp[(2) - (2)].string), 0, 1);
        if ((yyvsp[(2) - (2)].string)) free((yyvsp[(2) - (2)].string));
    }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 171 "ymini_c.y"
    {
        add_symbol((yyvsp[(2) - (4)].string), 1, 0);
        if ((yyvsp[(2) - (4)].string)) free((yyvsp[(2) - (4)].string));
    }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 178 "ymini_c.y"
    { (yyval.number) = 0; }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 179 "ymini_c.y"
    { (yyval.number) = 1; }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 180 "ymini_c.y"
    { (yyval.number) = 2; }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 184 "ymini_c.y"
    {
        exit_scope();
    }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 209 "ymini_c.y"
    {
        emit("POP");
    }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 216 "ymini_c.y"
    {
        char *else_label = new_label();
        char *end_label = new_label();
        emit_jump("JZ", else_label);
        emit_jump("JMP", end_label);
        emit_label(else_label);
        emit_label(end_label);
        free(else_label);
        free(end_label);
    }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 226 "ymini_c.y"
    {
        char *end_label = new_label();
        emit_jump("JZ", end_label);
        emit_label(end_label);
        free(end_label);
    }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 235 "ymini_c.y"
    {
        char *loop_start = new_label();
        char *loop_end = new_label();
        emit_label(loop_start);
        emit_jump("JZ", loop_end);
        emit_jump("JMP", loop_start);
        emit_label(loop_end);
        free(loop_start);
        free(loop_end);
    }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 245 "ymini_c.y"
    {
        char *loop_start = new_label();
        char *loop_end = new_label();
        char *loop_inc = new_label();
        emit_label(loop_start);
        emit_jump("JZ", loop_end);
        emit_jump("JMP", loop_inc);
        emit_label(loop_inc);
        emit_jump("JMP", loop_start);
        emit_label(loop_end);
        free(loop_start);
        free(loop_end);
        free(loop_inc);
    }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 259 "ymini_c.y"
    {
        char *loop_start = new_label();
        emit_label(loop_start);
        emit_jump("JNZ", loop_start);
        free(loop_start);
    }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 268 "ymini_c.y"
    {
        char *end_label = new_label();
        emit_label(end_label);
        free(end_label);
    }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 281 "ymini_c.y"
    {
        char *next_case = new_label();
        emit("DUP");
        emit_num("CONST", (yyvsp[(2) - (4)].number));
        emit("EQ");
        emit_jump("JZ", next_case);
        emit("POP");
        emit_label(next_case);
        free(next_case);
    }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 291 "ymini_c.y"
    {
        emit("POP");
    }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 297 "ymini_c.y"
    {
        emit("RET");
    }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 300 "ymini_c.y"
    {
        emit("RET");
    }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 303 "ymini_c.y"
    {
        emit("BREAK");
    }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 306 "ymini_c.y"
    {
        emit("CONTINUE");
    }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 317 "ymini_c.y"
    {
        emit("ASSIGN");
    }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 320 "ymini_c.y"
    {
        emit("PLUS_ASSIGN");
    }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 323 "ymini_c.y"
    {
        emit("MINUS_ASSIGN");
    }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 326 "ymini_c.y"
    {
        emit("MUL_ASSIGN");
    }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 329 "ymini_c.y"
    {
        emit("DIV_ASSIGN");
    }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 332 "ymini_c.y"
    {
        emit("MOD_ASSIGN");
    }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 339 "ymini_c.y"
    {
        emit("TERNARY");
    }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 346 "ymini_c.y"
    {
        emit("OR");
    }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 353 "ymini_c.y"
    {
        emit("AND");
    }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 360 "ymini_c.y"
    {
        emit("BOR");
    }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 367 "ymini_c.y"
    {
        emit("XOR");
    }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 374 "ymini_c.y"
    {
        emit("BAND");
    }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 381 "ymini_c.y"
    {
        emit("EQ");
    }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 384 "ymini_c.y"
    {
        emit("NE");
    }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 391 "ymini_c.y"
    {
        emit("LT");
    }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 394 "ymini_c.y"
    {
        emit("GT");
    }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 397 "ymini_c.y"
    {
        emit("LE");
    }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 400 "ymini_c.y"
    {
        emit("GE");
    }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 407 "ymini_c.y"
    {
        emit("SHL");
    }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 410 "ymini_c.y"
    {
        emit("SHR");
    }
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 417 "ymini_c.y"
    {
        emit("ADD");
    }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 420 "ymini_c.y"
    {
        emit("SUB");
    }
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 427 "ymini_c.y"
    {
        emit("MUL");
    }
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 430 "ymini_c.y"
    {
        emit("DIV");
    }
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 433 "ymini_c.y"
    {
        emit("MOD");
    }
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 440 "ymini_c.y"
    {
        emit("PRE_INC");
    }
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 443 "ymini_c.y"
    {
        emit("PRE_DEC");
    }
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 446 "ymini_c.y"
    {
        // No operation needed
    }
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 449 "ymini_c.y"
    {
        emit("NEG");
    }
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 452 "ymini_c.y"
    {
        emit("NOT");
    }
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 455 "ymini_c.y"
    {
        emit("BNOT");
    }
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 462 "ymini_c.y"
    {
        emit("ARRAY_ACCESS");
    }
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 465 "ymini_c.y"
    {
        emit_str("CALL", "function");
    }
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 468 "ymini_c.y"
    {
        emit_str("CALL", "function");
    }
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 471 "ymini_c.y"
    {
        emit("POST_INC");
    }
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 474 "ymini_c.y"
    {
        emit("POST_DEC");
    }
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 477 "ymini_c.y"
    {
        emit("PRINT");
    }
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 480 "ymini_c.y"
    {
        emit_str("PRINTF", (yyvsp[(3) - (4)].string));
        if ((yyvsp[(3) - (4)].string)) free((yyvsp[(3) - (4)].string));
    }
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 484 "ymini_c.y"
    {
        emit_str("PRINTF", (yyvsp[(3) - (6)].string));
        if ((yyvsp[(3) - (6)].string)) free((yyvsp[(3) - (6)].string));
    }
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 488 "ymini_c.y"
    {
        emit_str("SCANF", (yyvsp[(3) - (6)].string));
        if ((yyvsp[(3) - (6)].string)) free((yyvsp[(3) - (6)].string));
    }
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 500 "ymini_c.y"
    {
        Symbol *sym = lookup_symbol((yyvsp[(1) - (1)].string));
        if (sym) {
            if (sym->type == 2) { // function
                emit_str("FUNC_ADDR", (yyvsp[(1) - (1)].string));
            } else {
                emit_num("LOAD", sym->offset);
            }
        } else {
            fprintf(stderr, "Undefined variable: %s\n", (yyvsp[(1) - (1)].string));
        }
        if ((yyvsp[(1) - (1)].string)) free((yyvsp[(1) - (1)].string));
    }
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 513 "ymini_c.y"
    {
        emit_num("CONST", (yyvsp[(1) - (1)].number));
    }
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 516 "ymini_c.y"
    {
        emit_str("STRING", (yyvsp[(1) - (1)].string));
        if ((yyvsp[(1) - (1)].string)) free((yyvsp[(1) - (1)].string));
    }
    break;


/* Line 1792 of yacc.c  */
#line 2291 "ymini_c.c"
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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
        yyerror (yymsgp);
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
	  yydestruct ("Error: discarding",
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
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
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
      if (!yypact_value_is_default (yyn))
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 523 "ymini_c.y"


void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", line_no, s);
}

void emit(const char *op) {
    printf("%s\n", op);
}

void emit_num(const char *op, int num) {
    printf("%s %d\n", op, num);
}

void emit_str(const char *op, const char *str) {
    printf("%s %s\n", op, str);
}

Symbol* lookup_symbol(const char *name) {
    Symbol *sym = symbol_table;
    while (sym) {
        if (strcmp(sym->name, name) == 0) {
            return sym;
        }
        sym = sym->next;
    }
    return NULL;
}

void add_symbol(const char *name, int type, int size) {
    if (!name) return;
    Symbol *sym = malloc(sizeof(Symbol));
    sym->name = strdup(name);
    sym->type = type;
    sym->size = size;
    sym->offset = stack_offset++;
    sym->next = symbol_table;
    symbol_table = sym;
}

void enter_scope() {
    // Simple scope management
}

void exit_scope() {
    // Pop symbols from current scope
}

char* new_label() {
    char *label = malloc(20);
    sprintf(label, "L%d", label_counter++);
    return label;
}

void emit_label(const char *label) {
    printf("%s:\n", label);
}

void emit_jump(const char *op, const char *label) {
    printf("%s %s\n", op, label);
}

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "Cannot open file %s\n", argv[1]);
            return 1;
        }
        yyin = file;
    }
    
    // Initialize with main function call
    emit("START");
    emit_str("CALL", "main");
    emit("HALT");
    
    yyparse();
    
    if (argc > 1) {
        fclose(yyin);
    }
    
    return 0;
}