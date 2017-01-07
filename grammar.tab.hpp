/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PROGRAM = 258,
     IDENTIFIER = 259,
     SEMICOLON = 260,
     DOT = 261,
     CONSTANTS = 262,
     EQUALS = 263,
     NUMBER = 264,
     TYPES = 265,
     INTEGER = 266,
     ARRAY = 267,
     SQBR_ON = 268,
     SQBR_OFF = 269,
     OF = 270,
     RECORD = 271,
     END = 272,
     COLON = 273,
     COMMA = 274,
     VAR = 275,
     FORWARD = 276,
     PROCEDURE = 277,
     FUNCTION = 278,
     PAR_ON = 279,
     PAR_OFF = 280,
     CURLY_ON = 281,
     CURLY_OFF = 282,
     PRINT = 283,
     READ = 284,
     WHILE = 285,
     DO = 286,
     IF = 287,
     THEN = 288,
     ELSE = 289,
     EQ = 290,
     NEQ = 291,
     LT = 292,
     GT = 293,
     LEQ = 294,
     GEQ = 295,
     FOR = 296,
     COLON_EQ = 297,
     UPTO = 298,
     DOWNTO = 299,
     PLUS = 300,
     MINUS = 301,
     MULT = 302,
     DIV = 303,
     MOD = 304
   };
#endif
/* Tokens.  */
#define PROGRAM 258
#define IDENTIFIER 259
#define SEMICOLON 260
#define DOT 261
#define CONSTANTS 262
#define EQUALS 263
#define NUMBER 264
#define TYPES 265
#define INTEGER 266
#define ARRAY 267
#define SQBR_ON 268
#define SQBR_OFF 269
#define OF 270
#define RECORD 271
#define END 272
#define COLON 273
#define COMMA 274
#define VAR 275
#define FORWARD 276
#define PROCEDURE 277
#define FUNCTION 278
#define PAR_ON 279
#define PAR_OFF 280
#define CURLY_ON 281
#define CURLY_OFF 282
#define PRINT 283
#define READ 284
#define WHILE 285
#define DO 286
#define IF 287
#define THEN 288
#define ELSE 289
#define EQ 290
#define NEQ 291
#define LT 292
#define GT 293
#define LEQ 294
#define GEQ 295
#define FOR 296
#define COLON_EQ 297
#define UPTO 298
#define DOWNTO 299
#define PLUS 300
#define MINUS 301
#define MULT 302
#define DIV 303
#define MOD 304




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

