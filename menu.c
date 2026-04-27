#include <stdio.h>

#include "create.h"
#include "delete.h"
#include "insert.h"
#include "select.h"

void greetUser()
{
    // Welcome Greetings
    printf("\n\n\n");
    printf("+------+------+------+------+------+------+\n");
    printf("|                                         |\n");
    printf("|      Welcome to command line DBMS       |\n");
    printf("|                                         |\n");
    printf("+------+------+------+------+------+------+\n");
}

void showMenu()
{
    // menu items
    printf("\n\n");
    printf("__________________________________\n\n");
    printf("***       DDL Operations       ***\n");
    printf("__________________________________\n\n");
    printf("1. Create\n");
    printf("2. Insert\n");
    printf("3. Select\n");
    printf("4. Delete\n");
    printf("\nNOTE: Use Ctrl + C to terminate the program\n");

    // users choice
    int choice;
    printf("\nYour Operation:\n");
    printf("-> ");
    scanf("%d", &choice);
    printf("\n................................................................\n");

    // commands
    switch (choice)
    {
    case 1:
        callCreate();
        break;
    case 2:
        callInsert();
        break;
    case 3:
        selectMenu();
        break;
    case 4:
        deleteMenu();
        break;
    default:
        printf("\n**  WARNING: Command was not recognized  **");
        showMenu();
    }
}

void callMenu()
{
    greetUser();
    showMenu();
}
