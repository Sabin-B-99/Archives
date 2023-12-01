// Dudeney num = 19683 = 27^3 and 1 + 9 + 6 + 8 + 3 = 27

#include <stdio.h>
#include <math.h>

int checkDudeney(int num);
int sumDigit(int n);

int main(){
    int a;
    printf("Enter a number\n");
    scanf(" %d", &a);

    int val;
    val = checkDudeney(a);

    if(val == 1){
        printf("The number is a dudeney\n");
    }else
    {
        printf("The number is not a dudeney\n");
    } 
    return 0;
}

int checkDudeney(int num){
    int sumInd;
    sumInd = sumDigit(num);
    int cube;
    cube = sumInd * sumInd * sumInd;
    if(cube == num){
        return 1;
    }else{
        return 0;
    }
}

int sumDigit(int n){
    int temp;
    int sum;
    sum = 0;
    
    while (n != 0)
    {
        temp = n % 10;
        sum += temp;
        n = n / 10;
    }

    return sum;
}