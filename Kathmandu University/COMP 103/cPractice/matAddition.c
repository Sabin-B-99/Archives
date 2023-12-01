#include <stdio.h>
int main(){
    int matA[3][3]  = 
    {
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };

    int matB[3][3] = 
    {
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };

    int matRes[3][3];

    for(int i = 0; i< 3; i++){
        for(int j = 0; j < 3; j++){
            matRes[i][j] = matA[i][j] + matB[i][j];
        }
    }

    
    for(int i = 0; i< 3; i++){
        for(int j = 0; j < 3; j++){
            printf(" %d\t",matRes[i][j]);
        }
        printf("\n");
    }

    return 0;
}

