#include <stdio.h>

struct student{
    char name[20];
    int contactNo;
    int age;
    char adress[20];
    int regdNo;
};


int main()
{
    struct student stdRec[3];
    printf("Enter the record of the student\n");

    for(int i = 0; i < 3 ; i++){
        printf("Name? \n");
        scanf(" %s", stdRec[i].name);

        printf("Contact Number?\n");
        scanf(" %d", &stdRec[i].contactNo);

        printf("Student's Age?\n");
        scanf(" %d", &stdRec[i].age);

        printf("Adress?\n");
        scanf(" %s", stdRec[i].adress);

        printf("Registration Number?\n");
        scanf(" %d", &stdRec[i].regdNo);

        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    }    

    
    printf("Printing students record\n");
    for(int i = 0; i < 3; i++){
        printf("Name is %s\n", stdRec[i].name);
        printf("Regestration Number: %d\n", stdRec[i].regdNo);
        printf("Address: %s\n", stdRec[i].adress);
        printf("Age: %d\n", stdRec[i].age);
        printf("Contact Number: %d\n", stdRec[i].contactNo);
        printf("+++++++++++++++++++++++++++++++++++++++++++++++\n");
    }

    return 0;
}


