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
bool find(List** table,char* value);
void store(List** table, char* value);

int main(){
    List** hashTable = NULL;
    hashTable = (List**)malloc(sizeof(List)*HASH_MAX);

    for(int i = 0; i<HASH_MAX; i++){
        hashTable[i] = NULL;
    }
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //Just some random code used for debugging during writing this program
    //store(hashTable, "Rolpa"); 
    store(hashTable, "Sabin");
    store(hashTable, "Babin");
    store(hashTable, "Asbin");
   // store(hashTable, "Sunil");
    store(hashTable, "Baikuntha");
    store(hashTable, "Van");
    store(hashTable, "Kabin");
    

    // printf("\n\n");
    // printf(" %s\n", hashTable[0] ->name); 
    // printf(" %s\n", hashTable[3] ->name);
    // printf(" %s\n", hashTable[5] ->name);
    // printf(" %s\n", hashTable[6] ->name);

    // printf(" %s\n", hashTable[3]->next->name);
    //random code ends
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    // char* key = NULL;
    // key = (char*)malloc(sizeof(char) * 20);
    
    // printf("Enter the names to be stored\n");
    // printf("Enter q to quit storing the name\n");
    
    //Stores a name in a hash table
    // while(true){
    //     printf("Name??\t");
    //     scanf(" %[^\n]", key);
    //     if((strcmp(key, "q") == 0)){
    //         break;
    //     }
    //     store(hashTable,key);
    // }

    // printf(" %s\n", hashTable[3] ->name);
    // printf(" %s\n", hashTable[5] ->name);

    // printf("HashTable[3]->name: %s\n", hashTable[3]->name);
    //storing process ends
    // free(nameToStore);

    //Searches for a name in the stored list.
    // char* nameToSearch = NULL;
    // nameToSearch = (char*)malloc(sizeof(char)*20);

    // printf("Enter the name to be searched for:\n");
    // scanf(" %[^\n]", nameToSearch);
    

    

    bool val;
    val = find(hashTable, "Van");
    if(val){
        printf("Yes, it is in the list.\n");
    }else{
        printf("No, it is not in the list.\n");
    }
    //searching process ends

    free(hashTable);
    //free(nameToSearch);

    return 0;
}

void store(List** table, char* value){
    //latest debug report: all function inside of stor works properly
    int hashVal;
    hashVal = hash(value);
    //printf("Name to store inside Store(): %s\n", value);
    
    if(table[hashVal] == NULL){
        table[hashVal] = create(value);
        //printf("Inside store() if\n");
    }else{
        table[hashVal] = insert(table[hashVal], value);
        //printf("Inside store() else\n");
    }
    // printf(" table[%d]==: %s\n", hashVal, table[hashVal]->name);
    // if(table[hashVal]->next != NULL){
    //     printf("next name: %s\n", table[hashVal]->next->name);
    // }
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

    head->name = (char*)malloc(strlen(value)+1);
    
    head->name = value;
    head->next = NULL;
    return head;
}

List* insert(List* head, char* value){
    List* nextNode = NULL;
    nextNode = (List*)malloc(sizeof(List));

    nextNode->name = (char*)malloc(strlen(value)+1);

    nextNode->name = value;
    nextNode->next = head;
    return nextNode;
}

bool find(List** table,char* value){
    int hashValue;
    hashValue = hash(value);
    

    List* traverse = NULL;
    traverse = (List*)malloc(sizeof(List));

    traverse = table[hashValue];
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