%{
	#include<stdio.h>
	#include<ctype.h>
	#include<stdlib.h>
	int yylex();
	void yyerror(char *s);
%}

%token num let
%left '+' '-'
%left '*' '/'

%%

Stmt:Stmt '\n'{
	printf("Valid Expression");
	exit(0);
	}
	| expr
	| error '\n'{
		printf("\n Invalid Expression");
		exit(0);
	}
;

expr : num
	| let
	| expr '+' expr
	| expr '-' expr
	| expr '*' expr
	| expr '/' expr
	| '(' expr ')'
;

%%
int main(){
	printf("\n Enter a expression to validate \t ");
	yyparse();
}

int yylex(){
	int ch;
	while((ch=getchar()) == ' ')
		if(isdigit(ch))
			return num;
		
		if(isalpha(ch))
			return let;
		
		return ch;
}
void yyerror(char *s){
	printf("%s",s);
}