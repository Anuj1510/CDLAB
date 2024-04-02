#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

//void removeWord(char *str, const char *word) {
//    char *ptr = str;
//    while ((ptr = strstr(ptr, word)) != NULL) {
//        memmove(ptr, ptr + strlen(word), strlen(ptr + strlen(word)) + 1);
//    }
//}

int main() {
    FILE *sourceFile, *destinationFile;
    char sourceFileName[100], destinationFileName[100];
    char word[MAX_WORD_LENGTH];
    const char *removeWords[] = {"a", "an", "the","and"}; // Words to remove

    // Input source file name
    printf("Enter source file name: ");
    scanf("%s", sourceFileName);

    // Input destination file name
    printf("Enter destination file name: ");
    scanf("%s", destinationFileName);

    // Open source file in read mode
    sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        printf("Unable to open source file '%s'\n", sourceFileName);
        return 1;
    }

    // Open destination file in write mode
    destinationFile = fopen(destinationFileName, "w");
    if (destinationFile == NULL) {
        printf("Unable to create destination file '%s'\n", destinationFileName);
        fclose(sourceFile);
        return 1;
    }

    // Copy contents from source to destination removing specified words
    int i;
    while (fscanf(sourceFile, "%s", word) != EOF) {
        int remove = 0;
        for (i = 0; i < sizeof(removeWords) / sizeof(removeWords[0]); ++i) {
            if (strcmp(word, removeWords[i]) == 0) {
                remove = 1;
                break;
            }
        }
        if (!remove) {
            fprintf(destinationFile, "%s ", word);
        }
    }

    printf("File copied successfully.\n");

    // Close files
    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}

