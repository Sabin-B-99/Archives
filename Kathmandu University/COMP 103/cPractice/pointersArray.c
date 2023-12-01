#include<stdlib.h>
#include<stdio.h>

int main(){
    int* x;
    x = (int*)malloc(10*sizeof(int));
    printf("Please enter the numbers in array\n");
    
    for(int i = 0; i < 10; i++){
        printf("elem[%d] = ", (i+1));
        scanf(" %d", (x + i));
    }

    printf("Entered numbers are:\n");
    for(int i = 0; i < 10; i++){
        printf(" %d", *(x + i));
    }
    free(x);
    return 0;
}