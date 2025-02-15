/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "semantic/symbol_table.h"

extern int yylineno;
extern char linha_atual[];

void yyerror(const char *s);
int yylex();
extern int yydebug;
Node *syntaxTree = NULL; 

#line 87 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INTEIRO = 3,                    /* INTEIRO  */
  YYSYMBOL_TEXTO = 4,                      /* TEXTO  */
  YYSYMBOL_IDENTIFICADOR = 5,              /* IDENTIFICADOR  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_SAIDA = 7,                      /* SAIDA  */
  YYSYMBOL_ENTRADA = 8,                    /* ENTRADA  */
  YYSYMBOL_NUMERO = 9,                     /* NUMERO  */
  YYSYMBOL_FREQUENCIA = 10,                /* FREQUENCIA  */
  YYSYMBOL_RESOLUCAO = 11,                 /* RESOLUCAO  */
  YYSYMBOL_COM = 12,                       /* COM  */
  YYSYMBOL_VAR = 13,                       /* VAR  */
  YYSYMBOL_BOOLEANO = 14,                  /* BOOLEANO  */
  YYSYMBOL_CONFIG = 15,                    /* CONFIG  */
  YYSYMBOL_REPITA = 16,                    /* REPITA  */
  YYSYMBOL_FIM = 17,                       /* FIM  */
  YYSYMBOL_LIGAR = 18,                     /* LIGAR  */
  YYSYMBOL_DESLIGAR = 19,                  /* DESLIGAR  */
  YYSYMBOL_ESPERAR = 20,                   /* ESPERAR  */
  YYSYMBOL_CONFIGURAR = 21,                /* CONFIGURAR  */
  YYSYMBOL_COMO = 22,                      /* COMO  */
  YYSYMBOL_CONFIGURARPWM = 23,             /* CONFIGURARPWM  */
  YYSYMBOL_CONECTARWIFI = 24,              /* CONECTARWIFI  */
  YYSYMBOL_ENVIARHTTP = 25,                /* ENVIARHTTP  */
  YYSYMBOL_VALOR = 26,                     /* VALOR  */
  YYSYMBOL_AJUSTARPWM = 27,                /* AJUSTARPWM  */
  YYSYMBOL_CONFIGURARSERIAL = 28,          /* CONFIGURARSERIAL  */
  YYSYMBOL_ESCREVERSERIAL = 29,            /* ESCREVERSERIAL  */
  YYSYMBOL_LERSERIAL = 30,                 /* LERSERIAL  */
  YYSYMBOL_SE = 31,                        /* SE  */
  YYSYMBOL_ENTAO = 32,                     /* ENTAO  */
  YYSYMBOL_SENAO = 33,                     /* SENAO  */
  YYSYMBOL_ENQUANTO = 34,                  /* ENQUANTO  */
  YYSYMBOL_VERDADEIRO = 35,                /* VERDADEIRO  */
  YYSYMBOL_FALSO = 36,                     /* FALSO  */
  YYSYMBOL_IGUAL = 37,                     /* IGUAL  */
  YYSYMBOL_DIFERENTE = 38,                 /* DIFERENTE  */
  YYSYMBOL_MENOR_QUE = 39,                 /* MENOR_QUE  */
  YYSYMBOL_MAIOR_QUE = 40,                 /* MAIOR_QUE  */
  YYSYMBOL_MAIOR_IGUAL = 41,               /* MAIOR_IGUAL  */
  YYSYMBOL_MENOR_IGUAL = 42,               /* MENOR_IGUAL  */
  YYSYMBOL_SOMA = 43,                      /* SOMA  */
  YYSYMBOL_SUBTRACAO = 44,                 /* SUBTRACAO  */
  YYSYMBOL_MULTIPLICACAO = 45,             /* MULTIPLICACAO  */
  YYSYMBOL_DIVISAO = 46,                   /* DIVISAO  */
  YYSYMBOL_47_ = 47,                       /* '='  */
  YYSYMBOL_48_ = 48,                       /* ':'  */
  YYSYMBOL_49_ = 49,                       /* ';'  */
  YYSYMBOL_50_ = 50,                       /* ','  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_programa = 52,                  /* programa  */
  YYSYMBOL_bloco_opt = 53,                 /* bloco_opt  */
  YYSYMBOL_declaracoes = 54,               /* declaracoes  */
  YYSYMBOL_declaracao = 55,                /* declaracao  */
  YYSYMBOL_lista_identificadores = 56,     /* lista_identificadores  */
  YYSYMBOL_config = 57,                    /* config  */
  YYSYMBOL_repita = 58,                    /* repita  */
  YYSYMBOL_bloco = 59,                     /* bloco  */
  YYSYMBOL_comando = 60,                   /* comando  */
  YYSYMBOL_atribuicao = 61,                /* atribuicao  */
  YYSYMBOL_operacao_pwm = 62,              /* operacao_pwm  */
  YYSYMBOL_operacao_io = 63,               /* operacao_io  */
  YYSYMBOL_operacao_wifi = 64,             /* operacao_wifi  */
  YYSYMBOL_operacao_serial = 65,           /* operacao_serial  */
  YYSYMBOL_operacao_controle = 66,         /* operacao_controle  */
  YYSYMBOL_fim_opt = 67,                   /* fim_opt  */
  YYSYMBOL_operacao_condicional = 68,      /* operacao_condicional  */
  YYSYMBOL_senao_opt = 69,                 /* senao_opt  */
  YYSYMBOL_expressao_logica = 70,          /* expressao_logica  */
  YYSYMBOL_operacoes_aritmeticas = 71,     /* operacoes_aritmeticas  */
  YYSYMBOL_operacao_soma = 72,             /* operacao_soma  */
  YYSYMBOL_operacao_subtracao = 73,        /* operacao_subtracao  */
  YYSYMBOL_operacao_multiplicacao = 74,    /* operacao_multiplicacao  */
  YYSYMBOL_operacao_divisao = 75           /* operacao_divisao  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   200

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    50,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    48,    49,
       2,    47,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    53,    53,    66,    67,    72,    73,    77,   104,   131,
     161,   162,   169,   178,   187,   188,   196,   197,   198,   199,
     200,   201,   202,   203,   208,   215,   220,   225,   230,   238,
     248,   253,   268,   273,   278,   282,   290,   297,   303,   312,
     315,   323,   332,   333,   337,   341,   348,   349,   353,   358,
     367,   376,   385,   394,   403,   412,   422,   423,   424,   425,
     428,   434,   442,   450,   461,   467,   475,   483,   494,   500,
     508,   516,   527,   533,   541,   549
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INTEIRO", "TEXTO",
  "IDENTIFICADOR", "STRING", "SAIDA", "ENTRADA", "NUMERO", "FREQUENCIA",
  "RESOLUCAO", "COM", "VAR", "BOOLEANO", "CONFIG", "REPITA", "FIM",
  "LIGAR", "DESLIGAR", "ESPERAR", "CONFIGURAR", "COMO", "CONFIGURARPWM",
  "CONECTARWIFI", "ENVIARHTTP", "VALOR", "AJUSTARPWM", "CONFIGURARSERIAL",
  "ESCREVERSERIAL", "LERSERIAL", "SE", "ENTAO", "SENAO", "ENQUANTO",
  "VERDADEIRO", "FALSO", "IGUAL", "DIFERENTE", "MENOR_QUE", "MAIOR_QUE",
  "MAIOR_IGUAL", "MENOR_IGUAL", "SOMA", "SUBTRACAO", "MULTIPLICACAO",
  "DIVISAO", "'='", "':'", "';'", "','", "$accept", "programa",
  "bloco_opt", "declaracoes", "declaracao", "lista_identificadores",
  "config", "repita", "bloco", "comando", "atribuicao", "operacao_pwm",
  "operacao_io", "operacao_wifi", "operacao_serial", "operacao_controle",
  "fim_opt", "operacao_condicional", "senao_opt", "expressao_logica",
  "operacoes_aritmeticas", "operacao_soma", "operacao_subtracao",
  "operacao_multiplicacao", "operacao_divisao", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-31)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -31,    20,    69,   -31,     1,   127,   -31,   127,   -25,   -19,
       6,    14,    67,    57,    64,    71,    89,    95,   101,   102,
     117,   105,   120,   130,   127,    19,   -31,   -31,   -31,   -31,
     -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   133,
     127,   138,   138,   138,     8,     9,    16,    17,    -3,    25,
      26,    40,    46,   104,   108,   110,   140,   148,   158,   159,
     152,   118,   119,   -30,   134,    47,   -31,   -31,   127,   127,
     -31,    54,    88,    90,   -31,   -31,   -31,   -31,   -31,   -31,
     -31,   -31,   121,   122,   123,   124,   125,   126,   -31,   -31,
     -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   109,
     166,   128,   129,   143,   -31,   -31,    92,   170,   171,   172,
     173,   174,   127,   -31,    68,   167,   -31,   180,   -31,   -31,
     -31,   -31,   -31,   -31,   -31,   -31,   137,   139,   178,   -31,
     -31,    74,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   100,
     -31,   -31,   -31,   -31,   -31,   -31,   179,   142,   144,   127,
     175,   185,   -31,   -31,   127,   -31,   146,   -31
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,     1,     0,     0,     6,     3,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,    16,    17,    18,
      19,    21,    20,    22,    23,    56,    57,    58,    59,     0,
       4,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,     0,     0,    12,    15,     0,     3,
      10,     0,     0,     0,    60,    61,    64,    65,    68,    69,
      72,    73,     0,     0,     0,     0,     0,     0,    62,    63,
      66,    67,    70,    71,    74,    75,    34,    35,    41,     0,
       0,     0,     0,     0,    38,    39,     0,     0,     0,     0,
       0,     0,     0,    45,     0,    42,     7,     0,     8,     9,
      25,    24,    40,    26,    27,    28,     0,     0,     0,    36,
      37,     0,    55,    49,    50,    51,    52,    53,    54,    46,
      13,    43,     2,    11,    32,    33,     0,     0,     0,     0,
       0,     0,    30,    29,    47,    44,     0,    31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -31,   -31,   131,   -31,   -31,    99,   -31,   -31,    -5,   -24,
     -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   141,
     -31,   -31,   -31,   -31,   -31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    39,     2,     6,    71,     7,    69,    40,    26,
      27,    28,    29,    30,    31,    32,   142,    33,   150,    64,
      34,    35,    36,    37,    38
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      25,    67,    63,    82,     8,     9,    83,   106,   107,   108,
     109,   110,   111,    74,    76,    10,    67,    75,    77,    65,
       3,    78,    80,    41,    11,    79,    81,    84,    12,    42,
      88,    90,    85,    86,    89,    91,    66,    13,    14,    15,
      16,    67,    17,    18,    19,    92,    20,    21,    22,    93,
      23,    94,    11,    24,    43,    95,    12,    44,    45,    46,
      47,    48,    53,   114,   113,    13,    14,    15,    16,    54,
      17,    18,    19,    11,    20,    21,    22,    12,    23,   147,
      55,    24,     4,   148,     5,   140,    13,    14,    15,    16,
      67,    17,    18,    19,    56,    20,    21,    22,   132,    23,
      57,   133,    24,   116,   117,    11,    58,   139,    59,    12,
      49,    50,    51,    52,    61,    67,   126,   127,    13,    14,
      15,    16,    60,    17,    18,    19,    62,    20,    21,    22,
      67,    23,    11,   149,    24,    63,    12,   118,   117,   119,
     117,    72,    73,    70,   154,    13,    14,    15,    16,    68,
      17,    18,    19,    96,    20,    21,    22,    97,    23,    98,
     100,    24,    99,   101,   103,   102,   112,   104,   105,   131,
     120,   121,   122,   123,   124,   125,   128,   129,   130,   134,
     135,   136,   137,   138,   141,   143,   144,   146,   145,    87,
     151,   152,   155,   153,   156,   157,     0,     0,     0,     0,
     115
};

static const yytype_int16 yycheck[] =
{
       5,    25,     5,     6,     3,     4,     9,    37,    38,    39,
      40,    41,    42,     5,     5,    14,    40,     9,     9,    24,
       0,     5,     5,    48,     5,     9,     9,    30,     9,    48,
       5,     5,    35,    36,     9,     9,    17,    18,    19,    20,
      21,    65,    23,    24,    25,     5,    27,    28,    29,     9,
      31,     5,     5,    34,    48,     9,     9,    43,    44,    45,
      46,    47,     5,    68,    17,    18,    19,    20,    21,     5,
      23,    24,    25,     5,    27,    28,    29,     9,    31,     5,
       9,    34,    13,     9,    15,    17,    18,    19,    20,    21,
     114,    23,    24,    25,     5,    27,    28,    29,     6,    31,
       5,     9,    34,    49,    50,     5,     5,   112,     6,     9,
      43,    44,    45,    46,     9,   139,     7,     8,    18,    19,
      20,    21,     5,    23,    24,    25,     6,    27,    28,    29,
     154,    31,     5,    33,    34,     5,     9,    49,    50,    49,
      50,    42,    43,     5,   149,    18,    19,    20,    21,    16,
      23,    24,    25,    49,    27,    28,    29,    49,    31,    49,
      12,    34,    22,     5,    12,     6,    32,    49,    49,    26,
      49,    49,    49,    49,    49,    49,    10,    49,    49,     9,
       9,     9,     9,     9,    17,     5,    49,     9,    49,    48,
      11,    49,    17,    49,     9,    49,    -1,    -1,    -1,    -1,
      69
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    52,    54,     0,    13,    15,    55,    57,     3,     4,
      14,     5,     9,    18,    19,    20,    21,    23,    24,    25,
      27,    28,    29,    31,    34,    59,    60,    61,    62,    63,
      64,    65,    66,    68,    71,    72,    73,    74,    75,    53,
      59,    48,    48,    48,    43,    44,    45,    46,    47,    43,
      44,    45,    46,     5,     5,     9,     5,     5,     5,     6,
       5,     9,     6,     5,    70,    59,    17,    60,    16,    58,
       5,    56,    56,    56,     5,     9,     5,     9,     5,     9,
       5,     9,     6,     9,    30,    35,    36,    70,     5,     9,
       5,     9,     5,     9,     5,     9,    49,    49,    49,    22,
      12,     5,     6,    12,    49,    49,    37,    38,    39,    40,
      41,    42,    32,    17,    59,    53,    49,    50,    49,    49,
      49,    49,    49,    49,    49,    49,     7,     8,    10,    49,
      49,    26,     6,     9,     9,     9,     9,     9,     9,    59,
      17,    17,    67,     5,    49,    49,     9,     5,     9,    33,
      69,    11,    49,    49,    59,    17,     9,    49
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    55,    55,    55,
      56,    56,    57,    58,    59,    59,    60,    60,    60,    60,
      60,    60,    60,    60,    61,    61,    61,    61,    61,    62,
      62,    62,    63,    63,    63,    63,    64,    64,    65,    65,
      65,    66,    67,    67,    68,    68,    69,    69,    70,    70,
      70,    70,    70,    70,    70,    70,    71,    71,    71,    71,
      72,    72,    72,    72,    73,    73,    73,    73,    74,    74,
      74,    74,    75,    75,    75,    75
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     6,     0,     1,     0,     2,     5,     5,     5,
       1,     3,     3,     3,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     6,
       6,     8,     5,     5,     3,     3,     4,     4,     3,     3,
       4,     3,     0,     1,     6,     3,     0,     2,     1,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* programa: declaracoes config bloco_opt repita bloco_opt fim_opt  */
#line 53 "parser.y"
                                                          { 
        printf("Programa reconhecido com sucesso!\n"); 
        syntaxTree = newNode("PROGRAMA", 6, (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
        if (!syntaxTree) {
            fprintf(stderr, "Erro: árvore sintática está NULL antes de printTree!\n");
            exit(EXIT_FAILURE);
        }
        printf("[DEBUG] Árvore sintática gerada, iniciando impressão...\n");
        printTree(syntaxTree, 0); // Para exibir a árvore sintática
    }
#line 1272 "parser.tab.c"
    break;

  case 3: /* bloco_opt: %empty  */
#line 66 "parser.y"
    { (yyval.node) = newNode("BLOCO_VAZIO", 0); }
#line 1278 "parser.tab.c"
    break;

  case 4: /* bloco_opt: bloco  */
#line 67 "parser.y"
            { (yyval.node) = (yyvsp[0].node); }
#line 1284 "parser.tab.c"
    break;

  case 5: /* declaracoes: %empty  */
#line 72 "parser.y"
    { (yyval.node) = newNode("DECLARACOES", 0); }
#line 1290 "parser.tab.c"
    break;

  case 6: /* declaracoes: declaracoes declaracao  */
#line 73 "parser.y"
                             { addChild((yyvsp[-1].node), (yyvsp[0].node)); (yyval.node) = (yyvsp[-1].node); }
#line 1296 "parser.tab.c"
    break;

  case 7: /* declaracao: VAR INTEIRO ':' lista_identificadores ';'  */
#line 77 "parser.y"
                                              { 
        if (!(yyvsp[-1].node)) {
            printf("[ERRO] lista_identificadores retornou NULL!\n");
            (yyval.node) = newNode("DECLARACAO", 1, newNode(strdup("INTEIRO"), 0));
        } else {
            (yyval.node) = newNode("DECLARACAO", 2, newNode(strdup("INTEIRO"), 0), (yyvsp[-1].node));
        }

        Node *idList = (yyvsp[-1].node);
        while (idList != NULL) {
            if (idList->numChildren > 0 && idList->children[0] != NULL) {
                Node *identNode = idList->children[0];  
                
                char *varName = (strcmp(identNode->label, "IDENTIFICADOR") == 0 && identNode->numChildren > 0) 
                                ? identNode->children[0]->label
                                : identNode->label;
                
                if (lookupSymbol(varName) != NULL) {
                    printf("Erro Semântico: Variável '%s' já declarada!\n", varName);
                    exit(1);
                }
                insertSymbol(varName, "INTEIRO");
            }
            idList = (idList->numChildren > 1) ? idList->children[1] : NULL;
            printSymbolTable();
        }
    }
#line 1328 "parser.tab.c"
    break;

  case 8: /* declaracao: VAR TEXTO ':' lista_identificadores ';'  */
#line 104 "parser.y"
                                              { 
        if (!(yyvsp[-1].node)) {
            printf("[ERRO] lista_identificadores retornou NULL!\n");
            (yyval.node) = newNode("DECLARACAO", 1, newNode(strdup("TEXTO"), 0)); // Nó mínimo
        } else {
            (yyval.node) = newNode("DECLARACAO", 2, newNode(strdup("TEXTO"), 0), (yyvsp[-1].node));
        }

        Node *idList = (yyvsp[-1].node);
        while (idList != NULL) {
            if (idList->numChildren > 0 && idList->children[0] != NULL) {
                Node *identNode = idList->children[0];  
                
                char *varName = (strcmp(identNode->label, "IDENTIFICADOR") == 0 && identNode->numChildren > 0) 
                                ? identNode->children[0]->label  // Pegando o filho correto
                                : identNode->label;  // Já é o nome correto

                if (lookupSymbol(varName) != NULL) {
                    printf("Erro Semântico: Variável '%s' já declarada!\n", varName);
                    exit(1);
                }
                insertSymbol(varName, "TEXTO");
            }
            idList = (idList->numChildren > 1) ? idList->children[1] : NULL;
            printSymbolTable();
        }
    }
#line 1360 "parser.tab.c"
    break;

  case 9: /* declaracao: VAR BOOLEANO ':' lista_identificadores ';'  */
#line 131 "parser.y"
                                                 { 
        if (!(yyvsp[-1].node)) {
            printf("[ERRO] lista_identificadores retornou NULL!\n");
            (yyval.node) = newNode("DECLARACAO", 1, newNode(strdup("BOOLEANO"), 0)); // Nó mínimo
        } else {
            (yyval.node) = newNode("DECLARACAO", 2, newNode(strdup("BOOLEANO"), 0), (yyvsp[-1].node));
        }

        Node *idList = (yyvsp[-1].node);
        while (idList != NULL) {
            if (idList->numChildren > 0 && idList->children[0] != NULL) {
                Node *identNode = idList->children[0];  
                
                char *varName = (strcmp(identNode->label, "IDENTIFICADOR") == 0 && identNode->numChildren > 0) 
                                ? identNode->children[0]->label  // Pegando o filho correto
                                : identNode->label;  // Já é o nome correto

                if (lookupSymbol(varName) != NULL) {
                    printf("Erro Semântico: Variável '%s' já declarada!\n", varName);
                    exit(1);
                }
                insertSymbol(varName, "BOOLEANO");
            }
            idList = (idList->numChildren > 1) ? idList->children[1] : NULL;
            printSymbolTable();
        }
    }
#line 1392 "parser.tab.c"
    break;

  case 10: /* lista_identificadores: IDENTIFICADOR  */
#line 161 "parser.y"
                  { (yyval.node) = newNode("LISTA_IDENTIFICADORES", 1, newNode("IDENTIFICADOR", 1, newNode((yyvsp[0].strval), 0))); }
#line 1398 "parser.tab.c"
    break;

  case 11: /* lista_identificadores: lista_identificadores ',' IDENTIFICADOR  */
#line 162 "parser.y"
                                              {
      addChild((yyvsp[-2].node), newNode("IDENTIFICADOR", 1, newNode((yyvsp[0].strval), 0)));
      (yyval.node) = (yyvsp[-2].node);}
#line 1406 "parser.tab.c"
    break;

  case 12: /* config: CONFIG bloco FIM  */
#line 169 "parser.y"
                     { 
        printf("Configuração processada.\n");
        printf("[DEBUG] Criando nó CONFIG, bloco=%p\n", (void*)(yyvsp[-1].node));
        (yyval.node) = newNode("CONFIG", 2, (yyvsp[-1].node), newNode("FIM", 0)); 
    }
#line 1416 "parser.tab.c"
    break;

  case 13: /* repita: REPITA bloco FIM  */
#line 178 "parser.y"
                     { 
        printf("Loop principal processado.\n");
        printf("[DEBUG] Criando nó para LOOP PRINCIPAL\n");
        (yyval.node) = newNode("REPITA", 2, (yyvsp[-1].node), newNode("FIM", 0));
    }
#line 1426 "parser.tab.c"
    break;

  case 14: /* bloco: comando  */
#line 187 "parser.y"
            { (yyval.node) = newNode("BLOCO", 1, (yyvsp[0].node)); }
#line 1432 "parser.tab.c"
    break;

  case 15: /* bloco: bloco comando  */
#line 188 "parser.y"
                    { 
        addChild((yyvsp[-1].node), (yyvsp[0].node));
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1441 "parser.tab.c"
    break;

  case 16: /* comando: atribuicao  */
#line 196 "parser.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1447 "parser.tab.c"
    break;

  case 17: /* comando: operacao_pwm  */
#line 197 "parser.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1453 "parser.tab.c"
    break;

  case 18: /* comando: operacao_io  */
#line 198 "parser.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1459 "parser.tab.c"
    break;

  case 19: /* comando: operacao_wifi  */
#line 199 "parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1465 "parser.tab.c"
    break;

  case 20: /* comando: operacao_controle  */
#line 200 "parser.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 1471 "parser.tab.c"
    break;

  case 21: /* comando: operacao_serial  */
#line 201 "parser.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1477 "parser.tab.c"
    break;

  case 22: /* comando: operacao_condicional  */
#line 202 "parser.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1483 "parser.tab.c"
    break;

  case 23: /* comando: operacoes_aritmeticas  */
#line 203 "parser.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 1489 "parser.tab.c"
    break;

  case 24: /* atribuicao: IDENTIFICADOR '=' NUMERO ';'  */
#line 208 "parser.y"
                                 { 
        checkVariableType((yyvsp[-3].strval), "INTEIRO");
        printf("Atribuição: %s = %d\n", (yyvsp[-3].strval), (yyvsp[-1].intval));
        char buffer[20];
        sprintf(buffer, "%d", (yyvsp[-1].intval)); // Converte inteiro para string
        (yyval.node) = newNode("ATRIBUICAO", 2, newNode((yyvsp[-3].strval), 0), newNode("NUMERO", 1, newNode(strdup(buffer), 0))); 
    }
#line 1501 "parser.tab.c"
    break;

  case 25: /* atribuicao: IDENTIFICADOR '=' STRING ';'  */
#line 215 "parser.y"
                                   { 
        checkVariableType((yyvsp[-3].strval), "TEXTO");
        printf("Atribuição: %s = %s\n", (yyvsp[-3].strval), (yyvsp[-1].strval));
        (yyval.node) = newNode("ATRIBUICAO", 2, newNode((yyvsp[-3].strval), 0), newNode("STRING", 1, newNode((yyvsp[-1].strval), 0))); 
    }
#line 1511 "parser.tab.c"
    break;

  case 26: /* atribuicao: IDENTIFICADOR '=' VERDADEIRO ';'  */
#line 220 "parser.y"
                                       { 
        checkVariableType((yyvsp[-3].strval), "BOOLEANO");
        printf("Atribuição: %s = VERDADEIRO\n", (yyvsp[-3].strval));
        (yyval.node) = newNode("ATRIBUICAO", 2, newNode((yyvsp[-3].strval), 0), newNode("BOOLEANO", 1, newNode("VERDADEIRO", 0))); 
    }
#line 1521 "parser.tab.c"
    break;

  case 27: /* atribuicao: IDENTIFICADOR '=' FALSO ';'  */
#line 225 "parser.y"
                                  { 
        checkVariableType((yyvsp[-3].strval), "BOOLEANO");
        printf("Atribuição: %s = FALSO\n", (yyvsp[-3].strval));
        (yyval.node) = newNode("ATRIBUICAO", 2, newNode((yyvsp[-3].strval), 0), newNode("BOOLEANO", 1, newNode("FALSO", 0))); 
    }
#line 1531 "parser.tab.c"
    break;

  case 28: /* atribuicao: IDENTIFICADOR '=' expressao_logica ';'  */
#line 230 "parser.y"
                                             { 
        checkVariableType((yyvsp[-3].strval), "BOOLEANO");
        (yyval.node) = newNode("ATRIBUICAO", 2, newNode((yyvsp[-3].strval), 0), (yyvsp[-1].node)); 
    }
#line 1540 "parser.tab.c"
    break;

  case 29: /* operacao_pwm: AJUSTARPWM IDENTIFICADOR COM VALOR NUMERO ';'  */
#line 238 "parser.y"
                                                  {
        checkVariableType((yyvsp[-4].strval), "INTEIRO");
        char valorStr[16];
        sprintf(valorStr, "%d", (yyvsp[-1].intval));  // Converte o número para string

        (yyval.node) = newNode("AJUSTAR_PWM", 3,  
            newNode((yyvsp[-4].strval), 0), 
            newNode("VALOR", 1, newNode(strdup(valorStr), 0))  
        );
    }
#line 1555 "parser.tab.c"
    break;

  case 30: /* operacao_pwm: AJUSTARPWM IDENTIFICADOR COM VALOR IDENTIFICADOR ';'  */
#line 248 "parser.y"
                                                           { 
        checkVariableType((yyvsp[-4].strval), "INTEIRO");
        checkVariableType((yyvsp[-1].strval), "INTEIRO");
        (yyval.node) = newNode("AJUSTAR_PWM", 3, newNode((yyvsp[-4].strval), 0), newNode("VALOR", 1, newNode((yyvsp[-1].strval), 0))); 
    }
#line 1565 "parser.tab.c"
    break;

  case 31: /* operacao_pwm: CONFIGURARPWM IDENTIFICADOR COM FREQUENCIA NUMERO RESOLUCAO NUMERO ';'  */
#line 253 "parser.y"
                                                                             {
        checkVariableType((yyvsp[-6].strval), "INTEIRO");
        char freqStr[16], resStr[16];
        sprintf(freqStr, "%d", (yyvsp[-3].intval));  // Converte o número para string
        sprintf(resStr, "%d", (yyvsp[-1].intval));   // Converte o número para string
    
        (yyval.node) = newNode("CONFIGURAR_PWM", 3,  
            newNode((yyvsp[-6].strval), 0), 
            newNode("FREQUENCIA", 1, newNode(strdup(freqStr), 0)),  
            newNode("RESOLUCAO", 1, newNode(strdup(resStr), 0))  
        );
    }
#line 1582 "parser.tab.c"
    break;

  case 32: /* operacao_io: CONFIGURAR IDENTIFICADOR COMO SAIDA ';'  */
#line 268 "parser.y"
                                            { 
        checkVariableType((yyvsp[-3].strval), "INTEIRO");
        printf("[DEBUG] Configurar %s como saída reconhecido corretamente!\n", (yyvsp[-3].strval));
        (yyval.node) = newNode("CONFIGURAR_IO", 2, newNode((yyvsp[-3].strval), 0), newNode("SAIDA", 0)); 
    }
#line 1592 "parser.tab.c"
    break;

  case 33: /* operacao_io: CONFIGURAR IDENTIFICADOR COMO ENTRADA ';'  */
#line 273 "parser.y"
                                                { 
        checkVariableType((yyvsp[-3].strval), "INTEIRO");
        printf("[DEBUG] Configurar %s como entrada reconhecido corretamente!\n", (yyvsp[-3].strval));
        (yyval.node) = newNode("CONFIGURAR_IO", 2, newNode((yyvsp[-3].strval), 0), newNode("ENTRADA", 0)); 
    }
#line 1602 "parser.tab.c"
    break;

  case 34: /* operacao_io: LIGAR IDENTIFICADOR ';'  */
#line 278 "parser.y"
                              { 
        checkVariableType((yyvsp[-1].strval), "INTEIRO");
        (yyval.node) = newNode("LIGAR", 1, newNode((yyvsp[-1].strval), 0)); 
    }
#line 1611 "parser.tab.c"
    break;

  case 35: /* operacao_io: DESLIGAR IDENTIFICADOR ';'  */
#line 282 "parser.y"
                                 { 
        checkVariableType((yyvsp[-1].strval), "INTEIRO");
        (yyval.node) = newNode("DESLIGAR", 1, newNode((yyvsp[-1].strval), 0)); 
    }
#line 1620 "parser.tab.c"
    break;

  case 36: /* operacao_wifi: CONECTARWIFI IDENTIFICADOR IDENTIFICADOR ';'  */
#line 290 "parser.y"
                                                 { 
        checkVariableType((yyvsp[-2].strval), "TEXTO");
        checkVariableType((yyvsp[-1].strval), "TEXTO");
        printf("Conectar WiFi com SSID %s e Senha %s\n", (yyvsp[-2].strval), (yyvsp[-1].strval));
        printf("[DEBUG] Criando nó para operação WiFi\n");
        (yyval.node) = newNode("CONECTAR_WIFI", 2, newNode((yyvsp[-2].strval), 0), newNode((yyvsp[-1].strval), 0)); 
    }
#line 1632 "parser.tab.c"
    break;

  case 37: /* operacao_wifi: ENVIARHTTP STRING STRING ';'  */
#line 297 "parser.y"
                                   {
         (yyval.node) = newNode("ENVIAR_HTTP", 2, newNode((yyvsp[-2].strval), 0), newNode((yyvsp[-1].strval), 0));
    }
#line 1640 "parser.tab.c"
    break;

  case 38: /* operacao_serial: CONFIGURARSERIAL NUMERO ';'  */
#line 303 "parser.y"
                                {
        if ((yyvsp[-1].intval) < 300 || (yyvsp[-1].intval) > 115200) {
            printf("Erro Semântico: Taxa de transmissão inválida '%d'. Deve estar entre 300 e 115200.\n", (yyvsp[-1].intval));
            exit(1);
        }
        char buffer[10];
        sprintf(buffer, "%d", (yyvsp[-1].intval));
        (yyval.node) = newNode("CONFIGURAR_SERIAL", 1, newNode(strdup(buffer), 0)); 
    }
#line 1654 "parser.tab.c"
    break;

  case 39: /* operacao_serial: ESCREVERSERIAL STRING ';'  */
#line 312 "parser.y"
                                {
        (yyval.node) = newNode("ESCREVER_SERIAL", 1, newNode((yyvsp[-1].strval), 0));
    }
#line 1662 "parser.tab.c"
    break;

  case 40: /* operacao_serial: IDENTIFICADOR '=' LERSERIAL ';'  */
#line 315 "parser.y"
                                      {
        checkVariableType((yyvsp[-3].strval), "TEXTO");
        (yyval.node) = newNode("LER_SERIAL", 1, newNode((yyvsp[-3].strval), 0));
    }
#line 1671 "parser.tab.c"
    break;

  case 41: /* operacao_controle: ESPERAR NUMERO ';'  */
#line 323 "parser.y"
                       { 
        printf("Esperar: %d ms\n", (yyvsp[-1].intval));
        char buffer[20];
        sprintf(buffer, "%d", (yyvsp[-1].intval));
        (yyval.node) = newNode("ESPERAR", 1, newNode(strdup(buffer), 0)); 
    }
#line 1682 "parser.tab.c"
    break;

  case 42: /* fim_opt: %empty  */
#line 332 "parser.y"
    { (yyval.node) = newNode("FIM_VAZIO", 0); }
#line 1688 "parser.tab.c"
    break;

  case 43: /* fim_opt: FIM  */
#line 333 "parser.y"
          { (yyval.node) = newNode("FIM", 0); }
#line 1694 "parser.tab.c"
    break;

  case 44: /* operacao_condicional: SE expressao_logica ENTAO bloco senao_opt FIM  */
#line 337 "parser.y"
                                                  {
        printf("Estrutura Condicional (se ... então ... fim)\n");
        (yyval.node) = newNode("CONDICIONAL", 3, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[-1].node), 0);
    }
#line 1703 "parser.tab.c"
    break;

  case 45: /* operacao_condicional: ENQUANTO bloco FIM  */
#line 341 "parser.y"
                         {
        printf("Estrutura de Repetição (enquanto ... fim)\n");
        (yyval.node) = newNode("ENQUANTO", 1, (yyvsp[-1].node), 0);
    }
#line 1712 "parser.tab.c"
    break;

  case 46: /* senao_opt: %empty  */
#line 348 "parser.y"
    { (yyval.node) = newNode("SENAO_VAZIO", 0); }
#line 1718 "parser.tab.c"
    break;

  case 47: /* senao_opt: SENAO bloco  */
#line 349 "parser.y"
                  { (yyval.node) = newNode("SENAO", 1, (yyvsp[0].node), 0); }
#line 1724 "parser.tab.c"
    break;

  case 48: /* expressao_logica: IDENTIFICADOR  */
#line 353 "parser.y"
                  {
        checkVariableType((yyvsp[0].strval), "BOOLEANO");

        (yyval.node) = newNode("EXPRESSAO_LOGICA", 1, newNode((yyvsp[0].strval), 0));
    }
#line 1734 "parser.tab.c"
    break;

  case 49: /* expressao_logica: IDENTIFICADOR IGUAL NUMERO  */
#line 358 "parser.y"
                                 {
        printf("Comparação: %s == %d\n", (yyvsp[-2].strval), (yyvsp[0].intval));

        checkVariableType((yyvsp[-2].strval), "INTEIRO");

        char valorStr[16];
        sprintf(valorStr, "%d", (yyvsp[0].intval));
        (yyval.node) = newNode("EXPRESSAO_LOGICA", 3, newNode((yyvsp[-2].strval), 0), newNode("==", 0), newNode(valorStr, 0));
    }
#line 1748 "parser.tab.c"
    break;

  case 50: /* expressao_logica: IDENTIFICADOR DIFERENTE NUMERO  */
#line 367 "parser.y"
                                     {
        printf("Comparação: %s == %d\n", (yyvsp[-2].strval), (yyvsp[0].intval));

        checkVariableType((yyvsp[-2].strval), "INTEIRO");

        char valorStr[16];
        sprintf(valorStr, "%d", (yyvsp[0].intval));
        (yyval.node) = newNode("EXPRESSAO_LOGICA", 3, newNode((yyvsp[-2].strval), 0), newNode("!=", 0), newNode(valorStr, 0));
    }
#line 1762 "parser.tab.c"
    break;

  case 51: /* expressao_logica: IDENTIFICADOR MENOR_QUE NUMERO  */
#line 376 "parser.y"
                                     {
        printf("Comparação: %s == %d\n", (yyvsp[-2].strval), (yyvsp[0].intval));

        checkVariableType((yyvsp[-2].strval), "INTEIRO");

        char valorStr[16];
        sprintf(valorStr, "%d", (yyvsp[0].intval));
        (yyval.node) = newNode("EXPRESSAO_LOGICA", 3, newNode((yyvsp[-2].strval), 0), newNode("<", 0), newNode(valorStr, 0));
    }
#line 1776 "parser.tab.c"
    break;

  case 52: /* expressao_logica: IDENTIFICADOR MAIOR_QUE NUMERO  */
#line 385 "parser.y"
                                     {
        printf("Comparação: %s == %d\n", (yyvsp[-2].strval), (yyvsp[0].intval));

        checkVariableType((yyvsp[-2].strval), "INTEIRO");

        char valorStr[16];
        sprintf(valorStr, "%d", (yyvsp[0].intval));
        (yyval.node) = newNode("EXPRESSAO_LOGICA", 3, newNode((yyvsp[-2].strval), 0), newNode(">", 0), newNode(valorStr, 0));
    }
#line 1790 "parser.tab.c"
    break;

  case 53: /* expressao_logica: IDENTIFICADOR MAIOR_IGUAL NUMERO  */
#line 394 "parser.y"
                                       {
        printf("Comparação: %s == %d\n", (yyvsp[-2].strval), (yyvsp[0].intval));

        checkVariableType((yyvsp[-2].strval), "INTEIRO");

        char valorStr[16];
        sprintf(valorStr, "%d", (yyvsp[0].intval));
        (yyval.node) = newNode("EXPRESSAO_LOGICA", 3, newNode((yyvsp[-2].strval), 0), newNode(">=", 0), newNode(valorStr, 0));
    }
#line 1804 "parser.tab.c"
    break;

  case 54: /* expressao_logica: IDENTIFICADOR MENOR_IGUAL NUMERO  */
#line 403 "parser.y"
                                       {
        printf("Comparação: %s == %d\n", (yyvsp[-2].strval), (yyvsp[0].intval));

        checkVariableType((yyvsp[-2].strval), "INTEIRO");

        char valorStr[16];
        sprintf(valorStr, "%d", (yyvsp[0].intval));
        (yyval.node) = newNode("EXPRESSAO_LOGICA", 3, newNode((yyvsp[-2].strval), 0), newNode("<=", 0), newNode(valorStr, 0));
    }
#line 1818 "parser.tab.c"
    break;

  case 55: /* expressao_logica: IDENTIFICADOR IGUAL STRING  */
#line 412 "parser.y"
                                 {
        printf("Comparação: %s == %s\n", (yyvsp[-2].strval), (yyvsp[0].strval));

        checkVariableType((yyvsp[-2].strval), "TEXTO");

        (yyval.node) = newNode("EXPRESSAO_LOGICA", 3, newNode((yyvsp[-2].strval), 0), newNode("==", 0), newNode((yyvsp[0].strval), 0));
    }
#line 1830 "parser.tab.c"
    break;

  case 56: /* operacoes_aritmeticas: operacao_soma  */
#line 422 "parser.y"
                  { (yyval.node) = (yyvsp[0].node);}
#line 1836 "parser.tab.c"
    break;

  case 57: /* operacoes_aritmeticas: operacao_subtracao  */
#line 423 "parser.y"
                         { (yyval.node) = (yyvsp[0].node);}
#line 1842 "parser.tab.c"
    break;

  case 58: /* operacoes_aritmeticas: operacao_multiplicacao  */
#line 424 "parser.y"
                             { (yyval.node) = (yyvsp[0].node);}
#line 1848 "parser.tab.c"
    break;

  case 59: /* operacoes_aritmeticas: operacao_divisao  */
#line 425 "parser.y"
                       { (yyval.node) = (yyvsp[0].node);}
#line 1854 "parser.tab.c"
    break;

  case 60: /* operacao_soma: IDENTIFICADOR SOMA IDENTIFICADOR  */
#line 428 "parser.y"
                                     {
        checkVariableType((yyvsp[-2].strval), "INTEIRO");
        checkVariableType((yyvsp[0].strval), "INTEIRO");

        (yyval.node) = newNode("OPERACAO_SOMA", 3, newNode((yyvsp[-2].strval), 0), newNode("+", 0), newNode((yyvsp[0].strval), 0));
    }
#line 1865 "parser.tab.c"
    break;

  case 61: /* operacao_soma: IDENTIFICADOR SOMA NUMERO  */
#line 434 "parser.y"
                                {
        checkVariableType((yyvsp[-2].strval), "INTEIRO");

        char valorStr[16];
        sprintf(valorStr, "%d", (yyvsp[0].intval));

        (yyval.node) = newNode("OPERACAO_SOMA", 3, newNode((yyvsp[-2].strval), 0), newNode("+", 0), newNode(valorStr, 0));
    }
#line 1878 "parser.tab.c"
    break;

  case 62: /* operacao_soma: NUMERO SOMA IDENTIFICADOR  */
#line 442 "parser.y"
                                {
        checkVariableType((yyvsp[0].strval), "INTEIRO");

        char valorStr[16];
        sprintf(valorStr, "%d", (yyvsp[-2].intval));

        (yyval.node) = newNode("OPERACAO_SOMA", 3, newNode(valorStr, 0), newNode("+", 0), newNode((yyvsp[0].strval), 0));
    }
#line 1891 "parser.tab.c"
    break;

  case 63: /* operacao_soma: NUMERO SOMA NUMERO  */
#line 450 "parser.y"
                         {
        char valorStr1[16];
        char valorStr2[16];
        sprintf(valorStr1, "%d", (yyvsp[-2].intval));
        sprintf(valorStr1, "%d", (yyvsp[0].intval));

        (yyval.node) = newNode("OPERACAO_SOMA", 3, newNode(valorStr1, 0), newNode("+", 0), newNode(valorStr2, 0));
    }
#line 1904 "parser.tab.c"
    break;

  case 64: /* operacao_subtracao: IDENTIFICADOR SUBTRACAO IDENTIFICADOR  */
#line 461 "parser.y"
                                          {
        checkVariableType((yyvsp[-2].strval), "INTEIRO");
        checkVariableType((yyvsp[0].strval), "INTEIRO");

        (yyval.node) = newNode("OPERACAO_SUBTRACAO", 3, newNode((yyvsp[-2].strval), 0), newNode("-", 0), newNode((yyvsp[0].strval), 0));
    }
#line 1915 "parser.tab.c"
    break;

  case 65: /* operacao_subtracao: IDENTIFICADOR SUBTRACAO NUMERO  */
#line 467 "parser.y"
                                     {
        checkVariableType((yyvsp[-2].strval), "INTEIRO");

        char valorStr[16];
        sprintf(valorStr, "%d", (yyvsp[0].intval));

        (yyval.node) = newNode("OPERACAO_SUBTRACAO", 3, newNode((yyvsp[-2].strval), 0), newNode("-", 0), newNode(valorStr, 0));
    }
#line 1928 "parser.tab.c"
    break;

  case 66: /* operacao_subtracao: NUMERO SUBTRACAO IDENTIFICADOR  */
#line 475 "parser.y"
                                     {
        checkVariableType((yyvsp[0].strval), "INTEIRO");

        char valorStr[16];
        sprintf(valorStr, "%d", (yyvsp[-2].intval));

        (yyval.node) = newNode("OPERACAO_SUBTRACAO", 3, newNode(valorStr, 0), newNode("-", 0), newNode((yyvsp[0].strval), 0));
    }
#line 1941 "parser.tab.c"
    break;

  case 67: /* operacao_subtracao: NUMERO SUBTRACAO NUMERO  */
#line 483 "parser.y"
                              {
        char valorStr1[16];
        char valorStr2[16];
        sprintf(valorStr1, "%d", (yyvsp[-2].intval));
        sprintf(valorStr1, "%d", (yyvsp[0].intval));

        (yyval.node) = newNode("OPERACAO_SUBTRACAO", 3, newNode(valorStr1, 0), newNode("-", 0), newNode(valorStr2, 0));
    }
#line 1954 "parser.tab.c"
    break;

  case 68: /* operacao_multiplicacao: IDENTIFICADOR MULTIPLICACAO IDENTIFICADOR  */
#line 494 "parser.y"
                                              {
        checkVariableType((yyvsp[-2].strval), "INTEIRO");
        checkVariableType((yyvsp[0].strval), "INTEIRO");

        (yyval.node) = newNode("OPERACAO_MULTIPLICACAO", 3, newNode((yyvsp[-2].strval), 0), newNode("*", 0), newNode((yyvsp[0].strval), 0));
    }
#line 1965 "parser.tab.c"
    break;

  case 69: /* operacao_multiplicacao: IDENTIFICADOR MULTIPLICACAO NUMERO  */
#line 500 "parser.y"
                                         {
        checkVariableType((yyvsp[-2].strval), "INTEIRO");

        char valorStr[16];
        sprintf(valorStr, "%d", (yyvsp[0].intval));

        (yyval.node) = newNode("OPERACAO_MULTIPLICACAO", 3, newNode((yyvsp[-2].strval), 0), newNode("*", 0), newNode(valorStr, 0));
    }
#line 1978 "parser.tab.c"
    break;

  case 70: /* operacao_multiplicacao: NUMERO MULTIPLICACAO IDENTIFICADOR  */
#line 508 "parser.y"
                                         {
        checkVariableType((yyvsp[0].strval), "INTEIRO");

        char valorStr[16];
        sprintf(valorStr, "%d", (yyvsp[-2].intval));

        (yyval.node) = newNode("OPERACAO_MULTIPLICACAO", 3, newNode(valorStr, 0), newNode("*", 0), newNode((yyvsp[0].strval), 0));
    }
#line 1991 "parser.tab.c"
    break;

  case 71: /* operacao_multiplicacao: NUMERO MULTIPLICACAO NUMERO  */
#line 516 "parser.y"
                                  {
        char valorStr1[16];
        char valorStr2[16];
        sprintf(valorStr1, "%d", (yyvsp[-2].intval));
        sprintf(valorStr1, "%d", (yyvsp[0].intval));

        (yyval.node) = newNode("OPERACAO_MULTIPLICACAO", 3, newNode(valorStr1, 0), newNode("*", 0), newNode(valorStr2, 0));
    }
#line 2004 "parser.tab.c"
    break;

  case 72: /* operacao_divisao: IDENTIFICADOR DIVISAO IDENTIFICADOR  */
#line 527 "parser.y"
                                        {
        checkVariableType((yyvsp[-2].strval), "INTEIRO");
        checkVariableType((yyvsp[0].strval), "INTEIRO");

        (yyval.node) = newNode("OPERACAO_DIVISAO", 3, newNode((yyvsp[-2].strval), 0), newNode("/", 0), newNode((yyvsp[0].strval), 0));
    }
#line 2015 "parser.tab.c"
    break;

  case 73: /* operacao_divisao: IDENTIFICADOR DIVISAO NUMERO  */
#line 533 "parser.y"
                                   {
        checkVariableType((yyvsp[-2].strval), "INTEIRO");

        char valorStr[16];
        sprintf(valorStr, "%d", (yyvsp[0].intval));

        (yyval.node) = newNode("OPERACAO_DIVISAO", 3, newNode((yyvsp[-2].strval), 0), newNode("/", 0), newNode(valorStr, 0));
    }
#line 2028 "parser.tab.c"
    break;

  case 74: /* operacao_divisao: NUMERO DIVISAO IDENTIFICADOR  */
#line 541 "parser.y"
                                   {
        checkVariableType((yyvsp[0].strval), "INTEIRO");

        char valorStr[16];
        sprintf(valorStr, "%d", (yyvsp[-2].intval));

        (yyval.node) = newNode("OPERACAO_DIVISAO", 3, newNode(valorStr, 0), newNode("/", 0), newNode((yyvsp[0].strval), 0));
    }
#line 2041 "parser.tab.c"
    break;

  case 75: /* operacao_divisao: NUMERO DIVISAO NUMERO  */
#line 549 "parser.y"
                            {
        char valorStr1[16];
        char valorStr2[16];
        sprintf(valorStr1, "%d", (yyvsp[-2].intval));
        sprintf(valorStr2, "%d", (yyvsp[0].intval));

        (yyval.node) = newNode("OPERACAO_DIVISAO", 3, newNode(valorStr1, 0), newNode("/", 0), newNode(valorStr2, 0));
    }
#line 2054 "parser.tab.c"
    break;


#line 2058 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 559 "parser.y"

void yyerror(const char *s) {
    fprintf(stderr, "Erro sintático na linha %d: %s\n", yylineno - 1, s);

    // Abrir o arquivo de entrada novamente para ler a linha do erro
    FILE *arquivo = fopen("entrada.txt", "r"); // Certifique-se de que está correto
    if (arquivo) {
        char linha[1024];
        int linha_atual = 1;

        while (fgets(linha, sizeof(linha), arquivo)) {
            if (linha_atual == yylineno - 1) {  // A linha do erro
                fprintf(stderr, ">> %s", linha);
                break;
            }
            linha_atual++;
        }
        fclose(arquivo);
    } else {
        fprintf(stderr, ">> [Erro ao abrir arquivo]\n");
    }
}

int main() {
    yydebug = 0;

    if (yyparse() != 0) {
        fprintf(stderr, "[ERRO] Falha na análise sintática.\n");
        return EXIT_FAILURE;
    }

    if (syntaxTree == NULL) {
        fprintf(stderr, "[ERRO] Árvore sintática não foi gerada corretamente!\n");
        return EXIT_FAILURE;
    }

    printf("[DEBUG] Gerando código C++...\n");

    // Abrir o arquivo de saída para C++
    FILE *cppFile = fopen("output/saida.cpp", "w");
    if (!cppFile) {
        perror("[ERRO] Não foi possível criar o arquivo de saída");
        return EXIT_FAILURE;
    }

    generateFinalCppCode(syntaxTree, cppFile);
    fclose(cppFile);

    printf("[SUCESSO] Código C++ gerado em 'saida.cpp'.\n");

    return 0;
}
