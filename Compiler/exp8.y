%{
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define YYSTYPE double
%}
%token NUM
%left '+' '-'
%left '*' '/'
%left '(' ')'
%right UMINUS

%%
stm: E {printf("\nResult=%g\n",$$);}
E:        E '+' E { $$=$1+$3; } 
	| E '*' E { $$=$1*$3; }
	| E '-' E { $$=$1-$3; }
	| E '/' E { $$=$1/$3; }
	| '-' E %prec UMINUS { $$=-$2;}
	| '(' E ')' { $$=$2; }
	| NUM { $$=$1;}
;
%%
int main(){
	printf("Enter the expression:\n");
	yyparse();
	return 0;
}

int yyerror(){
	printf("Invalid Expression\n");
	return 0;
}

