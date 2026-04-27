#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "checkValid.h"
#include "selectChoice.h"

void selectStart(int);

void selectMenu()
{
    int choice;

    do
    {
        printf("\n\n");
        printf("__________________________________\n\n");
        printf("***       SELECT Options       ***\n");
        printf("__________________________________\n\n");
        printf("1. SELECT * FROM ... \n");
        printf("2. SELECT * FROM ... WHERE ...\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        printf("\n................................................................\n");
    } while (choice != 1 && choice != 2); // Loop until a valid choice is made

    selectStart(choice);
}

void showSelect(char *tableName, char *dbName, int choice)
{
    char path[64];
    char metadataPath[64];
    char dataPath[64];
    path[0] = '\0';
    metadataPath[0] = '\0';
    dataPath[0] = '\0';
    strcat(path, dbName);
    strcat(path, "/");
    strcat(path, tableName);

    // path of metadatafile
    strcpy(metadataPath, path);
    strcat(metadataPath, "MD.csv");

    // path of data file
    strcpy(dataPath, path);
    strcat(dataPath, ".csv");

    // opening metadata file and reading
    FILE *fpMD, *fpD;
    fpMD = fopen(metadataPath, "r");
    fpD = fopen(dataPath, "r");

    if (!fpMD || !fpD)
    {
        printf("\n**  WARNING: Table cannot be accessed  **");
        selectMenu();
    }

    // find numbersOfColumns and primaryKey
    int columns;
    fscanf(fpMD, "%d", &columns);
    fclose(fpMD);

    // reads headers
    char headers[columns * 32];
    fgets(headers, sizeof(headers), fpD);
    headers[strcspn(headers, "\n")] = '\0';
    char *column_name[columns];
    int i = 0;
    char *token = strtok(headers, ",");
    while (token != NULL && i < columns)
    {
        while (*token == ' ')
        {
            token++;
        }
        column_name[i] = token;
        i++;
        token = strtok(NULL, ",");
    }

    // show data as per select
    switch (choice)
    {
    case 1:
        selectAll(fpD, column_name, columns);
        break;
    case 2:
        selectPart(fpD, column_name, columns, dataPath);
        break;
    }
}

void selectStart(int choice)
{
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
        selectMenu();
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
        selectMenu();
    }

    // call function to insert data
    showSelect(tableName, dbName, choice);
}