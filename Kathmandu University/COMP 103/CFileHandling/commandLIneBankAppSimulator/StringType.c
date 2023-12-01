#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "StringType.h"

String readString(FILE* inputStream){
    size_t MAX_BUFFER_SIZE = 5;
    size_t charPos = 0;
    char ch;

    char* newString = NULL;
    newString = (char*) malloc(sizeof(char) * MAX_BUFFER_SIZE);
    if(newString == NULL){ 
        free(newString);
        return NULL;
    }
    while ( ((ch = fgetc(inputStream)) != EOF && ch != '\n'))
    {
        newString[charPos++] = ch;
        if(charPos == MAX_BUFFER_SIZE){
            MAX_BUFFER_SIZE += 5;
            newString = (char*)realloc(newString, sizeof(char) * MAX_BUFFER_SIZE);
            if(newString == NULL){
                free(newString);
                return NULL;
            }
        }
    }

    if(charPos == 0){
        free(newString);
        return NULL;
    }

    if(charPos == SIZE_MAX){
        free(newString);
        return NULL;
    }
    newString[charPos] = '\0'; 
    return  (char*)realloc(newString, sizeof(char)*charPos);
}


bool checkIfRecordExists(String recordToBeChecked, FILE* fileInWhichToCheck){
    while (!feof(fileInWhichToCheck))
    {
        /* code */
    }
    
}

