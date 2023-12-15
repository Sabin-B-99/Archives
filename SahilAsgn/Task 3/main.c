#include <stdio.h>
#include <stdint.h>
#include "prime.h"



int64_t* allNumsInFile;
uint32_t totalNumber = 0;

pthread_mutex_t mutex;
int totalPrimeNum;
int main()
{
    FILE* dataSetFileI = fopen("PrimeData1.txt", "r");
    FILE* dataSetFileII = fopen("PrimeData2.txt", "r");
    FILE* dataSetFileIII = fopen("PrimeData3.txt", "r");

    
    int* sliceList;
    int* startList;
    int* endList;
    ComputationList* threadStartEnd;
    int totalThreadUse = 0;

    readAllNums(dataSetFileI, &allNumsInFile, &totalNumber);
    readAllNums(dataSetFileII, &allNumsInFile, &totalNumber);
    readAllNums(dataSetFileIII, &allNumsInFile, &totalNumber);
    
    fclose(dataSetFileI);
    fclose(dataSetFileII);
    fclose(dataSetFileIII);
    
    createSliceStartEndList(&totalNumber, &totalThreadUse, &sliceList, &startList, &endList, &threadStartEnd);
    createThreads(&totalThreadUse, &threadStartEnd);
  
    printf("All prime numbers saved in PrimeNumbers.txt file\n");
    printf("Total Number of Prime Number Saved is also written at the end of the same file\n");


    free(sliceList);
    free(startList);
    free(endList);
    free(threadStartEnd);
}

