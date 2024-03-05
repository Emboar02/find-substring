#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int findSubstringPosition(char *str, char *substring);
char *strlwr(char *str);

int main(int argc, char *argv[]) {
    FILE *file;
    char *buffer;
    // validate program arguments
    if (argc < 2) {
        perror("You did not provide enough arguments.");
        exit(EXIT_FAILURE);
    }
    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("You did not provide a valid file name.");
        exit(EXIT_FAILURE);
    }
    buffer = (char*)malloc(100 * sizeof(char));
    if (buffer == NULL) {
        perror("Error allocating memory");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    // Read data from the file into the dynamically allocated buffer
    fgets(buffer, 100, file);
    // Close the file
    fclose(file);
    buffer = buffer;

    for (int i = 2; i < argc; i++) {
        char *stringPointer = buffer;
        char *substring = argv[i];
        int instances = 0;
        int position = findSubstringPosition(stringPointer, substring);
        while (position != -1) {
            instances += 1;
            stringPointer += position + 1;
            position = findSubstringPosition(stringPointer, substring);
        }
        printf("%d\n", instances);
    }
    free(buffer);
}

int findSubstringPosition(char *str, char *substring) {
    char *full_string = strlwr(str);
    char *sub_string = strlwr(substring);
    char *position = strstr(full_string, sub_string);

    if (position != NULL) {
        // Calculate the position by subtracting the base address
        return (int)(position - str);
    }

    // Return -1 if the substring is not found
    return -1;
}

char *strlwr(char *str) { 
    unsigned char *p = (unsigned char *)str; 
    while (*p) { 
        *p = tolower((unsigned char)*p); 
        p++; 
    } 
    return str; 
}



