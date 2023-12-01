#include <stdio.h>
#include <stdlib.h>

typedef struct records
{
    char* name;
    char* address;
    int accnNum;
}records;

FILE* in = NULL;
FILE* out = NULL;

char* readString(FILE* input);
records* createRecords();

int main(void){
    records* recWrote = NULL;


    records recordRead;

    out = fopen("customerRecords.dat", "wb");
    if(out == NULL){
        return 1;
    }
    recWrote = createRecords();
    size_t bytes_written = fwrite(recWrote, sizeof(*recWrote), 1, out);
    fclose(out);
    if(bytes_written == 0){
        return 2;
    }

    in = fopen("customerRecords.dat", "rb");
    //bad example
    //what if i didn't knew the size of records that had to be read from the file\
    //i.e size of each record
    //i.e. what if there was no recWrote or any other writing portion of this file
    
    size_t bytes_read = fread(&recordRead, sizeof(*recWrote), 1, in);
    fclose(in);
    if(bytes_read == 0){
        return 3;
    }

    printf("***************************\n");
    printf("Name read: %s\n", recordRead.name);
    printf("Address read: %s\n", recordRead.address);
    printf("Account Number read: %d\n", recordRead.accnNum);

    return 0;
}

records* createRecords(){
    records* newRec = (records*) malloc(sizeof(records)* 1);
    printf("Enter full name of the customer\n");
    newRec ->name = readString(stdin);
    
    printf("Enter address of the customer\n");
    newRec -> address = readString(stdin);
   
    printf("Enter the account numeber of the customer\n");
    scanf("%d", &(newRec->accnNum));

    return newRec;
}



char* readString(FILE* input){
    int INIT_BUFFER  = 5;
    char* newWord = NULL;
    newWord = (char*)malloc(sizeof(char) * INIT_BUFFER);
    char ch;
    int pos = 0;
    while ((ch = getc(input)) != EOF && ch != '\n'){
        *(newWord + pos) = ch;
        pos++;
        if(INIT_BUFFER == pos){
            INIT_BUFFER += 5;
            newWord = (char*) realloc(newWord, sizeof(char) * INIT_BUFFER);
            if(newWord == NULL){
                return NULL;
            }
        }
    }
    newWord[pos++] = '\0';
    newWord = (char*)realloc(newWord, sizeof(char)* pos);
    if(newWord == NULL){
        return NULL;
    }
    return newWord;
}