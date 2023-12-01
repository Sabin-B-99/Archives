#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct metric
{
    float meters;
    float centims;
}Metric;

typedef struct british
{
    float feets;
    float inches;
}British;

British convertToBrit(Metric measures);
Metric convertMetric(British measures);

int main(){
    Metric distMet;
    British distBrit;
    
    //asking the user for their preffered system of measurement which 
    //needs to be converted
    printf("Select the system of measurement you currently ");
    printf("have the measurements in, and needs to be converted.\n");
    printf("Press 1: for Metric System\n");
    printf("Press 2: for British System\n");
    //user won't be able to quit the program until 
    //they input the correct numbers
    int choice;
    while(true){
        printf("Your Choice??\n");
        scanf(" %d", &choice);
        if(choice == 1 || choice == 2){
            if(choice == 1){
                printf("You choose the Metric system\n");
            }else{
                printf("You choose the British system\n");
            }
            break;
        }
        printf("*********************************\n");
        printf("Select the system of measurement:\n");
        printf("Press 1: for Metric System\n");
        printf("Press 2: for British System\n");
    }

    //after selecting preffered choice, users then will be prompted
    //to enter the measurements of lenght of their preffered system
    //and those measurements will sebsequently be converted into the
    //other option; that the user had'nt choose and stored in that 
    //other measurement system structure fields.
    switch (choice)
    {
    case 1:
        printf("Now, Enter the values in metric system:\n");
        printf("Enter the distance in meters.\n");
        scanf(" %f", &distMet.meters);
        printf("Enter the distance in centimeters.\n");
        scanf(" %f", &distMet.centims);
        distBrit = convertToBrit(distMet);
        printf(" %.3f meters are %.3f feets\n",distMet.meters, distBrit.feets);
        printf(" %.3f centimeters are %.3f inches\n",distMet.centims, distBrit.inches);
        break;
    
    case 2:
        printf("Now, Enter the values in british system:\n");
        printf("Enter the distance in feets.\n");
        scanf(" %f", &distBrit.feets);
        printf("Enter the distance in inches.\n");
        scanf(" %f", &distBrit.inches);
        distMet = convertMetric(distBrit);
        printf("%.3f feets are %.3f meters.\n",distBrit.feets, distMet.meters);
        printf("%.3f inches are %.3f centimeters.\n",distBrit.inches, distMet.centims);
        break;

    default:
        printf("Unspecified Error\n");
        break;
    }

    return 0;
}

//function that converts measurements in metric system into british system 
//stores those converted measurements in feets,and inches fields of a 
//British measurement system structure and returns that same british  
//measurement structure
British convertToBrit(Metric measures){
    float feet;
    float inches;
    feet = measures.meters / 0.3048;
    inches = measures.centims / 2.54;

    British tempDist;
    tempDist.feets = feet;
    tempDist.inches = inches;

    return tempDist;
}

//function that converts measurements in british system into metric system
//stores those converted measurements in meters, and centimeters fields of a 
//Mertic measurement systen structure and returns that same metric measurement
//structure
Metric convertMetric(British measures){
    float meter;
    float centimeter;
    meter = measures.feets * 0.3048;
    centimeter = measures.inches * 2.54;

    Metric tempDist;
    tempDist.meters = meter;
    tempDist.centims = centimeter;

    return tempDist;
}
