#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "checkValid.h"
#include "insert.h"
#include "menu.h"

void insertInto(char *tableName, char *dbName)
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
        callInsert();
    }

    // find numbersOfColumns and primaryKey
    int columns, primaryKey;
    fscanf(fpMD, "%d %d", &columns, &primaryKey);
    fclose(fpMD);

    // reads headers
    primaryKey -= 1;
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
    fclose(fpD);

    // reads the data to be inserted and writes it
    fpD = fopen(dataPath, "a");
    int num;
    char values[columns][32];
    printf("Enter numbers of data to be inserted: ");
    scanf("%d", &num);

    for (i = 0; i < num; i++)
    {
        // reads
        printf("%dth Data\n", i + 1);
        for (int j = 0; j < columns; j++)
        {
            printf("%s: ", column_name[j]);
            scanf("%s", values[j]);
        }

        if (!isValidPrimaryKey(values[primaryKey], primaryKey, dataPath))
        {
            printf("\n**  WARNING: Invalid Primary Key %s  **\n\n", column_name[primaryKey]);
            i--;
            continue;
        }

        // writes
        for (int j = 0; j < columns; j++)
        {
            fprintf(fpD, "%s", values[j]);
            if (j < columns - 1)
            {
                fprintf(fpD, ",");
            }
        }
        fprintf(fpD, "\n");
    }
    fclose(fpD);
    printf("\n................................................................\n");
    printf("\n**  Data Inserted Successfully  **");
    showMenu();
}