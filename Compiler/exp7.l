%option noyywrap
%{
#include "y.tab.h"
%}

%%
[_a-zA-Z]	return LETTER;
\n	return NL;
[0-9]	return DIGIT;
.	return yytext[0];
%%

