#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct disease{
    char name[10];
    int deaths;
    int recovered;
}Covid;

void search(Covid data[]);
bool exitsInFile(Covid* dataFile, char* region);

const int MAX_REGION = 10;

int main(){
    
    Covid* dataBase;
    
    for (int i = 0; i < 2; i++)
    {
        printf("Deaths\n");
        scanf(" %d", &dataBase[i].deaths);
        printf("Enter Name\n");
        scanf(" %s", dataBase[i].name);    
    }

    //search(dataBase);
    printf("Enter name to search\n");
    char name[6];
    scanf(" %s", name);
    if(exitsInFile(dataBase, name)){
        printf("true\n");
    }else
    {
        printf("false\n");
    }
    
    return 0;

}

void search(Covid data[]){
    Covid foundValue;
    foundValue.name[0] = '\0'; 
    printf("Enter name to search\n");
    char name[6];
    scanf(" %s", name);
    for (int i = 0; i < MAX_REGION; i++)
    {
        if(strcmp(data[i].name,name) == 0){
            printf("Found\n");
            foundValue = data[i];
            break;
        }
    }
    if(foundValue.name[0] == '\0'){
        printf("Value not found");
    }else{
        printf("Found value %s\n", foundValue.name);
    }
}

bool exitsInFile(Covid* dataFile, char* region){
    for (int i = 0; i < MAX_REGION; i++)
    {
        if(strcmp(dataFile[i].name,region) == 0){
            return true;
        }
    }
    return false;
}
