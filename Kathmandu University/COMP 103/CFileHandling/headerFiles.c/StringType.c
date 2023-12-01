#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StringType.h"


static int MAX_BUFFER_SIZE = 5;
void readString(char* word, FILE* inputDevice){
    word = (char*) realloc(word, sizeof(char) * MAX_BUFFER_SIZE);
    if(word == NULL){ return;}
    int strLen = 0;
    char ch;
    while ( ((ch = fgetc(inputDevice)) != EOF && ch != '\n'))
    {
        word[strLen++] = ch;
        if(strLen == MAX_BUFFER_SIZE){
            MAX_BUFFER_SIZE += 5;
            word = (char*)realloc(word, sizeof(char) * MAX_BUFFER_SIZE);
            if(word == NULL){return;}
        }
    }
    word[strLen++] = '\0';
    word = (char*)realloc(word, sizeof(char)* strLen);
}

// extern bool checkIfExistsInFile(FILE* fileToCheckIn){
    
// }