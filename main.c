#include <stdio.h>
#include "database.h"

int main() {
    int choice;
    char db_name[100];
    char table_name[100];

    printf("1. Delete Table\n");
    printf("2. Delete Database\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter database name: ");
        scanf("%s", db_name);
        printf("Enter table name: ");
        scanf("%s", table_name);
        delete_table(db_name, table_name);

    } else if (choice == 2) {
        printf("Enter database name: ");
        scanf("%s", db_name);
        delete_database(db_name);

    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}