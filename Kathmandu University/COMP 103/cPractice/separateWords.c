#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int countSpaces(char* str);

int main(){
    char* string;
    string = (char*)malloc(sizeof(char) * 24);
    string = "   My name is Sabin Badal   "; 
    int res = countSpaces(string);
    printf("No of words= %d", res);
    return 0;
}

int countSpaces(char* str){
    int flag = 0;
    int noOfWord = 0;
    
    for(int i = 0; i < (strlen(str) + 1); i++){
        printf(" %c %d\n", *(str + i), *(str + i));

        if((*(str + i) >= 65 && *(str + i) <= 97) || (*(str + i) >= 97 && *(str + i) <= 122)){
            flag = 1;
        }
        
        if(*(str + i) == ' ' && flag == 1){
            noOfWord++;
            flag = 0;
        }
        
        if(*(str + i) == '\0' && *(str + (i-1)) == ' ')
        {
            noOfWord--;
        }

        if(*(str + i) == '\0'){
            noOfWord++;
        }
    }

    return noOfWord;
}