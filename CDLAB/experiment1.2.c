// c program to read names and marks of n numbers of students from user and store them in a file

#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE *file;
	char path[100];
	printf("Enter file path\n");
	scanf("%s",path);
	int n;
	printf("Enter number of students\n");
	scanf("%d",&n);
	file = fopen(path,"w"); // w to write the file
	if(file==NULL){
		printf("Error");
		exit(EXIT_FAILURE);
	}
	char name[50];
	int marks,i; 
	for(i = 0;i<n;i++){
		printf("Enter the name\n");
		scanf("%s",name);
		printf("Enter marks\n");
		scanf("%d",&marks);
		fprintf(file,"\nName: %s \nMarks: %d\n",name,marks);
	}
	fclose(file);
	
}
