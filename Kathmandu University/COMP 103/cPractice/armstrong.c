#include <stdio.h>
#include <math.h>

void armstrongSeries(int nthVal);
int numDigit(int val);

int main(){

   int num;
   printf("Please enter the nth number\n");
   scanf(" %d", &num);

   armstrongSeries(num);
   return 0;
}

void armstrongSeries(int nthVal){
   int temp1;
   int temp2;
   int sum;
   for(int i = 1; i <= nthVal; i++){
       temp1 = i;
       temp2 = 0;
       sum = 0;
       while( temp1 != 0){
           temp2 = temp1 % 10;
           sum += pow(temp2, numDigit(i));
           temp1 = temp1 / 10;
       }
       if(sum == i){
           printf(" %d", sum);
       }
   }
}

//function to count total number of digit in a given number
int numDigit(int val){
    int count; 
    count = 0;
    while(val != 0){
        val = val / 10;
        count++;
    }
    return count;
}