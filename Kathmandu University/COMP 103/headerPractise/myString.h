#include <stdio.h>
#include <stdlib.h>

char* readString(FILE* inputDevice);
typedef char* String;
static int MAX_BUFF = 5;


extern char* readString(FILE* inputDevice){
    int len = 0;
    char ch;
    char* newString = (char*) malloc(sizeof(char) * MAX_BUFF);
    if(newString == NULL){
        return newString;
    }
    while((ch = fgetc(inputDevice)) != EOF && ch != '\n'){
        newString[len++] = ch;
        if(len == MAX_BUFF){
            newString = (char*) realloc(newString, sizeof(char) * (MAX_BUFF += 5));
            if(newString == NULL){
                return newString;
            }
        }            
    }
    newString[len++] = '\0';
    return (char*)realloc(newString, sizeof(char) * len);
}