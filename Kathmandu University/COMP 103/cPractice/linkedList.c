#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//node for the singly linked list
typedef struct slList
{
    int val;
    struct slList* next;
}List;

//function definitions
List* create(int val);
List* insert(List* head, int value);
bool find(List* head, int value);

int main(){

    printf("\n\n");
    printf("Enter the numbers to be stored in this linked list.\n");
    printf("To quit: enter 999\n");
    printf("**********************\n");
    
    int num;
    List* next = NULL;

    /*just counter for user prompt to so that the user can
        keep the track of numbers inputted in list in linne 41
        and line 32*/
    int i;
    i =0;
    printf("Number[%d]: ", (i+1));
    i = 1;

    //asks for first number to bbe inputted in the list
    scanf(" %d", &num);
    //creating the first member node of the linked list
    next = create(num);

    //for creating sebesquent member nodes of the list
    while (true)
    {
        //asks for the second and sebesequent numbers in the linked list
        printf("Number[%d]: ", (i+1));
        scanf(" %d", &num); 

        if(num == 999){
            break;
        }
        //creates and chains the second and sebesequent node members with the first member
        next = insert(next, num);
        i++;
    }


    //now checking wether a number is in the list or not
    printf("\n\n");
    printf("***************************\n");

    //asking for the numbers to be checked
    printf("Now, enter the numbers to be searched\n");
    scanf(" %d", &num);

    bool check;
    check = find(next, num);

    if(check){ // same as; if(check == true)
        printf("The number is in the list\n");
    }else
    {
        printf("It is not in this list\n");
    }

    return 0;
}

bool find(List* head, int value){

    List* traverse = NULL;
    traverse = (List*)malloc(sizeof(List));
    traverse = head;

    while(true){
        if(traverse->val == value){
            return true;
        }
        if(traverse->next == NULL){
            return false;
        }
        traverse = traverse->next;
    }  
}



List* create(int value){
    List* node = NULL;
    node = (List*) malloc(sizeof(List));
    node->next = NULL;
    node ->val = value; //(*node).val = val;
    return node;
}

List* insert(List* head, int value)
{
    List* newNode = NULL;
    newNode = (List*)malloc(sizeof(List));
    newNode ->next = head;
    newNode ->val = value;
    return newNode;
}




