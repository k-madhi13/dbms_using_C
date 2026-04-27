#include <stdio.h>
#include "create.h"
#include "createdb.h"
#include "createtable.h"

void menu();
void call() {
    menu();
}
//Menu for create
void menu() {
    int choice;

    do {
        printf("\nCREATE MENU\n");
        printf("1. Create Database\n");
        printf("2. Create Table\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createDb();    //Call Function to create database
                break;
            case 2: {
                char dbName[50];
                dbName[0] = '\0';  // Start with empty dbName
                createTable(dbName);   //Call Function to create table
                break;
            }
        }
    } while(choice != 1 && choice != 2); //Loop until a valid choice is made
}
