#ifndef CHECKVALID_H
#define CHECKVALID_H

#include <stdbool.h>
bool isValidDB(char *dbName);
bool isValidTable(char *tableFile, char *dbName);
bool isValidPrimaryKey(char *primaryKey, int index, char *dataPath);
#endif