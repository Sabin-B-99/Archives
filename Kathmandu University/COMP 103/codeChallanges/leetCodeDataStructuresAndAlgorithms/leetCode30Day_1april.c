/*
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:
Input: [2,2,1]
Output: 1

Example 2:
Input: [4,1,2,1,2]
Output: 4
*/
//Runtime: 1024ms, runtime beats only 8.39% total submissions :'(
//Result: Accepted

//Remarks: during first submission 15/16 cases passed
//         falied case was that i didn't check for when the 
//         single value was 0; i.e. input: [1,0,1]
//Date: 4/13/2020

//Overall Below Average :'(
#include <stdio.h>

int singleNumber(int* nums, int numsSize);

int main(){
    int arrA[11] = {2,1,2,1,4,3,3,7,4,8,8};
    int arrB[3] = {2,0,2};

    int sizeA;
    sizeA = sizeof(arrA)/sizeof(int);
    int sizeB;
    sizeB = sizeof(arrB)/sizeof(int);

    int resArrA = singleNumber(arrA, sizeA);
    int resArrB = singleNumber(arrB, sizeB);
    
    printf("For first Array: %d\n", resArrA);
    printf("For second Array: %d\n", resArrB);
    return 0;
}

int singleNumber(int* nums, int numsSize){
    
    for (int i = 0; i < numsSize; i++)
    {
        for(int j = 0; j < i; j++){
            if(*(nums+i) == *(nums+j)){
                *(nums+i) = 0;
                *(nums+j) = 0;
            }      
        }
    }    
   
    for (int i = 0; i < numsSize; i++)
    {
        if (*(nums+i) != 0)
        {
            return *(nums+i);
        }
    }
    return 0;
}


//Sample 0ms submission
// int singleNumber(int* nums, int numsSize){
//     int sum=0, i=0;
//     for (i=0; i<numsSize; i++){
//         sum ^= nums[i];
//     }
//     return sum;
// }


//sample 8ms submission (most common)
// int singleNumber(int* nums, int numsSize){
//     int temp=nums[0];
//     for(int i=1;i<numsSize;i++)
//     {
//         temp=temp^nums[i];
//     }
//     return temp;
// }

//used bitwise Exclusive OR (XOR) operator  ^ 
/*
The result of bitwise XOR operator is 1 if the corresponding bits of two operands are opposite. It is denoted by ^.

12 = 00001100 (In Binary)
25 = 00011001 (In Binary)

Bitwise XOR Operation of 12 and 25
  00001100
^ 00011001
  ________
  00010101  = 21 (In decimal)
*/