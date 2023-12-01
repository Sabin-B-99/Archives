#include <stdio.h>
void readVal(int matrix[][3], int rowNo);
void sum(int matrixA[][3], int matrixB[][3], int rowA, int rowB);

int main(){
    int n;
    int m;

    printf("Enter the no of rows of matrix A\n");
    scanf(" %d", &n);

    printf("Enter the no of rows of matrix B\n");
    scanf(" %d", &m);

    //there are some unimportant lines below so feel free to skip them
    while(n != m){
        printf("********************\n");
        printf("The dimensions of the matrix are not equal\n");
        printf("To perform matrix addition, their dimensions must be euqal\n");
        printf("Their rows and columns must have equal no of elments\n");
        printf("****************\n");

        printf("Enter the no of rows of matrix A, Again\n");
        scanf(" %d", &n);

        printf("Enter the no of rows of matrix B, Again\n");
        scanf(" %d", &m);

        /*these lines are optional allright..but lines except those inside/ 
        of printf statement are necessary condtions for matrix addition*/
        
        if(n == m){
            printf("Checking for dimensions correctness...\n");
            printf("Success\n");
            printf("********************\n"); 
        }        
    }

    int matA[n][3];
    int matB[m][3];

    printf("Enter values for matrix A\n");
    readVal(matA, n);
    printf("Enter values for matrix B\n");
    readVal(matB, m);

    sum(matA, matB, n , m);

}

void readVal(int matrix[][3], int rowNo){
    for(int i = 0; i < rowNo; i++){
        for(int j = 0; j < 3; j++){
            printf("Enter value for: mat[%d][%d]: ", (i+1), (j+1));
            scanf(" %d", &matrix[i][j]);
        }
    }
    printf("***********************\n");
}

void sum(int matrixA[][3], int matrixB[][3], int rowA, int rowB){
    int matRes[rowA][3];
    for(int i = 0; i < rowA; i++){
        for(int j = 0; j < 3; j++){
            matRes[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    printf("The result is\n");
    for(int i = 0; i < rowA; i++){
        for(int j = 0; j < 3; j++){
            printf(" %d\t", matRes[i][j]);
        }
        printf("\n");
    }

}

