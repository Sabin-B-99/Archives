#include <stdio.h>
void primeCheck(int n);

int main(){
    int n;
    printf("Please enter a positive number\n");
    scanf(" %d", &n);
    
    primeCheck(n);
    return 0;
}

void primeCheck(int n){
    int count;
    count = 0;
    for(int i = 2; i < n/2; i++){
        if(n % i == 0){
            count = 1;
        }
    }

    if(n == 1){
        printf("The number is neither prime nor composite\n");
    }else
    {
        if(count != 0){
            printf("The number is not prime\n");
        }else{
            printf("The number is prime\n");
        }
    }
    
}
























//main()
//{
   /* val = primeCheck(n);
    if(val == 1){
        printf("The number is not prime\n");
    }else if(val == 0){
        printf("The number is prime\n");
    }else{
        printf("The number is neither prime nor composite\n");
    }
*/
//}


/*int primeCheck(int n){
    int count;
    count = 0;
    for(int i = 2; i < n/2; i++){
        if(n % i == 0){
            count = 1;
        }
    }

    if(n == 1 || n < 1){
        return -1;
    }

    return count;
}*/