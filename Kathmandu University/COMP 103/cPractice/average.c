#include <stdio.h>
#include <stdlib.h>

void readValues(float* elem, float noElem);
float average(float* elem, float noElem);

int main(){
    float n;
    printf("Enter the total number of elements?\n");
    scanf(" %f", &n);

    float* arrA = NULL;
    arrA = (float*) malloc(sizeof(float)*n);

    readValues(arrA, n);
    float avg = 0;
    avg = average(arrA,n);

    printf("The average is: %.2f\n", avg);

    free(arrA);
    return 0;
}

void readValues(float* elem, float noElem){
    printf("Now, Enter the numbers\n");
    for(int i = 0; i< (int)noElem; i++){
        printf("Number[%d]? ", (i+1));
        scanf(" %f", (elem + i));
    }
}


float average(float* elem, float noElem){
   float sum;
   sum = 0;
   for(int i = 0; i < (int)noElem; i++){
       sum += *(elem + i);
   }
   return sum / noElem; 
}