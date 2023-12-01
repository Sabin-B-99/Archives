/*
Introduction:
 	The wave (known as the Mexican wave in the English-speaking world outside 
     North America) is an example of metachronal rhythm achieved in a packed 
     stadium when successive groups of spectators briefly stand, yell, 
     and raise their arms. Immediately upon stretching to full height, 
     the spectator returns to the usual seated position.

    The result is a wave of standing spectators that travels through the crowd,
    even though individual spectators never move away from their seats.
    In many large arenas the crowd is seated in a contiguous circuit all the way 
    around the sport field, and so the wave is able to travel continuously around
    the arena; in discontiguous seating arrangements, the wave can instead 
    reflect back and forth through the crowd. When the gap in seating is narrow, 
    the wave can sometimes pass through it. Usually only one wave crest will 
    be present at any given time in an arena, although simultaneous, 
    counter-rotating waves have been produced. (Source Wikipedia)

 

Task:
In this simple Kata your task is to create a function that turns a string into 
a Mexican Wave. You will be passed a string and you must return that string in an 
array where an uppercase letter is a person standing up.

Rules:
1.  The input string will always be lower case but maybe empty.
2.  If the character in the string is whitespace then pass over it as if 
    it was an empty seat.

Example
wave("hello") => []string{"Hello", "hEllo", "heLlo", "helLo", "hellO"}
*/
//Difficulty: 6kyu
//Result: 812 ms , passed all the test.
//Date: 4/16/2020
//overall: content. :) performance wise
//         Damn this was hard one, well atleast for me. 


//Remarks: if them strings are too long, i mean wayyy  toooo long the there 
//         may occur memory allocation problem in the subroutine and
//         sometimes program maynot behave as expected

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void wave(const char *y, char **target);

int main(){
    char** value1 = NULL;
    value1 = (char**)malloc(30);

    char** value2 = NULL;
    value2 = (char**)malloc(30);

    char** value3 = NULL;
    value3 = (char**)malloc(30);

    wave("hello", value1);
    wave(" sab i n", value2);
    wave(" gap ", value3);

    free(value1);
    free(value2);
    free(value3);

    return 0;
}



void wave(const char *y, char **target)
{
    int size;
    size = strlen(y);

    char stand;//later used to store that standing(uppercase) letter which sebsequently 
                //will be tied together with other members of the words
    

    char* words = NULL; //words (Hello, hEllo, ...) temporarily stored before assigning it to target
    words = (char*)malloc(size + 1);    
    strcpy(words,y);
    
    int targIndex;
    targIndex = 0;

    for(int i = 0; i < size; i++){
    
       if(*(y + i) == ' '){
            continue; //when an white space is found it is discarded
        }

        //wave member created(first creates Hello, then stores it in target, when loop ends
        //and again creates hEllo,..and so on...)
        //(characters strung together and stored in words temporarily )
        for (int j = 0; j < size; j++)
        {
            *(words + j) = *(y + j);
            if(i == j){
                stand =  toupper(*(y + i));
                *(words + j) = stand;
            }
        }

        //that temporary word from above loop is aggigned to target
        *(target + targIndex) = words; //this line should be: strcpy(*(target + targIndex), words); in codeWars other wise it wont compile and i don't know why
        printf(" %s\n", *(target + targIndex));
        targIndex++;
    }
    printf("************************\n");
    free(words);
}

/*
Sample 1:
void wave(const char *y, char **target)
{
  for (int i = 0, k = 0, j = 0, y_sz = strlen(y); i < y_sz; i++)
  {
    if (isalpha(y[i]))
    {
       memcpy(target[j], y, y_sz);
       if (i != 0) target[j][k] = tolower(target[j][k]);
       target[j][i] = toupper(target[j][i]);
       k = i;
       j++;
    }
  }
}

Sample 2:
void wave(char *y, char **target)
{
  for (char i = 0, *p = y; *p; ++p) {
    if (*p != ' ') {
      strcpy(target[i], y);
      target[i++][p-y] = toupper(*p);
    }
  }
}

Sample 3:
void wave(char *y, char **target)
{
  char *tmp = (char *)malloc(strlen(y+1));
  strcpy(tmp, y);
  
  for(int i = 0, j = 0; i < strlen(y); i++)
  {
    if(tmp[i] < 97 || tmp[i] > 122)
      continue;
    
    tmp[i] = toupper(y[i]);
    strcpy(target[j++], tmp);
    tmp[i] = tolower(y[i]);
  }
  
  free(tmp);
}
*/

