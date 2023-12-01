#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "StringType.h"
#include "clientInfo.h"

bool doesClientExist(FILE* fileToSearchIn, String clientFirsttName, String clientLastName, unsigned int accntNum){
    accountRecords tempRec;
    size_t retnSize;
    while (!feof(fileToSearchIn))
    {
        retnSize = fread(&tempRec,sizeof(accountRecords), 1, fileToSearchIn);
        if(retnSize == (sizeof(accountRecords) * 1) && strcmp(tempRec.clientFirstName, clientFirsttName) == 0 && strcmp(tempRec.clientLastName, clientLastName) == 0 && tempRec.accountNum == accntNum){
            return true;
        }   
    }
    return false;
}