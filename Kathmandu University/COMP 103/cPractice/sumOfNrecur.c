#include <stdio.h>

int addN(int nthVal);
int main(){
    int n;
    
    printf("Enter the nth natural no.\n");
    scanf(" %d", &n);

    int sum;
    sum = addN(n);
    printf("The sum of first n natural no = \n");
    printf(" %d", sum);
    return 0;
}

int addN(int nthVal){
   if(nthVal == 1){
       return 1;
   }else
   {
       return nthVal + addN(nthVal-1);
   }
}
