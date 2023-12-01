#include <stdio.h>
#include <stdlib.h>

void readVal(int* arrA[]);
void displayVal(int* arrA[]);

int main(){
    int* matA[4];

    for(int i = 0; i < 4; i++ ){
        matA[i] = (int*)malloc(sizeof(int) * 4); 
    }

    readVal(matA);
    displayVal(matA);

    return 0;
}

void readVal(int* arrA[]){
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("Enter matA[%d][%d] element: \n", (i+1),(j+1));
            scanf(" %d", (arrA[i] + j));
        }
    }
}

void displayVal(int* arrA[]){
    int sum;
    for (int i = 0; i < 4; i++)
    {
        sum = 0;
        for (int j = 0; j < 4; j++)
        {
            sum += *(arrA[i] + j);
            printf(" %d\t", *(arrA[i] + j));
        }
        printf("Sum: %d\n", sum);
    }
}