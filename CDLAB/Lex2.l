%{
#include <stdio.h>
%}

%%

[A-Z] {
    printf("'%c' is a capital letter.\n", yytext[0]);
}
. ;

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter a string: ");
    yylex();
    return 0;
}
