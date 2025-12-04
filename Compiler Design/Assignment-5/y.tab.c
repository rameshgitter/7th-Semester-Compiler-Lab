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
#line 4 "symbol_table.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Symbol Table Structure */
typedef struct SymbolTable {
    char name[50];
    char datatype[20];
    int scope;
    int line_no;
    struct SymbolTable *next;
} SymbolTable;

/* Global Variables */
SymbolTable *symbol_table_head = NULL;
int current_scope = 0;
int line_number = 1;
char current_datatype[20];

/* Function Declarations */
void yyerror(const char *s);
int yylex();
void insert_symbol(char *name, char *datatype, int scope, int line);
int lookup_symbol(char *name, int scope);
int lookup_symbol_all_scopes(char *name);
void display_symbol_table();
void enter_scope();
void exit_scope();
void remove_scope(int scope);


#line 104 "y.tab.c"

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
    INT = 260,                     /* INT  */
    FLOAT = 261,                   /* FLOAT  */
    CHAR = 262,                    /* CHAR  */
    DOUBLE = 263,                  /* DOUBLE  */
    VOID = 264,                    /* VOID  */
    IF = 265,                      /* IF  */
    ELSE = 266,                    /* ELSE  */
    WHILE = 267,                   /* WHILE  */
    FOR = 268,                     /* FOR  */
    RETURN = 269,                  /* RETURN  */
    SEMICOLON = 270,               /* SEMICOLON  */
    COMMA = 271,                   /* COMMA  */
    LBRACE = 272,                  /* LBRACE  */
    RBRACE = 273,                  /* RBRACE  */
    LPAREN = 274,                  /* LPAREN  */
    RPAREN = 275,                  /* RPAREN  */
    ASSIGN = 276,                  /* ASSIGN  */
    PLUS = 277,                    /* PLUS  */
    MINUS = 278,                   /* MINUS  */
    MULTIPLY = 279,                /* MULTIPLY  */
    DIVIDE = 280,                  /* DIVIDE  */
    LT = 281,                      /* LT  */
    GT = 282,                      /* GT  */
    LE = 283,                      /* LE  */
    GE = 284,                      /* GE  */
    EQ = 285,                      /* EQ  */
    NE = 286                       /* NE  */
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
#define INT 260
#define FLOAT 261
#define CHAR 262
#define DOUBLE 263
#define VOID 264
#define IF 265
#define ELSE 266
#define WHILE 267
#define FOR 268
#define RETURN 269
#define SEMICOLON 270
#define COMMA 271
#define LBRACE 272
#define RBRACE 273
#define LPAREN 274
#define RPAREN 275
#define ASSIGN 276
#define PLUS 277
#define MINUS 278
#define MULTIPLY 279
#define DIVIDE 280
#define LT 281
#define GT 282
#define LE 283
#define GE 284
#define EQ 285
#define NE 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 37 "symbol_table.y"

    char *string;
    int number;
    struct {
        char *type;
        int is_pointer;
        int is_array;
    } expr_attr;

#line 229 "y.tab.c"

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
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_FLOAT = 6,                      /* FLOAT  */
  YYSYMBOL_CHAR = 7,                       /* CHAR  */
  YYSYMBOL_DOUBLE = 8,                     /* DOUBLE  */
  YYSYMBOL_VOID = 9,                       /* VOID  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_FOR = 13,                       /* FOR  */
  YYSYMBOL_RETURN = 14,                    /* RETURN  */
  YYSYMBOL_SEMICOLON = 15,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 16,                     /* COMMA  */
  YYSYMBOL_LBRACE = 17,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 18,                    /* RBRACE  */
  YYSYMBOL_LPAREN = 19,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 20,                    /* RPAREN  */
  YYSYMBOL_ASSIGN = 21,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 22,                      /* PLUS  */
  YYSYMBOL_MINUS = 23,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 24,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 25,                    /* DIVIDE  */
  YYSYMBOL_LT = 26,                        /* LT  */
  YYSYMBOL_GT = 27,                        /* GT  */
  YYSYMBOL_LE = 28,                        /* LE  */
  YYSYMBOL_GE = 29,                        /* GE  */
  YYSYMBOL_EQ = 30,                        /* EQ  */
  YYSYMBOL_NE = 31,                        /* NE  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_program = 33,                   /* program  */
  YYSYMBOL_function_list = 34,             /* function_list  */
  YYSYMBOL_function = 35,                  /* function  */
  YYSYMBOL_36_1 = 36,                      /* $@1  */
  YYSYMBOL_parameter_list = 37,            /* parameter_list  */
  YYSYMBOL_parameter_declaration_list = 38, /* parameter_declaration_list  */
  YYSYMBOL_parameter_declaration = 39,     /* parameter_declaration  */
  YYSYMBOL_compound_statement = 40,        /* compound_statement  */
  YYSYMBOL_41_2 = 41,                      /* $@2  */
  YYSYMBOL_declaration_list = 42,          /* declaration_list  */
  YYSYMBOL_declaration = 43,               /* declaration  */
  YYSYMBOL_type = 44,                      /* type  */
  YYSYMBOL_identifier_list = 45,           /* identifier_list  */
  YYSYMBOL_statement_list = 46,            /* statement_list  */
  YYSYMBOL_statement = 47,                 /* statement  */
  YYSYMBOL_expression_statement = 48,      /* expression_statement  */
  YYSYMBOL_expression = 49,                /* expression  */
  YYSYMBOL_simple_expression = 50,         /* simple_expression  */
  YYSYMBOL_relop = 51,                     /* relop  */
  YYSYMBOL_additive_expression = 52,       /* additive_expression  */
  YYSYMBOL_term = 53,                      /* term  */
  YYSYMBOL_factor = 54,                    /* factor  */
  YYSYMBOL_selection_statement = 55,       /* selection_statement  */
  YYSYMBOL_iteration_statement = 56,       /* iteration_statement  */
  YYSYMBOL_return_statement = 57           /* return_statement  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   99

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  100

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    61,    61,    69,    70,    75,    74,    85,    87,    91,
      92,    96,   104,   103,   113,   115,   119,   120,   134,   135,
     136,   137,   138,   142,   153,   166,   168,   172,   173,   174,
     175,   176,   180,   181,   185,   215,   219,   220,   231,   231,
     231,   231,   231,   231,   235,   236,   244,   255,   256,   264,
     275,   299,   300,   304,   309,   317,   322,   330,   331
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
  "INT", "FLOAT", "CHAR", "DOUBLE", "VOID", "IF", "ELSE", "WHILE", "FOR",
  "RETURN", "SEMICOLON", "COMMA", "LBRACE", "RBRACE", "LPAREN", "RPAREN",
  "ASSIGN", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "LT", "GT", "LE", "GE",
  "EQ", "NE", "$accept", "program", "function_list", "function", "$@1",
  "parameter_list", "parameter_declaration_list", "parameter_declaration",
  "compound_statement", "$@2", "declaration_list", "declaration", "type",
  "identifier_list", "statement_list", "statement", "expression_statement",
  "expression", "simple_expression", "relop", "additive_expression",
  "term", "factor", "selection_statement", "iteration_statement",
  "return_statement", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-58)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       0,   -58,   -58,   -58,   -58,   -58,     2,     0,   -58,    10,
     -58,   -58,    -3,     0,    19,    17,   -58,    41,   -58,     0,
     -58,    32,   -58,   -58,   -58,   -58,     0,   -58,    48,    11,
      36,    44,    59,   -58,    62,    63,    64,    31,   -58,   -58,
       8,   -58,   -58,   -58,    69,   -58,    35,    45,   -58,   -58,
     -58,   -58,    81,   -58,    83,     8,     8,     8,    33,   -58,
      72,    68,   -58,    52,    52,   -58,   -58,   -58,   -58,   -58,
     -58,    52,    52,    52,    71,   -58,   -58,    70,    73,    33,
     -58,   -58,   -58,    45,    45,    50,   -58,   -58,    76,    28,
      28,     8,   -58,    84,   -58,    74,    28,    28,   -58,   -58
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    18,    19,    20,    21,    22,     0,     2,     4,     0,
       1,     3,     0,     7,     0,     8,     9,     0,     5,     0,
      11,     0,    10,    12,     6,    14,    25,    15,     0,     0,
      23,     0,    50,    51,     0,     0,     0,     0,    32,    13,
       0,    28,    26,    27,     0,    35,    36,    44,    47,    29,
      30,    31,     0,    16,     0,     0,     0,     0,     0,    57,
       0,     0,    33,     0,     0,    38,    39,    40,    41,    42,
      43,     0,     0,     0,     0,    24,    34,     0,     0,     0,
      58,    52,    50,    45,    46,    37,    48,    49,     0,     0,
       0,     0,    17,    53,    55,     0,     0,     0,    54,    56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -58,   -58,   -58,    85,   -58,   -58,   -58,    77,    78,   -58,
     -58,   -58,    -9,   -58,   -58,   -22,   -57,   -37,   -58,   -58,
      26,    13,     6,   -58,   -58,   -58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     6,     7,     8,    21,    14,    15,    16,    41,    25,
      26,    27,     9,    31,    29,    42,    43,    44,    45,    71,
      46,    47,    48,    49,    50,    51
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      60,    79,    10,    61,    17,     1,     2,     3,     4,     5,
      17,    32,    33,    12,    32,    33,    13,    28,    76,    77,
      78,    34,    91,    35,    36,    37,    38,    40,    23,    39,
      40,    32,    33,    19,    32,    33,    32,    33,    34,    18,
      35,    36,    37,    38,    20,    23,    59,    40,    38,    23,
      40,    30,    40,    52,    95,    82,    33,    63,    64,    53,
      54,    65,    66,    67,    68,    69,    70,    93,    94,    72,
      73,    40,    63,    64,    98,    99,    83,    84,    86,    87,
      55,    56,    57,    58,    62,    74,    75,    80,    81,    88,
      89,    92,    11,    90,    97,    96,    22,    85,     0,    24
};

static const yytype_int8 yycheck[] =
{
      37,    58,     0,    40,    13,     5,     6,     7,     8,     9,
      19,     3,     4,     3,     3,     4,    19,    26,    55,    56,
      57,    10,    79,    12,    13,    14,    15,    19,    17,    18,
      19,     3,     4,    16,     3,     4,     3,     4,    10,    20,
      12,    13,    14,    15,     3,    17,    15,    19,    15,    17,
      19,     3,    19,    17,    91,     3,     4,    22,    23,    15,
      16,    26,    27,    28,    29,    30,    31,    89,    90,    24,
      25,    19,    22,    23,    96,    97,    63,    64,    72,    73,
      21,    19,    19,    19,    15,     4,     3,    15,    20,    18,
      20,    15,     7,    20,    20,    11,    19,    71,    -1,    21
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     6,     7,     8,     9,    33,    34,    35,    44,
       0,    35,     3,    19,    37,    38,    39,    44,    20,    16,
       3,    36,    39,    17,    40,    41,    42,    43,    44,    46,
       3,    45,     3,     4,    10,    12,    13,    14,    15,    18,
      19,    40,    47,    48,    49,    50,    52,    53,    54,    55,
      56,    57,    17,    15,    16,    21,    19,    19,    19,    15,
      49,    49,    15,    22,    23,    26,    27,    28,    29,    30,
      31,    51,    24,    25,     4,     3,    49,    49,    49,    48,
      15,    20,     3,    53,    53,    52,    54,    54,    18,    20,
      20,    48,    15,    47,    47,    49,    11,    20,    47,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    36,    35,    37,    37,    38,
      38,    39,    41,    40,    42,    42,    43,    43,    44,    44,
      44,    44,    44,    45,    45,    46,    46,    47,    47,    47,
      47,    47,    48,    48,    49,    49,    50,    50,    51,    51,
      51,    51,    51,    51,    52,    52,    52,    53,    53,    53,
      54,    54,    54,    55,    55,    56,    56,    57,    57
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     0,     7,     0,     1,     1,
       3,     2,     0,     5,     0,     2,     3,     6,     1,     1,
       1,     1,     1,     1,     3,     0,     2,     1,     1,     1,
       1,     1,     1,     2,     3,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     3,     3,
       1,     1,     3,     5,     7,     5,     7,     2,     3
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
  case 2: /* program: function_list  */
#line 62 "symbol_table.y"
    {
        printf("\n=== Symbol Table ===\n");
        display_symbol_table();
    }
#line 1330 "y.tab.c"
    break;

  case 5: /* $@1: %empty  */
#line 75 "symbol_table.y"
    {
        enter_scope();
        insert_symbol((yyvsp[-3].string), (yyvsp[-4].string), current_scope, line_number);
    }
#line 1339 "y.tab.c"
    break;

  case 6: /* function: type IDENTIFIER LPAREN parameter_list RPAREN $@1 compound_statement  */
#line 80 "symbol_table.y"
    {
        exit_scope();
    }
#line 1347 "y.tab.c"
    break;

  case 11: /* parameter_declaration: type IDENTIFIER  */
#line 97 "symbol_table.y"
    {
        insert_symbol((yyvsp[0].string), (yyvsp[-1].string), current_scope, line_number);
    }
#line 1355 "y.tab.c"
    break;

  case 12: /* $@2: %empty  */
#line 104 "symbol_table.y"
    {
        enter_scope();
    }
#line 1363 "y.tab.c"
    break;

  case 13: /* compound_statement: LBRACE $@2 declaration_list statement_list RBRACE  */
#line 108 "symbol_table.y"
    {
        exit_scope();
    }
#line 1371 "y.tab.c"
    break;

  case 17: /* declaration: type IDENTIFIER LBRACE NUMBER RBRACE SEMICOLON  */
#line 120 "symbol_table.y"
                                                     {
        // Array declaration type checking
        char arr_type[64];
        snprintf(arr_type, sizeof(arr_type), "%s[%d]", (yyvsp[-5].string), (yyvsp[-2].number));
        if (lookup_symbol((yyvsp[-4].string), current_scope) == 1) {
            printf("Error: Array '%s' already declared in this scope at line %d\n", (yyvsp[-4].string), line_number);
        } else {
            insert_symbol((yyvsp[-4].string), arr_type, current_scope, line_number);
            printf("Declared array: %s (type: %s, scope: %d, line: %d)\n", (yyvsp[-4].string), arr_type, current_scope, line_number);
        }
    }
#line 1387 "y.tab.c"
    break;

  case 18: /* type: INT  */
#line 134 "symbol_table.y"
            { (yyval.string) = strdup("int"); strcpy(current_datatype, "int"); }
#line 1393 "y.tab.c"
    break;

  case 19: /* type: FLOAT  */
#line 135 "symbol_table.y"
            { (yyval.string) = strdup("float"); strcpy(current_datatype, "float"); }
#line 1399 "y.tab.c"
    break;

  case 20: /* type: CHAR  */
#line 136 "symbol_table.y"
            { (yyval.string) = strdup("char"); strcpy(current_datatype, "char"); }
#line 1405 "y.tab.c"
    break;

  case 21: /* type: DOUBLE  */
#line 137 "symbol_table.y"
             { (yyval.string) = strdup("double"); strcpy(current_datatype, "double"); }
#line 1411 "y.tab.c"
    break;

  case 22: /* type: VOID  */
#line 138 "symbol_table.y"
            { (yyval.string) = strdup("void"); strcpy(current_datatype, "void"); }
#line 1417 "y.tab.c"
    break;

  case 23: /* identifier_list: IDENTIFIER  */
#line 143 "symbol_table.y"
    {
        if (lookup_symbol((yyvsp[0].string), current_scope) == 1) {
            printf("Error: Variable '%s' already declared in this scope at line %d\n", 
                   (yyvsp[0].string), line_number);
        } else {
            insert_symbol((yyvsp[0].string), current_datatype, current_scope, line_number);
            printf("Declared: %s (type: %s, scope: %d, line: %d)\n", 
                   (yyvsp[0].string), current_datatype, current_scope, line_number);
        }
    }
#line 1432 "y.tab.c"
    break;

  case 24: /* identifier_list: identifier_list COMMA IDENTIFIER  */
#line 154 "symbol_table.y"
    {
        if (lookup_symbol((yyvsp[0].string), current_scope) == 1) {
            printf("Error: Variable '%s' already declared in this scope at line %d\n", 
                   (yyvsp[0].string), line_number);
        } else {
            insert_symbol((yyvsp[0].string), current_datatype, current_scope, line_number);
            printf("Declared: %s (type: %s, scope: %d, line: %d)\n", 
                   (yyvsp[0].string), current_datatype, current_scope, line_number);
        }
    }
#line 1447 "y.tab.c"
    break;

  case 34: /* expression: IDENTIFIER ASSIGN expression  */
#line 186 "symbol_table.y"
    {
        if (lookup_symbol_all_scopes((yyvsp[-2].string)) == 0) {
            printf("Error: Variable '%s' used before declaration at line %d\n", (yyvsp[-2].string), line_number);
        } else {
            // Assignment type checking
            SymbolTable *temp = symbol_table_head;
            char *lhs_type = NULL;
            int lhs_is_pointer = 0, lhs_is_array = 0;
            while (temp != NULL) {
                if (strcmp(temp->name, (yyvsp[-2].string)) == 0) {
                    lhs_type = temp->datatype;
                    if (strchr(lhs_type, '*')) lhs_is_pointer = 1;
                    if (strchr(lhs_type, '[')) lhs_is_array = 1;
                    break;
                }
                temp = temp->next;
            }
            if (lhs_type && strcmp(lhs_type, (yyvsp[0].expr_attr).type) != 0) {
                printf("Type Error: Assignment type mismatch at line %d ('%s' vs '%s')\n", line_number, lhs_type, (yyvsp[0].expr_attr).type);
            } else if (lhs_is_pointer != (yyvsp[0].expr_attr).is_pointer) {
                printf("Type Error: Pointer assignment mismatch at line %d\n", line_number);
            } else if (lhs_is_array != (yyvsp[0].expr_attr).is_array) {
                printf("Type Error: Array assignment mismatch at line %d\n", line_number);
            }
        }
        (yyval.expr_attr).type = (yyvsp[0].expr_attr).type;
        (yyval.expr_attr).is_pointer = (yyvsp[0].expr_attr).is_pointer;
        (yyval.expr_attr).is_array = (yyvsp[0].expr_attr).is_array;
    }
#line 1481 "y.tab.c"
    break;

  case 35: /* expression: simple_expression  */
#line 215 "symbol_table.y"
                        { (yyval.expr_attr).type = (yyvsp[0].expr_attr).type; (yyval.expr_attr).is_pointer = (yyvsp[0].expr_attr).is_pointer; (yyval.expr_attr).is_array = (yyvsp[0].expr_attr).is_array; }
#line 1487 "y.tab.c"
    break;

  case 36: /* simple_expression: additive_expression  */
#line 219 "symbol_table.y"
                        { (yyval.expr_attr).type = (yyvsp[0].expr_attr).type; (yyval.expr_attr).is_pointer = (yyvsp[0].expr_attr).is_pointer; (yyval.expr_attr).is_array = (yyvsp[0].expr_attr).is_array; }
#line 1493 "y.tab.c"
    break;

  case 37: /* simple_expression: additive_expression relop additive_expression  */
#line 220 "symbol_table.y"
                                                    {
        if (strcmp((yyvsp[-2].expr_attr).type, (yyvsp[0].expr_attr).type) != 0) {
            printf("Type Error: Sub-expressions have different types at line %d ('%s' vs '%s')\n", line_number, (yyvsp[-2].expr_attr).type, (yyvsp[0].expr_attr).type);
        }
        (yyval.expr_attr).type = strdup("int"); // Relational ops result in int (bool)
        (yyval.expr_attr).is_pointer = 0;
        (yyval.expr_attr).is_array = 0;
    }
#line 1506 "y.tab.c"
    break;

  case 44: /* additive_expression: term  */
#line 235 "symbol_table.y"
         { (yyval.expr_attr).type = (yyvsp[0].expr_attr).type; (yyval.expr_attr).is_pointer = (yyvsp[0].expr_attr).is_pointer; (yyval.expr_attr).is_array = (yyvsp[0].expr_attr).is_array; }
#line 1512 "y.tab.c"
    break;

  case 45: /* additive_expression: additive_expression PLUS term  */
#line 236 "symbol_table.y"
                                    {
        if (strcmp((yyvsp[-2].expr_attr).type, (yyvsp[0].expr_attr).type) != 0) {
            printf("Type Error: Addition operands have different types at line %d ('%s' vs '%s')\n", line_number, (yyvsp[-2].expr_attr).type, (yyvsp[0].expr_attr).type);
        }
        (yyval.expr_attr).type = (yyvsp[-2].expr_attr).type;
        (yyval.expr_attr).is_pointer = (yyvsp[-2].expr_attr).is_pointer;
        (yyval.expr_attr).is_array = (yyvsp[-2].expr_attr).is_array;
    }
#line 1525 "y.tab.c"
    break;

  case 46: /* additive_expression: additive_expression MINUS term  */
#line 244 "symbol_table.y"
                                     {
        if (strcmp((yyvsp[-2].expr_attr).type, (yyvsp[0].expr_attr).type) != 0) {
            printf("Type Error: Subtraction operands have different types at line %d ('%s' vs '%s')\n", line_number, (yyvsp[-2].expr_attr).type, (yyvsp[0].expr_attr).type);
        }
        (yyval.expr_attr).type = (yyvsp[-2].expr_attr).type;
        (yyval.expr_attr).is_pointer = (yyvsp[-2].expr_attr).is_pointer;
        (yyval.expr_attr).is_array = (yyvsp[-2].expr_attr).is_array;
    }
#line 1538 "y.tab.c"
    break;

  case 47: /* term: factor  */
#line 255 "symbol_table.y"
           { (yyval.expr_attr).type = (yyvsp[0].expr_attr).type; (yyval.expr_attr).is_pointer = (yyvsp[0].expr_attr).is_pointer; (yyval.expr_attr).is_array = (yyvsp[0].expr_attr).is_array; }
#line 1544 "y.tab.c"
    break;

  case 48: /* term: term MULTIPLY factor  */
#line 256 "symbol_table.y"
                           {
        if (strcmp((yyvsp[-2].expr_attr).type, (yyvsp[0].expr_attr).type) != 0) {
            printf("Type Error: Multiplication operands have different types at line %d ('%s' vs '%s')\n", line_number, (yyvsp[-2].expr_attr).type, (yyvsp[0].expr_attr).type);
        }
        (yyval.expr_attr).type = (yyvsp[-2].expr_attr).type;
        (yyval.expr_attr).is_pointer = (yyvsp[-2].expr_attr).is_pointer;
        (yyval.expr_attr).is_array = (yyvsp[-2].expr_attr).is_array;
    }
#line 1557 "y.tab.c"
    break;

  case 49: /* term: term DIVIDE factor  */
#line 264 "symbol_table.y"
                         {
        if (strcmp((yyvsp[-2].expr_attr).type, (yyvsp[0].expr_attr).type) != 0) {
            printf("Type Error: Division operands have different types at line %d ('%s' vs '%s')\n", line_number, (yyvsp[-2].expr_attr).type, (yyvsp[0].expr_attr).type);
        }
        (yyval.expr_attr).type = (yyvsp[-2].expr_attr).type;
        (yyval.expr_attr).is_pointer = (yyvsp[-2].expr_attr).is_pointer;
        (yyval.expr_attr).is_array = (yyvsp[-2].expr_attr).is_array;
    }
#line 1570 "y.tab.c"
    break;

  case 50: /* factor: IDENTIFIER  */
#line 275 "symbol_table.y"
               {
        if (lookup_symbol_all_scopes((yyvsp[0].string)) == 0) {
            printf("Error: Variable '%s' used before declaration at line %d\n", (yyvsp[0].string), line_number);
            (yyval.expr_attr).type = strdup("error");
            (yyval.expr_attr).is_pointer = 0;
            (yyval.expr_attr).is_array = 0;
        } else {
            SymbolTable *temp = symbol_table_head;
            char *id_type = NULL;
            int is_pointer = 0, is_array = 0;
            while (temp != NULL) {
                if (strcmp(temp->name, (yyvsp[0].string)) == 0) {
                    id_type = temp->datatype;
                    if (strchr(id_type, '*')) is_pointer = 1;
                    if (strchr(id_type, '[')) is_array = 1;
                    break;
                }
                temp = temp->next;
            }
            (yyval.expr_attr).type = id_type ? strdup(id_type) : strdup("error");
            (yyval.expr_attr).is_pointer = is_pointer;
            (yyval.expr_attr).is_array = is_array;
        }
    }
#line 1599 "y.tab.c"
    break;

  case 51: /* factor: NUMBER  */
#line 299 "symbol_table.y"
             { (yyval.expr_attr).type = strdup("int"); (yyval.expr_attr).is_pointer = 0; (yyval.expr_attr).is_array = 0; }
#line 1605 "y.tab.c"
    break;

  case 52: /* factor: LPAREN expression RPAREN  */
#line 300 "symbol_table.y"
                               { (yyval.expr_attr).type = (yyvsp[-1].expr_attr).type; (yyval.expr_attr).is_pointer = (yyvsp[-1].expr_attr).is_pointer; (yyval.expr_attr).is_array = (yyvsp[-1].expr_attr).is_array; }
#line 1611 "y.tab.c"
    break;

  case 53: /* selection_statement: IF LPAREN expression RPAREN statement  */
#line 304 "symbol_table.y"
                                          {
        if (strcmp((yyvsp[-2].expr_attr).type, "int") != 0) {
            printf("Type Error: Condition in IF must be int at line %d, got '%s'\n", line_number, (yyvsp[-2].expr_attr).type);
        }
    }
#line 1621 "y.tab.c"
    break;

  case 54: /* selection_statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 309 "symbol_table.y"
                                                           {
        if (strcmp((yyvsp[-4].expr_attr).type, "int") != 0) {
            printf("Type Error: Condition in IF-ELSE must be int at line %d, got '%s'\n", line_number, (yyvsp[-4].expr_attr).type);
        }
    }
#line 1631 "y.tab.c"
    break;

  case 55: /* iteration_statement: WHILE LPAREN expression RPAREN statement  */
#line 317 "symbol_table.y"
                                             {
        if (strcmp((yyvsp[-2].expr_attr).type, "int") != 0) {
            printf("Type Error: Condition in WHILE must be int at line %d, got '%s'\n", line_number, (yyvsp[-2].expr_attr).type);
        }
    }
#line 1641 "y.tab.c"
    break;

  case 56: /* iteration_statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement  */
#line 322 "symbol_table.y"
                                                                                       {
        if (strcmp((yyvsp[-2].expr_attr).type, "int") != 0) {
            printf("Type Error: Condition in FOR must be int at line %d, got '%s'\n", line_number, (yyvsp[-2].expr_attr).type);
        }
    }
#line 1651 "y.tab.c"
    break;


#line 1655 "y.tab.c"

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

#line 334 "symbol_table.y"


/* Symbol Table Functions */

void insert_symbol(char *name, char *datatype, int scope, int line) {
    SymbolTable *new_entry = (SymbolTable *)malloc(sizeof(SymbolTable));
    strcpy(new_entry->name, name);
    strcpy(new_entry->datatype, datatype);
    new_entry->scope = scope;
    new_entry->line_no = line;
    new_entry->next = symbol_table_head;
    symbol_table_head = new_entry;
}

int lookup_symbol(char *name, int scope) {
    SymbolTable *temp = symbol_table_head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0 && temp->scope == scope) {
            return 1; // Found in current scope
        }
        temp = temp->next;
    }
    return 0; // Not found in current scope
}

int lookup_symbol_all_scopes(char *name) {
    SymbolTable *temp = symbol_table_head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            return 1; // Found in some scope
        }
        temp = temp->next;
    }
    return 0; // Not found at all
}

void display_symbol_table() {
    SymbolTable *temp = symbol_table_head;
    printf("\n%-5s %-20s %-15s %-10s %-10s\n", 
           "SL No", "Name", "Data Type", "Scope", "Line No");
    printf("-----------------------------------------------------------\n");
    
    int count = 1;
    while (temp != NULL) {
        printf("%-5d %-20s %-15s %-10d %-10d\n", 
               count++, temp->name, temp->datatype, temp->scope, temp->line_no);
        temp = temp->next;
    }
    printf("-----------------------------------------------------------\n");
}

void enter_scope() {
    current_scope++;
    printf("Entering scope: %d\n", current_scope);
}

void exit_scope() {
    printf("Exiting scope: %d\n", current_scope);
    remove_scope(current_scope);
    current_scope--;
}

void remove_scope(int scope) {
    SymbolTable *temp = symbol_table_head;
    SymbolTable *prev = NULL;
    
    while (temp != NULL) {
        if (temp->scope == scope) {
            if (prev == NULL) {
                symbol_table_head = temp->next;
                free(temp);
                temp = symbol_table_head;
            } else {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", line_number, s);
}

int main() {
    printf("Enter your code (Ctrl+D to end):\n");
    yyparse();
    return 0;
}
