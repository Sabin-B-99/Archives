#include <stdio.h>

void readVal(int matrix[][4]);
void display(int matrix[][4]);



int main(){
    int matA[4][4];

    readVal(matA);
    display(matA);

    return 0;    
}


void readVal(int matrix[][4]){
    for(int i =0; i < 4 ; i++){
        for (int j = 0; j < 4; j++)
        {
            printf("Enter matA[%d][%d] element: \n", (i+1),(j+1));
            scanf(" %d", &matrix[i][j]);
        }
    }
}

void display(int matrix[][4]){
    int sum;
    for(int i =0; i < 4 ; i++){
        sum = 0;
        for (int j = 0; j < 4; j++)
        {
            sum += matrix[i][j];
            printf(" %d\t", matrix[i][j]);
        }
        printf("Sum = %d\n", sum);
    }
}