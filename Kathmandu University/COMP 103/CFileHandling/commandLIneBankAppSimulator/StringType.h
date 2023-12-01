#ifndef STRINGTYPE_H_
#define STRINGTYPE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char* String;
String readString(FILE* inputStream);
bool existInRecord(FILE* dataBase, String nameToFind);
#endif
