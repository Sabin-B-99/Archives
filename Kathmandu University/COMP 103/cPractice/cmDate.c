#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkMonth(char* monthInWords, int n);

struct date{
    int day;
    int month;
    int year;
};

int main(){
   
   struct date d1;
   
   printf("Please enter date in a single line & seperate them with space.\n");
   printf("MM/DD/YYYY:?\t");
   scanf("%d %d %d", &d1.month, &d1.day, &d1.year);
   
   char* monthWord = NULL;
   monthWord = (char*) malloc(sizeof(char) * 20);

   checkMonth(monthWord, d1.month);

   if(d1.month >= 1 && d1.month <= 12){
       printf("%s %d, %d\n", monthWord, d1.day, d1.year);
   }else{
       printf("%s", monthWord);
   }


   return 0;
}

void checkMonth(char* monthInWords, int n){
    switch (n)
    {
    case 1: strcpy(monthInWords, "Janurary");
        break;
    case 2: strcpy(monthInWords, "Feburary");
        break;
    case 3: strcpy(monthInWords,"March");
        break;
    case 4: strcpy(monthInWords,"April");
        break;
    case 5: strcpy(monthInWords, "May");
        break;
    case 6: strcpy(monthInWords,  "June");
        break;
    case 7: strcpy(monthInWords,"July");
        break;
    case 8: strcpy(monthInWords,"August");
        break;
    case 9: strcpy(monthInWords,"September");
        break;
    case 10: strcpy(monthInWords,"October");
        break;
    case 11: strcpy(monthInWords,"November");
        break;
    case 12: strcpy(monthInWords,"December");
        break;
    default:
            strcpy(monthInWords,"ERROR: Wrong Format");
    }
}