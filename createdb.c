#include <stdio.h>
#include <string.h>
#include <direct.h>
#include <stdlib.h>
#include "createdb.h"
#include "createtable.h"

void createDb() {
    char dbName[50];
    char line[50];
    char nameWithExt[50];
    char path[100];
    FILE *f;
    int i, found, flag;

    do {
        printf("Enter database name: ");
        scanf("%s", dbName);

        // Validate to ensure name does not contain extension
        flag = 1;
        i = 0;
        while (dbName[i] != '\0') {
            if (dbName[i] == '.') {
                printf("Error: No extensions allowed.\n");
                flag = 0;
                break;
            }
            i++;
        }

        if (flag == 0) continue; //Ask for new database name
        
        //nameWithExt = dbName + ".txt"
        strcpy(nameWithExt, dbName);
        strcat(nameWithExt, ".txt");

        // Check if already exists
        found = 0;
        f = fopen("names.txt", "r");
        if (f != NULL) {
            while (fscanf(f, "%s", line) != EOF) {
                if (strcmp(line, nameWithExt) == 0) {
                    found = 1;
                    break;
                }
            }
            fclose(f);
        }

        if (found) {
            printf("Database already exists. Try another name.\n");
        }

    } while (found || flag == 0);

    // Add database name to names.txt
    f = fopen("names.txt", "a");
    fprintf(f, "%s\n", nameWithExt);
    fclose(f);

    // Create folder
    _mkdir(dbName);

    // Create tableNames.txt inside folder
    path[0] = '\0';       //Set first character to null to avoid garbage value
    strcat(path, dbName);
    strcat(path, "/tableNames.txt");  //Create tableNames.txt inside folder  
    f = fopen(path, "w");
    if(f==NULL) {
        printf("Error creating CSV file.\n");
        exit(1);
    }
    fclose(f);

    printf("Database '%s' created successfully.\n", dbName);
    createTable(dbName);
}