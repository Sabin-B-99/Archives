#include <stdio.h>
#include <string.h>

typedef char* String;

int main(){
    String name = "Sabin asdjashdaksjgvfiasdo";
    String name1;
    printf("Enter name\n");
    scanf(" %[^\n]", name1);
    int a = strlen(name1);
    printf(" %d\n", a);

    printf(" %s", name1);

    return 0;
}



