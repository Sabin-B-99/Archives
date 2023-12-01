/*
Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: 
Starting with any positive integer, replace the number by the sum of the squares of its digits, 
and repeat the process until the number equals 1 (where it will stay), 
or it loops endlessly in a cycle which does not include 1. 
Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example: 

Input: 19
Output: true
Explanation: 
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
*/
/*
    Runtime: 0ms, Memory Usage: 4.9MB, 401/401 test cases passed, runtime beats 100% of submissions
    Result: Accepted

    Remarks: During the first try, tried to complete the program using 
             recursion, got a runtime error(stack overflow). pased only 1 case of 401 cases. Still need a lot of 
             practise, and need to think of the problem first out before 
             starting to code. Seen to code without thinking abount the problem 
             in hand(hit and trial). Was near solving many times but beacuse of the 
             negligence remarked above just didn't see the soln in front of the eyes.

    Date: 4/14/2020  
*/
//Overall: Satisfactory. :|

#include <stdio.h>
#include <stdbool.h>
#include <math.h>


bool isHappy(int n);
int main(){
    int num;
    printf("Enter a number\n");
    scanf(" %d", &num);

    bool res;
    res = isHappy(num);

    if(res){
        printf("Happy!\n");
    }else
    {
        printf("Sad!\n");
    }
    
    return 0;
}

bool isHappy(int n){
    int sum;
    sum = 0;
    int single;
    int count;
    count = 0;
   while (true)
   {
        while (n != 0){
        single = n % 10;
        sum += pow(single, 2);
        n = n / 10;
        }
        if(sum == 1){
            return true;
        }else
        {   
            count++;
            if(count > 50){
                break;
            }
            n = sum;
            sum = 0;
        }
   }
   return false;
}






/*
Sample: 4ms Submissions

#include<stdio.h> 
#include<stdbool.h>
#include<math.h>

bool isHappy(int n){
	int* cache = (int*) calloc(1000, sizeof(int));
	int sum, n2;
	n2 = n;
	do{
		sum = 0;
		while(n2 > 0){
			sum += pow(n2 % 10,2);
			n2 /= 10;
		}
		
		if(sum == 1) {
			return true;
		}
		
		int idx = (sum % 1000);
		while(cache[idx] > 0 && cache[idx] != sum) idx = (idx + 1) % 1000;
		
		if(cache[idx] == 0){
			cache[idx] = sum;
		}else{
			return false;
		}
		
		n2 = sum;
	}while(true);
	
	return false;	
}


Sample: 0ms submissions

bool isHappy(int n){
    int tmp = 0;
    for(int i=0;i<100;i++){
        tmp = 0;
        while(n){
            tmp = tmp + (n%10)*(n%10);
            n/=10;
        }
        if(tmp==1)  return true;        
        n = tmp;
    }
    
    return tmp==1;
}


*/