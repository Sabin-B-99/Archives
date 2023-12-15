#ifndef _LINEAR_REGRESSION_H
#define _LINEAR_REGRESSION_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
    A point structure that stores 2D (x,y) coordinates
*/
typedef struct point{
    int x;
    int y;
}Point;

void read2DPoints(FILE* dataSetFile, Point** data, int* total2DPoints);

static int sumX(Point** data, int total2DPoints);
static int sumY(Point** data, int total2DPoints);
static int sumXSqr(Point** data, int total2DPoints);
static int sumXY(Point** data, int total2DPoints);
static int sumXWholeSqr(Point** data, int total2DPoints);

double computeLinGrad(Point** data, int total2DPoints);
double computeLinConst(Point** data, int total2DPoints);

void printRegressionEqn(double gradient, double constant);
#endif