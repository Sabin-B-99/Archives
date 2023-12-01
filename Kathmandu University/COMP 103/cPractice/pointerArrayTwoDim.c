#include <stdio.h>
#include <stdlib.h>
int main(){
    int* x[3];
    
    for(int i = 0; i < 3; i++){
        x[i] = (int*)malloc(3*sizeof(int));
    }

    printf("Enter the values of the matrix\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("elem[%d][%d] = ", (i+1),(j+1));
            scanf(" %d", (x[i] + j));
        }
    }

    printf("Values entered are\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf(" %d\t", *(x[i] + j));
        }
        printf("\n");
    }
    return 0;
}