#include <stdio.h>
#include <stdlib.h>

void printVal(int *arr[], int rowNo, int colNo);
void readVal(int *arr[], int rowNo, int colNo);
int main(){
    int r;
    int c;
    printf("Enter the no of rows of the matrix\n");
    scanf(" %d", &r);
    printf("Enter the no of columns of the matix\n");
    scanf(" %d", &c);
    printf("********************************\n");
    
    
    int* matA[r];

    for(int i = 0; i < r; i++){
        matA[i] = (int*)malloc(c * sizeof(int));
    }

    readVal(matA, r, c);
    printf("+++++++++++++++++++++++++++++++++++++++++\n");
    printVal(matA, r, c);
    
    return 0;
}

void readVal(int* arr[], int rowNo, int colNo){
    printf("Start enter the value of the matrix\n");
    for(int i = 0; i < rowNo; i++){
        for(int j = 0; j < colNo; j++){
            printf("matA[%d][%d] = ", (i+1), (j+1));
            scanf(" %d", (arr[i] + j));
        }
    }
}

void printVal(int* arr[], int rowNo, int colNo){
    printf("The given matrix is\n");
    for(int i = 0; i < rowNo; i++){
        for(int j = 0; j < colNo; j++){
            printf(" %d\t", *(arr[i] + j));
        }
        printf("\n");
    }
}