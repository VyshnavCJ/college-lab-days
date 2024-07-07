%option noyywrap
%{
int chars = 0;
int words = 0;
int lines = 0;
%}
%%
[a-zA-Z]+ {words++; chars+=strlen(yytext);}
\n {lines++;chars++;}
. {chars++;}
%%
int main(int argc, char *argv[]){
	yyin = fopen(argv[1],"r");
	yylex();
	fclose(yyin);
	printf("Words=%d, Chars=%d, Lines=%d\n",words,chars,lines);
}

