// c program to copy content from one file to another

#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *fptr1,*fptr2;
	char path1[100],path2[100];
	printf("Enter path1\n");
	scanf("%s",path1);
	printf("Enter path2\n");
	scanf("%s",path2);
	fptr1 = fopen(path1,"r");
	fptr2 = fopen(path2,"w");
	char ch = getc(fptr1);
	while(ch != EOF){
		putc(ch,fptr2);
		ch = getc(fptr1);
	}
	return 0;
}
