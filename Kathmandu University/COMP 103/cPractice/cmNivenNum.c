#include <stdio.h>
int checkIfNiven(int num);
int sumOfDigit(int n);

int main(){
    int a;
    printf("Please enter a number?\n");
    scanf(" %d", &a);
    int val;
    val = checkIfNiven(a);

    if(val == 1){
        printf("The given number is a niven number\n");
    }else{
        printf("The given number is a not a niven number\n");
    }
    
    return 0;
}

int checkIfNiven(int num){
    int temp;
    int sum;
    sum = sumOfDigit(num);
    if(num % sum == 0){
        return 1;
    }else
    {
        return 0;
    }
}

int sumOfDigit(int n){
    int temp1;
    int sum;
    sum = 0;
    while(n != 0 ){
        temp1 = n % 10;
        sum += temp1;
        n = n / 10;
    }
    printf(" %d\n", sum);
    return sum;
}
