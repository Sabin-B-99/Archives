/*
You are given an odd-length array of integers, in which all of them are 
the same, except for one single number.

Complete the method which accepts such an array, 
and returns that single different number.

The input array will always be valid! (odd-length >= 3)

Examples
[1, 1, 2] ==> 2
[17, 17, 3, 17, 17, 17, 17] ==> 3
[4,5,5,6,4] ==> 6
*/
//Date: 4/16/2020
//Had already done this before
//Difficulty: 7kyu

#include <stdio.h>

int single(int* a, int size);

int main(){
    int arrA[5] = {2,1,8,1,2};
    int arrB[3] = {14,3,14};

    int sizeA;
    sizeA = sizeof(arrA)/sizeof(int);

    int sizeB;
    sizeB = sizeof(arrB)/sizeof(int);

    printf("Single number in the array of size %d is: %d\n", sizeA,single(arrA,sizeA));
    printf("Single number in the array of size %d is: %d\n", sizeB,single(arrB,sizeB));
}

int single(int* a, int size){
    int singleNum;
    singleNum = 0;
    for(int i = 0; i < size; i++){
        singleNum ^= *(a + i);
    }

    return singleNum;
}