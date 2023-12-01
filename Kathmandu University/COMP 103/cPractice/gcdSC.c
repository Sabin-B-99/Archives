#include <stdio.h>

int main() {
    int a;
    int b;
    int c;

    printf("Enter first number\n");
    scanf(" %d", &a);

    printf("Enter second number\n");
    scanf(" %d", &b);

    int temp1;
    int temp2;

    int gcd;
    gcd = 1;

    if(a > b){
        c = a;
    }else{
        c = b;
    }

    for(int i = 1; i <= c; i ++){
        temp1 = a % i;
        temp2 = b % i;

        if(temp1 == 0 && temp2 ==0){
            gcd = i;
        }
    }

    printf("The Greatest Common Factor = %d\n", gcd);
    return 0;
}