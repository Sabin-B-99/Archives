#include "linearRegression.h"
/*
    Function to read all the data cooridinates(x,y) from 
    a given dataFile (passed as first argument) into the
    array of a Point structure (passed as second argument)
    This function also writes the total number of Points 
    read form the file into the integer memory address 
    passed as the third argument. 
*/
void read2DPoints(FILE* dataSetFile, Point** data, int* total2DPoints)
{
    *data = NULL;
    int currentMemBloc = 0;
    int initMemBloc = 1;
    *data = (Point*) malloc(sizeof(Point) * initMemBloc);
    
    while (!feof(dataSetFile))
    {   
        if (initMemBloc == currentMemBloc)
        {
            *data = (Point*) realloc(*data, ((sizeof(Point) * (initMemBloc + 1))));        
            initMemBloc += 1;
        }
        fscanf(dataSetFile, "%d,%d", &((*data) + currentMemBloc)->x , &((*data + currentMemBloc))->y);
        currentMemBloc++;
    }
    *total2DPoints = currentMemBloc;
}

/*
    Function that performs summation of 
    all the x coordinates data passed as 
    Point array passed as first argument 
    and returns the final summation.
*/
int sumX(Point** data, int total2DPoints)
{
    int sumX = 0;
    for (int i = 0; i < total2DPoints; i++)
    {
        sumX += ((*data) + i)->x;  
    }
    return sumX;
}


/*
    Function that performs summation of 
    all the y coordinates data passed as 
    Point array passed as first argument 
    and returns the final summation.
*/
int sumY(Point** data, int total2DPoints)
{
    int sumY = 0;
    for (int i = 0; i < total2DPoints; i++)
    {
        sumY += ((*data) + i)->y;  
    }
    return sumY;
}

/*
    Function that performs summation of 
    square of all the x coordinates data passed as 
    Point array passed as first argument 
    and returns the final summation.
*/
int sumXSqr(Point** data, int total2DPoints)
{
    int sumXSqr = 0;
    for (int i = 0; i < total2DPoints; i++)
    {
        sumXSqr += lround(pow(((*data) + i)->x, 2)); 
    }
    return sumXSqr;
}


/*
    Function that performs summation of 
    value all the x multiplied by y coordinates data passed as 
    Point array passed as first argument 
    and returns the final summation.
*/
int sumXY(Point** data, int total2DPoints)
{
    int sumXY = 0;
    for (int i = 0; i < total2DPoints; i++)
    {
        sumXY += ((*data) + i)->x * ((*data) + i)->y;  
    }
    return sumXY;
}

/*
    Function that performs summation of 
    all the x coordinates data passed as 
    Point array passed as first argument 
    and returns the square of the final summation.
*/
int sumXWholeSqr(Point** data, int total2DPoints)
{
    return lround(pow(sumX(data,total2DPoints), 2));
}

/*
    Function that calcuates thr gradient of all the data 
    points passed as array in first argument and returns 
    the calculated gradient 
*/
double computeLinGrad(Point** data, int total2DPoints)
{
    double numeratorA = (sumY(data, total2DPoints) * sumXSqr(data, total2DPoints)) - (sumX(data, total2DPoints) * sumXY(data, total2DPoints));
    double denominatorA = (total2DPoints * (sumXSqr(data, total2DPoints))) - sumXWholeSqr(data, total2DPoints);

    return numeratorA / denominatorA;
}


/*
    Function that calcuates thr constant of all the data 
    points passed as array in first argument and returns 
    the calculated constant 
*/
double computeLinConst(Point** data, int total2DPoints)
{
    double numeratorB = (total2DPoints * sumXY(data, total2DPoints)) - (sumX(data, total2DPoints) * sumY(data, total2DPoints));
    double denominatorB = (total2DPoints * sumXSqr(data, total2DPoints)) - sumXWholeSqr(data, total2DPoints);

    return numeratorB / denominatorB;
}
/*
    Function that prints the regression equation to the 
    console equation based on the graident and constant 
    passed as arguments.
*/
void printRegressionEqn(double gradient, double constant)
{
    if(gradient > 0)
    {
        printf(" y = %.4fx + %.4f\n", constant, gradient);
    }
    else
    {
        printf(" y = %.4fx %.4f\n", constant, gradient);
    }
}