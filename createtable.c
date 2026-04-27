#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "createtable.h"
#include "menu.h"

void createTable(char dbName[50])
{
    char tableName[50];
    char nameWithExt[50];
    char line[50];
    char path[100];
    FILE *f;
    int i, found, flag, foundtb;
    int cols, primaryKey;
    char colNames[20][50];

    // If there is no dbname, ask for it
    if (dbName[0] == '\0')
    {
        do
        {
            printf("Enter database name: ");
            scanf("%s", dbName);

            // Check if database exists in names.txt
            found = 0;
            f = fopen("names.txt", "r");
            if (f != NULL)
            {
                while (fscanf(f, "%s", line) != EOF)
                {
                    if (strcmp(line, dbName) == 0)
                    {
                        found = 1;
                        break;
                    }
                }
                fclose(f);
            }

            if (found == 0)
            {
                printf("Database does not exist. Try again.\n");
            }

        } while (found == 0);
    }
    // Ask for table name
    do
    {
        printf("Enter table name: ");
        scanf("%s", tableName);

        // Validate to ensure name does not contain extension
        flag = 1;
        i = 0;
        while (tableName[i] != '\0')
        {
            if (tableName[i] == '.')
            {
                printf("Error: No extensions allowed.\n");
                flag = 0;
                break;
            }
            i++;
        }

        if (flag == 0)
            continue; // If extension found, ask for name again

        // nameWithExt = tableName + ".txt"
        strcpy(nameWithExt, tableName);
        strcat(nameWithExt, ".txt");

        // Check if already exists in tableNames.txt
        foundtb = 0;
        path[0] = '\0';
        strcat(path, dbName);
        strcat(path, "/tableNames.txt");
        f = fopen(path, "r");
        if (f != NULL)
        {
            while (fscanf(f, "%s", line) != EOF)
            {
                if (strcmp(line, nameWithExt) == 0)
                {
                    foundtb = 1;
                    break;
                }
            }
            fclose(f);
        }

        if (foundtb)
        {
            printf("Table already exists. Try another name.\n");
        }

    } while (foundtb || flag == 0);

    // Add to tableNames.txt
    path[0] = '\0';
    strcat(path, dbName);
    strcat(path, "/tableNames.txt");
    f = fopen(path, "a");
    fprintf(f, "%s\n", nameWithExt);
    fclose(f);

    // Ask for number of columns
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // Ask for column names
    for (i = 0; i < cols; i++)
    {
        int j, duplicate;
        do
        {
            printf("Column %d name: ", i + 1);
            scanf("%s", colNames[i]);
            duplicate = 0;
            // Check for duplicate column names
            for (j = 0; j < i; j++)
            {
                if (strcmp(colNames[i], colNames[j]) == 0)
                {
                    printf("Column name already used. Try again.\n");
                    duplicate = 1;
                    break;
                }
            }
        } while (duplicate);
    }

    // Ask for primary key
    printf("Enter primary key column number (1 to %d): ", cols);
    scanf("%d", &primaryKey);

    // Create tableNameMD.csv with metadata
    path[0] = '\0';
    strcat(path, dbName);
    strcat(path, "/");
    strcat(path, tableName);
    strcat(path, "MD.csv");
    f = fopen(path, "w");
    if (f == NULL)
    {
        printf("Error creating CSV file.\n");
        exit(1);
    }
    fprintf(f, "%d %d\n", cols, primaryKey);
    fclose(f);

    // Create tableName.csv with column headers
    path[0] = '\0';
    strcat(path, dbName);
    strcat(path, "/");
    strcat(path, tableName);
    strcat(path, ".csv");
    f = fopen(path, "w");
    if (f == NULL)
    {
        printf("Error creating CSV file.\n");
        exit(1);
    }

    // Write column names to first line of CSV
    for (i = 0; i < cols; i++)
    {
        if (i < cols - 1)
            fprintf(f, "%s,", colNames[i]);
        else
            fprintf(f, "%s\n", colNames[i]);
    }
    fclose(f);

    printf("\n................................................................\n");
    printf("\n**    TABLE '%s' CREATED SUCCESSFULLY    **", tableName);
    showMenu();
}