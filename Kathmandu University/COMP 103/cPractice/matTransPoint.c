#include <stdio.h>
#include <stdlib.h>

void readVal(int* arr[], int rowNo, int colNo);
void transpose(int* arrA[], int* arrRes[], int rowNo, int colNo);
void display(int* arrA[], int rowNo, int colNo);

int main(){
    int r;
    int c;
    printf("Enter the number of rows of the matirx\n");
    scanf(" %d", &r);
    printf("Enter the number of columns of the matrix\n");
    scanf(" %d", &c);

    int* matA[r];
    int* matRes[r];   

    for(int i = 0; i < r; i++){
        matA[i] = (int*) malloc(sizeof(int) * c);
        matRes[i] = (int*) malloc(sizeof(int) * c);
    }


    printf("Please enter the values of matrix A\n");

    readVal(matA,r,c);
    transpose(matA,matRes,r,c);
    display(matRes,r,c);

}

void readVal(int* arr[], int rowNo, int colNo){
    for(int i = 0; i < rowNo; i++){
        for(int j = 0; j < colNo; j++){
            printf("Value for matA[%d][%d]: ", (i+1), (j+1));
            scanf(" %d", (arr[i] + j));
        }
    }
    printf("**********************************\n");
}

void transpose(int* arrA[], int* arrRes[], int rowNo, int colNo){
    for(int i = 0; i < rowNo; i++){
        for(int j = 0; j < colNo; j++){
            *(arrRes[j] + i) = *(arrA[i] + j);
        }
    }
}

void display(int* arrA[], int rowNo, int colNo){
   printf("The resultant matrix is\n");
   if(rowNo != colNo){
       for(int i = 0; i < colNo; i++){
        for(int j = 0; j < rowNo; j++){
            printf(" %d\t", *(arrA[i] + j));
        }
        printf("\n");
    }
   }else
   {
       for(int i = 0; i < colNo; i++){
        for(int j = 0; j < rowNo; j++){
            printf(" %d\t", *(arrA[i] + j));
        }
        printf("\n");
    }
   }
}