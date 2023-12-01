/*
Simple, given a string of words, 
return the length of the shortest word(s).

String will never be empty and you do not need to 
account for different data types.

*/
//Difficulty: 7kyu
//Result: All test Passed(61) :), Time: 896 ms; 
//Date: 4/15/2020
//overall: Unsatisfactory for myself. :'(
//Remarks: still need to improve in thinking the problem on pen and paper rather than
//         attempeting on the computer. use less of the hit and tiral
//         did this inside the while(true) part below
//         took about 3 hrs to complete this code. so had i sketched out
//         the problem on paper first, then it might have taken a lot less time



#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


ssize_t find_short(const char *s);

int main(){
    char* word;
    word = (char*)malloc(sizeof(char) * 100);
    word = "b take over the world maybe who knows pheraphs";

    ssize_t lengthShort;
    lengthShort = find_short(word);

    printf("Length of the shortest word is: %d\n", lengthShort);
    return 0;
}



ssize_t find_short(const char *s)
{
    int size;
    size = strlen(s);
    int count;
    count = 0; //count = 1;
    int eachCount;
    eachCount = 0;
    int noOfSpaces;
    noOfSpaces = 0;

    //counting the total no of spaces in the text
    for (int i = 0; i < size; i++)
    {
        if(*(s+i) == ' ' || *(s + i) == '\0'){
            noOfSpaces++; 
        }
    }

    int j;
    j = 0; 

    int eachWordLen[noOfSpaces+1];  //array that stores length of each word
    

    // while (*s != '\0')
    // {
    //     s++;
    //     count++;
    //     if(*s == ' ' || *s == '\0'){
    //         eachCount = count - 1; //count length of each word
    //         printf(" %d\n", eachCount);
    //         eachWordLen[j] = eachCount; //storing legth of each word
    //         count = 0;
    //         j++;
    //     }
    // }

    while (true)
    {
        count++;    
        if(*s == ' ' || *s == '\0'){
            eachCount = count - 1; //count length of each word
            eachWordLen[j] = eachCount; //storing legth of each word
            count = 0;
            j++;
        }
        if(*s == '\0'){
            break;
        }
        s++;
    }
    

    //sort into ascending 
    int temp;
    for(int i = 0 ; i < (noOfSpaces+1) - 1; i++){
        for(int k = 0; k < (noOfSpaces+1) - i - 1; k++){
            if(eachWordLen[k] > eachWordLen[k+1]){
                temp = eachWordLen[k];
                eachWordLen[k] = eachWordLen[k+1];
                eachWordLen[k+1] = temp;            
            }
        }
    }

    
    return eachWordLen[0]; //returns the first elment that is the length of the smallest word
}


/*
Sample 1:

#include <sys/types.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>

ssize_t find_short(const char *s)
{
    int min = INT_MAX;
    char delim[] = " ";
    char *token = strtok((char*)s, delim);
    while(token != NULL) {
        int len = (int)strlen(token);
        if (min > len)
            min = len;
        token = strtok(NULL, delim);
    }
    return min;
}


Sample 2:

#include <sys/types.h>
#include <string.h>
#include <ctype.h>

ssize_t find_short(const char *s)
{
    int min, length;
    min = length = strlen(s);
    int temp = 0;
    
    for(int i=0; i <= length; i++){
        if(isspace(s[i]) || (s[i] == '\0') ){
            if(temp < min) min = temp;
            temp = 0;
        }
        else temp++;
    }
    return min;
}

Sample 3:

#include <sys/types.h>
#include <string.h>

void check_if_less_found(int *s, int *c){
  if(*c < *s || *s == 0)
    *s = *c;
  *c = 0;
}

ssize_t find_short(const char *s){
  int curr = 0, shortest = 0;

  while(*s != '\0'){
    if(*s == ' ') check_if_less_found(&shortest, &curr);
    else curr++;
    s += sizeof(char);
  }
    
  check_if_less_found(&shortest, &curr);
  return shortest;
}


Sample 4:

#include <sys/types.h>
#include <stdint.h>

ssize_t find_short(const char *s)
{
  uint8_t res = -1; 
  uint8_t wrd = 1;
  
  do {
    s++;
    
    for(; *s && *s != ' '; s++) {
       wrd++; 
    }
    
    if (wrd == 1) {
      return 1;
    }
    
    if(wrd < res) {
      res = wrd;
    }
    
    wrd = 0;
  } while (*s);
  
  return res;
}
*/