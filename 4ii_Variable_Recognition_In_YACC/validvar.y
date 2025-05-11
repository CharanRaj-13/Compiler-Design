%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<ctype.h>
	int yylex();
	void yyerror(char *s);
%}

%token let dig

%%

TERM: XTERM '\n'{
	printf("\n Accepted");
	exit(0);
	}
	|error{
		printf("\n Rejected");
		exit(0);
	}
;

XTERM: XTERM let
	| XTERM dig
	| let
;

%%

int main(){
	printf("Enter a variable : \t");	
	yyparse();
}
int yylex(){
	int ch;
	while((ch=getchar())== ' ');
	if(isalpha(ch))
		return let;
	if(isdigit(ch))
		return dig;
	return ch;
}
;
void yyerror(char *s){
	printf("%s",s);
}