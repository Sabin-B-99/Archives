#include <stdio.h>

void perfectNums(int nthVal);

int main(){
    int num;
    printf("Please enter the nth value\n");
    scanf(" %d", &num);

    perfectNums(num);
    return 0;
}

void perfectNums(int nthVal){
    int temp1;
    int sum;

    for(int i = 1; i <= nthVal; i++){
        temp1 = 0;
        sum = 0;
        for(int j = 1; j < i; j++){
            temp1 = i % j;
            if(temp1 == 0){
                sum += j;
            }
        }
        if(sum == i){
            printf(" %d", sum);
        }
    }
}