#include "types.h"
#include <stdio.h>

void
shortDisplay (Destination* dest, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\n%s\n", dest[i].shortName);
        printf("%s\n", dest[i].longName);
    }
}

void
longDisplay (Destination* dest, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\n%s\n", dest[i].longName);
        printf("%s\n", dest[i].shortName);
        printf("%s\n", dest[i].country);
        printf("%s\n", dest[i].geoGroup);
        printf("%s\n", dest[i].toDo);
    }
}

void
addRecord (Destination* dest, int *n)
{
    printf("\nLONGNAME\t: ");
    scanf("%s", dest[*n].longName);
    printf("\nSHORTNAME: ");
    scanf("%s", dest[*n].shortName);
    printf("\nCOUNTRY\t: ");
    scanf("%s", dest[*n].country);
    printf("\nGEOGROUP\t: ");
    scanf("%s", dest[*n].geoGroup);
    printf("\nTO DO\t\t: ");
    scanf("%s", dest[*n].toDo);
    *n+=1;
}

void
deleteRecord (Destination* dest, int *n)
{
    str_t temp;
    int i=0, k=-1;

    do {
        printf("\nWhich destination would you like to delete? ");
        printf("\nENTER SHORTNAME (CASE SENSITIVE):");
        scanf("%s", temp);

        for (i=0;i<*n;i++)
        {
            if (!strcmp(temp, dest[i].shortName))
            {
                k=i;
                i=*n;
            }
        }

        if (i==*n-1)
        {
            printf("\nINVALID SHORTNAME\n");
        }
    } while (k==-1);

    for (k;k<*n;k++)
    {
        dest[k]=dest[k+1];
    }

    *n-=1;
}

void
editRecord (Destination* dest, int *n)
{
    str_t temp;
    int i=0, k=-1;
    int option;

    do {
        printf("\nWhich destination would you like to edit? ");
        printf("\nENTER SHORTNAME (CASE SENSITIVE):");
        scanf("%s", temp);

        for (i=0;i<*n;i++)
        {
            if (!strcmp(temp, dest[i].shortName))
            {
                k=i;
                i=*n;
            }
        }

        if (i==*n-1)
        {
            printf("\nINVALID SHORTNAME\n");
        }
    } while (k==-1);

    do {
        printf("\nWhat would you like to edit? :");
        printf("\nLONGNAME\t(1)");
        printf("\nCOUNTRY\t(2)");
        printf("\nGEOGROUP\t(3)");
        printf("\nTO DO\t(4)");
        printf("\nEXIT\t\t(5)");
        printf("\nENTER OPTION: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                printf("\nENTER NEW LONGNAME: ");
                scanf("%s", dest[k].longName);
                break;
            case 2:
                printf("\nENTER NEW COUNTRY: ");
                scanf("%s", dest[k].country);
                break;
            case 3:
                printf("\nENTER NEW GEOGROUP: ");
                scanf("%s", dest[k].geoGroup);
                break;
            case 4:
                printf("\nENTER NEW \"TO DO\": ");
                scanf("%s", dest[k].toDo);
                break;
        }

    } while (option!=5);
}

void
destman (Destination* dest, int *n)
{
    int choice;
    do
    {
        printf("DESTINATION MANAGEMENT MENU");
        printf("OPTIONS:");
        printf("DISPLAY LIST SHORT (1)");
        printf("DISPLAY LIST LONG (2)");
        printf("ADD RECORD (3)");
        printf("DELETE RECORD (4)");
        printf("EDIT RECORD (5)");
        printf("BACK TO MAIN MENU (6)");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
        }
    } while (choice!=6);
    
}