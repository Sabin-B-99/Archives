#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const int HASH_MAX = 10;
int hash(char* value);


int main(){
    char* name;
    name = (char*)malloc(sizeof(char)*20);
    
    printf("Enter the names to be stored\n");
    printf("Enter Q to quit storing the name\n");
    
    
    while(true){
        printf("Name??\t");
        scanf(" %[^\n]", name);
        if((strcmp(name, "Q") == 0) || (strcmp(name, "q")== 0)){
            break;
        }
        printf("%d\n",hash(name));
    }

    printf(" %s\n", name);
    
    
    //printf("%s\n", name);
    //printf("%d\n", strlen(name));

    // for(int i = 0; i < strlen(name); i++){
    //     printf("%c %d\n", *(name+i), *(name+i));
        
    // }

    return 0;
}

int hash(char* value){
    int sum;
    sum = 0;
    for(int i = 0; i < strlen(value); i++){
        sum += *(value + i);
    }
    return sum % HASH_MAX;
}