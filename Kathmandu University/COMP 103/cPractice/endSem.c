#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

typedef struct disease
{
    char nameRegion[10];
    int totalCase;
    int numActive;
    int numRecovered;
    int numDeath;
}covidData;


void dataBaseSpaceCheck(covidData* dataFile);
void initalizeDatabase(covidData* dataFile);
char instructions();
void inputSelections(covidData* dataFile,char action);
void updateDatabase(covidData* dataFile);
covidData updateFields(covidData regionRecord);
char displayActions(char* region);
void displaySelections(covidData* dataBase);
void displayTotalCaseFor(char* region, covidData* dataBase);
void displayActiveCaseFor(char* region, covidData* dataBase);
void displayDeathCaseFor(char* region, covidData* dataBase);
void displayRecoveredCaseFor(char* region, covidData* dataBase);
void displayAllCaseFor(char* region, covidData* dataBase);
int searchInRecord(covidData* dataFile, char* region);
bool exitsInFile(covidData* dataFile, char* region);
void quitMessage();


int REGION_MAX = 500; //maxmimum number of recods that can be tracked
int DATA_IN_FILE = 0; //to keep track of total no of records in memory(array)
int LAST_RECORD_NO = 0; //



int main(){
    covidData* dataBase = NULL;
    dataBase = (covidData*) malloc(sizeof(covidData)*REGION_MAX); 
    
    //Initalizes database for the first time when progarm runs
    //One time action
    printf("Looks like there are no records in database\n");
    printf("You should initialize some records in database\n");
    initalizeDatabase(dataBase);
    
    /*
    User now after data initialization can choose to 
    wether to update,view or initialize new records for
    new regions in the database 
    */
    char input;
    while (true)
    {
        input = instructions(); //main menu instructions selection window
        if(input == 'q'){
            quitMessage(); //qutis the program 
            break;
        }
        inputSelections(dataBase,input); //Goes to process based on user selection
    }
    
    free(dataBase);
    return 0;
}

/*
Function below initalizes the data for the records/regions to be tracked:
for example: intializes--   Country Name: Nepal
                            Active cases: 276
                            Recovered cases: 31
                            Death Cases: 2 ,etc
    And stores them in database, First at start of the program and later
    as user demands.
*/
void initalizeDatabase(covidData* dataFile){    
    printf("*********INITILIZATION MENU******************\n");
    printf("Initalize the database with records.\n");
    
    int num; //number of records to be initalized
    printf("How many regions do you want to keep record for now?\n");
    scanf(" %d", &num);

    char regionName[10];
    for (int i = LAST_RECORD_NO; i < (LAST_RECORD_NO + num); i++)
    {
        //checks if database(array) is full before storing it
        //if full the increases its size
        dataBaseSpaceCheck(dataFile);
        printf("************INITIALZTION SUB MENU****************\n");
        printf("Enter the name of the region(world/country/city)(Ex: World, Nepal)\n");
        printf("Name length can be upto 9 characters for a region(Case Sensitive) at max\n");
        scanf(" %s", regionName);

        //checks if the region already exits in the database
        //if true(exists) the suggests updating that record
        //other wise starts initalizing the informations(name,cases etc) of that region 
        if (exitsInFile(dataFile,regionName))
        {   
            printf("************************************************\n"); 
            printf("Data already in file.You should instead update it.\n");
            continue;
        }

        //starts initalizing data if entered region is not in database

        strcpy(dataFile[i].nameRegion,regionName);
        
        printf("Enter total case in %s\n", regionName);
        scanf(" %d", &dataFile[i].totalCase);
        
        printf("Enter active case in %s\n", regionName);
        scanf(" %d", &dataFile[i].numActive);
        
        printf("Enter recovered case in %s\n", regionName);
        scanf(" %d", &dataFile[i].numRecovered);
        
        printf("Enter death case in %s\n", regionName);
        scanf(" %d", &dataFile[i].numDeath);
        
        DATA_IN_FILE++;
        printf("************************************************\n");
        printf("Initializtion Successfull!\n");
        printf("Current records in database: %d\n", DATA_IN_FILE);
    }
    LAST_RECORD_NO = DATA_IN_FILE;
   
}//end of function initalzeDatabase()

/*
    Function below shows the main menu of the program
    form which users can select wether to see  or update or initalize 
    data(Total Cases, Active Cases, Death Cases, Recovered Cases) or 
    they can close the program.

    function returns a lowercase-character(only 'u','v','i','q') 
    that tracks users choice which can be later user to jump into
    other menu(update menu, data-view menu, initalize menu, or quit) 
*/
char instructions(){
    char action;
    while(true){
        printf("*************MAIN MENU**************************\n");
        printf("Wel-come to COVID-19 tracker\n");
        printf("Select Action:\n");
        printf("Press 'U' from keyboard to update data\n");
        printf("Press 'V' from keyboard to view data\n");
        printf("Press 'I' from keyboard to initalize new records.\n");
        printf("Press 'Q' from keyboard to quit\n");
        scanf(" %c", &action);
        if(tolower(action) == 'u' || tolower(action) == 'v' || tolower(action) == 'q' || tolower(action) == 'i'){
            break;
        }else{
            printf("**************************************\n");
            printf("Read the instructions carefully\n");
        }
    }

    return action;
}//end of instructions() function

/*
    Function below, based on the user input from function instructions(),
    jumps to user desired menu(update data, display data, initalize new records)
*/
void inputSelections(covidData* dataFile,char action){
    if(action == 'u'){
        //if user wants to update data that exists then jumps to update menu
        updateDatabase(dataFile); 
    }else if(action == 'v'){
        //if user wants to view data form record then jumps to view menu
        displaySelections(dataFile);
    }else if(action == 'i'){
        //jumps to initalize menu if new records are to be added
        initalizeDatabase(dataFile);
    }else
    {
        //displays exit messages and closes the program
        quitMessage;
    }    
}//inputSelections() ends

//group of database updating function starts
/*
    Function below, first among two of data updating function,
    after user chooses to update data of existing records
    shows the update menu. User is asked the name of region
    (country/city/world) to be updated, then checks first
    if the region exits and then if exits jump to the 
    second function in this group that actually updates 
    the fields(Active cases, etc) and returns the updated 
    record which is then stored in the database in same position
    as previous record, within this function.
*/
void updateDatabase(covidData* dataFile){
    printf("********************UPDATE MENU**********************\n");
    printf("Name the region for which data is to be updated\n");
    printf("Name length can be upto 9 characters for a region(Case Sensitive) at max\n");
    char updateRegion[10];
    scanf(" %s", updateRegion);
    
    int recNum = searchInRecord(dataFile,updateRegion); //checking if entered region exists
    if(recNum != -1){
        covidData updatedRecord = updateFields(dataFile[recNum]);
        dataFile[recNum] = updatedRecord; //updated record updated
        printf("********************************************\n");
        printf("Update Successful!!\n");
    }else{
        printf("********************************************\n");
        printf("No such record exists in database to update.\n");
        printf("Update Unsuccessful\n");
    }
}
/*
    Second among the group of function that updates the database,
    Function below actually updates the data of records to be
    updated(active cases, death cases, etc) and returns the
    instance of newly updated record basck to function above 
    where it is saved in database
*/
covidData updateFields(covidData regionRecord){
    printf("******UPDATE SUB-MENU****************\n");
    covidData newRecord;
    strcpy(newRecord.nameRegion, regionRecord.nameRegion);

    printf("Enter new Total Cases in %s\n", newRecord.nameRegion);
    scanf(" %d", &newRecord.totalCase);
    printf("Enter new Active Cases in %s\n", newRecord.nameRegion);
    scanf(" %d", &newRecord.numActive);
    printf("Enter new Recovered Cases in %s\n", newRecord.nameRegion);
    scanf(" %d", &newRecord.numRecovered);
    printf("Enter new Death Cases in %s\n", newRecord.nameRegion);
    scanf(" %d", &newRecord.numDeath);
    
    return newRecord;
}
//group of database updating function ends

//group of function that dispays case-data of records starts
/*
    Function that tracks the user choice, inside of view menu 
    wether s/he wants to see single-sepecfied cases like death case
    only or wants to see every type of case. Returns a 
    lowerrcase-charcater('t' or 'a' or 'r' or 'd' or 'f') 
    based on the user choice.
*/
char displayActions(char* region){

    char action;
    while(true){            
        printf("Press 'T' to view total cases in %s\n", region);
        printf("Press 'A' to view active cases in %s\n", region);
        printf("Press 'R' to view recovered cases in %s\n", region);
        printf("Press 'D' to view death cases in %s\n", region);
        printf("Press 'F' to view all of above data in %s\n", region);
        scanf(" %c", &action);
        if(tolower(action) == 't' || tolower(action) == 'a' || tolower(action) == 'r' || tolower(action) == 'd' || tolower(action) == 'f'){
            break;
        }else{
            printf("**************************************\n");
            printf("Read the instructions carefully\n");
        }
    }
    return action;
}

/*
    Function that gets envoked when user chooses to view cases-data from 
    the main menu. Asks the user the name of region of which s/he
    wants to view data of. Then, shows the user what available list of
    actions that can be perfored by envoKing function displayActions()
    above and tracks his/her choice. Based on the choice then, jumps into
    other function to show the desired record
*/
void displaySelections(covidData* dataBase){
    printf("****************CASES VIEW MENU******************\n");
    printf("Name the region for which data is to be viewed\n");
    printf("Name length can be upto 9 characters for a region(Case Sensitive) at max\n");
    char regionView[10];
    scanf(" %s", regionView);
    char select = displayActions(regionView);

    if(select == 't'){
        //shows only total cases for the region 
        displayTotalCaseFor(regionView, dataBase);   
    }else if(select == 'a'){
        //shows only active cases for the region
        displayActiveCaseFor(regionView, dataBase);
    }else if(select == 'r'){
        //shows only recovered cases for the region
        displayRecoveredCaseFor(regionView, dataBase);
    }else if(select == 'd'){
        //shows only death cases for the region
        displayDeathCaseFor(regionView, dataBase);
    }else
    {
        //show every-type of cases for the region
        displayAllCaseFor(regionView, dataBase);
    }
    
}

/*
    Function that displays only total cases for the selected region.
    First checks if the regions exists or not in the database.
    if exits then shows only total cases other wises
    shows error message
*/
void displayTotalCaseFor(char* region, covidData* dataBase){
    int recordNum = searchInRecord(dataBase,region);
    if(recordNum != -1){
        printf("Total Cases in  %s is %d.\n", region, dataBase[recordNum].totalCase);
    }else{
        printf("Record for %s doesn't exist in database to display.\n", region);
        printf("Check the keyword and try again\n");
        printf("Or, create new record for %s from initaliztion menu.\n");   
    }
}

/*
    Function that displays only active cases for the selected region.
    First checks if the regions exists or not in the database.
    if exits then shows only active cases other wises
    shows error message
*/
void displayActiveCaseFor(char* region, covidData* dataBase){
    int recordNum = searchInRecord(dataBase,region);
    if(recordNum != -1){
        printf("Active Cases in  %s is %d.\n", region, dataBase[recordNum].numActive);
    }else{
        printf("Record for %s doesn't exist in database to display.\n", region);
        printf("Check the keyword and try again\n");
        printf("Or, create new record for %s from initaliztion menu.\n");   
    }
}

/*
    Function that displays only death cases for the selected region.
    First checks if the regions exists or not in the database.
    if exits then shows only death cases other wises
    shows error message
*/
void displayDeathCaseFor(char* region, covidData* dataBase){
    int recordNum = searchInRecord(dataBase,region);
    if(recordNum != -1){
        printf("Death Cases in  %s is %d.\n", region, dataBase[recordNum].numDeath);
    }else{
        printf("Record for %s doesn't exist in database to display.\n", region);
        printf("Check the keyword and try again\n");
        printf("Or, create new record for %s from initaliztion menu.\n");   
    }
}

/*
    Function that displays only recovered cases for the selected region.
    First checks if the regions exists or not in the database.
    if exits then shows only recovered cases other wises
    shows error message
*/
void displayRecoveredCaseFor(char* region, covidData* dataBase){
    int recordNum = searchInRecord(dataBase,region);
    if(recordNum != -1){
        printf("Recovered Cases in  %s is %d.\n", region, dataBase[recordNum].numRecovered);
    }else{
        printf("Record for %s doesn't exist in database to display.\n", region);
        printf("Check the keyword and try again\n");
        printf("Or, create new record for %s from initaliztion menu.\n");   
    }
}

/*
    Function that displays all type of cases for the selected region.
    First checks if the regions exists or not in the database.
    if exits then shows all type of cases other wises
    shows error message
*/
void displayAllCaseFor(char* region, covidData* dataBase){
    int recordNum = searchInRecord(dataBase,region);
    if(recordNum != -1){
        printf("Total Cases in  %s is %d.\n", region, dataBase[recordNum].totalCase);
        printf("Active Cases in  %s is %d.\n", region, dataBase[recordNum].numActive);
        printf("Death Cases in  %s is %d.\n", region, dataBase[recordNum].numDeath);
        printf("Recovered Cases in  %s is %d.\n", region, dataBase[recordNum].numRecovered);
    }else{
        printf("Record for %s doesn't exist in database to display.\n", region);
        printf("Check the keyword and try again\n"); 
        printf("Or, create new record for %s from initaliztion menu.\n");  
    }
}

//group of function that dispays case-data of records ends


/*
    Function below searches for a record based on the name
    of the region entered from the user. Returns the database
    (array) position of the record if it exits. otherwise,
    returns -1 if it doesn't
*/
int searchInRecord(covidData* dataFile, char* region){
    /*  
        linearly searching through the database(array) - datafile
        should use binary search if large number of data exits
        and for more efficiency
    */ 
    for (int i = 0; i < DATA_IN_FILE; i++)
    {
        if(strcmp(dataFile[i].nameRegion,region) == 0){
            return i; //returning position in array
        }
    }
    return -1;
}


/*
    Similar to serachInRecord function above. Too uses linear
    seacrch. But this returns boolean value 'true' if the region
    entered from the user exists in database(array) - dataFile
    Otherwise, returns boolean value 'false' if it does not.
*/
bool exitsInFile(covidData* dataFile, char* region){
    if(DATA_IN_FILE == 0){
        return false;
    }
    for (int i = 0; i < DATA_IN_FILE; i++)
    {
        if(strcmp(dataFile[i].nameRegion,region) == 0){
            return true;
        }
    }
    return false;
}
/*
    Function that maintains the space of database(array)
    dynamically. Reallocates the size of array when the 
    space left in array is 1 less then from being full.
    Increases the size of the database by 500.
*/
void dataBaseSpaceCheck(covidData* dataFile){
    if(DATA_IN_FILE == (REGION_MAX - 1)){
        printf("Database nearly full\n");
        printf("Increasing storage space\n");
        realloc(dataFile, sizeof(covidData)*(DATA_IN_FILE+500));
        REGION_MAX = (DATA_IN_FILE + 500);
        printf("Success!!\n");
        printf("***************************\n");
    }
}

/*
    Function that shows some important links related to COVID-19
    form which user can get more information about the virus.
*/
void quitMessage(){
    printf("Thank You For Using This Program!!!");
    printf("Stay Safe! Stay Healthy!\n");
    printf("Folow these links for more information on COVID -19\n");
    printf("https://www.who.int/emergencies/diseases/novel-coronavirus-2019/advice-for-public\n");
    printf("http://crrp.ku.edu.np/\n");
}