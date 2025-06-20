/**
 * @file   db.l
 * @author Wei-Ning Huang (AZ) <aitjcize@gmail.com>
 *
 * Copyright (C) 2012 - 2014 Wei-Ning Huang (AZ) <aitjcize@gmail.com>
 * All Rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

delim       [ \t]
nl          [\n\r]
ws          {delim}+
pletter     [A-Za-z0-9_.\-+/&"':;]
mletter     [A-Za-z0-9_.\-+/&"':; ]
var         {pletter}{mletter}*{pletter}

%option noyywrap
%option yylineno

%{

#ifdef _MSC_VER
#include <io.h>
#define YY_NO_UNISTD_H
#define strdup _strdup
#define isatty _isatty
#endif

#include "yyheader.h"
#include "yyheader.h"

#include <stdio.h>
#include <string.h>
#include "db.tab.h"

extern YYSTYPE yylval;

%}

%%

"{"        { return *yytext; }
"}"        { return *yytext; }
"="        { return *yytext; }
{pletter}  { yylval = strdup(yytext); return VAR; }
{var}      { yylval = strdup(yytext); return VAR; }
{nl}       { return NL; }
{ws}       { }

%%
