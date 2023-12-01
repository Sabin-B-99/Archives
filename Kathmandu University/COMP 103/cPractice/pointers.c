#include <stdio.h>
int main(){
    int m = 5;
    int* p = NULL;
    p = &m;
    printf(" m = %d\n", m);
    printf("m's memory location = %x\n", p);
    printf("m = *p == %d\n",*p);
    *p = 8;
    printf("*p has been changed to %d\n", *p);
    int z = *p;
    int* ptr = NULL;
    ptr = &z;
    printf("new z variable value = %d", z);
    printf("z's memory address = %x\n", ptr);

    double num1 = 5.0;
    double *p1; 
    p1 = &num1;
    *p1 = 7;
    printf("Size of double-pointer: %d\n", sizeof(p1));
    printf("Size of double-pointer: %d\n", sizeof(&p1));
    printf("Size of pointer-type: %d\n", sizeof(*p1));
    printf("Value pointed: %lf\n", *p1);
    printf("Size of double: %d\n", sizeof(double));
    return 0;
}