#include <stdio.h>
#include "StringType.h"
typedef struct date
{
    int year;
    int month;
    int day;
}Date;


typedef struct bankAccount
{
    String holderName;
    String holderAddress;
    int accountNum;
    int balance;
    Date transactionDate;
}accountRecords;

void writeNewRecords(accountRecords* customerRecord);

FILE* bankRecords; 

int main(void){

    bankRecords = fopen("Bank_Records.txt", "r+");
    if(bankRecords == NULL){
        bankRecords = fopen("Bank_Records.txt", "w+");
    }

    

    accountRecords customer;
    writeNewRecords(&customer);
    printf("Name:%s\n",customer.holderName);
    printf("Address: %s\n", customer.holderAddress);
    fprintf(bankRecords, "%s, %s, %d, %d\n", customer.holderName, customer.holderAddress, customer.accountNum, customer.balance);
    return 0;
}

void writeNewRecords(accountRecords* customerRecord){
    printf("Enter name:\n");
    customerRecord->holderName = readString(stdin);
    printf("Enter Address:\n");
    customerRecord->holderAddress = readString(stdin);
    printf("Enter accountNum:\n");
    scanf("%d", &customerRecord->accountNum);
    printf("Enter balance left in account:\n");
    scanf("%d", &customerRecord->balance);
}