#include <stdio.h>
#include <stdlib.h>
#include "StringType.h"

int main(void){
    printf("Enter a word\n");
    String name = readString(stdin);
    printf("%s\n", name);
}