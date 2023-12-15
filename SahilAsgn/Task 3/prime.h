#ifndef _PRIME_H
#define _PRIME_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

/*
    struct that keeps tracks of start and end
    list of computation that is to be performed 
    by each thread.
*/
typedef struct computationList
{
    int start;
    int end;
}ComputationList;

extern int64_t* allNumsInFile;
extern uint32_t totalNumber;

extern pthread_mutex_t mutex;

void readAllNumsInAFile(FILE* dataSetFile, int64_t** data, int* totalDataPoints);
void readAllNums(FILE* dataSetFile, int64_t** data, int* totalDataPoints);
void getNoThreads(int* noThrd);

void createSliceList(uint32_t* noItert, int* noThrd, int** sliceList);
void createSliceStartEndList(uint32_t* noItert, int* noThrd, int** sliceList, int** startList, int** endList, ComputationList** threadStartEndList);
void createThreads(int* noThrd, ComputationList** threadStartEndList);


void createThreads(int* noThrd, ComputationList** threadStartEndList);
void* checkPrimeAndWrite(void* startEndList);

#endif