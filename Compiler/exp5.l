%option noyywrap
%{
int vowels = 0;
int con = 0;
%}
%%
[aeiouAEIOU] {vowels++;}
[a-zA-Z] {con++;}
. {;}
%%
int main(int argc, char **argv){
	yylex();
	printf("\n The number of vowels is %d and consonants is %d\n",vowels,con);
}

