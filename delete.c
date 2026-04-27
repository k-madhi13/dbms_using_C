#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <direct.h>
#include "database.h"

void delete_table(char *db_name, char *table_name) {
    char confirm;
    printf("Delete table '%s'? (Y/N): ", table_name);
    scanf(" %c", &confirm);

    if (confirm == 'Y' || confirm == 'y') {
        // Remove .csv file
        char csv_path[100];
        sprintf(csv_path, "%s/%s.csv", db_name, table_name);
        remove(csv_path);

        // Rewrite tables.txt
        char txt_path[100];
        sprintf(txt_path, "%s/tables.txt", db_name);

        FILE *f = fopen(txt_path, "r");
        FILE *temp = fopen("temp.txt", "w");

        char line[100];
        while (fgets(line, sizeof(line), f)) {
            line[strcspn(line, "\n")] = 0;
            if (strcmp(line, table_name) != 0)
                fprintf(temp, "%s\n", line);
        }

        fclose(f);
        fclose(temp);
        remove(txt_path);
        rename("temp.txt", txt_path);

        printf("Table '%s' deleted.\n", table_name);

    } else {
        printf("Deletion cancelled.\n");
    }
}
void delete_database(char *db_name) {
    char confirm;
    printf("Delete database '%s'? (Y/N): ", db_name);
    scanf(" %c", &confirm);
    if (confirm != 'Y' && confirm != 'y') return;

    // Delete all .csv files listed in tables.txt
    char txt_path[100];
    sprintf(txt_path, "%s/tables.txt", db_name);

    FILE *f = fopen(txt_path, "r");
    if (f) {
        char table[100];
        while (fgets(table, sizeof(table), f)) {
            table[strcspn(table, "\n")] = 0;

            char csv_path[100];
            sprintf(csv_path, "%s/%s.csv", db_name, table);
            remove(csv_path);
        }
        fclose(f);
    }

    // Remove tables.txt
    remove(txt_path);

    // Remove the database folder
    rmdir(db_name);

    // Rewrite databases.txt excluding deleted entry
    FILE *db_file = fopen("databases.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    char line[100];
    while (fgets(line, sizeof(line), db_file)) {
        line[strcspn(line, "\n")] = 0;
        if (strcmp(line, db_name) != 0)
            fprintf(temp, "%s\n", line);
    }

    fclose(db_file);
    fclose(temp);

    remove("databases.txt");

    rename("temp.txt", "databases.txt");

    printf("Database '%s' deleted.\n", db_name);
}