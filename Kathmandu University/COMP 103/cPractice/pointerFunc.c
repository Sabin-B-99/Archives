#include <stdlib.h>
#include <stdio.h>

void readVal(int* e, int n);
void printVal(int* e, int n);

int main(){
   int* x = NULL;
   int a;
   printf("How many elements are there in your array?\n");
   scanf(" %d", &a);
   x = (int*)malloc(a*sizeof(int));
   
   readVal(x, a);
   printVal(x, a);

   free(x);
   return 0;
}

 void readVal(int* e, int n){
     printf("Please enter the elements in this one dim array\n");
     for(int i = 0; i < n; i++){
         printf(" elem[%d] ", (i+1));
         scanf(" %d", (e + i));
     }
 }

 void printVal(int* e, int n){
     printf("Entered data are:\n");
     for(int i = 0; i < n; i++){
         printf(" %d\t", *(e + i));
     }
 }