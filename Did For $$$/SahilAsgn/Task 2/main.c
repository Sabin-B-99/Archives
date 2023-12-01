#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

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

double leibnizSumVal;
pthread_mutex_t mutex;

void* leibniz(void* startEndList);

double calculatePI();

void getNoIteration(uint32_t* noItert);
void getNoThreads(int* noThrd);
void createSliceList(uint32_t* noItert, int* noThrd, int** sliceList);
void createSliceStartEndList(uint32_t* noItert, int* noThrd, int** sliceList, int** startList, int** endList, ComputationList** threadStartEndList);
void createThreads(int* noThrd, ComputationList** threadStartEndList);

int main()
{
    uint32_t totalItrs;
    int thrds;
    int* sliceList;
    int* startList;
    int* endList;
    ComputationList* threadStartEnd;
    createSliceStartEndList(&totalItrs, &thrds, &sliceList, &startList, &endList, &threadStartEnd);
    createThreads(&thrds, &threadStartEnd);
    
    printf("The value of PI is: %f\n", calculatePI());
    
    free(sliceList);
    free(startList);
    free(endList);
    free(threadStartEnd);
}
/*
    Function to get from the user
    the total number of computation to be performed
*/
void getNoIteration(uint32_t* noItert)
{
    printf("Enter the total number of iteration/computation : \n");
    scanf(" %d", noItert);
}

/*
    Function to get total number of threads from the user.
    This number input will be equal to the total number
    of thread created and used later during computation
*/
void getNoThreads(int* noThrd)
{
    printf("Enter the total number of threads to be used: \n");
    scanf(" %d", noThrd);
}

/*
    Function to slice the total number of computations to be done
    by each thread into equal number of parts.
*/
void createSliceList(uint32_t* noItert, int* noThrd, int** sliceList)
{
    getNoIteration(noItert);
    getNoThreads(noThrd);
    int remainder = (*noItert) % (*noThrd);

    *sliceList = NULL;
    *sliceList = (int*) malloc(sizeof(int) * (*noThrd));
    

    for (int i = 0; i < (*noThrd); i++)
    {
        *(*sliceList + i) = (*noItert) / (*noThrd);
    }
    
    for(int i = 0; i < remainder; i++)
    {
        *(*sliceList + i) = (*(*sliceList + i)) + 1; 
    }
}
/*
    Function to create start and end list of computaion 
    which will be performed by each thread.
*/
void createSliceStartEndList(uint32_t* noItert, int* noThrd, int** sliceList, int** startList, int** endList, ComputationList** threadStartEndList)
{
    createSliceList(noItert, noThrd, sliceList);
    
    *startList = NULL;
    *startList = (int*) malloc(sizeof(int) * (*noThrd));

    *endList = NULL;
    *endList = (int*) malloc(sizeof(int) * (*noThrd));

    for (int i = 0; i < (*noThrd); i++)
    {
        if (i == 0)
        {
            *(*startList + i) = 0;
        } 
        else
        {
            *(*startList + i) = *(*endList + (i-1)) + 1;
        }

        *(*endList + i) = *(*startList + i) + *(*sliceList + i) - 1;
    }   

    *threadStartEndList = NULL;
    *threadStartEndList = (ComputationList*) malloc(sizeof(ComputationList) * (*noThrd));

    for (int i = 0; i < (*noThrd); i++)
    {
        (*threadStartEndList + i)->start = *(*startList + i);
        (*threadStartEndList + i)->end = *(*endList + i);
    }
}

/*
    Function to create threads depending upon no of
    threads desired by the user and number of compuation
    each thrad performs
*/
void createThreads(int* noThrd, ComputationList** threadStartEndList)
{
    pthread_t threadIds[*noThrd];
    pthread_mutex_init(&mutex, NULL);
    
    for(int i = 0; i < (*noThrd); i++)
    {
        pthread_create(&threadIds[i], NULL, leibniz, (*threadStartEndList + i));
    }
    for(int i = 0; i < (*noThrd); i++)
    {
        pthread_join(threadIds[i], NULL);
    }
    
    pthread_mutex_destroy(&mutex);
}

/*
    Thread Function that is used to compute leibinz sum 
    which will be later used to calculate the value of PI
    using the calculautePI() function.
*/
void* leibniz(void* startEndList)
{
    pthread_mutex_lock(&mutex);
    ComputationList* computationStartEnd = (ComputationList*) startEndList;
    int lowerLimit = computationStartEnd->start;
    int upperLimit = computationStartEnd->end;
    
    for(int num = lowerLimit; num <= upperLimit; num++)
    {
        leibnizSumVal = leibnizSumVal + (pow(-1, num) / (2 * num + 1));
    }
    pthread_mutex_unlock(&mutex);
    pthread_exit(0);
}

/*
    Calculates the value of PI using the leibniz sum
*/
double calculatePI()
{
    return leibnizSumVal * 4;
}