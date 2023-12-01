#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int MAX_BUFF = 5;
typedef char* String;

char* readString(FILE* inputDevice);
int main(void){
    printf("Enter a word\n");
    String word = readString(stdin);
    printf("%s", word);
}

char* readString(FILE* inputDevice){
    char* newString = (char*)malloc(sizeof(char) * MAX_BUFF);
    if(newString == NULL){ return newString;}
    int strLen = 0;
    char strChar;
    
    while (true)
    {
        strChar = fgetc(inputDevice);
        if(strChar == EOF || strChar == '\n'){ break;}
        newString[strLen] = strChar;
        strLen++;
        if(strLen == MAX_BUFF){
            MAX_BUFF += 5;
            newString = realloc(newString, sizeof(char) * MAX_BUFF);
            if(newString == NULL){return newString;}
        } 
    }

    newString[strLen] = '\0';
    return realloc(newString, sizeof(char) * strLen);   
}