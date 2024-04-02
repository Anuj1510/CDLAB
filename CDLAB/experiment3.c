//  Write a C program to identify all types of comments inside a program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void extract(FILE *input,FILE *output){
	int ch,prev = EOF;
	while((ch = fgetc(input)) != EOF){
		if(ch == '/' && prev == '/'){
			while((ch = fgetc(input))!=EOF && ch != '\n'){
				fputc(ch,output);
			}
			fputc('\n',output);
		}else if(ch == '*' && prev == '/'){
			fputc(prev,output);
			while((ch = fgetc(input)) != EOF){
				fputc(ch,output);
				if(ch == '*' && (ch = fgetc(input)) == '/'){
					break;
				}
			}
		}
		prev = ch;
	}
}

int main(){
	char path1[100];
	char path2[100];
	scanf("%s",path1);
	scanf("%s",path2);
	FILE *input = fopen(path1,"r");
	FILE *output = fopen(path2,"w");
	extract(input,output);
}
