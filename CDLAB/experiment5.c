#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char s[5];
	printf("\n Enter any operator:");
	fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0'; // Remove newline character from input
	switch(s[0])
	{
		case'>': if(s[1]=='=')
					printf("\n Greater than or equal");
				else
					printf("\n Greater than");
				break;
		case'<': if(s[1]=='=')
					printf("\n Less than or equal");
				else
					printf("\nLess than");
				break;
		case'=': if(s[1]=='=')
					printf("\nEqual to");
				else
					printf("\nAssignment");
				break;
		case'!': if(s[1]=='=')
					printf("\nNot Equal");
				else
					printf("\n Bit Not");
				break;
		case'&': if(s[1]=='&')
					printf("\nLogical AND");
				else
					printf("\n Bitwise AND");
				break;
		case'|': if(s[1]=='|')
					printf("\nLogical OR");
				else
					printf("\nBitwise OR");
				break;
		case'+': printf("\n Addition");
				break;
		case'-': printf("\nSubstraction");
				break;
		case'*': printf("\nMultiplication");
				break;
		case'/': printf("\nDivision");
				break;
		case'%': printf("Modulus");
				break;
		default: printf("\n Not an operator");
	}
}
