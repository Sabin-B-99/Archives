#include <stdio.h>

void fibonacciNums(int val1, int val2, int nth);

int main(){
    int num1;
    int num2;
    int nthVal;

    printf("Please enter the first value in the series\n");
    scanf(" %d", &num1);
    printf("Please enter the second value in the series\n");
    scanf(" %d", &num2);
    printf("Please enter the nth value in the series\n");
    scanf(" %d", &nthVal);

    fibonacciNums(num1, num2, nthVal);
    return 0;
}

void fibonacciNums(int val1, int val2, int nth){

    printf(" %d %d", val1, val2);
    
    
    int sum;
    for(int i = 1; i <= (nth - 2); i++){
        sum = val1 + val2;
        val1 = val2;
        val2 = sum;
        printf(" %d", val2);
    }
}