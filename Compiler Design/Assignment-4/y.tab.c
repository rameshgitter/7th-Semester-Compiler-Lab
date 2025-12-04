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

extern int yylex();
extern int yylineno;
extern char* yytext;

void yyerror(const char* s);

typedef struct symbol {
    char* name;
    char* type;
    int line;
    struct symbol* next;
} symbol_t;

symbol_t* symbol_table = NULL;

void add_symbol(char* name, char* type, int line);
int symbol_exists(char* name);


#line 96 "y.tab.c"

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

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    NUMBER = 259,                  /* NUMBER  */
    STRING_LITERAL = 260,          /* STRING_LITERAL  */
    INT = 261,                     /* INT  */
    FLOAT = 262,                   /* FLOAT  */
    CHAR = 263,                    /* CHAR  */
    VOID = 264,                    /* VOID  */
    IF = 265,                      /* IF  */
    ELSE = 266,                    /* ELSE  */
    WHILE = 267,                   /* WHILE  */
    FOR = 268,                     /* FOR  */
    RETURN = 269,                  /* RETURN  */
    MAIN = 270,                    /* MAIN  */
    ASSIGN = 271,                  /* ASSIGN  */
    EQ = 272,                      /* EQ  */
    NE = 273,                      /* NE  */
    LT = 274,                      /* LT  */
    LE = 275,                      /* LE  */
    GT = 276,                      /* GT  */
    GE = 277,                      /* GE  */
    AND = 278,                     /* AND  */
    OR = 279,                      /* OR  */
    NOT = 280,                     /* NOT  */
    PLUS = 281,                    /* PLUS  */
    MINUS = 282,                   /* MINUS  */
    MULTIPLY = 283,                /* MULTIPLY  */
    DIVIDE = 284,                  /* DIVIDE  */
    MODULO = 285,                  /* MODULO  */
    INCREMENT = 286,               /* INCREMENT  */
    DECREMENT = 287,               /* DECREMENT  */
    SEMICOLON = 288,               /* SEMICOLON  */
    COMMA = 289,                   /* COMMA  */
    LPAREN = 290,                  /* LPAREN  */
    RPAREN = 291,                  /* RPAREN  */
    LBRACE = 292,                  /* LBRACE  */
    RBRACE = 293,                  /* RBRACE  */
    LBRACKET = 294,                /* LBRACKET  */
    RBRACKET = 295,                /* RBRACKET  */
    COLON = 296,                   /* COLON  */
    LOWER_THAN_ELSE = 297          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IDENTIFIER 258
#define NUMBER 259
#define STRING_LITERAL 260
#define INT 261
#define FLOAT 262
#define CHAR 263
#define VOID 264
#define IF 265
#define ELSE 266
#define WHILE 267
#define FOR 268
#define RETURN 269
#define MAIN 270
#define ASSIGN 271
#define EQ 272
#define NE 273
#define LT 274
#define LE 275
#define GT 276
#define GE 277
#define AND 278
#define OR 279
#define NOT 280
#define PLUS 281
#define MINUS 282
#define MULTIPLY 283
#define DIVIDE 284
#define MODULO 285
#define INCREMENT 286
#define DECREMENT 287
#define SEMICOLON 288
#define COMMA 289
#define LPAREN 290
#define RPAREN 291
#define LBRACE 292
#define RBRACE 293
#define LBRACKET 294
#define RBRACKET 295
#define COLON 296
#define LOWER_THAN_ELSE 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "parser.y"

    char* string;
    int number;

#line 238 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_NUMBER = 4,                     /* NUMBER  */
  YYSYMBOL_STRING_LITERAL = 5,             /* STRING_LITERAL  */
  YYSYMBOL_INT = 6,                        /* INT  */
  YYSYMBOL_FLOAT = 7,                      /* FLOAT  */
  YYSYMBOL_CHAR = 8,                       /* CHAR  */
  YYSYMBOL_VOID = 9,                       /* VOID  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_FOR = 13,                       /* FOR  */
  YYSYMBOL_RETURN = 14,                    /* RETURN  */
  YYSYMBOL_MAIN = 15,                      /* MAIN  */
  YYSYMBOL_ASSIGN = 16,                    /* ASSIGN  */
  YYSYMBOL_EQ = 17,                        /* EQ  */
  YYSYMBOL_NE = 18,                        /* NE  */
  YYSYMBOL_LT = 19,                        /* LT  */
  YYSYMBOL_LE = 20,                        /* LE  */
  YYSYMBOL_GT = 21,                        /* GT  */
  YYSYMBOL_GE = 22,                        /* GE  */
  YYSYMBOL_AND = 23,                       /* AND  */
  YYSYMBOL_OR = 24,                        /* OR  */
  YYSYMBOL_NOT = 25,                       /* NOT  */
  YYSYMBOL_PLUS = 26,                      /* PLUS  */
  YYSYMBOL_MINUS = 27,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 28,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 29,                    /* DIVIDE  */
  YYSYMBOL_MODULO = 30,                    /* MODULO  */
  YYSYMBOL_INCREMENT = 31,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 32,                 /* DECREMENT  */
  YYSYMBOL_SEMICOLON = 33,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 34,                     /* COMMA  */
  YYSYMBOL_LPAREN = 35,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 36,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 37,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 38,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 39,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 40,                  /* RBRACKET  */
  YYSYMBOL_COLON = 41,                     /* COLON  */
  YYSYMBOL_LOWER_THAN_ELSE = 42,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_program = 44,                   /* program  */
  YYSYMBOL_translation_unit = 45,          /* translation_unit  */
  YYSYMBOL_external_declaration = 46,      /* external_declaration  */
  YYSYMBOL_function_definition = 47,       /* function_definition  */
  YYSYMBOL_declaration = 48,               /* declaration  */
  YYSYMBOL_declaration_specifiers = 49,    /* declaration_specifiers  */
  YYSYMBOL_type_specifier = 50,            /* type_specifier  */
  YYSYMBOL_init_declarator_list = 51,      /* init_declarator_list  */
  YYSYMBOL_init_declarator = 52,           /* init_declarator  */
  YYSYMBOL_declarator = 53,                /* declarator  */
  YYSYMBOL_direct_declarator = 54,         /* direct_declarator  */
  YYSYMBOL_parameter_list = 55,            /* parameter_list  */
  YYSYMBOL_parameter_declaration = 56,     /* parameter_declaration  */
  YYSYMBOL_compound_statement = 57,        /* compound_statement  */
  YYSYMBOL_block_item_list = 58,           /* block_item_list  */
  YYSYMBOL_block_item = 59,                /* block_item  */
  YYSYMBOL_statement = 60,                 /* statement  */
  YYSYMBOL_expression_statement = 61,      /* expression_statement  */
  YYSYMBOL_matched_statement = 62,         /* matched_statement  */
  YYSYMBOL_unmatched_statement = 63,       /* unmatched_statement  */
  YYSYMBOL_iteration_statement = 64,       /* iteration_statement  */
  YYSYMBOL_jump_statement = 65,            /* jump_statement  */
  YYSYMBOL_expression = 66,                /* expression  */
  YYSYMBOL_assignment_expression = 67,     /* assignment_expression  */
  YYSYMBOL_assignment_operator = 68,       /* assignment_operator  */
  YYSYMBOL_conditional_expression = 69,    /* conditional_expression  */
  YYSYMBOL_logical_or_expression = 70,     /* logical_or_expression  */
  YYSYMBOL_logical_and_expression = 71,    /* logical_and_expression  */
  YYSYMBOL_equality_expression = 72,       /* equality_expression  */
  YYSYMBOL_relational_expression = 73,     /* relational_expression  */
  YYSYMBOL_additive_expression = 74,       /* additive_expression  */
  YYSYMBOL_multiplicative_expression = 75, /* multiplicative_expression  */
  YYSYMBOL_unary_expression = 76,          /* unary_expression  */
  YYSYMBOL_unary_operator = 77,            /* unary_operator  */
  YYSYMBOL_postfix_expression = 78,        /* postfix_expression  */
  YYSYMBOL_primary_expression = 79,        /* primary_expression  */
  YYSYMBOL_argument_expression_list = 80   /* argument_expression_list  */
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
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   327

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  171

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    70,    70,    76,    77,    81,    82,    86,    90,    97,
     101,   105,   106,   107,   108,   112,   113,   117,   118,   126,
     130,   135,   140,   145,   150,   157,   158,   162,   166,   167,
     171,   172,   176,   177,   182,   183,   191,   192,   196,   197,
     198,   199,   200,   207,   211,   215,   219,   223,   227,   231,
     238,   242,   249,   250,   254,   255,   262,   266,   270,   271,
     275,   276,   280,   281,   282,   286,   287,   288,   289,   290,
     294,   295,   296,   300,   301,   302,   303,   307,   308,   309,
     310,   314,   315,   316,   320,   328,   332,   336,   340,   341,
     345,   346,   347,   348,   352,   353
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER", "NUMBER",
  "STRING_LITERAL", "INT", "FLOAT", "CHAR", "VOID", "IF", "ELSE", "WHILE",
  "FOR", "RETURN", "MAIN", "ASSIGN", "EQ", "NE", "LT", "LE", "GT", "GE",
  "AND", "OR", "NOT", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "MODULO",
  "INCREMENT", "DECREMENT", "SEMICOLON", "COMMA", "LPAREN", "RPAREN",
  "LBRACE", "RBRACE", "LBRACKET", "RBRACKET", "COLON", "LOWER_THAN_ELSE",
  "$accept", "program", "translation_unit", "external_declaration",
  "function_definition", "declaration", "declaration_specifiers",
  "type_specifier", "init_declarator_list", "init_declarator",
  "declarator", "direct_declarator", "parameter_list",
  "parameter_declaration", "compound_statement", "block_item_list",
  "block_item", "statement", "expression_statement", "matched_statement",
  "unmatched_statement", "iteration_statement", "jump_statement",
  "expression", "assignment_expression", "assignment_operator",
  "conditional_expression", "logical_or_expression",
  "logical_and_expression", "equality_expression", "relational_expression",
  "additive_expression", "multiplicative_expression", "unary_expression",
  "unary_operator", "postfix_expression", "primary_expression",
  "argument_expression_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-68)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      59,    14,   -68,   -68,   -68,   -68,   -13,    39,    59,   -68,
     -68,   -68,    32,   -68,    17,   -68,    21,    57,    33,   -68,
     -68,    43,   -68,    15,   101,   -68,   -68,    32,   -28,   -68,
      63,   -68,   -68,    32,   281,   -68,   -68,   -68,   -68,    38,
     100,   102,   256,   -68,   -68,   -68,   281,   281,   -68,   281,
     -68,   -68,    32,   -68,   137,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   127,   -68,   -68,   106,   125,   107,    74,   139,
      93,   151,   281,    24,   -68,   -68,    91,   -68,   -68,   -68,
     155,   -68,   281,   281,   245,   -68,   146,   -68,   -68,   -25,
     -68,   -68,   -68,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   -68,   281,   -68,
     -68,   -68,   186,   281,   -68,    36,    95,   270,   270,   -68,
     -68,   -68,   125,   -68,   107,    74,    74,   139,   139,   139,
     139,    93,    93,   -68,   -68,   -68,   -68,   -68,   -68,   118,
     -21,    11,   173,   198,   211,   281,   -68,   -68,   -68,   162,
     149,   -68,   173,   119,   173,   122,   -68,    11,   281,   -68,
     173,   -68,   173,   -68,   -68,   123,   -68,   -68,   173,   177,
     173
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    20,    13,    14,    12,    11,     0,     0,     2,     3,
       5,     6,     0,    10,     0,    19,     0,     0,     0,     1,
       4,     0,    15,    17,     0,     8,    23,     0,     0,    25,
       0,    24,     9,     0,     0,     7,    90,    91,    92,     0,
       0,     0,     0,    83,    81,    82,     0,     0,    36,     0,
      28,    32,     0,    38,     0,    30,    33,    39,    34,    35,
      40,    41,     0,    52,    54,    57,    58,    60,    62,    65,
      70,    73,     0,    77,    84,    27,     0,    22,    21,    16,
      17,    18,     0,     0,     0,    50,     0,    78,    79,     0,
      29,    31,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    56,     0,    80,
      88,    89,     0,     0,    26,     0,     0,     0,     0,    51,
      93,    53,    59,    73,    61,    63,    64,    66,    68,    67,
      69,    71,    72,    74,    75,    76,    55,    86,    94,     0,
       0,     0,     0,     0,     0,     0,    87,    85,    43,    34,
       0,    45,     0,     0,     0,     0,    95,     0,     0,    48,
       0,    46,     0,    42,    44,     0,    49,    47,     0,     0,
       0
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -68,   -68,   -68,   187,   -68,   -20,     2,   -68,   -68,   161,
      -7,   -68,   -68,   120,   -11,   -68,   143,    66,   -67,   157,
      52,   -68,   -68,   -42,   -33,   -68,   -68,   -68,   126,   124,
      85,    19,    90,   -14,   -68,   -68,   -68,   -68
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     7,     8,     9,    10,    11,    52,    13,    21,    22,
      14,    15,    28,    29,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,   108,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,   139
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      86,    81,    12,    25,    51,    23,    76,    89,    77,    93,
      12,   120,    35,    93,    36,    37,    38,   118,    27,   147,
      75,    39,    18,    40,    41,    42,    80,     2,     3,     4,
       5,    34,    87,    88,    51,     1,    43,    44,    45,    19,
     115,   116,    46,    47,    48,    80,    49,     6,    24,    16,
     143,   144,    24,    17,    24,   110,   111,    26,   109,   112,
     121,    30,     1,   113,   117,     2,     3,     4,     5,    31,
      93,   140,   141,    82,     6,   136,    32,    33,    27,   138,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     133,   134,   135,    98,    99,   100,   101,     2,     3,     4,
       5,   153,   155,    78,    36,    37,    38,     2,     3,     4,
       5,    39,   156,    40,    41,    42,   165,   127,   128,   129,
     130,   104,   105,   106,    96,    97,    43,    44,    45,    93,
      94,   142,    46,    47,    48,    83,    49,    84,    24,    50,
      36,    37,    38,     2,     3,     4,     5,    39,    95,    40,
      41,    42,   145,    93,   146,   160,    93,    93,   162,   168,
      92,    93,    43,    44,    45,   102,   103,   107,    46,    47,
      48,    34,    49,   157,    24,    90,    36,    37,    38,   119,
      93,   125,   126,   150,   158,    40,    41,    42,   170,    36,
      37,    38,   131,   132,    79,    20,   114,    91,    43,    44,
      45,    36,    37,    38,    46,    47,    48,   148,    49,   164,
      24,    43,    44,    45,    36,    37,    38,    46,    47,   124,
     122,    49,   137,    43,    44,    45,     0,     0,     0,    46,
      47,     0,     0,    49,   152,     0,    43,    44,    45,     0,
       0,     0,    46,    47,     0,     0,    49,   154,    36,    37,
      38,     2,     3,     4,     5,     0,     0,     0,     0,    36,
      37,    38,     0,     0,     0,     0,     0,     0,     0,     0,
      43,    44,    45,    36,    37,    38,    46,    47,    48,     0,
      49,    43,    44,    45,    36,    37,    38,    46,    47,    85,
       0,    49,     0,     0,     0,    43,    44,    45,   149,   151,
       0,    46,    47,    48,     0,    49,    43,    44,    45,   159,
       0,   161,    46,    47,   163,     0,    49,   166,     0,   167,
       0,     0,     0,     0,     0,   169,     0,   163
};

static const yytype_int16 yycheck[] =
{
      42,    34,     0,    14,    24,    12,    34,    49,    36,    34,
       8,    36,    23,    34,     3,     4,     5,    84,    16,    40,
      27,    10,    35,    12,    13,    14,    33,     6,     7,     8,
       9,    16,    46,    47,    54,     3,    25,    26,    27,     0,
      82,    83,    31,    32,    33,    52,    35,    15,    37,    35,
     117,   118,    37,    39,    37,    31,    32,    36,    72,    35,
      93,     4,     3,    39,    84,     6,     7,     8,     9,    36,
      34,   113,    36,    35,    15,   108,    33,    34,    76,   112,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,    19,    20,    21,    22,     6,     7,     8,
       9,   143,   144,    40,     3,     4,     5,     6,     7,     8,
       9,    10,   145,    12,    13,    14,   158,    98,    99,   100,
     101,    28,    29,    30,    17,    18,    25,    26,    27,    34,
      24,    36,    31,    32,    33,    35,    35,    35,    37,    38,
       3,     4,     5,     6,     7,     8,     9,    10,    23,    12,
      13,    14,    34,    34,    36,    36,    34,    34,    36,    36,
      33,    34,    25,    26,    27,    26,    27,    16,    31,    32,
      33,    16,    35,    11,    37,    38,     3,     4,     5,    33,
      34,    96,    97,    10,    35,    12,    13,    14,    11,     3,
       4,     5,   102,   103,    33,     8,    76,    54,    25,    26,
      27,     3,     4,     5,    31,    32,    33,   141,    35,   157,
      37,    25,    26,    27,     3,     4,     5,    31,    32,    95,
      94,    35,    36,    25,    26,    27,    -1,    -1,    -1,    31,
      32,    -1,    -1,    35,    36,    -1,    25,    26,    27,    -1,
      -1,    -1,    31,    32,    -1,    -1,    35,    36,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    26,    27,     3,     4,     5,    31,    32,    33,    -1,
      35,    25,    26,    27,     3,     4,     5,    31,    32,    33,
      -1,    35,    -1,    -1,    -1,    25,    26,    27,   141,   142,
      -1,    31,    32,    33,    -1,    35,    25,    26,    27,   152,
      -1,   154,    31,    32,   157,    -1,    35,   160,    -1,   162,
      -1,    -1,    -1,    -1,    -1,   168,    -1,   170
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     6,     7,     8,     9,    15,    44,    45,    46,
      47,    48,    49,    50,    53,    54,    35,    39,    35,     0,
      46,    51,    52,    53,    37,    57,    36,    49,    55,    56,
       4,    36,    33,    34,    16,    57,     3,     4,     5,    10,
      12,    13,    14,    25,    26,    27,    31,    32,    33,    35,
      38,    48,    49,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    53,    34,    36,    40,    52,
      53,    67,    35,    35,    35,    33,    66,    76,    76,    66,
      38,    59,    33,    34,    24,    23,    17,    18,    19,    20,
      21,    22,    26,    27,    28,    29,    30,    16,    68,    76,
      31,    32,    35,    39,    56,    66,    66,    48,    61,    33,
      36,    67,    71,    76,    72,    73,    73,    74,    74,    74,
      74,    75,    75,    76,    76,    76,    67,    36,    67,    80,
      66,    36,    36,    61,    61,    34,    36,    40,    60,    62,
      10,    62,    36,    66,    36,    66,    67,    11,    35,    62,
      36,    62,    36,    62,    63,    66,    62,    62,    36,    62,
      11
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    47,    47,    48,
      49,    50,    50,    50,    50,    51,    51,    52,    52,    53,
      54,    54,    54,    54,    54,    55,    55,    56,    57,    57,
      58,    58,    59,    59,    60,    60,    61,    61,    62,    62,
      62,    62,    62,    63,    63,    64,    64,    64,    64,    64,
      65,    65,    66,    66,    67,    67,    68,    69,    70,    70,
      71,    71,    72,    72,    72,    73,    73,    73,    73,    73,
      74,    74,    74,    75,    75,    75,    75,    76,    76,    76,
      76,    77,    77,    77,    78,    78,    78,    78,    78,    78,
      79,    79,    79,    79,    80,    80
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     2,     3,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     1,
       1,     4,     4,     3,     3,     1,     3,     2,     2,     3,
       1,     2,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     7,     5,     7,     5,     6,     7,     6,     7,
       2,     3,     1,     3,     1,     3,     1,     1,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     2,     2,
       2,     1,     1,     1,     1,     4,     3,     4,     2,     2,
       1,     1,     1,     3,     1,     3
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
  case 2: /* program: translation_unit  */
#line 71 "parser.y"
    {
    }
#line 1453 "y.tab.c"
    break;

  case 7: /* function_definition: declaration_specifiers declarator compound_statement  */
#line 87 "parser.y"
    {
        printf("Function definition completed at line %d\n", yylineno);
    }
#line 1461 "y.tab.c"
    break;

  case 8: /* function_definition: declarator compound_statement  */
#line 91 "parser.y"
    {
        printf("Function definition (no return type) at line %d\n", yylineno);
    }
#line 1469 "y.tab.c"
    break;

  case 11: /* type_specifier: VOID  */
#line 105 "parser.y"
            { (yyval.string) = "void"; }
#line 1475 "y.tab.c"
    break;

  case 12: /* type_specifier: CHAR  */
#line 106 "parser.y"
            { (yyval.string) = "char"; }
#line 1481 "y.tab.c"
    break;

  case 13: /* type_specifier: INT  */
#line 107 "parser.y"
            { (yyval.string) = "int"; }
#line 1487 "y.tab.c"
    break;

  case 14: /* type_specifier: FLOAT  */
#line 108 "parser.y"
            { (yyval.string) = "float"; }
#line 1493 "y.tab.c"
    break;

  case 18: /* init_declarator: declarator ASSIGN assignment_expression  */
#line 119 "parser.y"
    {
        /* handle initialized declarator like: int a = 5; */
        printf("Initialized declarator at line %d\n", yylineno);
    }
#line 1502 "y.tab.c"
    break;

  case 20: /* direct_declarator: IDENTIFIER  */
#line 131 "parser.y"
    {
        add_symbol((yyvsp[0].string), "variable", yylineno);
        printf("Variable declared: %s at line %d\n", (yyvsp[0].string), yylineno);
    }
#line 1511 "y.tab.c"
    break;

  case 21: /* direct_declarator: IDENTIFIER LBRACKET NUMBER RBRACKET  */
#line 136 "parser.y"
    {
        add_symbol((yyvsp[-3].string), "array", yylineno);
        printf("Array declared: %s[%d] at line %d\n", (yyvsp[-3].string), (yyvsp[-1].number), yylineno);
    }
#line 1520 "y.tab.c"
    break;

  case 22: /* direct_declarator: IDENTIFIER LPAREN parameter_list RPAREN  */
#line 141 "parser.y"
    {
        add_symbol((yyvsp[-3].string), "function", yylineno);
        printf("Function declarator: %s at line %d\n", (yyvsp[-3].string), yylineno);
    }
#line 1529 "y.tab.c"
    break;

  case 23: /* direct_declarator: IDENTIFIER LPAREN RPAREN  */
#line 146 "parser.y"
    {
        add_symbol((yyvsp[-2].string), "function", yylineno);
        printf("Function declarator: %s at line %d\n", (yyvsp[-2].string), yylineno);
    }
#line 1538 "y.tab.c"
    break;

  case 24: /* direct_declarator: MAIN LPAREN RPAREN  */
#line 151 "parser.y"
    {
        printf("Main function declarator at line %d\n", yylineno);
    }
#line 1546 "y.tab.c"
    break;

  case 42: /* matched_statement: IF LPAREN expression RPAREN matched_statement ELSE matched_statement  */
#line 201 "parser.y"
    {
        printf("If-else statement at line %d\n", yylineno);
    }
#line 1554 "y.tab.c"
    break;

  case 43: /* unmatched_statement: IF LPAREN expression RPAREN statement  */
#line 208 "parser.y"
    {
        printf("If statement at line %d\n", yylineno);
    }
#line 1562 "y.tab.c"
    break;

  case 45: /* iteration_statement: WHILE LPAREN expression RPAREN matched_statement  */
#line 216 "parser.y"
    {
        printf("While loop at line %d\n", yylineno);
    }
#line 1570 "y.tab.c"
    break;

  case 46: /* iteration_statement: FOR LPAREN expression_statement expression_statement RPAREN matched_statement  */
#line 220 "parser.y"
    {
        printf("For loop at line %d\n", yylineno);
    }
#line 1578 "y.tab.c"
    break;

  case 47: /* iteration_statement: FOR LPAREN expression_statement expression_statement expression RPAREN matched_statement  */
#line 224 "parser.y"
    {
        printf("For loop at line %d\n", yylineno);
    }
#line 1586 "y.tab.c"
    break;

  case 48: /* iteration_statement: FOR LPAREN declaration expression_statement RPAREN matched_statement  */
#line 228 "parser.y"
    {
        printf("For loop with declaration at line %d\n", yylineno);
    }
#line 1594 "y.tab.c"
    break;

  case 49: /* iteration_statement: FOR LPAREN declaration expression_statement expression RPAREN matched_statement  */
#line 232 "parser.y"
    {
        printf("For loop with declaration at line %d\n", yylineno);
    }
#line 1602 "y.tab.c"
    break;

  case 50: /* jump_statement: RETURN SEMICOLON  */
#line 239 "parser.y"
    {
        printf("Return statement at line %d\n", yylineno);
    }
#line 1610 "y.tab.c"
    break;

  case 51: /* jump_statement: RETURN expression SEMICOLON  */
#line 243 "parser.y"
    {
        printf("Return statement with value at line %d\n", yylineno);
    }
#line 1618 "y.tab.c"
    break;

  case 55: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 256 "parser.y"
    {
        printf("Assignment at line %d\n", yylineno);
    }
#line 1626 "y.tab.c"
    break;

  case 84: /* postfix_expression: primary_expression  */
#line 321 "parser.y"
    {
        if ((yyvsp[0].string) != NULL) {
            if (!symbol_exists((yyvsp[0].string))) {
                printf("Error: Undeclared variable '%s' used at line %d\n", (yyvsp[0].string), yylineno);
            }
        }
    }
#line 1638 "y.tab.c"
    break;

  case 85: /* postfix_expression: postfix_expression LBRACKET expression RBRACKET  */
#line 329 "parser.y"
    {
        printf("Array access at line %d\n", yylineno);
    }
#line 1646 "y.tab.c"
    break;

  case 86: /* postfix_expression: postfix_expression LPAREN RPAREN  */
#line 333 "parser.y"
    {
        printf("Function call (no args) at line %d\n", yylineno);
    }
#line 1654 "y.tab.c"
    break;

  case 87: /* postfix_expression: postfix_expression LPAREN argument_expression_list RPAREN  */
#line 337 "parser.y"
    {
        printf("Function call with args at line %d\n", yylineno);
    }
#line 1662 "y.tab.c"
    break;

  case 90: /* primary_expression: IDENTIFIER  */
#line 345 "parser.y"
               { (yyval.string) = (yyvsp[0].string); }
#line 1668 "y.tab.c"
    break;

  case 91: /* primary_expression: NUMBER  */
#line 346 "parser.y"
             { (yyval.string) = NULL; }
#line 1674 "y.tab.c"
    break;

  case 92: /* primary_expression: STRING_LITERAL  */
#line 347 "parser.y"
                     { (yyval.string) = NULL; }
#line 1680 "y.tab.c"
    break;

  case 93: /* primary_expression: LPAREN expression RPAREN  */
#line 348 "parser.y"
                               { (yyval.string) = NULL; }
#line 1686 "y.tab.c"
    break;


#line 1690 "y.tab.c"

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

#line 356 "parser.y"


void yyerror(const char* s) {
    printf("Syntax Error at line %d: %s near '%s'\n", yylineno, s, yytext);
}

void add_symbol(char* name, char* type, int line) {
    symbol_t* current = symbol_table;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Warning: Variable '%s' redeclared at line %d (previously declared at line %d)\n", 
                   name, line, current->line);
            return;
        }
        current = current->next;
    }
    
    symbol_t* new_symbol = (symbol_t*)malloc(sizeof(symbol_t));
    new_symbol->name = strdup(name);
    new_symbol->type = strdup(type);
    new_symbol->line = line;
    new_symbol->next = symbol_table;
    symbol_table = new_symbol;
}

int symbol_exists(char* name) {
    symbol_t* current = symbol_table;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void print_symbol_table() {
    printf("\n--- Symbol Table ---\n");
    printf("Name\t\tType\t\tLine\n");
    printf("----\t\t----\t\t----\n");
    
    symbol_t* current = symbol_table;
    while (current != NULL) {
        printf("%-15s %-15s %d\n", current->name, current->type, current->line);
        current = current->next;
    }
    printf("-------------------\n");
}

int main() {
    printf("C Subset Syntax Analyzer\n");
    printf("========================\n");
    
    printf("Enter your C code (Ctrl+D to end input):\n");
    /* Pre-populate symbol table with common stdlib functions to avoid false 'undeclared' errors */
    add_symbol("printf", "function", 0);
    add_symbol("scanf", "function", 0);
    add_symbol("puts", "function", 0);
    
    if (yyparse() == 0) {
        printf("\nParsing completed successfully!\n");
        print_symbol_table();
    } else {
        printf("\nParsing failed due to syntax errors.\n");
    }
    
    return 0;
}
