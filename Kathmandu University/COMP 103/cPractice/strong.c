#include <stdio.h>

int factorial(int val);
void strongNUms(int nthVal);

int main(){
    int num;
    printf("Please enter the nth value\n");
    scanf(" %d", &num);

    strongNUms(num);
    return 0;
}

void strongNUms(int nthVal){
    int temp1;
    int temp2;
    int sum;
    for(int i = 1; i <= nthVal; i++){
        temp1 = i;
        sum = 0;
        temp2 = 0;
        while(temp1 != 0){
            temp2 = temp1 % 10;
            sum += factorial(temp2);
            temp1 = temp1 / 10;
        }
        if(sum == i){
            printf(" %d", sum);
        }
    }

}

int factorial(int val){
    int result = 1;
    for(int i = val; i >= 1; i--){
        result *= i; 
    }
    return result;
}