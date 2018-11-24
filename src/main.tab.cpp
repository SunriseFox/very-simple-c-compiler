/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "src/main.y" /* yacc.c:339  */

  #include "common.h"
  extern int lineno;
  extern TreeNode * root;
  Symbol::ValueType currentType = Symbol::VALUE_NONE;

  int yylex();
  int yyerror( char const* );
  Scope scope;

#line 77 "src/main.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
   by #include "main.tab.h".  */
#ifndef YY_YY_SRC_MAIN_TAB_H_INCLUDED
# define YY_YY_SRC_MAIN_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_AUTO = 258,
    T_CHAR = 259,
    T_INT = 260,
    T_DOUBLE = 261,
    T_VOID = 262,
    T_STRING = 263,
    K_BREAK = 264,
    K_CASE = 265,
    K_CONTINUE = 266,
    K_DEFAULT = 267,
    K_DO = 268,
    K_ELSE = 269,
    K_FOR = 270,
    K_GOTO = 271,
    K_IF = 272,
    K_RET = 273,
    K_SWITCH = 274,
    K_WHILE = 275,
    LP = 276,
    RP = 277,
    INC = 278,
    DEC = 279,
    SIZEOF = 280,
    NOT = 281,
    BREV = 282,
    LMOVE = 283,
    RMOVE = 284,
    MUL = 285,
    DIV = 286,
    MOD = 287,
    ADD = 288,
    SUB = 289,
    BAND = 290,
    BXOR = 291,
    BOR = 292,
    LESS = 293,
    LESSEQ = 294,
    MORE = 295,
    MOREEQ = 296,
    EQ = 297,
    NE = 298,
    LAND = 299,
    LOR = 300,
    QM = 301,
    COLON = 302,
    MULAS = 303,
    DIVAS = 304,
    MODAS = 305,
    ADDAS = 306,
    SUBAS = 307,
    BANDAS = 308,
    BXORAS = 309,
    BORAS = 310,
    ASSIGN = 311,
    COMMA = 312,
    SEMICOLON = 313,
    LABEL = 314,
    SYMBOL = 315,
    IDENTIFIER = 316,
    LB = 317,
    RB = 318,
    IFX = 319
  };
#endif
/* Tokens.  */
#define T_AUTO 258
#define T_CHAR 259
#define T_INT 260
#define T_DOUBLE 261
#define T_VOID 262
#define T_STRING 263
#define K_BREAK 264
#define K_CASE 265
#define K_CONTINUE 266
#define K_DEFAULT 267
#define K_DO 268
#define K_ELSE 269
#define K_FOR 270
#define K_GOTO 271
#define K_IF 272
#define K_RET 273
#define K_SWITCH 274
#define K_WHILE 275
#define LP 276
#define RP 277
#define INC 278
#define DEC 279
#define SIZEOF 280
#define NOT 281
#define BREV 282
#define LMOVE 283
#define RMOVE 284
#define MUL 285
#define DIV 286
#define MOD 287
#define ADD 288
#define SUB 289
#define BAND 290
#define BXOR 291
#define BOR 292
#define LESS 293
#define LESSEQ 294
#define MORE 295
#define MOREEQ 296
#define EQ 297
#define NE 298
#define LAND 299
#define LOR 300
#define QM 301
#define COLON 302
#define MULAS 303
#define DIVAS 304
#define MODAS 305
#define ADDAS 306
#define SUBAS 307
#define BANDAS 308
#define BXORAS 309
#define BORAS 310
#define ASSIGN 311
#define COMMA 312
#define SEMICOLON 313
#define LABEL 314
#define SYMBOL 315
#define IDENTIFIER 316
#define LB 317
#define RB 318
#define IFX 319

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 13 "src/main.y" /* yacc.c:355  */

  string *value;
  Symbol *symbol;
  TreeNode *node;

#line 251 "src/main.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_MAIN_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 268 "src/main.tab.cpp" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  54
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   289

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  147

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   319

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    84,    84,    87,    91,    94,    99,   102,   105,   108,
     111,   116,   119,   122,   125,   128,   133,   138,   143,   148,
     153,   159,   164,   165,   166,   167,   168,   169,   171,   174,
     180,   184,   189,   199,   202,   208,   211,   214,   217,   220,
     223,   226,   229,   232,   235,   240,   243,   246,   251,   254,
     257,   260,   263,   266,   269,   274,   277,   280,   283,   286,
     289,   294,   297,   300,   303,   308,   311,   314,   319,   322,
     325,   330,   333,   336,   341,   344,   349,   357
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_AUTO", "T_CHAR", "T_INT", "T_DOUBLE",
  "T_VOID", "T_STRING", "K_BREAK", "K_CASE", "K_CONTINUE", "K_DEFAULT",
  "K_DO", "K_ELSE", "K_FOR", "K_GOTO", "K_IF", "K_RET", "K_SWITCH",
  "K_WHILE", "LP", "RP", "INC", "DEC", "SIZEOF", "NOT", "BREV", "LMOVE",
  "RMOVE", "MUL", "DIV", "MOD", "ADD", "SUB", "BAND", "BXOR", "BOR",
  "LESS", "LESSEQ", "MORE", "MOREEQ", "EQ", "NE", "LAND", "LOR", "QM",
  "COLON", "MULAS", "DIVAS", "MODAS", "ADDAS", "SUBAS", "BANDAS", "BXORAS",
  "BORAS", "ASSIGN", "COMMA", "SEMICOLON", "LABEL", "SYMBOL", "IDENTIFIER",
  "LB", "RB", "IFX", "$accept", "start", "program", "lb_scope",
  "statement", "if_condition", "if_else_condition", "for_statement",
  "while_statement", "do_while_statement", "declaration", "type",
  "id_list", "id_pair", "id_prefix", "expression", "assignment", "logical",
  "comparative", "additive", "multiplicative", "bitshift", "bitbinary",
  "postfix", "cast", "node", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319
};
# endif

#define YYPACT_NINF -59

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-59)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     167,   -59,   -59,   -59,   -59,   -59,   -59,   -58,    -7,    -1,
       4,   -11,     3,     3,   -11,   -11,   -59,   -59,   -59,   -26,
      51,   227,   167,   -59,   -59,   -59,   -59,   -59,   -59,    57,
      18,   -49,   -59,    61,   -10,    24,    35,     6,   -59,   -59,
     -59,    22,   -59,   227,   -11,   -11,   -11,   -16,   -59,   -59,
     -59,   -59,   -59,   -59,   -59,   -59,   142,   -59,   -59,    59,
     -59,    62,   -11,   -59,   -11,   -11,   -11,   -11,   -11,   -11,
     -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,
     -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,
     -11,    -8,    50,   -15,    -5,   -59,   -59,    18,   -11,   -59,
     -10,   -10,    24,    24,    24,    24,    24,    24,    35,    35,
      35,    35,    35,     6,     6,     6,   -59,   -59,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    97,   -11,   227,
     227,   -59,   -59,    99,    54,   107,   -59,   -11,   -11,   227,
      -4,    -3,   -59,    65,   227,   -59,   -59
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    27,    23,    22,    25,    26,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     9,    77,    76,     6,
       0,     2,     0,     4,    12,    11,    13,    14,    15,     0,
       0,     0,    33,    35,    45,    48,    55,    61,    65,    68,
      71,    75,     6,     0,     0,     0,     0,     0,    72,    75,
      73,    69,    70,     5,     1,     3,     0,     8,    32,    21,
      28,    31,     0,     7,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,    10,     0,     0,    34,
      46,    47,    49,    50,    51,    52,    53,    54,    56,    57,
      58,    59,    60,    62,    63,    64,    66,    67,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,     0,     0,
       0,    29,    30,     0,     0,    16,    19,     0,     0,     0,
       0,     0,    17,     0,     0,    20,    18
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -59,   -59,   103,   119,   -20,   -59,   -59,   -59,   -59,   -59,
     -59,   -59,   -59,    30,   -59,    -6,    71,    -2,   -17,    33,
      21,    12,   -12,   101,   -59,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    59,    60,    61,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    49
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      41,    55,    51,    52,    42,    47,    95,   129,    62,    63,
      11,    41,    12,    13,    44,    14,    15,   130,   143,   144,
      45,    41,    41,    91,    11,    46,    12,    13,    66,    67,
      68,    69,    70,    71,    80,    81,    55,    53,    92,    93,
      94,    62,    62,    41,    41,    41,    41,   100,   101,    17,
      18,    54,    62,    62,    62,   127,    41,    72,    73,    74,
      75,    76,    41,    17,    18,    77,    78,    79,   116,   117,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    58,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   113,
     114,   115,   132,   108,   109,   110,   111,   112,    41,   102,
     103,   104,   105,   106,   107,    64,    65,    62,   128,   135,
     136,    62,   138,    48,    50,    57,    97,   133,    98,   142,
     137,   139,   134,   145,   146,    56,    43,   131,    41,    41,
      41,   140,   141,    99,     0,     0,     0,    41,    41,    41,
       0,     0,     0,     0,    41,     1,     2,     3,     4,     5,
       6,     0,     0,     0,     0,     7,     0,     8,     0,     9,
       0,     0,    10,    11,     0,    12,    13,     0,    14,    15,
       1,     2,     3,     4,     5,     6,     0,     0,     0,     0,
       7,     0,     8,     0,     9,     0,     0,    10,    11,     0,
      12,    13,     0,    14,    15,     0,     0,     0,     0,     0,
      16,     0,    17,    18,    42,    96,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,     0,    17,    18,    19,
       1,     2,     3,     4,     5,     6,     0,     0,     0,     0,
       7,     0,     8,     0,     9,     0,     0,    10,    11,     0,
      12,    13,     0,    14,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,     0,    17,    18,    42
};

static const yytype_int16 yycheck[] =
{
       0,    21,    14,    15,    62,    11,    22,    22,    57,    58,
      21,    11,    23,    24,    21,    26,    27,    22,    22,    22,
      21,    21,    22,    43,    21,    21,    23,    24,    38,    39,
      40,    41,    42,    43,    28,    29,    56,    63,    44,    45,
      46,    57,    57,    43,    44,    45,    46,    64,    65,    60,
      61,     0,    57,    57,    57,    63,    56,    33,    34,    35,
      36,    37,    62,    60,    61,    30,    31,    32,    80,    81,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    61,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    77,
      78,    79,    98,    72,    73,    74,    75,    76,    98,    66,
      67,    68,    69,    70,    71,    44,    45,    57,    58,   129,
     130,    57,    58,    12,    13,    58,    57,    20,    56,   139,
      21,    14,   128,    58,   144,    22,     7,    97,   128,   129,
     130,   137,   138,    62,    -1,    -1,    -1,   137,   138,   139,
      -1,    -1,    -1,    -1,   144,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    -1,    13,    -1,    15,    -1,    17,
      -1,    -1,    20,    21,    -1,    23,    24,    -1,    26,    27,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,
      13,    -1,    15,    -1,    17,    -1,    -1,    20,    21,    -1,
      23,    24,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    60,    61,    62,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    60,    61,    62,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,
      13,    -1,    15,    -1,    17,    -1,    -1,    20,    21,    -1,
      23,    24,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    60,    61,    62
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    13,    15,    17,
      20,    21,    23,    24,    26,    27,    58,    60,    61,    62,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    62,    68,    21,    21,    21,    80,    88,    90,
      88,    87,    87,    63,     0,    69,    67,    58,    61,    77,
      78,    79,    57,    58,    44,    45,    38,    39,    40,    41,
      42,    43,    33,    34,    35,    36,    37,    30,    31,    32,
      28,    29,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    69,    80,    80,    80,    22,    63,    57,    56,    81,
      83,    83,    84,    84,    84,    84,    84,    84,    85,    85,
      85,    85,    85,    86,    86,    86,    87,    87,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    63,    58,    22,
      22,    78,    80,    20,    80,    69,    69,    21,    58,    14,
      80,    80,    69,    22,    22,    58,    69
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    67,    67,    67,    68,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    70,    71,    72,    73,
      74,    75,    76,    76,    76,    76,    76,    76,    77,    77,
      78,    78,    79,    80,    80,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    82,    82,    82,    83,    83,
      83,    83,    83,    83,    83,    84,    84,    84,    84,    84,
      84,    85,    85,    85,    85,    86,    86,    86,    87,    87,
      87,    88,    88,    88,    89,    89,    90,    90
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     2,     2,     1,
       3,     1,     1,     1,     1,     1,     5,     7,     9,     5,
       9,     2,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     1,     1,     1,     3,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     1,     3,     3,     1,     2,
       2,     1,     2,     2,     3,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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
      yychar = yylex ();
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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 84 "src/main.y" /* yacc.c:1646  */
    {root = (yyvsp[0].node);}
#line 1480 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 87 "src/main.y" /* yacc.c:1646  */
    {
          ((yyvsp[-1].node)) -> addSibling((yyvsp[0].node));
          (yyval.node) = (yyvsp[-1].node);
        }
#line 1489 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 91 "src/main.y" /* yacc.c:1646  */
    {
          (yyval.node) = (yyvsp[0].node);
        }
#line 1497 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 94 "src/main.y" /* yacc.c:1646  */
    {
          (yyval.node) = new StatementNode(lineno, StatementNode::ST_SCOPE);
        }
#line 1505 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 99 "src/main.y" /* yacc.c:1646  */
    { scope.pushScope(); }
#line 1511 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 102 "src/main.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[-1].node);
          }
#line 1519 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 105 "src/main.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[-1].node);
          }
#line 1527 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 108 "src/main.y" /* yacc.c:1646  */
    {
            (yyval.node) = new StatementNode(lineno, StatementNode::ST_EMPTY);
          }
#line 1535 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 111 "src/main.y" /* yacc.c:1646  */
    {
            (yyval.node) = new StatementNode(lineno, StatementNode::ST_SCOPE);
            (yyval.node) -> addChild((yyvsp[-1].node));
            scope.popScope();
          }
#line 1545 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 116 "src/main.y" /* yacc.c:1646  */
    {
              (yyval.node) = (yyvsp[0].node);
          }
#line 1553 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 119 "src/main.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
          }
#line 1561 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 122 "src/main.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
          }
#line 1569 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 125 "src/main.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
          }
#line 1577 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 128 "src/main.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
          }
#line 1585 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 133 "src/main.y" /* yacc.c:1646  */
    {
                (yyval.node) = new StatementNode(lineno, StatementNode::ST_IF, {(yyvsp[-2].node), (yyvsp[0].node)});
              }
#line 1593 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 138 "src/main.y" /* yacc.c:1646  */
    {
                (yyval.node) = new StatementNode(lineno, StatementNode::ST_IF_ELSE, {(yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)});
              }
#line 1601 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 143 "src/main.y" /* yacc.c:1646  */
    {
                (yyval.node) = new StatementNode(lineno, StatementNode::ST_FOR, {(yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)});
              }
#line 1609 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 148 "src/main.y" /* yacc.c:1646  */
    {
                  (yyval.node) = new StatementNode(lineno, StatementNode::ST_WHILE, {(yyvsp[-2].node), (yyvsp[0].node)});
                }
#line 1617 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 153 "src/main.y" /* yacc.c:1646  */
    {
                  (yyval.node) = new StatementNode(lineno, StatementNode::ST_DO_WHILE, {(yyvsp[-6].node), (yyvsp[-2].node)});
                  scope.popScope();
                }
#line 1626 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 159 "src/main.y" /* yacc.c:1646  */
    {
              (yyval.node) = (yyvsp[0].node);
            }
#line 1634 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 164 "src/main.y" /* yacc.c:1646  */
    { currentType = Symbol::VALUE_INT; }
#line 1640 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 165 "src/main.y" /* yacc.c:1646  */
    { currentType = Symbol::VALUE_CHAR; }
#line 1646 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 166 "src/main.y" /* yacc.c:1646  */
    { currentType = Symbol::VALUE_STRING; }
#line 1652 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 167 "src/main.y" /* yacc.c:1646  */
    { currentType = Symbol::VALUE_DOUBLE; }
#line 1658 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 168 "src/main.y" /* yacc.c:1646  */
    { currentType = Symbol::VALUE_VOID; }
#line 1664 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 169 "src/main.y" /* yacc.c:1646  */
    { currentType = Symbol::VALUE_NONE; }
#line 1670 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 171 "src/main.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
          }
#line 1678 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 174 "src/main.y" /* yacc.c:1646  */
    {
            (yyvsp[-2].node) -> addSibling((yyvsp[0].node));
            (yyval.node) = (yyvsp[-2].node);
          }
#line 1687 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 180 "src/main.y" /* yacc.c:1646  */
    {
            (yyval.node) = new DeclarationNode(lineno, (yyvsp[-2].symbol));
            (yyval.node) -> addChild((yyvsp[0].node));
          }
#line 1696 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 184 "src/main.y" /* yacc.c:1646  */
    {
            (yyval.node) = new DeclarationNode(lineno, (yyvsp[0].symbol));
          }
#line 1704 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 189 "src/main.y" /* yacc.c:1646  */
    {
            Symbol* symbol = new Variable(currentType, *(yyvsp[0].value));
            bool ok = scope.insertSymbol(*(yyvsp[0].value), lineno, symbol);
            if (!ok)  {
              cerr << "Line " << lineno << ": symbol " << *(yyvsp[0].value) << " has already been declared." << endl;
              return -1;
            }
            (yyval.symbol) = symbol;
          }
#line 1718 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 199 "src/main.y" /* yacc.c:1646  */
    {
              (yyval.node) = (yyvsp[0].node);
            }
#line 1726 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 202 "src/main.y" /* yacc.c:1646  */
    {
              (yyvsp[-2].node) -> addSibling((yyvsp[0].node));
              (yyval.node) = (yyvsp[0].node);
            }
#line 1735 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 208 "src/main.y" /* yacc.c:1646  */
    {
              (yyval.node) = (yyvsp[0].node);
            }
#line 1743 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 211 "src/main.y" /* yacc.c:1646  */
    {
              (yyval.node) = new OperatorNode(lineno, OperatorNode::OP_MULAS, {(yyvsp[-2].node), (yyvsp[0].node)});
            }
#line 1751 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 214 "src/main.y" /* yacc.c:1646  */
    {
              (yyval.node) = new OperatorNode(lineno, OperatorNode::OP_DIVAS, {(yyvsp[-2].node), (yyvsp[0].node)});
            }
#line 1759 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 217 "src/main.y" /* yacc.c:1646  */
    {
              (yyval.node) = new OperatorNode(lineno, OperatorNode::OP_MODAS, {(yyvsp[-2].node), (yyvsp[0].node)});
            }
#line 1767 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 220 "src/main.y" /* yacc.c:1646  */
    {
              (yyval.node) = new OperatorNode(lineno, OperatorNode::OP_ADDAS, {(yyvsp[-2].node), (yyvsp[0].node)});
            }
#line 1775 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 223 "src/main.y" /* yacc.c:1646  */
    {
              (yyval.node) = new OperatorNode(lineno, OperatorNode::OP_ADDAS, {(yyvsp[-2].node), (yyvsp[0].node)});
            }
#line 1783 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 226 "src/main.y" /* yacc.c:1646  */
    {
              (yyval.node) = new OperatorNode(lineno, OperatorNode::OP_BANDAS, {(yyvsp[-2].node), (yyvsp[0].node)});
            }
#line 1791 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 229 "src/main.y" /* yacc.c:1646  */
    {
              (yyval.node) = new OperatorNode(lineno, OperatorNode::OP_BXORAS, {(yyvsp[-2].node), (yyvsp[0].node)});
            }
#line 1799 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 232 "src/main.y" /* yacc.c:1646  */
    {
              (yyval.node) = new OperatorNode(lineno, OperatorNode::OP_BORAS, {(yyvsp[-2].node), (yyvsp[0].node)});
            }
#line 1807 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 235 "src/main.y" /* yacc.c:1646  */
    {
              (yyval.node) = new OperatorNode(lineno, OperatorNode::OP_ASSIGN, {(yyvsp[-2].node), (yyvsp[0].node)});
            }
#line 1815 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 240 "src/main.y" /* yacc.c:1646  */
    {
              (yyval.node) = (yyvsp[0].node);
            }
#line 1823 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 243 "src/main.y" /* yacc.c:1646  */
    {
              (yyval.node) = new OperatorNode(lineno, OperatorNode::OP_LAND, {(yyvsp[-2].node), (yyvsp[0].node)});
            }
#line 1831 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 246 "src/main.y" /* yacc.c:1646  */
    {
              (yyval.node) = new OperatorNode(lineno, OperatorNode::OP_LOR, {(yyvsp[-2].node), (yyvsp[0].node)});
            }
#line 1839 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 251 "src/main.y" /* yacc.c:1646  */
    {
              (yyval.node) = (yyvsp[0].node);
            }
#line 1847 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 254 "src/main.y" /* yacc.c:1646  */
    {
              (yyval.node) = new OperatorNode(lineno, OperatorNode::OP_LESS, {(yyvsp[-2].node), (yyvsp[0].node)});
            }
#line 1855 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 257 "src/main.y" /* yacc.c:1646  */
    {
              (yyval.node) = new OperatorNode(lineno, OperatorNode::OP_LESSEQ, {(yyvsp[-2].node), (yyvsp[0].node)});
            }
#line 1863 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 260 "src/main.y" /* yacc.c:1646  */
    {
              (yyval.node) = new OperatorNode(lineno, OperatorNode::OP_MORE, {(yyvsp[-2].node), (yyvsp[0].node)});
            }
#line 1871 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 263 "src/main.y" /* yacc.c:1646  */
    {
              (yyval.node) = new OperatorNode(lineno, OperatorNode::OP_MOREEQ, {(yyvsp[-2].node), (yyvsp[0].node)});
            }
#line 1879 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 266 "src/main.y" /* yacc.c:1646  */
    {
              (yyval.node) = new OperatorNode(lineno, OperatorNode::OP_EQ, {(yyvsp[-2].node), (yyvsp[0].node)});
            }
#line 1887 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 269 "src/main.y" /* yacc.c:1646  */
    {
              (yyval.node) = new OperatorNode(lineno, OperatorNode::OP_NE, {(yyvsp[-2].node), (yyvsp[0].node)});
            }
#line 1895 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 274 "src/main.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
          }
#line 1903 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 277 "src/main.y" /* yacc.c:1646  */
    {
            (yyval.node) = new OperatorNode(lineno, OperatorNode::OP_ADD, {(yyvsp[-2].node), (yyvsp[0].node)});
          }
#line 1911 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 280 "src/main.y" /* yacc.c:1646  */
    {
            (yyval.node) = new OperatorNode(lineno, OperatorNode::OP_SUB, {(yyvsp[-2].node), (yyvsp[0].node)});
          }
#line 1919 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 283 "src/main.y" /* yacc.c:1646  */
    {
            (yyval.node) = new OperatorNode(lineno, OperatorNode::OP_BAND, {(yyvsp[-2].node), (yyvsp[0].node)});
          }
#line 1927 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 286 "src/main.y" /* yacc.c:1646  */
    {
            (yyval.node) = new OperatorNode(lineno, OperatorNode::OP_BXOR, {(yyvsp[-2].node), (yyvsp[0].node)});
          }
#line 1935 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 289 "src/main.y" /* yacc.c:1646  */
    {
            (yyval.node) = new OperatorNode(lineno, OperatorNode::OP_BOR, {(yyvsp[-2].node), (yyvsp[0].node)});
          }
#line 1943 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 294 "src/main.y" /* yacc.c:1646  */
    {
                  (yyval.node) = (yyvsp[0].node);
                }
#line 1951 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 297 "src/main.y" /* yacc.c:1646  */
    {
                  (yyval.node) = new OperatorNode(lineno, OperatorNode::OP_MUL, {(yyvsp[-2].node), (yyvsp[0].node)});
                }
#line 1959 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 300 "src/main.y" /* yacc.c:1646  */
    {
                  (yyval.node) = new OperatorNode(lineno, OperatorNode::OP_DIV, {(yyvsp[-2].node), (yyvsp[0].node)});
                }
#line 1967 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 303 "src/main.y" /* yacc.c:1646  */
    {
                  (yyval.node) = new OperatorNode(lineno, OperatorNode::OP_MOD, {(yyvsp[-2].node), (yyvsp[0].node)});
                }
#line 1975 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 308 "src/main.y" /* yacc.c:1646  */
    {
                  (yyval.node) = (yyvsp[0].node);
                }
#line 1983 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 311 "src/main.y" /* yacc.c:1646  */
    {
                  (yyval.node) = new OperatorNode(lineno, OperatorNode::OP_LMOVE, {(yyvsp[-2].node), (yyvsp[0].node)});
                }
#line 1991 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 314 "src/main.y" /* yacc.c:1646  */
    {
                  (yyval.node) = new OperatorNode(lineno, OperatorNode::OP_RMOVE, {(yyvsp[-2].node), (yyvsp[0].node)});
                }
#line 1999 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 319 "src/main.y" /* yacc.c:1646  */
    {
                  (yyval.node) = (yyvsp[0].node);
                }
#line 2007 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 322 "src/main.y" /* yacc.c:1646  */
    {
                  (yyval.node) = new OperatorNode(lineno, OperatorNode::OP_NOT, {(yyvsp[0].node)});
                }
#line 2015 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 325 "src/main.y" /* yacc.c:1646  */
    {
                  (yyval.node) = new OperatorNode(lineno, OperatorNode::OP_BREV, {(yyvsp[0].node)});
                }
#line 2023 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 330 "src/main.y" /* yacc.c:1646  */
    {
                  (yyval.node) = (yyvsp[0].node);
                }
#line 2031 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 333 "src/main.y" /* yacc.c:1646  */
    {
                  (yyval.node) = new OperatorNode(lineno, OperatorNode::OP_INC, {(yyvsp[0].node)});
                }
#line 2039 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 336 "src/main.y" /* yacc.c:1646  */
    {
                  (yyval.node) = new OperatorNode(lineno, OperatorNode::OP_DEC, {(yyvsp[0].node)});
                }
#line 2047 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 341 "src/main.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[-1].node);
      }
#line 2055 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 344 "src/main.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2063 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 349 "src/main.y" /* yacc.c:1646  */
    {
        auto symbol = scope.findSymbol(*(yyvsp[0].value));
        if (symbol == nullptr) {
          std::cerr << "Line " << lineno << ": symbol " << *(yyvsp[0].value) << " is not defined." << endl;
          return -1;
        }
        (yyval.node) = new ExprNode(lineno, symbol);
      }
#line 2076 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 357 "src/main.y" /* yacc.c:1646  */
    {
        (yyval.node) = new ExprNode(lineno, (yyvsp[0].symbol));
      }
#line 2084 "src/main.tab.cpp" /* yacc.c:1646  */
    break;


#line 2088 "src/main.tab.cpp" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 362 "src/main.y" /* yacc.c:1906  */


int yyerror(char const* message)
{
  cout << message << endl;
  return -1;
}
