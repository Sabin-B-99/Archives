#include "myString.h"
#include <stdio.h>

int main(void){
    printf("Enter a string:\n");
    String name = readString(stdin);
    printf("You entered: %s\n", name);
    return 0;
}