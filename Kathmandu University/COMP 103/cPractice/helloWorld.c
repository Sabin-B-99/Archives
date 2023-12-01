#include <stdio.h>
int main()
{
    printf("Hello World!\n");
    int a = 6;
    int b = 7;
    int c = 8;
    int temp = -1;
    int marks;
    int result = a > b ? (a > c ? a : c) : (b > c ? b : c); //max of three
    do{
        printf("Please enter the marks of the student or 999 to exit.\n");
        scanf(" %d", &marks);
        if(marks == 999){
            printf("Thanks\n ");
            printf("Exiting...\n");
            printf("****************************************************************************\n");
            break;
        }
        if(marks < 0 || marks > 100){
            printf("Please enter a value ranging from [0 - 100]\n");
            continue;
        }
        printf("Processing\n"); 
        printf("Data Saved!!\n");
        printf("**********************************************************************************\n");
    }while(temp == -1);
    return 0;
}