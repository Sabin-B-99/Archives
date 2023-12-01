#include <stdio.h>
#include <stdlib.h>
void readVal(int* arr, int len);
void reOrder(int* arr, int size);
void display(int* arr, int size);

int main(){
    int* arrA;
    int n;
    printf("Enter number of elements to be stored\n");
    scanf(" %d", &n);
    arrA = (int*) malloc(sizeof(int)*n);
    readVal(arrA, n);
    reOrder(arrA,n);
    display(arrA,n);
    return 0;    
}

void readVal(int* arr, int len){
    for(int i = 0; i < len; i++){
        printf(" element[%d] = ", (i+1));
        scanf(" %d", (arr + i));
    }
}

void reOrder(int* arr, int size){
    int temp;
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i -1; j++){
            if(*(arr + j) > *(arr + (j +1))){
                temp = *(arr + j);
                *(arr + j) = *(arr + (j+1));
                *(arr+(j+1)) = temp;
            }
        }
    }
}

/*int computeAverage(int* arr, int size){
    int sum;
    sum = 0;
    for(int i = 0; i < size; i++){
        sum += *(arr + i);
    }
    return sum / size;
    
}*/

void display(int* arr, int size){
    for(int i = 0; i < size; i++){
        printf(" %d", *(arr +i));
    }
}