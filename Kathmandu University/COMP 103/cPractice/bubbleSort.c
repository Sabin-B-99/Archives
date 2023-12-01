#include <stdio.h>
int main(){
    int n;
    printf("Enter the number of elements to be sorted\n");
    scanf(" %d", &n);

    int temp;
    int elem[n];

    printf("Enter elements to be sorted\n");

    for(int i = 0; i < n; i++){
        scanf(" %d", &elem[i]);
    }

    //bubble sort
    for(int i = 0 ; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(elem[j] > elem[j+1]){
                temp = elem[j];
                elem[j] = elem[j+1];
                elem[j+1] = temp;            }
        }
    }

    printf("Sorted List\n");
    for(int i = 0; i < n; i++){
        printf(" %d", elem[i]);
    }
}