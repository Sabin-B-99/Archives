#include <stdio.h>
#include <stdint.h>

int32_t fibonacci(int32_t num);

int main(){
    printf("Enter a number:\n");
    int32_t num;
    scanf("%d", &num);
    int res = fibonacci(num);
    printf("The fibonacci sum of first %d natural numbers is: %d\n", num, res);
    return 0;
}

int32_t fibonacci(int32_t num){
    int32_t result = 0;
    if(num < 2){
        result = num;
    }else{
        result = fibonacci(num - 2) + fibonacci(num - 1);
    }
    return result;
}