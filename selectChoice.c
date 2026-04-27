#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"

void selectAll(FILE *fp, char **column_name, int columns)
{
    printf("\n\n");
    printf("__________________________________\n\n");
    printf("***            DATA            ***\n");
    printf("__________________________________\n\n");
    // showing table headers
    for (int i = 0; i < columns; i++)
    {
        printf("%s\t\t", column_name[i]);
    }
    printf("\n\n");
    char line[256];
    int count = 0;
    int flags = -1;
    int res = 0;
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        line[strcspn(line, "\n")] = '\0';
        char *token = strtok(line, ",");
        int column = 0;
        while (token != NULL)
        {
            while (*token == ' ')
            {
                token++;
            }
            printf("%s\t\t", token);
            token = strtok(NULL, ",");
        }
        res++;
        printf("\n");
    }
    printf("\n................................................................\n");
    printf("\n**    %d RESULTS FOUND    **", res);
    fclose(fp);
    getchar();
    getchar();
    showMenu();
}

void selectPart(FILE *fp, char **column_name, int columns, char *dataPath)
{
    // which field for condition
    int choice;
    printf("\nEnter field to apply condition: \n");
    for (int i = 0; i < columns; i++)
    {
        printf("%d. %s\n", i + 1, column_name[i]);
    }
    printf("-> ");
    scanf("%d", &choice);
    int index = choice - 1;

    // what is condition
    char condition[32];
    printf("\n");
    printf("SELECT * FROM %s WHERE %s = ", dataPath, column_name[index]);
    scanf("%s", condition);

    printf("\n\n");
    printf("__________________________________\n\n");
    printf("***            DATA            ***\n");
    printf("__________________________________\n\n");
    // showing table headers
    for (int i = 0; i < columns; i++)
    {
        printf("%s\t\t", column_name[i]);
    }
    printf("\n");

    char line[256];
    int count = 0;
    int res = 0;
    while (fgets(line, sizeof(line), fp) != NULL)
    {

        line[strcspn(line, "\n")] = '\0';

        // keep a copy because strtok modifies the string
        char lineCopy[256];
        strcpy(lineCopy, line);

        // check if condition matches at index column
        char *token = strtok(lineCopy, ",");
        int column = 0;
        int match = 0;

        while (token != NULL)
        {
            if (column == index)
            {
                while (*token == ' ')
                    token++; // trim space
                if (strcmp(token, condition) == 0)
                {
                    match = 1;
                }
                break;
            }
            column++;
            token = strtok(NULL, ",");
        }

        // if matched, print the full row using original line
        if (match)
        {
            token = strtok(line, ",");
            while (token != NULL)
            {
                while (*token == ' ')
                    token++; // trim space
                printf("%s\t\t", token);
                token = strtok(NULL, ",");
            }
            res++;
            printf("\n");
        }
    }
    printf("\n................................................................\n");
    printf("\n**    %d RESULTS FOUND    **", res);
    fclose(fp);
    getchar();
    getchar();
    showMenu();
}