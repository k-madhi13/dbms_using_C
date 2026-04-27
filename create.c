#include <stdio.h>

#include "create.h"
#include "createdb.h"
#include "createtable.h"

void createMenu();
void callCreate()
{
    createMenu();
}
// Menu for create
void createMenu()
{
    int choice;

    do
    {
        printf("\n\n");
        printf("__________________________________\n\n");
        printf("***       CREATE Options       ***\n");
        printf("__________________________________\n\n");
        printf("1. CREATE Database\n");
        printf("2. CREATE Table\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        printf("\n................................................................\n");

        switch (choice)
        {
        case 1:
            createDb(); // Call Function to create database
            break;
        case 2:
        {
            char dbName[50];
            dbName[0] = '\0';    // Start with empty dbName
            createTable(dbName); // Call Function to create table
            break;
        }
        }
    } while (choice != 1 && choice != 2); // Loop until a valid choice is made
}
