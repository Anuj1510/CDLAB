%{
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int inSpaces = 0;
%}

%%
[ \t]+  { if (!inSpaces) { printf(" "); inSpaces = 1; } }
\n      { if (!inSpaces) printf("\n"); inSpaces = 0; }
[^ \t\n] { fprintf(yyout, "%s", yytext); inSpaces = 0; }
%%

int yywrap() {
    return 1;
}

int main() {
    char path1[100];
    char path2[100];
    printf("Enter path1:\n");
    fgets(path1, sizeof(path1), stdin);
    path1[strcspn(path1, "\n")] = '\0';
    printf("Enter path2:\n");
    fgets(path2, sizeof(path2), stdin);
    path2[strcspn(path2, "\n")] = '\0';
    FILE *inputFile = fopen(path1, "r");
    FILE *outputFile = fopen(path2, "w");

    if (!inputFile || !outputFile) {
        printf("Error opening files.\n");
        return 1;
    }

    yyin = inputFile;
    yyout = outputFile;

    yylex();

    fclose(inputFile);
    fclose(outputFile);

    printf("\nSpaces, newlines, and tabs removed successfully. Result written to output.txt\n");

    return 0;
}
