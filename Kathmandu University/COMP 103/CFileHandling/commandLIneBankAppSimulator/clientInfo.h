#ifndef CLIENTINFO_H
#define CLIENTINFO_H

#include <stdlib.h>
#include "StringType.h"
#include <time.h>
typedef struct bankAccount
{
    unsigned int accountNum;
    String clientFirstName;
    String clientLastName;
    String clientAddress;
    String client_e_Mail;
    int balance;
    struct tm transactionDate;
}accountRecords;

accountRecords ;

#endif