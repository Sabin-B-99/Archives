#include <stdio.h>
#include <stdlib.h>
void readVal(int* arrA[], int rowNo, int colNo);
void sum(int* arrA[], int* arrB[], int* arrR[], int rowNo, int colNo);
void result(int* arraA[], int rowNo, int colNo);

int main(void){
    int r;
    printf("Please enter the number of rows in the given matrix\n");
    scanf(" %d", &r);

    int c;
    printf("Please enter the number of columns in the given matrix\n");
    scanf(" %d",&c);

    int* matA[r];
    int* matB[r];
    int* matRes[r];

    for(int i =0; i < r; i++){
        matA[i] = (int*)malloc(c*sizeof(int));
        matB[i] = (int*)malloc(c* sizeof(int));
        matRes[i] = (int*)malloc(c* sizeof(int));
    }
    printf("Enter value for matrix A\n");
    readVal(matA, r,c);
    printf("Now, Enter value for matrix B\n");
    readVal(matB, r,c);

    sum(matA, matB, matRes, r, c);

    result(matRes, r,c);
}

void readVal(int* arrA[], int rowNo, int colNo){
        for(int i = 0; i < rowNo; i++){
            for(int j = 0; j < colNo; j++){
                printf("Enter value for: elem[%d][%d]",(i+1),(j+1));
                scanf(" %d", (arrA[i] + j));
            }
        }
        printf("**********************************************\n");
}

void sum(int* arrA[], int* arrB[], int* arrR[], int rowNo, int colNo){
    for(int i = 0; i < rowNo; i++){
            for(int j = 0; j < colNo; j++){
                *(arrR[i] + j) = *(arrA[i] + j) + *(arrB[i] + j);
            }
        }

}


void result(int* arrA[], int rowNo, int colNo){
    printf("Your result is\n");
    for(int i = 0; i < rowNo; i++){
            for(int j = 0; j < colNo; j++){
                printf(" %d", *(arrA[i] + j));
            }
            printf("\n");
        }
 }



