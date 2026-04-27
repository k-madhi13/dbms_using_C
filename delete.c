#include <stdio.h>
#include "deleteOptions.h"
void deleteMenu()
{
    int choice;
    char db_name[100];
    char table_name[100];
    char column[100];
    char value[100];
    int row_number;

    printf("\n\n");
    printf("__________________________________\n\n");
    printf("***       DELETE Options       ***\n");
    printf("__________________________________\n\n");
    printf("1. DELETE Table\n");
    printf("2. DELETE Database\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    printf("\n................................................................\n");

    if (choice == 1)
    {
        printf("Enter database name: ");
        scanf("%s", db_name);
        printf("Enter table name: ");
        scanf("%s", table_name);
        delete_table(db_name, table_name);
    }
    else if (choice == 2)
    {
        printf("Enter database name: ");
        scanf("%s", db_name);
        delete_database(db_name);
    }
    else
    {
        deleteMenu();
    }
}