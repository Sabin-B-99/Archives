// Check to see if a string has the same amount of 'x's and 'o's. The method must return a boolean and be case insensitive. The string can contain any char.

// Examples input/output:

// XO("ooxx") => true
// XO("xooxx") => false
// XO("ooxXm") => true
// XO("zpzpzpp") => true // when no 'x' and 'o' is present should return true
// XO("zzoo") => false


//Difficulty: 7kyu
//Result: All test Passed :), Time: 864 ms; 
//Date: 4/13/2020

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool xo (const char* str);

int main(){
    char* word;
    word = (char*)malloc(sizeof(char)*20);
    printf("Enter a word\n");
    fgets(word, 20, stdin);

    bool res;
    res = xo(word);

    if(res){
        printf("Yes!!\n");
    }else{
        printf("No..\n");
    }

    return 0;
}

bool xo (const char* str){
  
    int n;
    n = strlen(str);
  
    int countX;
    countX = 0;
    int countO;
    countO = 0;
  
    for(int i = 0; i < n; i++){
        if(*(str + i) == 'o' || *(str + i) == 'O' ){
            countO++;
        }

        if(*(str + i) == 'x' || *(str + i) == 'X' ){
            countX++;
        }
    }
    
    if(countO == countX){
        return true;
    }
  
    return false;
} 