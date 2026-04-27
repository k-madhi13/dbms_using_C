#include <stdio.h>
#include "database.h"
int main() {
    int choice;
    char db_name[100];
    char table_name[100];
    char column[100];
    char value[100];
    int row_number;

    printf("1. Delete Row (by condition)\n");
    printf("2. Delete Database\n");
    printf("3. Delete Column\n");
    printf("4. Delete Row (by row number)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter database name: ");
        scanf("%s", db_name);
        printf("Enter table name: ");
        scanf("%s", table_name);
        printf("Enter column: ");
        scanf("%s", column);
        printf("Enter value: ");
        scanf("%s", value);
        delete_table(db_name, table_name, column, value);

    } else if (choice == 2) {
        printf("Enter database name: ");
        scanf("%s", db_name);
        delete_database(db_name);

    } else if (choice == 3) {
        printf("Enter database name: ");
        scanf("%s", db_name);
        printf("Enter table name: ");
        scanf("%s", table_name);
        printf("Enter column name to delete: ");
        scanf("%s", column);
        delete_column(db_name, table_name, column);

    } else if (choice == 4) {
        printf("Enter database name: ");
        scanf("%s", db_name);
        printf("Enter table name: ");
        scanf("%s", table_name);
        printf("Enter row number to delete (1 = first data row): ");
        scanf("%d", &row_number);
        delete_row(db_name, table_name, row_number);

    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
}
