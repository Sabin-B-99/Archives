#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdbool.h>

typedef struct disease
{
    char nameRegion[10];
    int totalCase;
    int numActive;
    int numRecovered;
    int numDeath;
}covidData;

void search(FILE* dataFile);
FILE* covidFile = NULL;

int main(){
    covidData data[3];
    
    covidFile = fopen("CovidTotalData.txt", "r+");
    
    if(covidFile == NULL){
    printf("*****************************************\n");
    printf("One time operation\n");
    printf("You haven't made any record previously\n");
    printf("Making new file to save records, which\n");
    printf("you can update later.\n");

    covidFile = fopen("CovidTotalData.txt", "w+");
    for (int i = 0; i < 3; i++)
    {
        printf("Eneter name\n");
        scanf(" %s", data[i].nameRegion);
        printf("Enter totalCases\n");
        scanf("%d", &data[i].numActive);
        fprintf(covidFile ,"%s %d\n", data[i].nameRegion, data[i].numActive);
    }    
}
    
   search(covidFile); 
   fclose(covidFile);

}

void search(FILE* dataFile){
    char wordFromFile[64];
    char wordToMatch[64];
    wordToMatch[0] = '\0';
    char c;
    int i = 0;
    printf("Enter the region to view\n");
    char wordToSearch[64];
    scanf(" %s", wordToSearch);

    while (!feof(dataFile))
    {
        c = fgetc(dataFile);

        if(c == ' ' || c == '\n'){
            wordFromFile[i+1] = '\0';
            i = 0;
            strcpy(wordToMatch,wordFromFile);
            memset(wordFromFile, 0, 64);
            continue;   
        }else
        {
            wordFromFile[i] = c;
            i++;
           
        }

        if(strcmp(wordToMatch,wordToSearch)==0){
            printf("Found\n");

            break;
        }
    }
    
}
