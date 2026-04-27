#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isValidDB(char *dbName)
{
    FILE *fp;
    fp = fopen("names.txt", "r");

    // search for DataBase
    char line[32];
    while (fscanf(fp, "%s", line) != EOF)
    {
        if (strcmp(line, dbName) == 0)
        {
            fclose(fp);
            return true;
        }
    }
    fclose(fp);
    return false;
}

bool isValidTable(char *tableFile, char *dbName)
{
    // open table names to find table
    char path[64];
    path[0] = '\0';
    strcpy(path, dbName);
    strcat(path, "/tableNames.txt");

    FILE *fp;
    fp = fopen(path, "r");
    char line[32];
    while (fscanf(fp, "%s", line) != EOF)
    {
        if (strcmp(line, tableFile) == 0)
        {
            fclose(fp);
            return true;
        }
    }
    fclose(fp);
    return false;
}

bool isValidPrimaryKey(char *primaryKey, int index, char *dataPath)
{
    FILE *fp = fopen(dataPath, "r");
    char line[256];
    int count = 0;
    int flags = -1;
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        if (count == 0)
        {
            count++;
            continue;
        }

        line[strcspn(line, "\n")] = '\0';
        char *token = strtok(line, ",");
        int column = 0;
        while (token != NULL)
        {
            if (column == index)
            {
                while (*token == ' ')
                {
                    token++;
                }
                if (strcmp(token, primaryKey) == 0)
                {
                    flags = 0;
                }
                break;
            }
            column++;
            token = strtok(NULL, ",");
        }
    }
    fclose(fp);
    if (flags == 0)
    {
        return false;
    }
    return true;
}