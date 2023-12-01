#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct deviation
{
    char* foodName;
    char* foodType;
    int noTrackDay;
    float* prices;
}kalimatiFood;


void readValues(kalimatiFood data);
float average(kalimatiFood data);
float calcStdDev(kalimatiFood data);
kalimatiFood openingInstructions();


int main(){

    kalimatiFood food = openingInstructions();

    readValues(food);
    
    float stdDev = calcStdDev(food);
    printf("The Standard Deviation of prices of %s for last %d days is  %.3f",food.foodName, food.noTrackDay ,stdDev);

    return 0;
}

void readValues(kalimatiFood data){
    printf("Enter the prices for last %d days\n", data.noTrackDay);
    for(int i = 0; i < data.noTrackDay; i++){
        printf("PriceForDay[%d] = ", (i+1));
        scanf(" %f", (data.prices + i));
    }
}


float average(kalimatiFood data){
   float sum;
   sum = 0;
   for(int i = 0; i < data.noTrackDay; i++){
       sum += *(data.prices + i);
   }
   return sum / data.noTrackDay; 
}

float calcStdDev(kalimatiFood data){
    float avg = average(data);
    float devFromMeanSqr[data.noTrackDay];
    
    float sum = 0;
    for (int i = 0; i < data.noTrackDay; i++)
    {
        devFromMeanSqr[i] = pow( (*(data.prices + i) - avg) , 2);  
        sum += devFromMeanSqr[i];  
    }

    return sqrt((sum/data.noTrackDay));
}

kalimatiFood openingInstructions(){

    kalimatiFood data;

    printf("Enter the name of food.\n");
    data.foodName = (char*)malloc(sizeof(char)*10);
    scanf(" %s", data.foodName);

    data.foodType = (char*)malloc(sizeof(char)*10);
    printf("Enter the food type.(Vegetable or Fruit?)\n");
    scanf(" %s", data.foodType);

    printf("No of days to track price of %s?\n", data.foodName);
    scanf(" %d", &data.noTrackDay);
    data.prices = (float*) malloc(sizeof(float) * data.noTrackDay);

    return data;
    
}