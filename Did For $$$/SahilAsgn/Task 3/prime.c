#include "prime.h"

/*
    Function that reads data or numbers from the given file
    writes all those data into an array of memory passed as the 
    second parameter to this function. And also count the total 
    number of data/number written into that array and writes in 
    the memory address of an integer passed as the third parameter
    to this function
*/
void readAllNumsInAFile(FILE* dataSetFile, int64_t** data, int* totalDataPoints)
{
    *data = NULL;
    int currentMemBloc = 0;
    int initMemBloc = 1;
    *data = (int64_t*) malloc(sizeof(int64_t) * initMemBloc);
    
    while (!feof(dataSetFile))
    {   
        if (initMemBloc == currentMemBloc)
        {
            *data = (int64_t*) realloc(*data, ((sizeof(int64_t) * (initMemBloc + 1))));        
            initMemBloc += 1;
        }
        fscanf(dataSetFile, "%ld", (*data + currentMemBloc));
        currentMemBloc++;
    }
    *totalDataPoints = currentMemBloc;
}


/*
    Function that reads data or numbers from the given file
    writes all those data into an array of memory passed as the 
    second parameter to this function.
    
    But unlike the function readAllNumsInAFile(..) above this 
    function will not clear/reset the values present in the array 
    passed as second argument. But, appends newer data from newer 
    file in the same single array.

    Also keeps the count of total number present in the array

*/
void readAllNums(FILE* dataSetFile, int64_t** data, int* totalDataPoints)
{   
    int currentMemBloc = *totalDataPoints;
    int initMemBloc = *totalDataPoints;
    
    if (*totalDataPoints == 0)
    {
        *data = NULL;
        currentMemBloc = 0;
        initMemBloc = 1;
        *data = (int64_t*) malloc(sizeof(int64_t) * initMemBloc);
    }
    
    
    while (!feof(dataSetFile))
    {   
        if (initMemBloc == currentMemBloc)
        {
            *data = (int64_t*) realloc(*data, ((sizeof(int64_t) * (initMemBloc + 1))));        
            initMemBloc += 1;
        }
        fscanf(dataSetFile, "%ld", (*data + currentMemBloc));
        currentMemBloc++;
    }
    *totalDataPoints = currentMemBloc;
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
        pthread_create(&threadIds[i], NULL, checkPrimeAndWrite, (*threadStartEndList + i));
    }
    for(int i = 0; i < (*noThrd); i++)
    {
        pthread_join(threadIds[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
}

/*
    Function to check wether a given number is prime
    or not. Returns true if the number is prime else
    returns false. Refrence: GeeksForGeeks.com
*/
bool checkPrime(int64_t* num)
{
    int flag = 1; 
    for (int i = 2; i <= sqrt(*num); i++) { 
         if (*num % i == 0) { 
            flag = 0; 
            break; 
        } 
    } 
    if(*num<=1) 
    flag=0; 
    else if(*num==2) 
    flag=1;  
  
    if (flag == 1) { 
        return true; 
    } 
    else { 
        return false; 
    }
}

/*
    Thread Function that checks wether the numbers 
    in the given list is prime or not using the help 
    of fuction checkPrime(...) and writes the 
    prime numbers into a separate .txt file named
    'PrimeNumbers.txt along with the total numbers 
    of prime numbers written. 
*/
void* checkPrimeAndWrite(void* startEndList)
{
    pthread_mutex_lock(&mutex);
    ComputationList* computationStartEnd = (ComputationList*) startEndList;
    int lowerLimit = computationStartEnd->start;
    int upperLimit = computationStartEnd->end;
    FILE* primeFile = fopen("PrimeNumbers.txt", "w");
    int totalPrimeNum = 0;
    for (int i = 0; i < totalNumber; i++)
    {
        if (checkPrime((allNumsInFile + i)))
        {
            fprintf(primeFile, "%ld\n", *(allNumsInFile + i));
            totalPrimeNum++;
        }
    }
    fprintf(primeFile, "Total Number of Prime Numbers = %d\n", totalPrimeNum);
    pthread_mutex_unlock(&mutex);
    pthread_exit(0);
}
