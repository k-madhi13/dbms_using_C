#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "checkValid.h"
#include "insertInto.h"

void insert()
{
    printf("\n\n");
    printf("__________________________________\n\n");
    printf("***      INSERT Operation      ***\n");
    printf("__________________________________\n\n");

    // input DB name
    char dbName[32];
    printf("Enter DataBase Name:\n");
    printf("-> ");
    scanf("%s", dbName);
    printf("\n................................................................\n");

    // validate DB name
    if (!isValidDB(dbName))
    {
        printf("\n**  WARNING: DataBase does not exists  **");
        insert();
    }

    // input table name
    char tableName[32];
    char tableFile[32];
    printf("Enter Table Name:\n");
    printf("-> ");
    scanf("%s", tableName);
    printf("\n................................................................\n");

    // valid table name
    strcpy(tableFile, tableName);
    strcat(tableFile, ".txt");
    if (!isValidTable(tableFile, dbName))
    {
        printf("\n**  WARNING: Table does not exists  **");
        insert();
    }

    // call function to insert data
    insertInto(tableName, dbName);
}

void callInsert()
{
    insert();
}