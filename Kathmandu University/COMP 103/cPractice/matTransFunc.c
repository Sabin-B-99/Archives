#include <stdio.h>

void readValue(int arr[][3], int rowNo);
void transpose(int matrix[][3], int rowNo);

int main(){
    int n;
    printf("Please enter the no of rows\n");
    scanf(" %d", &n);
   
    int matA[n][3];

    readValue(matA,n);
    transpose(matA,n);
    

}

void readValue(int arr[][3], int rowNo){
    for(int i = 0; i < rowNo; i++){
        for(int j = 0; j < 3; j++){
            printf("Enter value for: matA[%d][%d]", (i+1),(j+1));
            scanf(" %d", &arr[i][j]);
        }
    }
}

void transpose(int matrix[][3], int rowNo){
    int matRes[rowNo][3];

    for(int i = 0; i < rowNo; i++){
        for(int j = 0; j < 3; j++){
            matRes[j][i] = matrix[i][j];
        }
    }

    if(rowNo != 3){
        for(int i = 0; i < 3; i++){
        for(int j = 0; j < rowNo; j++){
            printf(" %d\t", matRes[i][j]);
        }
        printf("\n");
    }
    }else{
         for(int i = 0; i < rowNo; i++){
        for(int j = 0; j < 3; j++){
            printf(" %d\t", matRes[i][j]);
        }
        printf("\n");
    }
    }
}

