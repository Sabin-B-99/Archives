#include <stdio.h>
int main(){
    printf("Please enter a number?\n");
    int n;
    scanf(" %d", &n);
    int count;
    count = 0;

    for(int i = 2; i < n; i++){
        if(n % i == 0){
            count += 1;
        }
    }

    if(n == 1){
        printf("The number is neither prime nor composite\n");
    }else{
        if(count != 0){
            printf("The number is not prime.\n");
        }else{
            printf("The number is prime.\n");
        }
    }
    
    return 0;
}