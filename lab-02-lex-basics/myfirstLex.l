%option noyywrap

%{
#include<stdio.h>
#include<stdlib.h>
%}

digit [0-9]
letter [A-Za-z_]
key "int"|"main"|"for"|"if"|"else"|"return"|"while"

%%

{key} {
    printf("%s is a keyword and length is: %d\n", yytext, yyleng);
}

{letter}({letter}|{digit})* {
    printf("%s is an identifier and length is: %d\n", yytext, yyleng);
}

{digit}+ {
    printf("%s is an int number and int value is %d\n", yytext, atoi(yytext));
}

{digit}+"."{digit}+([Ee][+-]?{digit}+)? {
    printf("%s is an Exponential number\n", yytext);
}

. { }

%%

int main()
{
    yylex();
    return 0;
}%option noyywrap

%{
#include<stdio.h>
#include<stdlib.h>
%}

digit [0-9]
letter [A-Za-z_]
key "int"|"main"|"for"|"if"|"else"|"return"|"while"

%%

{key} {
    printf("%s is a keyword and length is: %d\n", yytext, yyleng);
}

{letter}({letter}|{digit})* {
    printf("%s is an identifier and length is: %d\n", yytext, yyleng);
}

{digit}+ {
    printf("%s is an int number and int value is %d\n", yytext, atoi(yytext));
}

{digit}+"."{digit}+([Ee][+-]?{digit}+)? {
    printf("%s is an Exponential number\n", yytext);
}

. { }

%%

int main()
{
    yylex();
    return 0;
}