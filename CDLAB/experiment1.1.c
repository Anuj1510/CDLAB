// Count total number of characters words and lines in a file using C
#include<stdio.h>
#include<stdlib.h>
int main(){
	char path[100];
	FILE *file;
	char ch;
	int cntlines = 0,cntwords=0,cntchar = 0;
	printf("Enter source file name: ");
	gets(path);
	file = fopen(path,"r"); // r to read the file
	if(file==NULL){
		printf("file does not exist.\n");
		exit(EXIT_FAILURE);
	}
	while((ch = fgetc(file)) != EOF){
		cntchar++;
		if((ch == '\n') || (ch == '\0')){
			cntlines++;
		}
		
		if((ch == ' ') || (ch == '\t') || (ch == '\n') || (ch == '\0')){
			cntwords++;
		}
		
		
	}
	if(cntchar>0){
		cntwords++;
		cntlines++;
	}
	
	printf("%d\n",cntchar);
	printf("%d\n",cntlines);
	printf("%d\n",cntwords);
	fclose(file);
}
