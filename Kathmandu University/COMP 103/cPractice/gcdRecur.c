#include <stdio.h>
int computeGfc(int x, int y);
int main(){
    int a;
    int b;
    printf("Enter first number\n");
    scanf(" %d", &a);
    printf("Enter second number\n");
    scanf(" %d", &b);

    int hcf;
    hcf = computeGfc(a,b);
    printf("HCF is %d\n",hcf);
    return 0;
}

int computeGfc(int x, int y){
    //uses--> elucid algorithm to coputer gfc
    if(y != 0){
        return computeGfc(y, x % y);
    }else{
        return x;
    }
}