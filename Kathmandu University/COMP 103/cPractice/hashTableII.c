//still needs some work on it
//searching process in still not on par
//I still can easily break the program
//After workoing on it for sometime 
// i conclude that my search function is absolutely shit



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct slList
{
    char* name;
    struct slList* next;
}List;

const int HASH_MAX = 10;

int hash(char* value);
List* create(char* value);
List* insert(List* head, char* value);
bool find(List* table[],char* value);
void store(List* table[], char* value);

int main(){
    List* hashTable[HASH_MAX]; 

    for(int i = 0; i<HASH_MAX; i++){
        hashTable[i] = NULL;
    }
    

    char* nameToStore = NULL;
    nameToStore = (char*)malloc(sizeof(char) * 20);
    
    printf("Enter the names to be stored\n");
    printf("Enter q to quit storing the name\n");
    
    //Stores a name in a hash table
    while(true){
        printf("Name??\t");
        scanf(" %[^\n]", nameToStore);
        if((strcmp(nameToStore, "q") == 0)){
            break;
        }
        store(hashTable,nameToStore);
        memset(nameToStore, 0, 20);
    }
    //storing process ends



    free(nameToStore);


    //Searches for a name in the stored list.
    char* nameToSearch = NULL;
    nameToSearch = (char*)malloc(sizeof(char)*20);
    
    printf("Enter the name to be searched for:\n");
    scanf(" %[^\n]", nameToSearch);
    

    

    bool val;
    val = find(hashTable, nameToSearch);
    if(val){
        printf("Yes, it is in the list.\n");
    }else{
        printf("No, it is not in the list.\n");
    }
    //searching process ends

    free(nameToSearch);
    free(hashTable);

    return 0;
}

void store(List* table[], char* value){
    int hashVal;
    hashVal = hash(value);
    
    
    if(table[hashVal] == NULL){
        table[hashVal] = create(value);
    }else{
        table[hashVal] = insert(table[hashVal], value);
    }
    

    //Just some random code used for debugging during writing this program
    // printf(" %s\t", table[hashVal]->name);
    // printf(" %d\n", hash(table[hashVal]->name));
    //random code ends
}


int hash(char* value){
    int sum;
    sum = 0;
    for(int i = 0; i < strlen(value); i++){
        sum += *(value + i);
    }
    return sum % HASH_MAX;
}


List* create(char* value){
    List* head = NULL;
    head = (List*)malloc(sizeof(List));

    head->name = (char*)malloc(strlen(value) + 1);

    strcpy(head->name,value);
    head->next = NULL;
    return head;
}

List* insert(List* head, char* value){
    List* nextNode = NULL;
    nextNode = (List*)malloc(sizeof(List));

    nextNode->name = (char*)malloc(strlen(value) + 1);

    strcpy(nextNode->name,value);
    nextNode->next = head;
    return nextNode;
}

bool find(List* table[],char* value){
    int hashValue;
    hashValue = hash(value);
    

    List* traverse = NULL;
    traverse = (List*)malloc(sizeof(List));

    traverse = table[hashValue];

    
    
    // while (traverse->next != NULL)
    // {
    //     if(traverse ->name == value){
    //         return true;
    //     }
    //     traverse = traverse -> next;
    // }
    // return false;

    if(traverse != NULL){
        while(true){
            if(traverse ->name == value){
                printf("Hurray! %s found\n", value);
                return true;
            }
            if(traverse->next == NULL){
                printf("Sorry! %s not found\n", value);
                return false;
            }  
            traverse = traverse -> next;
        }
    }
    printf("Sorry! %s not found\n", value);
    return false;

}



// void printlist(THING **head)
// // this routine uses pointer-to-pointer techniques :-)
// {
// 	THING **tracer = head;
// 	while ((*tracer) != NULL) {
// 		printf("%s \n",(*tracer)->item);
// 		tracer = &(*tracer)->next;
// 	}
// }