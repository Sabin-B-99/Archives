/*
This time no story, no theory. The examples below show you how to write function accum:

Examples:

accum("abcd") -> "A-Bb-Ccc-Dddd"
accum("RqaEzty") -> "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"
accum("cwAt") -> "C-Ww-Aaa-Tttt"


The parameter of accum is a string which includes only letters from a..z and A..Z.
*/

//Difficulty: 7kyu
//Result: All test Passed(121) :), Time: 997 ms; 
//Date: 4/14/2020
//overall: Satisfactory

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *accum(const char *source);
char* toLower(char* value);
char* toUpper(char* value);


int main(){

    char* res = NULL;
    res = (char*) malloc(sizeof(char) * 500);
    
    res = accum("NyffsGeyylB");
    printf(" %s\n", res);
    
    return 0;
}

char *accum(const char *source){
    int size;
    size = strlen(source);
    int increase;
    

    char* new = NULL;
    new = (char*)malloc(sizeof(char)*500);
    
    int count;
    count = 0;

   for(int i = 0; i <= size; i++){

        for(int j = 0; j <= i; j++){
            
            if(i == 0){
                *(new + count) = toupper(*(source + i)); //toupper function from <ctype.h> and not the one defined by me
            }else if(*(new + (count - 1)) == '-')
            {
                *(new + count) = toupper(*(source + i));
            }else
            {
                *(new + count) = towlower(*(source + i)); //tolower function from <ctype.h> and not the one defined by me
            }
                       
            count++;
        }
        if(i < (size-1)){
            *(new + count) = '-';
            count++;
        } 
    }
    return new;
}

char* toLower(char* value){
    char* low = NULL;
    low = (char*)malloc(sizeof(char) * (strlen(value) + 1)); //line can be optional, but better to allocate a memory
    low = value;
  
    for(int i = 0; i < strlen(value); i++){
        if(*(value + i) >= 'A' && *(value + i) < 'Z'){
            *(low + i) = *(value + i) + 32;
        }else{
            *(low + i) = *(value + i);
        }
    }
    return low;

    /*
        Remarks: What i learnt here:
                    whenever one passes a literal constant string to a 
                    function like this, its contents cannot be changed
                    and segmentation faluts occurs.
                    here, in main() function, if i had passed in 
                    printf(" %s", toLower("SABIN"));
                    i pass a literal, constant sting in above case "SABIN" and 
                    i wont be able to change its contents. and i will fail
                    or a segmentation fault occurs.
                    Also,
                    this toLower() function doesn't work if i 
                    don't include the line:
                    low = value;
                    for some reason i can't seem to figure out.
                    //Figured out this problem after 5 minutes.
                     and it was basically that:--->
                                        if i don't assign low = value;
                    then when the program reaches the line 
                    *(low + i) = *(value + i) + 32;
                    then the progrm tries to assign this *(value + i) + 32
                    to a memory address that is not defined or not pointed to.
    */
}

char* toUpper(char* value){
    char* up = NULL;
    up = (char*)malloc(sizeof(char) * (strlen(value) + 1)); //line can be optional, but better to allocate a memory
    up = value;
  
    for(int i = 0; i < strlen(value); i++){
        if(*(value + i) >= 'a' && *(value + i) < 'z'){
            *(up + i) = *(value + i) - 32;
        }else{
            *(up + i) = *(value + i);
        }
    }
    return up;
}    


//some other solutions:
/*
#include <malloc.h>
#include <string.h>
#include <ctype.h>

char *accum(const char *source) {
  int len = strlen(source);
  char *str = (char*)malloc(len * (len + 1));
  int i = 0;

  for (int j = 0; j < len; j++, i++) {
    for (int k = 0; k < (j + 1); k++, i++) str[i] = !k ? toupper(source[j]) : tolower(source[j]);
    str[i] = '-';
  }
  str[i-1] = '\0';
  return str;
}


#include <string.h> // for strlen
#include <ctype.h>  // for tolower and toupper
#include <stdlib.h> // for malloc

char *accum(const char *source)
{
  int length = strlen(source);                                        // String Length
  char *str = (char *)malloc(length * (length + 1) / 2 + length);     // Memory Allocation
  int x = 0, y = 1;                                                   // Set counters
  for (int i = 0; i < length; ++i, ++x)                               // Main Loop
  {                                                                   // ----------------- //
    str[x++] = toupper(source[i]);                                    // Uppercase letter  //
    while (y++ == 0) str[x++] = '-';                                  // First "-"         //
    for (int j = 0; j < i; ++j, ++x) str[x]=tolower(source[i]);       // Lowercase letters //
    if (i != strlen(source)-1)  str[x] = '-';                         // All others "-"    //
  }                                                                   // ----------------- //
  return str;
}

char *accum(const char *sc) {
  int s = (3 + strlen(sc)) * strlen(sc) / 2;
  char* str = malloc(s);
  for (int i = 0, sci = 0; i < s; i++, sci++) {
    str[i] = toupper(sc[sci]);
    for (int j = 0; j < sci; j++) {
      str[++i] = tolower(sc[sci]);
    }
    str[++i] = '-';
  }
  str[s - 1] = '\0';
  return str;
}

*/