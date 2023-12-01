#include <stdio.h>
#include <stdbool.h>

bool leapYear(int year);

int main(){
    
    printf("Enter year\n");
    int year = 0;
    scanf(" %d", &year);

    bool res = leapYear(year);
    
    if(res){
        printf("It is a leap year.");
    }else
    {
        printf("It is not a leap year");
    }

    return 0;
}

bool leapYear(int year){
    if(year % 4 == 0 && year % 100 == 0 && year % 400 != 0){
        return false;
    }else if(year % 4 == 0)
    {
        return true;
    }else
    {
        return false;
    }
}