#include <stdio.h>
#include <string.h>

int main(){
    char name[50];
    printf("Please enter the sentence\n");
    scanf(" %[^\n]", name);

    int count;
    count = 0;
    for(int i = 0; i < strlen(name); i++){
        if(name[i] == ' '){
            count++;
        }
    }
    int total;
    total = 0;
    total = strlen(name) - count;
    printf("The total number of characters in the string is %d\n", total);
    return 0;
}