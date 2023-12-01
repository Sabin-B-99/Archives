#include <stdio.h>
#include <stdint.h>

int32_t factorial(int32_t);

int main(){
    printf("Enter a number to find its factorial\n");
    int32_t num;
    scanf("%d", &num);
    printf("The factorial of %d is: %d", num, factorial(num));
    return 0;
}

int32_t factorial(int32_t n){
    int32_t result = 0;
    if(n == 0){
        result = 1;
    }else{
        result = n * factorial(n-1);
    }
    return result;
}