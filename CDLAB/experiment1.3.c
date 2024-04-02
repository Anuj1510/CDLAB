/*
 * C Program Delete a specific Line from a Text File
 */
#include <stdio.h>
 
int main()
{
    FILE *fileptr1, *fileptr2;
    char filename[40];
    char dup[40];
    char ch;
    int delete_line, temp = 1;
 
    printf("Enter file name: ");
    scanf("%s", filename);
    printf("\n");
    printf("Enter duplicate file name: ");
    scanf("%s", dup);
    //open file in read mode
    fileptr1 = fopen(filename, "r");
    while ((ch = getc(fileptr1))!= EOF)
    {
        printf("%c", ch);
    }
    //rewind
    rewind(fileptr1);
    printf(" \n Enter line number of the line to be deleted:");
    scanf("%d", &delete_line);
    //open new file in write mode
    fileptr2 = fopen(dup, "w");
    
    while ((ch = getc(fileptr1)) != EOF)
    {
        if (ch == '\n')
            temp++;
            //except the line to be deleted
        if (temp != delete_line)
        {
            //copy all lines in file replica.c
            putc(ch, fileptr2);
        }
    }
    fclose(fileptr1);
    fclose(fileptr2);
    remove(filename);
    //rename the file replica.c to original name
    rename(dup, filename);
    printf("\n The contents of file after being modified are as follows:\n");
    fileptr1 = fopen(filename, "r");
    while ((ch = getc(fileptr1)) != EOF)
    {
        printf("%c", ch);
    }
    fclose(fileptr1);
    return 0;
}
