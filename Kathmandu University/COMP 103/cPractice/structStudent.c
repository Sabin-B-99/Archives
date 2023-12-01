#include<stdio.h>
#include <string.h>

typedef struct std
{
    char name[20];
    //char majorCode[10];
    //int regNo;
    int age;
    //int contactNo;
}student;

int main(){
    int n;
    printf("Total no. of students whose data is to be recorded?\n");
    scanf(" %d", &n);
    student stuRecord[n];
    student stdRecTemp;
    
    //recording students data
    printf("*******************\n");
    printf("For student's data...\n");
    for(int i = 0; i < n; i ++){
        
     printf("Name?: \n");
    scanf(" %s", stuRecord[i].name);


        /*printf("Code of student's major?:\n");
        scanf(" %[^\n]", stuRecord[i].majorCode);

        prinf("Registration Number?: \n");
        scanf(" %d", stuRecord[i].regNo);
    */
        printf("Age?:\n");
        scanf(" %d", &stuRecord[i].age);

      /*  printf("Contact number?:\n");
        scanf(" %d", &stuRecord[i].contactNo);*/
        printf("*************\n");
    }

    //sorting by name
    /*int z;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n - i - 1; j ++){
           z = strcmp(stuRecord[j].name,stuRecord[j+1].name);
           if(z > 0){
            stdRecTemp = stuRecord[j];
            stuRecord[j] = stuRecord[j+1];
            stuRecord[j+1] = stdRecTemp;
           }
    }
  }*/

//sorted list
 /*for(int i = 0; i < n; i++){
        printf(" %s\n", stuRecord[i].name);
    }*/

//sorting by age
for(int i = 0; i < n; i++){
    for(int j = 0; j < n - i -1; j++){
        if(stuRecord[j].age > stuRecord[j+1].age){
            stdRecTemp = stuRecord[j];
            stuRecord[j] = stuRecord[j+1];
            stuRecord[j+1] = stdRecTemp;
        }
    }
}

//printing sorted list by age
for (int i = 0; i < n; i++)
{
    printf(" %d", stuRecord[i].age);
}



}