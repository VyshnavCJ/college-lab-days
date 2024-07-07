preprocessor #.*
identifier [a-zA-Z_][_a-zA-Z0-9]*
keyword int|float|char|double|while\(.*\)|for\(.*\)|do|if\(.*\)|break|continue|switch\(.*\)|case|long|struct|const|typedef|return|else|goto
comment "/*"([^*]|(\*+[^*/]))*\*+\/|"//".*
asmnt_op "="|"+="|"-="|"/="|"*="
relop "=="|"!="|"<"|">"|"<="|">="
arith_op [+\-*/%]
integer [-+]?([0-9])+
string \".*\"
punct [;\.,]
%%
{string} {printf("\n String:\t%s ",yytext);}
{keyword} {printf("\n Keyword:\t%s ",yytext);}
{preprocessor} {printf("\n Preprocessor directive:\t%s ",yytext);}
{comment} {printf("\n Comment:\t%s ",yytext);}
{identifier}\( {printf("\n Function:\t%s",yytext);}
\{ {printf("\n begin block");}
\} {printf("\n end block");}
{relop} {printf("\nRelational Operator:\t%s ",yytext);}
{asmnt_op} {printf("\n Assignment Operator:\t%s ",yytext);}
{arith_op} {printf("\n Arithmetic Operator:\t%s ",yytext);}
{identifier}: {printf("\n Label:\t%s ",yytext);}
{identifier} {printf("\n Variable:\t%s ",yytext);}
{integer} {printf("\n Integer Number:\t%s ",yytext);}
\) {printf("\n End of function\t%s ",yytext);}
{punct} {printf("\n Punctuation:\t%s ",yytext);}
%%
int main(int argc, char *argv[]){
        yyin = fopen(argv[1],"r");
        yylex();
        fclose(yyin);
}
int yywrap(){
        return 1;
}

