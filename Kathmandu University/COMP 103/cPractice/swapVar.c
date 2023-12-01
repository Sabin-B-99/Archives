#include <stdio.h>
void swap (int* x, int* y);
int main(){
    int a;
    int b;

    int* p = NULL;
    int* q = NULL;
    
    p = &a;
    q = &b;

    printf("Please enter the first number\n");
    scanf(" %d", &a);
    printf("Please enter the second number\n");
    scanf(" %d", &b);

    printf("\n\n");
    printf("Currently first number 'a' is = %d\n", a);
    printf("Currently second number 'b' is = %d\n", b);
    printf("\n\n");

    swap(p,q);

    printf("Swap function has been called.\n");
    printf("\n\n");
    printf("Variable 'a' has been changed to %d\n", a);
    printf("Variable 'b' has been changed to %d\n", b);
    return 0;
}

void swap (int* x, int* y){
    int temp;
    temp =  *x;
    *x = *y;
    *y = temp;
}