#include <stdio.h>
void merge(int arr[], int low,int high, int mid,int auxArr[]);
void sort(int arr[], int size);
void sortArr(int arrA[], int low, int high, int auxArr[]);
//Incomplete

int main(){
    int arrA[10] = {-1,3,0,-4,8,12,9,10,2,6};

    int size;
    size = sizeof(arrA) / sizeof(arrA[0]);

    sort(arrA, size);

    for (int i = 0; i < size; i++)
    {
        printf(" %d\n", arrA);
    }
    

    return 0;
}

void sort(int arr[], int size){
    int aux[size];
    int lo = 0;
    int hi = size;
    sortArr(arr,lo,hi, aux);
}

void sortArr(int arrA[], int low, int high, int auxArr[]){
    int mid;
    int N = high - low;
    
    if(N <= 1) return;
    mid = low + N / 2;

    sortArr(arrA,low,mid,auxArr);
    sortArr(arrA,mid + 1,high,auxArr);
    merge(arrA,low,high,mid, auxArr);
}

void merge(int arr[], int low,int high, int mid,int auxArr[]){

    int i = low;
    int j = mid;
    int N = high - low;
    
    for (int k = 0; k < N; k++)
    {
        if (i == mid)
        {
            auxArr[k] = arr[j]; 
            j++;
        }else if( j == high)
        {
            auxArr[k] = arr[i];
            i++; 
        }else if(arr[j] < arr[i])
        {
            arr[k] = arr[i];
            i++;
        }else
        {
            arr[k] = arr[j];
            j++;
        }    
    }

    for (int k = 0; k < N; k++)
    {
        arr[k] = auxArr[k];
    }
}