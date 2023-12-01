/*
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

Example:

Input: 13
Output: 6 
Explanation: Digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
*/
//Difficulty: hard
//result: Time limit Exceeded; 4ms; 16/20 test passed :'(
//Date: 4/12/2020    

#include <stdio.h>

int countDigitOne(int n);

int main(){
    printf("Enter a digit\n");
    int num;
    scanf(" %d", &num);
    
    int total_1;
    total_1 = countDigitOne(num);
    
    //printf("%d\n", total_1);
    printf("Input: %d\n", num);
    printf("Output: %d\n", total_1);

    return 0;
}

int countDigitOne(int n){
    
    int single;
    int count = 0;
    int tempI = 0;
    
    for(int i = 1; i <= n; i++){
        tempI = i;
        single = 0;
        while(tempI != 0){
            single = tempI % 10;
            if(single == 1){
                count++;
            }
            tempI = tempI / 10;
        }
    }
    return count;
}

