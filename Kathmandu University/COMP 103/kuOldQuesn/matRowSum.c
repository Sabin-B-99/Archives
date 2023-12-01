//this is my quicky bodged up code

#include <stdio.h>

int main(){
    int mattA[4][4];

    //Getting input from user
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("Enter element matA[%d][%d] of the matrix:\n", (i+1),(j+1));
            scanf(" %d", &mattA[i][j]);
        }
    }
    
    int sum;

    //sum and print the rows
    for (int i = 0; i < 4; i++)
    {
        sum = 0;
        for (int j = 0; j < 4; j++)
        {
            sum += mattA[i][j];
            printf(" %d\t", mattA[i][j]);            
        }
        printf("Sum =  %d\n", sum);
    }
    
    return 0;

}