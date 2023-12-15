#include <stdio.h>
#include "linearRegression.h"

void showRegEqnAndCalcY(Point** data, int total2DPoints);
int main()
{
  
    printf("*************************For File I********************************\n");
    FILE* dataSetFileI = fopen("datasetLR1.txt", "r");
    Point* coordinatesI;
    int noCordInFileI;
    read2DPoints(dataSetFileI, &coordinatesI, &noCordInFileI);
    showRegEqnAndCalcY(&coordinatesI, noCordInFileI);
    fclose(dataSetFileI);
    free(coordinatesI);

    printf("*************************For File II*******************************\n");
    FILE* dataSetFileII = fopen("datasetLR2.txt", "r");
    Point* coordinatesII;
    int noCordInFileII;
    read2DPoints(dataSetFileII, &coordinatesII, &noCordInFileII);
    showRegEqnAndCalcY(&coordinatesII, noCordInFileII);
    fclose(dataSetFileII);
    free(coordinatesII);

    printf("*************************For File III******************************\n");
    FILE* dataSetFileIII = fopen("datasetLR3.txt", "r");
    Point* coordinatesIII;
    int noCordInFileIII;
    read2DPoints(dataSetFileIII, &coordinatesIII, &noCordInFileIII);
    showRegEqnAndCalcY(&coordinatesIII, noCordInFileIII);
    fclose(dataSetFileIII);
    free(coordinatesIII);

    printf("*************************For File IV*******************************\n");
    FILE* dataSetFileIV = fopen("datasetLR4.txt", "r");
    Point* coordinatesIV;
    int noCordInFileIV;
    read2DPoints(dataSetFileIV, &coordinatesIV, &noCordInFileIV);
    showRegEqnAndCalcY(&coordinatesIV, noCordInFileIV);
    fclose(dataSetFileIV);
    free(coordinatesIV);
}

/*
    Function to show the linear regression equation and
    calulate the value of y after asking for the value of
    x from the user.
*/
void showRegEqnAndCalcY(Point** data, int total2DPoints)
{
    double grad = computeLinGrad(data, total2DPoints);
    double constant = computeLinConst(data, total2DPoints);
    

    double userXVal;

    printf("*******************************************************************\n");
    printf("The linear regression equation for given points is calulated to be: \n");
    printRegressionEqn(grad, constant);
    printf("\n");
    printf("Enter desired value of x in above equation to calulate y\n");
    scanf(" %lf", &userXVal);

    double y = (constant * userXVal) + grad;
    printf("y = %.4f\n", y);
    printf("*******************************************************************\n");
}
