%{
#include<stdio.h>
%}
%token NL DIGIT LETTER

%%
stm: variable NL {printf("Valid Identifer\n");}
variable: LETTER alphanumeric | LETTER
alphanumeric: LETTER alphanumeric | DIGIT alphanumeric | DIGIT | LETTER
;
%%

int yyerror(){
	printf("Invalid Identifier\n");
	return 0;
}

int main(){
	printf("Enter the Identifier: ");
	yyparse();
	return 0;
} 

