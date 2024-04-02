%{
#include <stdio.h>
%}

%%
[aeiouAEIOU] {
    printf("'%c' is a vowel.\n", yytext[0]);
}
. {
    printf("'%c' is not a vowel.\n", yytext[0]);
}
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter a letter: ");
    yylex();
    return 0;
}
