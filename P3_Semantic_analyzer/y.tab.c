/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "grammar.y"

/** Code by @author Wonsun Ahn, Fall 2024
 * 
 * The parser implementation file.
 */

#include <stdlib.h>
#include <stdio.h>
#include "proj2.h"

extern int yylex();
static void yyerror(char *str);

tree SyntaxTree;
static tree method_type, tree_type;

/* TODO: Add variable definitons as needed. */


#line 90 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    PROGRAMnum = 258,
    IDnum = 259,
    SEMInum = 260,
    CLASSnum = 261,
    DECLARATIONSnum = 262,
    ENDDECLARATIONSnum = 263,
    COMMAnum = 264,
    EQUALnum = 265,
    LBRACEnum = 266,
    RBRACEnum = 267,
    LBRACnum = 268,
    RBRACnum = 269,
    LPARENnum = 270,
    RPARENnum = 271,
    VOIDnum = 272,
    INTnum = 273,
    METHODnum = 274,
    VALnum = 275,
    DOTnum = 276,
    ASSGNnum = 277,
    RETURNnum = 278,
    IFnum = 279,
    ELSEnum = 280,
    WHILEnum = 281,
    LTnum = 282,
    LEnum = 283,
    EQnum = 284,
    NEnum = 285,
    GEnum = 286,
    GTnum = 287,
    PLUSnum = 288,
    MINUSnum = 289,
    ORnum = 290,
    TIMESnum = 291,
    DIVIDEnum = 292,
    ANDnum = 293,
    ICONSTnum = 294,
    SCONSTnum = 295
  };
#endif
/* Tokens.  */
#define PROGRAMnum 258
#define IDnum 259
#define SEMInum 260
#define CLASSnum 261
#define DECLARATIONSnum 262
#define ENDDECLARATIONSnum 263
#define COMMAnum 264
#define EQUALnum 265
#define LBRACEnum 266
#define RBRACEnum 267
#define LBRACnum 268
#define RBRACnum 269
#define LPARENnum 270
#define RPARENnum 271
#define VOIDnum 272
#define INTnum 273
#define METHODnum 274
#define VALnum 275
#define DOTnum 276
#define ASSGNnum 277
#define RETURNnum 278
#define IFnum 279
#define ELSEnum 280
#define WHILEnum 281
#define LTnum 282
#define LEnum 283
#define EQnum 284
#define NEnum 285
#define GEnum 286
#define GTnum 287
#define PLUSnum 288
#define MINUSnum 289
#define ORnum 290
#define TIMESnum 291
#define DIVIDEnum 292
#define ANDnum 293
#define ICONSTnum 294
#define SCONSTnum 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "grammar.y"

  int intg;
  tree tptr;

#line 227 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   233

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  198

#define YYUNDEFTOK  2
#define YYMAXUTOK   295


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    81,    81,    89,    94,   100,   115,   119,   123,   129,
     133,   142,   146,   151,   157,   163,   169,   175,   182,   192,
     197,   201,   205,   214,   218,   223,   227,   231,   235,   240,
     252,   258,   262,   266,   279,   285,   294,   298,   303,   309,
     316,   322,   335,   342,   345,   349,   353,   357,   362,   367,
     373,   378,   385,   388,   392,   396,   401,   405,   410,   414,
     422,   426,   430,   434,   438,   443,   449,   461,   467,   471,
     477,   484,   488,   493,   497,   501,   506,   513,   519,   526,
     530,   535,   542,   547,   548,   552,   564,   569,   574,   580,
     584,   588,   592,   596,   600,   606,   610,   615,   619,   623,
     629,   633,   637,   641,   645,   650,   654
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAMnum", "IDnum", "SEMInum",
  "CLASSnum", "DECLARATIONSnum", "ENDDECLARATIONSnum", "COMMAnum",
  "EQUALnum", "LBRACEnum", "RBRACEnum", "LBRACnum", "RBRACnum",
  "LPARENnum", "RPARENnum", "VOIDnum", "INTnum", "METHODnum", "VALnum",
  "DOTnum", "ASSGNnum", "RETURNnum", "IFnum", "ELSEnum", "WHILEnum",
  "LTnum", "LEnum", "EQnum", "NEnum", "GEnum", "GTnum", "PLUSnum",
  "MINUSnum", "ORnum", "TIMESnum", "DIVIDEnum", "ANDnum", "ICONSTnum",
  "SCONSTnum", "$accept", "Program", "ClassDecl", "ClassBody", "Decls",
  "FieldDecl_Rec", "FieldDecl", "VariableDecIdList", "VariableDecId",
  "Type", "Type_Rec", "VariableInitializer", "ArrayInitializer",
  "ArrayVariableDecIdList", "ArrayCreationExpression",
  "ArrayCreationDimensions", "MethodDecl_Rec", "MethodDecl",
  "FormalParameterList", "Parameter", "RAParameter", "VAParameter",
  "Block", "StatementList", "Statement_Rec", "Statement",
  "AssignmentStatement", "MethodCallStatement", "Variable", "VarList",
  "ExpressionList", "ReturnStatement", "IfStatement", "ElseStatment",
  "WhileStatement", "Expression", "SimpleExpression", "Comp_op", "Term",
  "Operate", "Factor", "UnsignedConstant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

#define YYPACT_NINF (-135)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      24,    77,    99,   105,  -135,    46,   107,   123,   122,   134,
      93,  -135,   122,    59,  -135,    65,    72,    82,  -135,  -135,
      40,  -135,    40,    86,    85,  -135,   136,   138,   145,  -135,
     111,  -135,  -135,   137,    86,  -135,  -135,  -135,  -135,  -135,
     139,    17,   140,   141,   142,  -135,    40,  -135,   144,  -135,
     136,     2,   116,   121,  -135,  -135,   143,    75,     0,     4,
     146,     4,  -135,  -135,  -135,  -135,  -135,  -135,   147,  -135,
      87,    89,  -135,  -135,   102,   150,   148,   149,  -135,   102,
     151,     2,     4,   156,  -135,  -135,  -135,    16,   152,     4,
    -135,     4,  -135,  -135,  -135,  -135,  -135,  -135,     4,     4,
       4,     4,  -135,  -135,  -135,     4,    42,   153,  -135,  -135,
     154,   164,   157,   102,  -135,   102,  -135,   158,    75,     2,
    -135,  -135,   159,   155,   161,    89,    89,    89,   110,  -135,
    -135,     4,   160,   162,    52,   169,  -135,  -135,   109,  -135,
    -135,  -135,  -135,   150,    37,   167,   173,  -135,  -135,    75,
    -135,  -135,   166,  -135,     4,  -135,     4,     4,  -135,   175,
    -135,     4,  -135,  -135,   157,    37,  -135,     4,  -135,  -135,
     165,   168,  -135,  -135,  -135,  -135,   171,   153,   153,   166,
     130,  -135,  -135,     5,  -135,   172,  -135,     4,   170,   153,
     163,    47,  -135,   174,     4,   176,   153,   163
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     2,     0,     0,
       0,     4,     0,     0,     8,     0,     0,     0,    37,     3,
      25,    10,    25,     0,     0,    12,     0,     0,     0,     6,
       0,     7,    36,     0,     0,    20,    21,    22,     9,    11,
      18,     0,    14,     0,     0,     5,    25,    24,     0,    13,
       0,     0,     0,     0,    23,    19,    15,    68,     0,     0,
       0,     0,   106,   105,    17,    27,    28,   102,   101,    26,
      83,    85,    95,   100,    52,     0,     0,     0,    42,    52,
       0,     0,     0,     0,    67,    30,    31,     0,     0,     0,
     104,    73,    89,    90,    91,    92,    93,    94,     0,     0,
       0,     0,    97,    98,    99,     0,     0,    54,    39,    55,
      48,    44,     0,    52,    41,    52,    16,     0,    68,     0,
      29,   103,     0,     0,    71,    86,    87,    88,    84,    96,
      56,    75,     0,     0,     0,     0,    60,    61,     0,    62,
      63,    64,    53,     0,    43,    50,    45,    38,    40,    68,
      69,    32,    35,    66,    73,    74,     0,     0,    57,     0,
      58,     0,    49,    46,     0,    43,    70,     0,    33,    72,
       0,     0,    59,    65,    51,    47,     0,     0,     0,    35,
      77,    82,    34,     0,    76,     0,    79,     0,     0,     0,
      78,     0,    81,     0,     0,     0,     0,    80
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -135,  -135,  -135,   178,   181,  -135,   177,  -135,   132,    36,
      -1,   -57,  -135,  -135,  -135,    14,   179,    30,   180,  -134,
      51,    19,   -65,  -104,  -135,    62,  -135,   -99,   -97,  -116,
      43,  -135,  -135,    18,  -135,   -59,    98,  -135,    48,  -135,
     -56,  -135
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     7,    11,   107,    24,    25,    41,    42,    26,
      35,    64,    65,    87,    66,   168,    17,    18,    77,    78,
     111,   146,   108,   109,   134,   135,   136,    67,    68,    84,
     123,   139,   140,   192,   141,    69,    70,   101,    71,   105,
      72,    73
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      88,    86,   150,   142,    57,    90,    57,   137,    57,   138,
     163,    58,    85,    58,   114,    59,   106,    59,    60,    59,
      60,    36,    49,   117,   116,   119,    50,     1,   120,   185,
     122,   175,   124,   166,    61,   137,    61,   138,    61,    62,
      63,    62,    63,    62,    63,    54,    57,    32,   147,   129,
     148,    28,     6,    33,   130,    75,    57,    76,   106,    37,
      32,    34,   151,    20,   158,   131,   132,    21,   133,    20,
      47,   193,   155,   180,   181,   131,   132,    22,   133,   186,
      23,     3,    27,    22,    29,   190,    23,   186,    82,    20,
      20,    15,   197,    38,    31,   124,    83,   170,   171,     4,
      13,    15,   173,    22,    22,    14,    23,    23,   176,    13,
       5,     8,    15,   106,    92,    93,    94,    95,    96,    97,
      98,    99,   100,    45,    91,   102,   103,   104,   188,     9,
      15,   161,    74,    10,    75,   195,    76,    79,    12,    75,
      40,    76,    43,    98,    99,   100,   125,   126,   127,    44,
      51,    46,    48,    81,   110,   183,    52,    53,    55,    89,
     118,   145,    91,   143,   106,   113,   112,   115,   121,   144,
     154,   153,   149,   152,   160,   156,   164,   157,   165,   167,
     172,   177,    56,   174,   178,   179,   189,   187,   191,   194,
      19,    16,   196,   182,   162,    30,   159,   169,   184,   128,
       0,    39,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80
};

static const yytype_int16 yycheck[] =
{
      59,    58,   118,   107,     4,    61,     4,   106,     4,   106,
     144,    11,    12,    11,    79,    15,    11,    15,    18,    15,
      18,    22,     5,    82,    81,     9,     9,     3,    12,    24,
      89,   165,    91,   149,    34,   134,    34,   134,    34,    39,
      40,    39,    40,    39,    40,    46,     4,    17,   113,   105,
     115,    15,     6,    13,    12,    18,     4,    20,    11,    23,
      30,    21,   119,     4,    12,    23,    24,     8,    26,     4,
      34,    24,   131,   177,   178,    23,    24,    18,    26,   183,
      21,     4,    17,    18,    12,   189,    21,   191,    13,     4,
       4,    19,   196,     8,    12,   154,    21,   156,   157,     0,
       7,    19,   161,    18,    18,    12,    21,    21,   167,     7,
       5,     4,    19,    11,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    12,    15,    36,    37,    38,   187,     6,
      19,    22,    16,    11,    18,   194,    20,    16,     4,    18,
       4,    20,     4,    33,    34,    35,    98,    99,   100,     4,
      10,    14,    13,    10,     4,    25,    15,    15,    14,    13,
       4,     4,    15,     9,    11,    16,    18,    16,    16,     5,
       9,    16,    14,    14,     5,    15,     9,    15,     5,    13,
       5,    16,    50,   164,    16,    14,    16,    15,    25,    15,
      12,    10,    16,   179,   143,    16,   134,   154,   180,   101,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    42,     4,     0,     5,     6,    43,     4,     6,
      11,    44,     4,     7,    12,    19,    45,    57,    58,    44,
       4,     8,    18,    21,    46,    47,    50,    17,    50,    12,
      57,    12,    58,    13,    21,    51,    51,    50,     8,    47,
       4,    48,    49,     4,     4,    12,    14,    50,    13,     5,
       9,    10,    15,    15,    51,    14,    49,     4,    11,    15,
      18,    34,    39,    40,    52,    53,    55,    68,    69,    76,
      77,    79,    81,    82,    16,    18,    20,    59,    60,    16,
      59,    10,    13,    21,    70,    12,    52,    54,    76,    13,
      81,    15,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    78,    36,    37,    38,    80,    11,    45,    63,    64,
       4,    61,    18,    16,    63,    16,    52,    76,     4,     9,
      12,    16,    76,    71,    76,    79,    79,    79,    77,    81,
      12,    23,    24,    26,    65,    66,    67,    68,    69,    72,
      73,    75,    64,     9,     5,     4,    62,    63,    63,    14,
      70,    52,    14,    16,     9,    76,    15,    15,    12,    66,
       5,    22,    61,    60,     9,     5,    70,    13,    56,    71,
      76,    76,     5,    76,    62,    60,    76,    16,    16,    14,
      64,    64,    56,    25,    74,    24,    64,    15,    76,    16,
      64,    25,    74,    24,    15,    76,    16,    64
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    44,    45,
      45,    46,    46,    47,    48,    48,    48,    48,    49,    49,
      50,    50,    50,    51,    51,    51,    52,    52,    52,    53,
      53,    54,    54,    55,    56,    56,    57,    57,    58,    58,
      58,    58,    59,    60,    60,    60,    60,    60,    61,    61,
      62,    62,    63,    63,    63,    63,    64,    64,    65,    65,
      66,    66,    66,    66,    66,    67,    68,    69,    70,    70,
      70,    71,    71,    71,    72,    72,    73,    73,    73,    74,
      74,    74,    75,    76,    76,    77,    77,    77,    77,    78,
      78,    78,    78,    78,    78,    79,    79,    80,    80,    80,
      81,    81,    81,    81,    81,    82,    82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     4,     3,     4,     3,     3,     2,     3,
       2,     2,     1,     3,     1,     3,     5,     3,     1,     3,
       2,     2,     2,     3,     2,     0,     1,     1,     1,     3,
       2,     1,     3,     5,     4,     0,     2,     1,     7,     6,
       7,     6,     1,     0,     2,     3,     4,     5,     1,     3,
       1,     3,     0,     2,     1,     1,     2,     3,     2,     3,
       1,     1,     1,     1,     1,     3,     4,     2,     0,     3,
       4,     1,     3,     0,     2,     1,     6,     5,    11,     2,
       6,     7,     5,     1,     3,     1,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     3,     2,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 82 "grammar.y"
                        { 
                          (yyval.tptr) = MakeTree(ProgramOp, (yyvsp[0].tptr), MakeLeaf(IDNode, (yyvsp[-2].intg)));
                          SyntaxTree = (yyval.tptr);
                        }
#line 1557 "y.tab.c"
    break;

  case 3:
#line 90 "grammar.y"
                        {
                          tree moreClass = MakeTree(ClassDefOp, (yyvsp[0].tptr), MakeLeaf(IDNode, (yyvsp[-1].intg)));
                          (yyval.tptr) = MakeTree(ClassOp, (yyvsp[-3].tptr) ,moreClass);
                        }
#line 1566 "y.tab.c"
    break;

  case 4:
#line 95 "grammar.y"
                        {
                          tree oneClass = MakeTree(ClassDefOp, (yyvsp[0].tptr), MakeLeaf(IDNode, (yyvsp[-1].intg)));
                          (yyval.tptr) = MakeTree(ClassOp, NullExp(),oneClass);
                        }
#line 1575 "y.tab.c"
    break;

  case 5:
#line 101 "grammar.y"
                        {
                          // if($3 == NullExp())
                          // {
                          //   $$ = $2;
                          // }
                          // else if($2 != NullExp())
                          // {
                          //   $$ = NullExp();
                          // }
                          // else
                          // {
                            (yyval.tptr) = MkLeftC((yyvsp[-2].tptr), (yyvsp[-1].tptr));
                          //}
                        }
#line 1594 "y.tab.c"
    break;

  case 6:
#line 116 "grammar.y"
                        {
                          (yyval.tptr) = (yyvsp[-1].tptr);
                        }
#line 1602 "y.tab.c"
    break;

  case 7:
#line 120 "grammar.y"
                        {
                          (yyval.tptr) = (yyvsp[-1].tptr);
                        }
#line 1610 "y.tab.c"
    break;

  case 8:
#line 124 "grammar.y"
                        {
                          (yyval.tptr) = NullExp();
                        }
#line 1618 "y.tab.c"
    break;

  case 9:
#line 130 "grammar.y"
                        {
                          (yyval.tptr) = (yyvsp[-1].tptr);
                        }
#line 1626 "y.tab.c"
    break;

  case 10:
#line 134 "grammar.y"
                        {
                          (yyval.tptr) = MakeTree(BodyOp, NullExp(), NullExp());
                        }
#line 1634 "y.tab.c"
    break;

  case 11:
#line 143 "grammar.y"
                        {
                          (yyval.tptr) = MakeTree(BodyOp, (yyvsp[-1].tptr), (yyvsp[0].tptr));
                        }
#line 1642 "y.tab.c"
    break;

  case 12:
#line 147 "grammar.y"
                        {
                          (yyval.tptr) = MakeTree(BodyOp, NullExp(), (yyvsp[0].tptr));
                        }
#line 1650 "y.tab.c"
    break;

  case 13:
#line 152 "grammar.y"
                        {
                          (yyval.tptr) = (yyvsp[-1].tptr);
                        }
#line 1658 "y.tab.c"
    break;

  case 14:
#line 158 "grammar.y"
                        {
                          tree comma = MakeTree(CommaOp,tree_type, NullExp());
                          tree var = MakeTree(CommaOp, (yyvsp[0].tptr), comma);
                          (yyval.tptr) = MakeTree(DeclOp, NullExp(),var);
                        }
#line 1668 "y.tab.c"
    break;

  case 15:
#line 164 "grammar.y"
                        {
                          tree comma = MakeTree(CommaOp,tree_type, NullExp());
                          tree var = MakeTree(CommaOp, (yyvsp[0].tptr), comma);
                          (yyval.tptr) = MakeTree(DeclOp, (yyvsp[-2].tptr),var);
                        }
#line 1678 "y.tab.c"
    break;

  case 16:
#line 170 "grammar.y"
                        {
                          tree comma = MakeTree(CommaOp,tree_type, (yyvsp[0].tptr));
                          tree var = MakeTree(CommaOp, (yyvsp[-2].tptr), comma);
                          (yyval.tptr) = MakeTree(DeclOp, (yyvsp[-4].tptr),var);
                        }
#line 1688 "y.tab.c"
    break;

  case 17:
#line 176 "grammar.y"
                        {
                          tree comma = MakeTree(CommaOp,tree_type, (yyvsp[0].tptr));
                          tree var = MakeTree(CommaOp, (yyvsp[-2].tptr), comma);
                          (yyval.tptr) = MakeTree(DeclOp, NullExp(),var);
                        }
#line 1698 "y.tab.c"
    break;

  case 18:
#line 183 "grammar.y"
                        {
                          (yyval.tptr) = MakeLeaf(IDNode, (yyvsp[0].intg));
                        }
#line 1706 "y.tab.c"
    break;

  case 19:
#line 193 "grammar.y"
                        {
                          (yyval.tptr) = MakeLeaf(IDNode, (yyvsp[-2].intg));
                        }
#line 1714 "y.tab.c"
    break;

  case 20:
#line 198 "grammar.y"
                        {
                          (yyval.tptr) = tree_type = MakeTree(TypeIdOp, MakeLeaf(IDNode, (yyvsp[-1].intg)), (yyvsp[0].tptr));
                        }
#line 1722 "y.tab.c"
    break;

  case 21:
#line 202 "grammar.y"
                        {
                          (yyval.tptr)  = tree_type = MakeTree(TypeIdOp, MakeLeaf(INTEGERTNode, (yyvsp[-1].intg)), (yyvsp[0].tptr));
                        }
#line 1730 "y.tab.c"
    break;

  case 22:
#line 206 "grammar.y"
                        {
                          (yyval.tptr) = MakeTree(FieldOp,(yyvsp[0].tptr), NullExp()); 
                        }
#line 1738 "y.tab.c"
    break;

  case 23:
#line 215 "grammar.y"
                        {
                          (yyval.tptr)  = MakeTree(IndexOp, NullExp(), (yyvsp[0].tptr));
                        }
#line 1746 "y.tab.c"
    break;

  case 24:
#line 219 "grammar.y"
                        {
                          (yyval.tptr) = MakeTree(FieldOp,(yyvsp[0].tptr), NullExp()); 
                        }
#line 1754 "y.tab.c"
    break;

  case 25:
#line 223 "grammar.y"
                        {
                          (yyval.tptr) = NullExp();
                        }
#line 1762 "y.tab.c"
    break;

  case 26:
#line 228 "grammar.y"
                        {
                          (yyval.tptr) = (yyvsp[0].tptr);
                        }
#line 1770 "y.tab.c"
    break;

  case 27:
#line 232 "grammar.y"
                        {
                          (yyval.tptr) = (yyvsp[0].tptr);
                        }
#line 1778 "y.tab.c"
    break;

  case 28:
#line 236 "grammar.y"
                        {
                          (yyval.tptr) = (yyvsp[0].tptr);
                        }
#line 1786 "y.tab.c"
    break;

  case 29:
#line 241 "grammar.y"
                        {
                          // if($2 == NullExp())
                          // {
                          //   tree comma = MakeTree(CommaOp, NullExp(), NullExp());
                          //   $$ = MakeTree(ArrayTypeOp, tree_type, comma);
                          // }
                          // else
                          // {
                            (yyval.tptr) = MakeTree(ArrayTypeOp, (yyvsp[-1].tptr), tree_type);
                          //}
                        }
#line 1802 "y.tab.c"
    break;

  case 30:
#line 253 "grammar.y"
                        {
                          tree comma = MakeTree(CommaOp, NullExp(), NullExp());
                          (yyval.tptr) = MakeTree(ArrayTypeOp, tree_type, comma);
                        }
#line 1811 "y.tab.c"
    break;

  case 31:
#line 259 "grammar.y"
                          {
                            (yyval.tptr) = MakeTree(CommaOp, NullExp(),(yyvsp[0].tptr));
                          }
#line 1819 "y.tab.c"
    break;

  case 32:
#line 263 "grammar.y"
                          {
                            (yyval.tptr) = MakeTree(CommaOp, (yyvsp[-2].tptr),(yyvsp[0].tptr));
                          }
#line 1827 "y.tab.c"
    break;

  case 33:
#line 267 "grammar.y"
                         {
                           /* Create the int type leaf */
                           tree integr = MakeLeaf(INTEGERTNode, 0);

                           /* Handle array dimensions recursively */
                           tree dimensionTree = MakeTree(BoundOp, (yyvsp[0].tptr), (yyvsp[-2].tptr));

                           /* Create the final array type node */
                           (yyval.tptr) = MakeTree(ArrayTypeOp, dimensionTree, integr);
                         }
#line 1842 "y.tab.c"
    break;

  case 34:
#line 280 "grammar.y"
                         {
                           /* Recursive case: Adding array dimension using BoundOp */
                           (yyval.tptr) = MakeTree(BoundOp, (yyvsp[0].tptr), (yyvsp[-2].tptr));
                         }
#line 1851 "y.tab.c"
    break;

  case 35:
#line 285 "grammar.y"
                         {
                          (yyval.tptr) = NullExp();
                         }
#line 1859 "y.tab.c"
    break;

  case 36:
#line 295 "grammar.y"
                        {
                          (yyval.tptr) = MakeTree(BodyOp, (yyvsp[-1].tptr), (yyvsp[0].tptr));
                        }
#line 1867 "y.tab.c"
    break;

  case 37:
#line 299 "grammar.y"
                        {
                          (yyval.tptr) = MakeTree(BodyOp, NullExp(), (yyvsp[0].tptr));
                        }
#line 1875 "y.tab.c"
    break;

  case 38:
#line 304 "grammar.y"
                      {
                        method_type = NullExp();
                        tree head = MakeTree(HeadOp, MakeLeaf(IDNode, (yyvsp[-4].intg)), (yyvsp[-2].tptr));
                        (yyval.tptr) = MakeTree(MethodOp, head, (yyvsp[0].tptr));
                      }
#line 1885 "y.tab.c"
    break;

  case 39:
#line 310 "grammar.y"
                    {
                        method_type = NullExp();
                        tree spec = MakeTree(SpecOp, NullExp(), method_type);
                        tree head = MakeTree(HeadOp, MakeLeaf(IDNode, (yyvsp[-3].intg)), spec);
                        (yyval.tptr) = MakeTree(MethodOp, head, (yyvsp[0].tptr));
                    }
#line 1896 "y.tab.c"
    break;

  case 40:
#line 317 "grammar.y"
                      {
                        method_type = (yyvsp[-5].tptr);
                        tree head = MakeTree(HeadOp, MakeLeaf(IDNode, (yyvsp[-4].intg)), (yyvsp[-2].tptr));
                        (yyval.tptr) = MakeTree(MethodOp, head, (yyvsp[0].tptr));
                      }
#line 1906 "y.tab.c"
    break;

  case 41:
#line 323 "grammar.y"
                    {
                      method_type = (yyvsp[-4].tptr);
                      tree spec = MakeTree(SpecOp, NullExp(), method_type);
                      tree head = MakeTree(HeadOp, MakeLeaf(IDNode, (yyvsp[-3].intg)), spec);
                      (yyval.tptr) = MakeTree(MethodOp, head, (yyvsp[0].tptr));
                    }
#line 1917 "y.tab.c"
    break;

  case 42:
#line 336 "grammar.y"
                     {
                       /* Single parameter */
                       (yyval.tptr) = MakeTree(SpecOp, (yyvsp[0].tptr), tree_type);
                     }
#line 1926 "y.tab.c"
    break;

  case 43:
#line 342 "grammar.y"
                      {
                        (yyval.tptr) = NullExp();
                      }
#line 1934 "y.tab.c"
    break;

  case 44:
#line 346 "grammar.y"
                      {
                        (yyval.tptr) = (yyvsp[0].tptr);
                      }
#line 1942 "y.tab.c"
    break;

  case 45:
#line 350 "grammar.y"
                      {
                        (yyval.tptr) = (yyvsp[0].tptr);
                      }
#line 1950 "y.tab.c"
    break;

  case 46:
#line 354 "grammar.y"
                      {
                        (yyval.tptr) = MkRightC((yyvsp[0].tptr),(yyvsp[-2].tptr));
                      }
#line 1958 "y.tab.c"
    break;

  case 47:
#line 358 "grammar.y"
                      {
                        (yyval.tptr) = MkRightC((yyvsp[0].tptr), (yyvsp[-2].tptr));
                      }
#line 1966 "y.tab.c"
    break;

  case 48:
#line 363 "grammar.y"
                      {
                        tree comma = MakeTree(CommaOp, MakeLeaf(IDNode, (yyvsp[0].intg)), MakeLeaf(INTEGERTNode, 0));
                        (yyval.tptr) = MakeTree(RArgTypeOp, comma, NullExp());
                      }
#line 1975 "y.tab.c"
    break;

  case 49:
#line 368 "grammar.y"
                      {
                        tree comma = MakeTree(CommaOp, MakeLeaf(IDNode, (yyvsp[-2].intg)), MakeLeaf(INTEGERTNode, 0));
                        (yyval.tptr) = MakeTree(RArgTypeOp, comma, (yyvsp[0].tptr));
                      }
#line 1984 "y.tab.c"
    break;

  case 50:
#line 374 "grammar.y"
                      {
                        tree comma = MakeTree(CommaOp, MakeLeaf(IDNode, (yyvsp[0].intg)), MakeLeaf(INTEGERTNode, 0));
                        (yyval.tptr) = MakeTree(VArgTypeOp, comma, NullExp());
                      }
#line 1993 "y.tab.c"
    break;

  case 51:
#line 379 "grammar.y"
                      {
                        tree comma = MakeTree(CommaOp, MakeLeaf(IDNode, (yyvsp[-2].intg)), MakeLeaf(INTEGERTNode, 0));
                        (yyval.tptr) = MakeTree(VArgTypeOp, comma, (yyvsp[0].tptr));
                      }
#line 2002 "y.tab.c"
    break;

  case 52:
#line 385 "grammar.y"
                      {
                        (yyval.tptr) = MakeTree(BodyOp, NullExp(), NullExp());
                      }
#line 2010 "y.tab.c"
    break;

  case 53:
#line 389 "grammar.y"
                      {
                        (yyval.tptr) = MakeTree(BodyOp, (yyvsp[-1].tptr), (yyvsp[0].tptr));
                      }
#line 2018 "y.tab.c"
    break;

  case 54:
#line 393 "grammar.y"
                      {
                        (yyval.tptr) = MakeTree(BodyOp,  (yyvsp[0].tptr), NullExp());
                      }
#line 2026 "y.tab.c"
    break;

  case 55:
#line 397 "grammar.y"
                      {
                        (yyval.tptr) = MakeTree(BodyOp, NullExp(), (yyvsp[0].tptr));
                      }
#line 2034 "y.tab.c"
    break;

  case 56:
#line 402 "grammar.y"
                      {
                        (yyval.tptr) = MakeTree(BodyOp, NullExp(), NullExp());
                      }
#line 2042 "y.tab.c"
    break;

  case 57:
#line 406 "grammar.y"
                      {
                        (yyval.tptr) = (yyvsp[-1].tptr);
                      }
#line 2050 "y.tab.c"
    break;

  case 58:
#line 411 "grammar.y"
                      {
                        (yyval.tptr) = MakeTree(StmtOp, NullExp(),(yyvsp[-1].tptr));
                      }
#line 2058 "y.tab.c"
    break;

  case 59:
#line 415 "grammar.y"
                      {
                        (yyval.tptr) = MakeTree(StmtOp, (yyvsp[-2].tptr), (yyvsp[-1].tptr));
                      }
#line 2066 "y.tab.c"
    break;

  case 60:
#line 423 "grammar.y"
                      {
                        (yyval.tptr) = (yyvsp[0].tptr);
                      }
#line 2074 "y.tab.c"
    break;

  case 61:
#line 427 "grammar.y"
                      {
                        (yyval.tptr) = (yyvsp[0].tptr);
                      }
#line 2082 "y.tab.c"
    break;

  case 62:
#line 431 "grammar.y"
                      {
                        (yyval.tptr) = (yyvsp[0].tptr);
                      }
#line 2090 "y.tab.c"
    break;

  case 63:
#line 435 "grammar.y"
                      {
                        (yyval.tptr) = (yyvsp[0].tptr);
                      }
#line 2098 "y.tab.c"
    break;

  case 64:
#line 439 "grammar.y"
                      {
                        (yyval.tptr) = (yyvsp[0].tptr);
                      }
#line 2106 "y.tab.c"
    break;

  case 65:
#line 444 "grammar.y"
                      {
                        tree innerA = MakeTree(AssignOp, NullExp(), (yyvsp[-2].tptr));
                        (yyval.tptr) = MakeTree(AssignOp,innerA, (yyvsp[0].tptr));
                      }
#line 2115 "y.tab.c"
    break;

  case 66:
#line 450 "grammar.y"
                      {
                        if((yyvsp[-1].tptr) == NullExp())
                        {
                          (yyval.tptr) = MakeTree(RoutineCallOp,(yyvsp[-3].tptr), NullExp());
                        }
                        else
                        {
                          (yyval.tptr) = MakeTree(RoutineCallOp, (yyvsp[-3].tptr), (yyvsp[-1].tptr));
                        }
                      }
#line 2130 "y.tab.c"
    break;

  case 67:
#line 462 "grammar.y"
                      {
                        (yyval.tptr) = MakeTree(VarOp, MakeLeaf(IDNode, (yyvsp[-1].intg)), (yyvsp[0].tptr));
                      }
#line 2138 "y.tab.c"
    break;

  case 68:
#line 467 "grammar.y"
                      {
                        /* Represents an empty sequence of selectors */
                        (yyval.tptr) = NullExp();
                      }
#line 2147 "y.tab.c"
    break;

  case 69:
#line 472 "grammar.y"
                      {
                        /* Field access followed by more selectors */
                        tree field = MakeTree(FieldOp, MakeLeaf(IDNode, (yyvsp[-1].intg)), NullExp());
                        (yyval.tptr) = MakeTree(SelectOp, field, (yyvsp[0].tptr));
                      }
#line 2157 "y.tab.c"
    break;

  case 70:
#line 478 "grammar.y"
                      {
                        /* Array index followed by more selectors */
                        tree index = MakeTree(IndexOp, (yyvsp[-2].tptr), NullExp());
                        (yyval.tptr) = MakeTree(SelectOp, index, (yyvsp[0].tptr));
                      }
#line 2167 "y.tab.c"
    break;

  case 71:
#line 485 "grammar.y"
                      {
                        (yyval.tptr) = MakeTree(CommaOp, (yyvsp[0].tptr), NullExp());
                      }
#line 2175 "y.tab.c"
    break;

  case 72:
#line 489 "grammar.y"
                      {
                        (yyval.tptr) = MakeTree(CommaOp, (yyvsp[-2].tptr), (yyvsp[0].tptr));
                      }
#line 2183 "y.tab.c"
    break;

  case 73:
#line 493 "grammar.y"
                      {
                        (yyval.tptr) = NullExp();
                      }
#line 2191 "y.tab.c"
    break;

  case 74:
#line 498 "grammar.y"
                      {
                        (yyval.tptr) = MakeTree(ReturnOp,(yyvsp[0].tptr), NullExp());
                      }
#line 2199 "y.tab.c"
    break;

  case 75:
#line 502 "grammar.y"
                      {
                        (yyval.tptr) = MakeTree(ReturnOp,NullExp(), NullExp());
                      }
#line 2207 "y.tab.c"
    break;

  case 76:
#line 507 "grammar.y"
                      {
                        /* Handle an if-else statement */
                        tree comma = MakeTree(CommaOp, (yyvsp[-3].tptr), (yyvsp[-1].tptr)); // Combines the if condition and statement block
                        tree ifElse = MakeTree(IfElseOp, NullExp(), comma); // If part
                        (yyval.tptr) = MkLeftC(ifElse, (yyvsp[0].tptr)); // Attach the else block
                      }
#line 2218 "y.tab.c"
    break;

  case 77:
#line 514 "grammar.y"
                      {
                        /* Handle an if statement without an else part */
                        tree comma = MakeTree(CommaOp, (yyvsp[-2].tptr), (yyvsp[0].tptr)); // Combines the if condition and statement block
                        (yyval.tptr) = MakeTree(IfElseOp, NullExp(), comma); // Simple if without else
                      }
#line 2228 "y.tab.c"
    break;

  case 78:
#line 520 "grammar.y"
                      {
                        tree comma = MakeTree(CommaOp, (yyvsp[-8].tptr), (yyvsp[-6].tptr));
                        tree elseif = MakeTree(CommaOp, (yyvsp[-2].tptr), (yyvsp[0].tptr));
                        (yyval.tptr) = MakeTree(IfElseOp, comma, elseif);
                      }
#line 2238 "y.tab.c"
    break;

  case 79:
#line 527 "grammar.y"
                      {
                        (yyval.tptr) = MakeTree(IfElseOp, NullExp(),(yyvsp[0].tptr));
                      }
#line 2246 "y.tab.c"
    break;

  case 80:
#line 531 "grammar.y"
                      {
                        tree comma = MakeTree(CommaOp, (yyvsp[-2].tptr), (yyvsp[0].tptr));
                        (yyval.tptr) = MakeTree(IfElseOp, NullExp(), comma);
                      }
#line 2255 "y.tab.c"
    break;

  case 81:
#line 536 "grammar.y"
                      {
                        tree comma = MakeTree(CommaOp, (yyvsp[-3].tptr), (yyvsp[-1].tptr));
                        tree ifElse = MakeTree(IfElseOp, NullExp(),comma);
                        (yyval.tptr) = MkLeftC(ifElse, (yyvsp[0].tptr));
                      }
#line 2265 "y.tab.c"
    break;

  case 82:
#line 543 "grammar.y"
                      {
                        (yyval.tptr) = MakeTree(LoopOp, (yyvsp[-2].tptr), (yyvsp[0].tptr));
                      }
#line 2273 "y.tab.c"
    break;

  case 83:
#line 547 "grammar.y"
                                        {(yyval.tptr) = (yyvsp[0].tptr);}
#line 2279 "y.tab.c"
    break;

  case 84:
#line 549 "grammar.y"
{ MkLeftC((yyvsp[-2].tptr), (yyvsp[-1].tptr)); (yyval.tptr) = MkRightC((yyvsp[0].tptr), (yyvsp[-1].tptr)); }
#line 2285 "y.tab.c"
    break;

  case 85:
#line 553 "grammar.y"
                      {
                          (yyval.tptr) = (yyvsp[0].tptr);
                      }
#line 2293 "y.tab.c"
    break;

  case 86:
#line 565 "grammar.y"
                        {
                          /* Binary addition */
                          (yyval.tptr) = MakeTree(AddOp, (yyvsp[-2].tptr), (yyvsp[0].tptr));
                        }
#line 2302 "y.tab.c"
    break;

  case 87:
#line 570 "grammar.y"
                        {
                          /* Binary subtraction */
                            (yyval.tptr) = MakeTree(SubOp, (yyvsp[-2].tptr), (yyvsp[0].tptr));
                        }
#line 2311 "y.tab.c"
    break;

  case 88:
#line 575 "grammar.y"
                        {
                          /* Logical OR */
                          (yyval.tptr) = MakeTree(OrOp, (yyvsp[-2].tptr), (yyvsp[0].tptr));
                        }
#line 2320 "y.tab.c"
    break;

  case 89:
#line 581 "grammar.y"
                        {
                          (yyval.tptr) = MakeTree(LTOp, NullExp(), NullExp());
                        }
#line 2328 "y.tab.c"
    break;

  case 90:
#line 585 "grammar.y"
                        {
                          (yyval.tptr) = MakeTree(LEOp, NullExp(), NullExp());
                        }
#line 2336 "y.tab.c"
    break;

  case 91:
#line 589 "grammar.y"
                        {
                          (yyval.tptr) = MakeTree(EQOp, NullExp(), NullExp());
                        }
#line 2344 "y.tab.c"
    break;

  case 92:
#line 593 "grammar.y"
                        {
                          (yyval.tptr) = MakeTree(NEOp, NullExp(), NullExp());
                        }
#line 2352 "y.tab.c"
    break;

  case 93:
#line 597 "grammar.y"
                        {
                          (yyval.tptr) = MakeTree(GEOp, NullExp(), NullExp());
                        }
#line 2360 "y.tab.c"
    break;

  case 94:
#line 601 "grammar.y"
                        {
                          (yyval.tptr) = MakeTree(GTOp, NullExp(), NullExp());
                        }
#line 2368 "y.tab.c"
    break;

  case 95:
#line 607 "grammar.y"
                        {
                          (yyval.tptr) = (yyvsp[0].tptr);
                        }
#line 2376 "y.tab.c"
    break;

  case 96:
#line 611 "grammar.y"
                        {
                           MkLeftC((yyvsp[-2].tptr), (yyvsp[-1].tptr)); (yyval.tptr) = MkRightC((yyvsp[0].tptr), (yyvsp[-1].tptr));
                        }
#line 2384 "y.tab.c"
    break;

  case 97:
#line 616 "grammar.y"
                        {
                          (yyval.tptr) = MakeTree(MultOp, NullExp(), NullExp());
                        }
#line 2392 "y.tab.c"
    break;

  case 98:
#line 620 "grammar.y"
                        {
                          (yyval.tptr) = MakeTree(DivOp, NullExp(), NullExp());
                        }
#line 2400 "y.tab.c"
    break;

  case 99:
#line 624 "grammar.y"
                        {
                          (yyval.tptr) = MakeTree(AndOp, NullExp(), NullExp());
                        }
#line 2408 "y.tab.c"
    break;

  case 100:
#line 630 "grammar.y"
                        {
                            (yyval.tptr) =  (yyvsp[0].tptr);
                        }
#line 2416 "y.tab.c"
    break;

  case 101:
#line 634 "grammar.y"
                        {
                            (yyval.tptr) = (yyvsp[0].tptr);
                        }
#line 2424 "y.tab.c"
    break;

  case 102:
#line 638 "grammar.y"
                        {
                            (yyval.tptr) = (yyvsp[0].tptr);
                        }
#line 2432 "y.tab.c"
    break;

  case 103:
#line 642 "grammar.y"
                        {
                            (yyval.tptr) = (yyvsp[-1].tptr);  // Simply returns the enclosed expression
                        }
#line 2440 "y.tab.c"
    break;

  case 104:
#line 646 "grammar.y"
                        {
                            (yyval.tptr) = MakeTree(UnaryNegOp, (yyvsp[0].tptr), NullExp());
                        }
#line 2448 "y.tab.c"
    break;

  case 105:
#line 651 "grammar.y"
                        {
                          (yyval.tptr) = MakeLeaf(STRINGNode, (yyvsp[0].intg));
                        }
#line 2456 "y.tab.c"
    break;

  case 106:
#line 655 "grammar.y"
                        {
                          (yyval.tptr) = MakeLeaf(NUMNode, (yyvsp[0].intg));
                        }
#line 2464 "y.tab.c"
    break;


#line 2468 "y.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 661 "grammar.y"


int yycolumn = 1, yyline = 1;

void yyerror(char *str)
{
  printf("yyerror: %s at line %d\n", str, yyline);
  exit(0);
}

#include "lex.yy.c"
