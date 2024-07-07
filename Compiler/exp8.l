%option noyywrap
%{
#define YYSTYPE double
#include "y.tab.h"
#include <stdio.h>
%}
%%
([1-9][0-9]+|[0-9])?(\.[0-9]+)? { yylval= atof(yytext); return NUM;}
[\t] ;
\n return 0;
. return yytext[0];
%%

