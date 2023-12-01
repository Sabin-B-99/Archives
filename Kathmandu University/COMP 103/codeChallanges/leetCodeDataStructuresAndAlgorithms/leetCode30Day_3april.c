/*
Given an integer array nums, find the contiguous subarray 
(containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Follow up:
If you have figured out the O(n) solution, 
try coding another solution using the divide and conquer approach, 
which is more subtle.
*/
#include <stdio.h>

int maxSubArray(int* nums, int numsSize);

int main(){
    int arrA[9] = {-2,1,-3,4,-1,2,1,-5,4};
    int res;
    int size;
    res = maxSubArray(arrA, size);
    printf("max is: %d\n", res);

    return 0;
}

int maxSubArray(int* nums, int numsSize){
       
}

