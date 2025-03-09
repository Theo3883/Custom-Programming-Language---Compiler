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
#line 12 "limbaj.y"

#include "SymTable.h"
#include "AST.h"
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();
void yyerror(const char * s);
class SymTable* current;
int errorCount = 0;

// Enhanced error reporting function
void reportTypeError(const string& msg, const string& var) {
    errorCount++;
    cerr << "Type Error at line " << yylineno << ": " << msg << " '" << var << "'" << endl;
}

// Enhanced type checking for expressions
string getResultType(const string& left, const string& op, const string& right) {
    if (left != right) {
        reportTypeError("Type mismatch in operation: cannot mix types", left + " " + op + " " + right);
        return "error";
    }
    
    if (left == "int" && right == "int") {
        if (op == "+" || op == "-" || op == "*" || op == "/") return "int";
    }
    else if (left == "string" && right == "string" && op == "+") return "string"; 
    else if (left == "bool" && right == "bool" && (op == "&&" || op == "||")) return "bool";
    
    reportTypeError("Invalid operation between types", left + " " + op + " " + right);
    return "error";
}

string makeArrayType(const string& baseType, int dimensions) {
    string type = baseType;
    for(int i = 0; i < dimensions; i++) type += "[]";
    return type;
}

void enterScope(const string& name, ScopeType type);
void exitScope();

#line 115 "limbaj.tab.c"

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

#include "limbaj.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_BGIN = 3,                       /* BGIN  */
  YYSYMBOL_END = 4,                        /* END  */
  YYSYMBOL_ASSIGN = 5,                     /* ASSIGN  */
  YYSYMBOL_ID = 6,                         /* ID  */
  YYSYMBOL_TYPE = 7,                       /* TYPE  */
  YYSYMBOL_STRING_LITERAL = 8,             /* STRING_LITERAL  */
  YYSYMBOL_BOOL_LITERAL = 9,               /* BOOL_LITERAL  */
  YYSYMBOL_CLASS = 10,                     /* CLASS  */
  YYSYMBOL_NEW = 11,                       /* NEW  */
  YYSYMBOL_NR = 12,                        /* NR  */
  YYSYMBOL_FUNCTION = 13,                  /* FUNCTION  */
  YYSYMBOL_RETURN = 14,                    /* RETURN  */
  YYSYMBOL_IF = 15,                        /* IF  */
  YYSYMBOL_ELSE = 16,                      /* ELSE  */
  YYSYMBOL_WHILE = 17,                     /* WHILE  */
  YYSYMBOL_FOR = 18,                       /* FOR  */
  YYSYMBOL_EQ = 19,                        /* EQ  */
  YYSYMBOL_NEQ = 20,                       /* NEQ  */
  YYSYMBOL_LT = 21,                        /* LT  */
  YYSYMBOL_GT = 22,                        /* GT  */
  YYSYMBOL_LE = 23,                        /* LE  */
  YYSYMBOL_GE = 24,                        /* GE  */
  YYSYMBOL_Print = 25,                     /* Print  */
  YYSYMBOL_TypeOf = 26,                    /* TypeOf  */
  YYSYMBOL_THEN = 27,                      /* THEN  */
  YYSYMBOL_28_ = 28,                       /* '+'  */
  YYSYMBOL_29_ = 29,                       /* '-'  */
  YYSYMBOL_30_ = 30,                       /* '*'  */
  YYSYMBOL_31_ = 31,                       /* '/'  */
  YYSYMBOL_32_ = 32,                       /* '.'  */
  YYSYMBOL_33_ = 33,                       /* '['  */
  YYSYMBOL_34_ = 34,                       /* ']'  */
  YYSYMBOL_UMINUS = 35,                    /* UMINUS  */
  YYSYMBOL_36_ = 36,                       /* ';'  */
  YYSYMBOL_37_ = 37,                       /* '{'  */
  YYSYMBOL_38_ = 38,                       /* '}'  */
  YYSYMBOL_39_ = 39,                       /* '('  */
  YYSYMBOL_40_ = 40,                       /* ')'  */
  YYSYMBOL_41_ = 41,                       /* ':'  */
  YYSYMBOL_42_ = 42,                       /* ','  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_program = 44,                   /* program  */
  YYSYMBOL_declarations = 45,              /* declarations  */
  YYSYMBOL_decl = 46,                      /* decl  */
  YYSYMBOL_class_decl = 47,                /* class_decl  */
  YYSYMBOL_function_decl = 48,             /* function_decl  */
  YYSYMBOL_function_params = 49,           /* function_params  */
  YYSYMBOL_function_block = 50,            /* function_block  */
  YYSYMBOL_51_1 = 51,                      /* $@1  */
  YYSYMBOL_simple_block = 52,              /* simple_block  */
  YYSYMBOL_53_2 = 53,                      /* $@2  */
  YYSYMBOL_class_body = 54,                /* class_body  */
  YYSYMBOL_member_decl = 55,               /* member_decl  */
  YYSYMBOL_array_dims = 56,                /* array_dims  */
  YYSYMBOL_main = 57,                      /* main  */
  YYSYMBOL_statements = 58,                /* statements  */
  YYSYMBOL_statement = 59,                 /* statement  */
  YYSYMBOL_assignment = 60,                /* assignment  */
  YYSYMBOL_lvalue = 61,                    /* lvalue  */
  YYSYMBOL_array_access = 62,              /* array_access  */
  YYSYMBOL_field_access = 63,              /* field_access  */
  YYSYMBOL_control_stmt = 64,              /* control_stmt  */
  YYSYMBOL_if_stmt = 65,                   /* if_stmt  */
  YYSYMBOL_if_then = 66,                   /* if_then  */
  YYSYMBOL_if_then_else = 67,              /* if_then_else  */
  YYSYMBOL_while_stmt = 68,                /* while_stmt  */
  YYSYMBOL_69_3 = 69,                      /* $@3  */
  YYSYMBOL_for_stmt = 70,                  /* for_stmt  */
  YYSYMBOL_71_4 = 71,                      /* $@4  */
  YYSYMBOL_condition = 72,                 /* condition  */
  YYSYMBOL_print_stmt = 73,                /* print_stmt  */
  YYSYMBOL_type_stmt = 74,                 /* type_stmt  */
  YYSYMBOL_rel_op = 75,                    /* rel_op  */
  YYSYMBOL_expr_list = 76,                 /* expr_list  */
  YYSYMBOL_expr = 77,                      /* expr  */
  YYSYMBOL_term = 78,                      /* term  */
  YYSYMBOL_factor = 79,                    /* factor  */
  YYSYMBOL_function_call = 80              /* function_call  */
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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   187

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  163

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


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
      39,    40,    30,    28,    42,    29,    32,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    41,    36,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    33,     2,    34,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
      25,    26,    27,    35
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   107,   107,   110,   111,   114,   121,   128,   141,   142,
     145,   159,   182,   197,   202,   208,   208,   224,   224,   242,
     246,   252,   256,   263,   266,   272,   275,   276,   279,   280,
     281,   282,   283,   286,   304,   312,   313,   316,   327,   334,
     356,   357,   358,   361,   362,   365,   370,   376,   375,   387,
     386,   396,   431,   442,   451,   452,   453,   454,   455,   456,
     459,   463,   469,   475,   481,   484,   490,   496,   499,   509,
     510,   511,   512,   513,   514,   515,   516,   527
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
  "\"end of file\"", "error", "\"invalid token\"", "BGIN", "END",
  "ASSIGN", "ID", "TYPE", "STRING_LITERAL", "BOOL_LITERAL", "CLASS", "NEW",
  "NR", "FUNCTION", "RETURN", "IF", "ELSE", "WHILE", "FOR", "EQ", "NEQ",
  "LT", "GT", "LE", "GE", "Print", "TypeOf", "THEN", "'+'", "'-'", "'*'",
  "'/'", "'.'", "'['", "']'", "UMINUS", "';'", "'{'", "'}'", "'('", "')'",
  "':'", "','", "$accept", "program", "declarations", "decl", "class_decl",
  "function_decl", "function_params", "function_block", "$@1",
  "simple_block", "$@2", "class_body", "member_decl", "array_dims", "main",
  "statements", "statement", "assignment", "lvalue", "array_access",
  "field_access", "control_stmt", "if_stmt", "if_then", "if_then_else",
  "while_stmt", "$@3", "for_stmt", "$@4", "condition", "print_stmt",
  "type_stmt", "rel_op", "expr_list", "expr", "term", "factor",
  "function_call", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-127)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     105,    -1,    12,    15,    20,    41,   114,  -127,  -127,  -127,
      -4,    29,     6,    10,  -127,    77,  -127,  -127,  -127,    51,
    -127,    40,    47,     5,    -5,    71,    94,   102,   108,   112,
      49,    60,  -127,   111,  -127,   125,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,  -127,   126,   147,  -127,   155,     4,
    -127,   156,   122,    42,   158,    -2,    -2,    -2,    -2,   159,
      -2,    -2,  -127,   130,  -127,    -2,    -2,  -127,   133,    64,
    -127,  -127,  -127,   161,   128,   163,  -127,    -5,  -127,  -127,
     165,  -127,    -2,  -127,   125,    97,   -17,  -127,  -127,    59,
      57,   132,    85,   134,   117,   137,     7,    28,  -127,    57,
     100,  -127,  -127,   106,   138,   169,   171,  -127,    32,    -2,
      -2,  -127,    -2,    -2,  -127,    -2,   141,  -127,  -127,  -127,
    -127,  -127,  -127,    -2,  -127,    -2,  -127,  -127,  -127,  -127,
    -127,  -127,   138,  -127,  -127,   -17,   -17,  -127,  -127,    57,
    -127,   164,    57,   141,   143,    77,  -127,    77,   141,  -127,
     159,    63,    33,  -127,   142,    -2,  -127,  -127,    62,   141,
     145,  -127,  -127
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     3,     8,     9,
       0,     0,     0,     0,     1,     0,     4,     2,     7,     0,
       5,     0,     0,     0,    34,     0,     0,     0,     0,     0,
       0,     0,    28,     0,    35,    36,    29,    40,    43,    44,
      41,    42,    30,    31,    32,     0,     0,     6,     0,     0,
      19,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    25,     0,    26,     0,     0,    23,     0,     0,
      10,    20,    13,     0,     0,     0,    39,    68,    70,    71,
       0,    69,     0,    72,    73,     0,    64,    67,    75,     0,
      60,     0,     0,     0,    34,     0,     0,     0,    27,    33,
       0,    24,    21,     0,     0,     0,     0,    76,     0,     0,
       0,    37,     0,     0,    77,     0,     0,    54,    55,    56,
      57,    58,    59,     0,    47,     0,    52,    53,    38,    22,
      15,    12,     0,    14,    74,    62,    63,    65,    66,    61,
      17,    45,    51,     0,     0,     0,    11,     0,     0,    48,
       0,     0,     0,    46,     0,     0,    18,    49,     0,     0,
       0,    50,    16
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -127,  -127,  -127,   175,  -127,  -127,  -127,    52,  -127,  -126,
    -127,  -127,   136,   118,  -127,  -107,   -29,   -57,  -127,   -15,
      -7,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,   -55,
    -127,  -127,  -127,  -127,   -36,    45,    44,     1
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,     8,     9,    53,   131,   145,   141,
     147,    49,    50,    21,    17,    30,    31,    32,    33,    83,
      84,    36,    37,    38,    39,    40,   143,    41,   159,    91,
      42,    43,   123,    89,    92,    86,    87,    88
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      34,    63,    95,    93,    77,    10,    78,    79,    35,    80,
      81,    48,    51,   112,   113,    34,    44,   149,    11,    85,
      90,    12,   153,    35,    96,    97,    13,    54,    55,    99,
     100,    44,    18,   161,    56,   109,   110,    82,   151,    24,
     152,    14,    70,    22,    34,    52,   108,   126,    25,    23,
      26,    27,    35,    62,    48,    24,   109,   110,    28,    29,
     109,   110,    19,    45,    25,    20,    26,    27,   127,    24,
     144,   156,   134,    46,    28,    29,    47,   155,    25,   139,
      26,    27,    74,    24,    75,   109,   110,   142,    28,    29,
     109,   110,    25,   154,    26,    27,    64,    19,   160,   114,
     102,   115,    28,    29,   117,   118,   119,   120,   121,   122,
      57,     1,     2,   109,   110,     3,    65,    15,     4,   158,
       1,     2,    63,    63,     3,   109,   110,     4,   109,   110,
      34,   111,    34,    58,   128,    34,    34,    34,    35,    46,
      35,    59,   129,    35,    35,    35,    44,    60,    44,    54,
      55,    61,    44,    44,   135,   136,   137,   138,    66,    68,
      67,    69,    72,    73,    76,    94,    98,   101,   104,   105,
     106,   107,   116,   125,   124,   130,   132,   133,   140,   150,
     148,    16,   157,   162,   146,    71,     0,   103
};

static const yytype_int16 yycheck[] =
{
      15,    30,    59,    58,     6,     6,     8,     9,    15,    11,
      12,     7,     7,    30,    31,    30,    15,   143,     6,    55,
      56,     6,   148,    30,    60,    61,     6,    32,    33,    65,
      66,    30,    36,   159,    39,    28,    29,    39,   145,     6,
     147,     0,    38,    37,    59,    40,    82,    40,    15,    39,
      17,    18,    59,     4,     7,     6,    28,    29,    25,    26,
      28,    29,    33,    12,    15,    36,    17,    18,    40,     6,
     125,    38,    40,    33,    25,    26,    36,    14,    15,   115,
      17,    18,    40,     6,    42,    28,    29,   123,    25,    26,
      28,    29,    15,   150,    17,    18,    36,    33,    36,    40,
      36,    42,    25,    26,    19,    20,    21,    22,    23,    24,
      39,     6,     7,    28,    29,    10,     5,     3,    13,   155,
       6,     7,   151,   152,    10,    28,    29,    13,    28,    29,
     145,    34,   147,    39,    34,   150,   151,   152,   145,    33,
     147,    39,    36,   150,   151,   152,   145,    39,   147,    32,
      33,    39,   151,   152,   109,   110,   112,   113,    33,    12,
      34,     6,     6,    41,     6,     6,    36,    34,     7,    41,
       7,     6,    40,    36,    40,    37,     7,     6,    37,    36,
      16,     6,    40,    38,   132,    49,    -1,    69
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,    10,    13,    44,    45,    46,    47,    48,
       6,     6,     6,     6,     0,     3,    46,    57,    36,    33,
      36,    56,    37,    39,     6,    15,    17,    18,    25,    26,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    70,    73,    74,    80,    12,    33,    36,     7,    54,
      55,     7,    40,    49,    32,    33,    39,    39,    39,    39,
      39,    39,     4,    59,    36,     5,    33,    34,    12,     6,
      38,    55,     6,    41,    40,    42,     6,     6,     8,     9,
      11,    12,    39,    62,    63,    77,    78,    79,    80,    76,
      77,    72,    77,    72,     6,    60,    77,    77,    36,    77,
      77,    34,    36,    56,     7,    41,     7,     6,    77,    28,
      29,    34,    30,    31,    40,    42,    40,    19,    20,    21,
      22,    23,    24,    75,    40,    36,    40,    40,    34,    36,
      37,    50,     7,     6,    40,    78,    78,    79,    79,    77,
      37,    52,    77,    69,    72,    51,    50,    53,    16,    52,
      36,    58,    58,    52,    60,    14,    38,    40,    77,    71,
      36,    52,    38
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    46,    46,    46,
      47,    48,    48,    49,    49,    51,    50,    53,    52,    54,
      54,    55,    55,    56,    56,    57,    58,    58,    59,    59,
      59,    59,    59,    60,    61,    61,    61,    62,    62,    63,
      64,    64,    64,    65,    65,    66,    67,    69,    68,    71,
      70,    72,    73,    74,    75,    75,    75,    75,    75,    75,
      76,    76,    77,    77,    77,    78,    78,    78,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    80
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     2,     3,     4,     3,     1,     1,
       5,     8,     7,     2,     4,     0,     7,     0,     4,     1,
       2,     3,     4,     3,     4,     3,     2,     3,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     4,     4,     3,
       1,     1,     1,     1,     1,     5,     7,     0,     6,     0,
      10,     3,     4,     4,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     2,     4
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
  case 2: /* program: declarations main  */
#line 107 "limbaj.y"
                           { if (errorCount == 0) cout << "The program is correct!" << endl; }
#line 1293 "limbaj.tab.c"
    break;

  case 5: /* decl: TYPE ID ';'  */
#line 114 "limbaj.y"
                  {
    if(current->existsId((yyvsp[-1].string))) {
        reportTypeError("Variable already defined in current scope", (yyvsp[-1].string));
    } else {
        current->addVar((yyvsp[-2].string), (yyvsp[-1].string));
    }
}
#line 1305 "limbaj.tab.c"
    break;

  case 6: /* decl: TYPE ID array_dims ';'  */
#line 121 "limbaj.y"
                             {
        if(!current->existsId((yyvsp[-2].string))) {
            string arrayType = makeArrayType((yyvsp[-3].string), (yyvsp[-1].number));
            current->addVar(arrayType.c_str(), (yyvsp[-2].string));
        }
        else { errorCount++; yyerror("Array already defined"); }
    }
#line 1317 "limbaj.tab.c"
    break;

  case 7: /* decl: ID ID ';'  */
#line 128 "limbaj.y"
                {  
        if(!current->existsClass((yyvsp[-2].string))) {
            errorCount++; 
            yyerror("Class type not defined");
        }
        else if(!current->existsId((yyvsp[-1].string))) {
            current->addVar((yyvsp[-2].string), (yyvsp[-1].string));
        }
        else {
            errorCount++;
            yyerror("Variable already defined");
        }
    }
#line 1335 "limbaj.tab.c"
    break;

  case 10: /* class_decl: CLASS ID '{' class_body '}'  */
#line 145 "limbaj.y"
                                        {
        if(!current->existsClass((yyvsp[-3].string))) {
            // First add the class definition
            current->addClass((yyvsp[-3].string), *(yyvsp[-1].classInfo));
            // Then enter scope, process members, and exit
            enterScope((yyvsp[-3].string), ScopeType::CLASS);
            exitScope();
        } else {
            errorCount++;
            yyerror("Class already defined");
        }
    }
#line 1352 "limbaj.tab.c"
    break;

  case 11: /* function_decl: FUNCTION ID '(' function_params ')' ':' TYPE function_block  */
#line 159 "limbaj.y"
                                                                           {
        FunctionInfo func;
        func.name = (yyvsp[-6].string);
        func.returnType = (yyvsp[-1].string);
        

        for(int i = (yyvsp[-4].vector)->size()-2; i >= 0; i-=2) {
            func.params.push_back((yyvsp[-4].vector)->at(i)); 
        }
        
        if(!current->existsFunction((yyvsp[-6].string))) {
            current->addFunction((yyvsp[-6].string), func); // Add function first
            enterScope((yyvsp[-6].string), ScopeType::FUNCTION);
            // Add parameters to function scope
            for(int i = (yyvsp[-4].vector)->size()-2; i >= 0; i-=2) {
                current->addVar((yyvsp[-4].vector)->at(i), (yyvsp[-4].vector)->at(i+1)); // type, name
            }
            exitScope();
        } else {
            errorCount++;
            yyerror("Function already defined");
        }
    }
#line 1380 "limbaj.tab.c"
    break;

  case 12: /* function_decl: FUNCTION ID '(' ')' ':' TYPE function_block  */
#line 182 "limbaj.y"
                                                  {
        FunctionInfo func;
        func.name = (yyvsp[-5].string);
        func.returnType = (yyvsp[-1].string);
        if(!current->existsFunction((yyvsp[-5].string))) {
            enterScope((yyvsp[-5].string), ScopeType::FUNCTION);
            current->addFunction((yyvsp[-5].string), func);
            exitScope();
        } else {
            errorCount++;
            yyerror("Function already defined");
        }
    }
#line 1398 "limbaj.tab.c"
    break;

  case 13: /* function_params: TYPE ID  */
#line 197 "limbaj.y"
                         {
        (yyval.vector) = new vector<string>();
        (yyval.vector)->push_back((yyvsp[-1].string)); // type
        (yyval.vector)->push_back((yyvsp[0].string)); // name
    }
#line 1408 "limbaj.tab.c"
    break;

  case 14: /* function_params: function_params ',' TYPE ID  */
#line 202 "limbaj.y"
                                  {
        (yyval.vector) = (yyvsp[-3].vector);
        (yyval.vector)->push_back((yyvsp[-1].string)); // type
        (yyval.vector)->push_back((yyvsp[0].string)); // name
    }
#line 1418 "limbaj.tab.c"
    break;

  case 15: /* $@1: %empty  */
#line 208 "limbaj.y"
                    {
        enterScope("block", ScopeType::BLOCK);
        // Copy parent scope variables 
        SymTable* parent = current->getParent();
        while(parent) {
            auto vars = parent->getVariables();
            for(const auto& var : vars) {
                if(!current->existsId(var.first)) {
                    current->addVar(var.second.type, var.first);
                }
            }
            parent = parent->getParent();
        }
    }
#line 1437 "limbaj.tab.c"
    break;

  case 16: /* function_block: '{' $@1 statements RETURN expr ';' '}'  */
#line 221 "limbaj.y"
                                     {
        exitScope();
    }
#line 1445 "limbaj.tab.c"
    break;

  case 17: /* $@2: %empty  */
#line 224 "limbaj.y"
                  {
        enterScope("block", ScopeType::BLOCK);
        // Copy all variables from parent scopes up to global
        SymTable* parent = current->getParent();
        while(parent) {
            auto vars = parent->getVariables();
            for(const auto& var : vars) {
                if(!current->existsId(var.first)) {
                    current->addVar(var.second.type, var.first);
                }
            }
            parent = parent->getParent();
        }
    }
#line 1464 "limbaj.tab.c"
    break;

  case 18: /* simple_block: '{' $@2 statements '}'  */
#line 237 "limbaj.y"
                     {
        exitScope();
    }
#line 1472 "limbaj.tab.c"
    break;

  case 19: /* class_body: member_decl  */
#line 242 "limbaj.y"
                        { 
        (yyval.classInfo) = new ClassInfo(); 
        (yyval.classInfo)->addField((yyvsp[0].idInfo)->name, *(yyvsp[0].idInfo)); 
    }
#line 1481 "limbaj.tab.c"
    break;

  case 20: /* class_body: class_body member_decl  */
#line 246 "limbaj.y"
                             { 
        (yyval.classInfo) = (yyvsp[-1].classInfo); 
        (yyval.classInfo)->addField((yyvsp[0].idInfo)->name, *(yyvsp[0].idInfo)); 
    }
#line 1490 "limbaj.tab.c"
    break;

  case 21: /* member_decl: TYPE ID ';'  */
#line 252 "limbaj.y"
                         {
        (yyval.idInfo) = new IdInfo((yyvsp[-2].string));
        (yyval.idInfo)->name = (yyvsp[-1].string);
    }
#line 1499 "limbaj.tab.c"
    break;

  case 22: /* member_decl: TYPE ID array_dims ';'  */
#line 256 "limbaj.y"
                             {
        string arrayType = makeArrayType((yyvsp[-3].string), (yyvsp[-1].number));
        (yyval.idInfo) = new IdInfo(arrayType);
        (yyval.idInfo)->name = (yyvsp[-2].string);
    }
#line 1509 "limbaj.tab.c"
    break;

  case 23: /* array_dims: '[' NR ']'  */
#line 263 "limbaj.y"
                       { 
        (yyval.number) = 1; 
    }
#line 1517 "limbaj.tab.c"
    break;

  case 24: /* array_dims: array_dims '[' NR ']'  */
#line 266 "limbaj.y"
                            { 
        (yyval.number) = (yyvsp[-3].number) + 1;  // array dimensions
    }
#line 1525 "limbaj.tab.c"
    break;

  case 28: /* statement: assignment  */
#line 279 "limbaj.y"
                      { (yyval.string) = "assignment"; }
#line 1531 "limbaj.tab.c"
    break;

  case 29: /* statement: control_stmt  */
#line 280 "limbaj.y"
                   { (yyval.string) = (yyvsp[0].string); }
#line 1537 "limbaj.tab.c"
    break;

  case 30: /* statement: print_stmt  */
#line 281 "limbaj.y"
                 { (yyval.string) = "print"; }
#line 1543 "limbaj.tab.c"
    break;

  case 31: /* statement: type_stmt  */
#line 282 "limbaj.y"
                { (yyval.string) = "type"; }
#line 1549 "limbaj.tab.c"
    break;

  case 32: /* statement: function_call  */
#line 283 "limbaj.y"
                    { (yyval.string) = "function"; }
#line 1555 "limbaj.tab.c"
    break;

  case 33: /* assignment: lvalue ASSIGN expr  */
#line 286 "limbaj.y"
                               {
    std::string lhsType;
    if ((yyvsp[-2].exprValue)->isArray) {
        lhsType = (yyvsp[-2].exprValue)->type;
    } else {
        lhsType = (yyvsp[-2].exprValue)->type;
    }
    
    // Store the evaluated value in the symbol table
    if (current->existsId((yyvsp[-2].exprValue)->name)) {
        IdInfo& info = current->getVar((yyvsp[-2].exprValue)->name);
        info.value = (yyvsp[0].ast)->evaluate(current);  // Store the actual value
    }
    
    if ((yyvsp[0].ast)->getValueType() != "error" && lhsType != "error" && lhsType != (yyvsp[0].ast)->getValueType()) {
        reportTypeError("Type mismatch in assignment", (yyvsp[-2].exprValue)->name + " = " + (yyvsp[0].ast)->getName());
    }
}
#line 1578 "limbaj.tab.c"
    break;

  case 34: /* lvalue: ID  */
#line 304 "limbaj.y"
           { 
    if (current->existsId((yyvsp[0].string))) {
        IdInfo info = current->getVar((yyvsp[0].string));
        (yyval.exprValue) = new NameAndType((yyvsp[0].string), info.type); 
    } else {
        (yyval.exprValue) = new NameAndType("error", "error");
    }
}
#line 1591 "limbaj.tab.c"
    break;

  case 35: /* lvalue: array_access  */
#line 312 "limbaj.y"
                   { (yyval.exprValue) = (yyvsp[0].exprValue); }
#line 1597 "limbaj.tab.c"
    break;

  case 36: /* lvalue: field_access  */
#line 313 "limbaj.y"
                   { (yyval.exprValue) = (yyvsp[0].exprValue); }
#line 1603 "limbaj.tab.c"
    break;

  case 37: /* array_access: ID '[' expr ']'  */
#line 316 "limbaj.y"
                              {
    if (current->existsId((yyvsp[-3].string))) {
        IdInfo info = current->getVar((yyvsp[-3].string));
        string baseType = info.type;
        // Strip array brackets to get base type
        if (baseType.find("[]") != string::npos) {
            baseType = baseType.substr(0, baseType.find("[]"));
        }
        (yyval.exprValue) = new NameAndType((yyvsp[-3].string), baseType, true);  // true indicates array type
    }
}
#line 1619 "limbaj.tab.c"
    break;

  case 38: /* array_access: field_access '[' expr ']'  */
#line 327 "limbaj.y"
                            {
    string fieldType = (yyvsp[-3].exprValue)->type;
    if (fieldType.find("[]") != string::npos) {
        fieldType = fieldType.substr(0, fieldType.find("[]"));
    }
    (yyval.exprValue) = new NameAndType((yyvsp[-3].exprValue)->name, fieldType, true);
}
#line 1631 "limbaj.tab.c"
    break;

  case 39: /* field_access: ID '.' ID  */
#line 334 "limbaj.y"
                        {
    (yyval.exprValue) = new NameAndType();
    if (current->existsId((yyvsp[-2].string))) {
        IdInfo info = current->getVar((yyvsp[-2].string));
        if (current->existsClass(info.type)) {
            ClassInfo classInfo = current->getClass(info.type);
            if (!classInfo.existsField((yyvsp[0].string))) {
                errorCount++;
                yyerror("Field not found in class");
            } else {
                IdInfo fieldInfo = classInfo.getField((yyvsp[0].string));
                (yyval.exprValue) = new NameAndType((yyvsp[0].string), fieldInfo.type);
            }
        } else {
            errorCount++;
            yyerror("Not a class type");
        }
    } else {
        errorCount++;
        yyerror("Variable not declared");
    }
}
#line 1658 "limbaj.tab.c"
    break;

  case 40: /* control_stmt: if_stmt  */
#line 356 "limbaj.y"
                      { (yyval.string) = (yyvsp[0].string); }
#line 1664 "limbaj.tab.c"
    break;

  case 41: /* control_stmt: while_stmt  */
#line 357 "limbaj.y"
                 { (yyval.string) = (yyvsp[0].string); }
#line 1670 "limbaj.tab.c"
    break;

  case 42: /* control_stmt: for_stmt  */
#line 358 "limbaj.y"
               { (yyval.string) = (yyvsp[0].string); }
#line 1676 "limbaj.tab.c"
    break;

  case 43: /* if_stmt: if_then  */
#line 361 "limbaj.y"
                 { (yyval.string) = (yyvsp[0].string); }
#line 1682 "limbaj.tab.c"
    break;

  case 44: /* if_stmt: if_then_else  */
#line 362 "limbaj.y"
                   { (yyval.string) = (yyvsp[0].string); }
#line 1688 "limbaj.tab.c"
    break;

  case 45: /* if_then: IF '(' condition ')' simple_block  */
#line 365 "limbaj.y"
                                           {
        (yyval.string) = "if";
    }
#line 1696 "limbaj.tab.c"
    break;

  case 46: /* if_then_else: IF '(' condition ')' simple_block ELSE simple_block  */
#line 370 "limbaj.y"
                                                                  {
        (yyval.string) = "if-else"; 
    }
#line 1704 "limbaj.tab.c"
    break;

  case 47: /* $@3: %empty  */
#line 376 "limbaj.y"
    {
        enterScope("while", ScopeType::BLOCK);
    }
#line 1712 "limbaj.tab.c"
    break;

  case 48: /* while_stmt: WHILE '(' condition ')' $@3 simple_block  */
#line 380 "limbaj.y"
    {
        exitScope();
        //$$ = $7;  // Use simple_block's value
    }
#line 1721 "limbaj.tab.c"
    break;

  case 49: /* $@4: %empty  */
#line 387 "limbaj.y"
    {
        enterScope("for", ScopeType::BLOCK);
    }
#line 1729 "limbaj.tab.c"
    break;

  case 50: /* for_stmt: FOR '(' assignment ';' condition ';' assignment ')' $@4 simple_block  */
#line 391 "limbaj.y"
    {
        exitScope();
        //$$ = $11;  // Use simple_block's value
    }
#line 1738 "limbaj.tab.c"
    break;

  case 51: /* condition: expr rel_op expr  */
#line 396 "limbaj.y"
                            {
    // Check if expressions are valid
    if (!(yyvsp[-2].ast) || !(yyvsp[0].ast)) {
        errorCount++;
        yyerror("Invalid operands in condition");
        (yyval.ast) = new NameAndType("error", "error");
        YYERROR;
    }

    // Get the actual value types
    string leftType = (yyvsp[-2].ast)->getValueType();
    string rightType = (yyvsp[0].ast)->getValueType();
    string leftValue = (yyvsp[-2].ast)->evaluate(current);
    string rightValue = (yyvsp[0].ast)->evaluate(current);

    // Check type compatibility
    if (leftType != rightType) {
        string errorMsg = "Type mismatch in condition: cannot compare " + 
                         leftType + " with " + rightType;
        yyerror(errorMsg.c_str());
        (yyval.ast) = new NameAndType("error", "error");
        YYERROR;
    }

    // Create comparison operator node
    auto op = new OperatorNode((yyvsp[-1].string));
    op->left = std::shared_ptr<ASTNode>((yyvsp[-2].ast));
    op->right = std::shared_ptr<ASTNode>((yyvsp[0].ast));
    (yyval.ast) = op;

    // Store condition result
    current->addVar("bool", "_condition_result");
}
#line 1776 "limbaj.tab.c"
    break;

  case 52: /* print_stmt: Print '(' expr ')'  */
#line 431 "limbaj.y"
                               {
    try {
        std::string value = (yyvsp[-1].ast)->evaluate(current);
        std::string type = (yyvsp[-1].ast)->getValueType();
        std::cout << "Print: " << value << " (type: " << type << ")\n";
        delete (yyvsp[-1].ast);
    } catch(std::exception& e) {
        yyerror(e.what());
    }
}
#line 1791 "limbaj.tab.c"
    break;

  case 53: /* type_stmt: TypeOf '(' expr ')'  */
#line 442 "limbaj.y"
                               {
if ((yyvsp[-1].ast)->getValueType() != "error") {
    std::cout << "Type of " << (yyvsp[-1].ast)->getName() << " is " << (yyvsp[-1].ast)->getValueType() << '\n';
}
        (yyval.string) = "type";
    }
#line 1802 "limbaj.tab.c"
    break;

  case 54: /* rel_op: EQ  */
#line 451 "limbaj.y"
           { (yyval.string) = "=="; }
#line 1808 "limbaj.tab.c"
    break;

  case 55: /* rel_op: NEQ  */
#line 452 "limbaj.y"
          { (yyval.string) = "!="; }
#line 1814 "limbaj.tab.c"
    break;

  case 56: /* rel_op: LT  */
#line 453 "limbaj.y"
         { (yyval.string) = "<"; }
#line 1820 "limbaj.tab.c"
    break;

  case 57: /* rel_op: GT  */
#line 454 "limbaj.y"
         { (yyval.string) = ">"; }
#line 1826 "limbaj.tab.c"
    break;

  case 58: /* rel_op: LE  */
#line 455 "limbaj.y"
         { (yyval.string) = "<="; }
#line 1832 "limbaj.tab.c"
    break;

  case 59: /* rel_op: GE  */
#line 456 "limbaj.y"
         { (yyval.string) = ">="; }
#line 1838 "limbaj.tab.c"
    break;

  case 60: /* expr_list: expr  */
#line 459 "limbaj.y"
                { 
    (yyval.exprList) = new vector<NameAndType*>();
    (yyval.exprList)->push_back(dynamic_cast<NameAndType*>((yyvsp[0].ast)));  
}
#line 1847 "limbaj.tab.c"
    break;

  case 61: /* expr_list: expr_list ',' expr  */
#line 463 "limbaj.y"
                     {
    (yyval.exprList) = (yyvsp[-2].exprList);
    (yyval.exprList)->push_back(dynamic_cast<NameAndType*>((yyvsp[0].ast)));  
}
#line 1856 "limbaj.tab.c"
    break;

  case 62: /* expr: expr '+' term  */
#line 469 "limbaj.y"
                    { 
    auto op = new OperatorNode("+");
    op->left = std::shared_ptr<ASTNode>((yyvsp[-2].ast));
    op->right = std::shared_ptr<ASTNode>((yyvsp[0].ast));
    (yyval.ast) = op;
}
#line 1867 "limbaj.tab.c"
    break;

  case 63: /* expr: expr '-' term  */
#line 475 "limbaj.y"
                    {
        auto op = new OperatorNode("-");
        op->left = std::shared_ptr<ASTNode>((yyvsp[-2].ast));
        op->right = std::shared_ptr<ASTNode>((yyvsp[0].ast));
        (yyval.ast) = op;
    }
#line 1878 "limbaj.tab.c"
    break;

  case 64: /* expr: term  */
#line 481 "limbaj.y"
           { (yyval.ast) = (yyvsp[0].ast); }
#line 1884 "limbaj.tab.c"
    break;

  case 65: /* term: term '*' factor  */
#line 484 "limbaj.y"
                      {
        auto op = new OperatorNode("*");
        op->left = std::shared_ptr<ASTNode>((yyvsp[-2].ast));
        op->right = std::shared_ptr<ASTNode>((yyvsp[0].ast));
        (yyval.ast) = op;
    }
#line 1895 "limbaj.tab.c"
    break;

  case 66: /* term: term '/' factor  */
#line 490 "limbaj.y"
                      {
        auto op = new OperatorNode("/");
        op->left = std::shared_ptr<ASTNode>((yyvsp[-2].ast));
        op->right = std::shared_ptr<ASTNode>((yyvsp[0].ast));
        (yyval.ast) = op;
    }
#line 1906 "limbaj.tab.c"
    break;

  case 67: /* term: factor  */
#line 496 "limbaj.y"
             { (yyval.ast) = (yyvsp[0].ast); }
#line 1912 "limbaj.tab.c"
    break;

  case 68: /* factor: ID  */
#line 499 "limbaj.y"
           { 
    if (current->existsId((yyvsp[0].string))) {
        IdInfo info = current->getVar((yyvsp[0].string));
        (yyval.ast) = new NameAndType((yyvsp[0].string), info.type);
    } else {
        errorCount++;
        yyerror("Variable not declared");
        (yyval.ast) = new NameAndType("error", "error");
    }
}
#line 1927 "limbaj.tab.c"
    break;

  case 69: /* factor: NR  */
#line 509 "limbaj.y"
         { (yyval.ast) = new NameAndType(std::to_string((yyvsp[0].number)), "int"); }
#line 1933 "limbaj.tab.c"
    break;

  case 70: /* factor: STRING_LITERAL  */
#line 510 "limbaj.y"
                     { (yyval.ast) = new NameAndType((yyvsp[0].string), "string"); }
#line 1939 "limbaj.tab.c"
    break;

  case 71: /* factor: BOOL_LITERAL  */
#line 511 "limbaj.y"
                   { (yyval.ast) = new NameAndType((yyvsp[0].string), "bool"); }
#line 1945 "limbaj.tab.c"
    break;

  case 72: /* factor: array_access  */
#line 512 "limbaj.y"
                   { (yyval.ast) = (yyvsp[0].exprValue); }
#line 1951 "limbaj.tab.c"
    break;

  case 73: /* factor: field_access  */
#line 513 "limbaj.y"
                   { (yyval.ast) = (yyvsp[0].exprValue); }
#line 1957 "limbaj.tab.c"
    break;

  case 74: /* factor: '(' expr ')'  */
#line 514 "limbaj.y"
                   { (yyval.ast) = (yyvsp[-1].ast); }
#line 1963 "limbaj.tab.c"
    break;

  case 75: /* factor: function_call  */
#line 515 "limbaj.y"
                    { (yyval.ast) = new NameAndType("", "function"); }
#line 1969 "limbaj.tab.c"
    break;

  case 76: /* factor: NEW ID  */
#line 516 "limbaj.y"
             {  
        if(!current->existsClass((yyvsp[0].string))) {
            errorCount++;
            yyerror("Class not defined");
            (yyval.ast) = new NameAndType("error", "error");
        } else {
            (yyval.ast) = new NameAndType("new_" + std::string((yyvsp[0].string)), (yyvsp[0].string));
        }
    }
#line 1983 "limbaj.tab.c"
    break;

  case 77: /* function_call: ID '(' expr_list ')'  */
#line 527 "limbaj.y"
                                    {
    if (!current->existsFunction((yyvsp[-3].string))) {
        reportTypeError("Function not declared", (yyvsp[-3].string));
    } else {
        FunctionInfo func = current->getFunction((yyvsp[-3].string));
        if (func.params.size() != (yyvsp[-1].exprList)->size()) {
            reportTypeError("Wrong number of parameters in call to", (yyvsp[-3].string));
        } else {
            for(size_t i = 0; i < (yyvsp[-1].exprList)->size(); i++) {
                if((*(yyvsp[-1].exprList))[i]->type != func.params[i]) {
                    reportTypeError("Parameter type mismatch in function", 
                        string((yyvsp[-3].string)) + ": expected " + func.params[i] + 
                        ", got " + (*(yyvsp[-1].exprList))[i]->type);
                    break;
                }
            }
        }
    }
    (yyval.string) = "function"; 
    }
#line 2008 "limbaj.tab.c"
    break;


#line 2012 "limbaj.tab.c"

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

#line 549 "limbaj.y"


void yyerror(const char * s){
    cout << "error:" << s << " at line: " << yylineno << endl;
}

void enterScope(const string& name, ScopeType type) {
    current = current->createChildScope(name, type);
}

void exitScope() {
    if(current->getParent()) {
        current = current->getParent();
    }
}

int main(int argc, char** argv) {
    yyin = fopen(argv[1],"r");
    current = new SymTable("global", ScopeType::GLOBAL);
    yyparse();
    
    ofstream symFile("symbol_tables.txt");
    current->dumpToFile(symFile);
    symFile.close();
    
    delete current;
    return 0;
}
