/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 13 "src/main.y" /* yacc.c:1909  */

  string *value;
  Symbol *symbol;
  TreeNode *node;

#line 188 "src/main.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_MAIN_TAB_H_INCLUDED  */
