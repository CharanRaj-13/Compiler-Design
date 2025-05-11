%{
	#include<stdio.h>
	int regs[26];
	int base;
	int yywrap();
	void yyerror(char *s);
%}

%start list
%token DIGIT LETTER
%left '|'
%left '&'
%left '+' '-'
%left '*' '/' '%'
%left UMINUS

%%

list:
	| list stat '\n'
	| list error '\n' {yyerrok;}
;

stat:
	expr {printf("%d \n",$1);}
	| LETTER '=' expr {regs[$1]=$3;}
;
expr:
	'(' expr ')' {$$=$2;}
	| expr '*' expr {$$=$1*$3;}
	| expr '/' expr {$$=$1/$3;}
	| expr '%' expr {$$=$1%$3;}
	| expr '+' expr {$$=$1+$3;}
	| expr '-' expr {$$=$1-$3;}
	| expr '|' expr {$$=$1|$3;}
	| expr '&' expr {$$=$1&$3;}
	| '-' expr %prec UMINUS {$$=-$2;}
	| LETTER {$$=regs[$1];}
	| number
;
number: 
	DIGIT{
		$$ = $1;
		base = ($1==0)?8:10;
	}
	| number DIGIT {$$ = base*$1+$2;}
;

%%

int main(){
	return yyparse();
}

int yywrap(){
	return 1;
}

void yyerror(char *s){
	printf("%s",s);
}