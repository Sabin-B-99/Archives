#include <stdio.h>
int factorial(int n);
int main(){
    int val;
    printf("Enter the number\n");
    scanf(" %d", &val);
    int ans;
    ans = factorial(val);
    printf("The factorial is\n");
    printf(" %d", ans);
}

int factorial(int n){
    if(n == 0){
        return 1;
    }else{
        return n *factorial(n-1);
    } 
}