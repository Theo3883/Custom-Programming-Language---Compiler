%{
#include <stdio.h>
#include "limbaj.tab.h"
%}
%option noyywrap
%%
"Print" { return Print; }
"TypeOf" { return TypeOf; }

"if"    { return IF; }
"else"  { return ELSE; }
"then"  { return THEN; }
"while" { return WHILE; }
"for"   { return FOR; }
"=="    { return EQ; }
"!="    { return NEQ; }
"<"     { return LT; }
">"     { return GT; }
"<="    { return LE; }
">="    { return GE; }
"+"     { return '+'; }
"-"     { return '-'; }
"*"     { return '*'; }
"/"     { return '/'; }
"("     { return '('; }
")"     { return ')'; }
"{"     { return '{'; }
"}"     { return '}'; }

"function" { return FUNCTION; }
"return"   { return RETURN; }
"," { return ','; }
":" { return ':'; }

"class" {return CLASS;}
"new" {return NEW;}
"int"|"float"|"char"|"string"|"bool" {yylval.string = strdup(yytext);return TYPE;}
"begin_progr" {return BGIN;}
"end_progr" {return END;}
"true"|"false" {yylval.string = strdup(yytext); return BOOL_LITERAL;}
[a-zA-Z][a-zA-Z0-9]* {yylval.string = strdup(yytext); return ID;}
":=" {return ASSIGN;}
[0-9]+ {yylval.number = atoi(yytext); return NR;}
\"[^\"]*\" {yylval.string = strdup(yytext); return STRING_LITERAL;}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}
%%