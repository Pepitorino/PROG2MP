#include "types.h"
#include <stdio.h>
#include <stdlib.h>

void
shortDisplay (Destination* dest, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("SHORTNAME: %s\n", dest[i].shortName);
        printf("\nLONGNAME: %s\n", dest[i].longName);
    }
}

void
longDisplay (Destination* dest, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nSHORTNAME: %s\n", dest[i].shortName);
        printf("LONGNAME: %s\n", dest[i].longName);
        printf("COUNTRY: %s\n", dest[i].country);
        printf("GEOGRAPHICAL GROUP: %s\n", dest[i].geoGroup);
        printf("TO DO: %s\n", dest[i].toDo);
    }
}

void
addDest (Destination* dest, int *n)
{
    printf("\nSHORTNAME: ");
    scanf("%s", dest[*n].shortName);
    printf("\nLONGNAME\t: ");
    scanf("%s", dest[*n].longName);
    printf("\nCOUNTRY\t: ");
    scanf("%s", dest[*n].country);
    printf("\nGEOGROUP\t: ");
    scanf("%s", dest[*n].geoGroup);
    printf("\nTO DO\t\t: ");
    scanf("%s", dest[*n].toDo);
    *n+=1;
}

void
deleteDest (Destination* dest, int *n)
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
editDest (Destination* dest, int *n)
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
        printf("\n\nDESTINATION MANAGEMENT MENU");
        printf("\nOPTIONS:");
        printf("\nDISPLAY LIST SHORT (1)");
        printf("\nDISPLAY LIST LONG (2)");
        printf("\nADD RECORD (3)");
        printf("\nDELETE RECORD (4)");
        printf("\nEDIT RECORD (5)");
        printf("\nBACK TO MAIN MENU (6)");
        printf("\nWHERE WOULD YOU LIKE TO GO? (1-6): ");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
                shortDisplay(dest, *n);
                break;
            case 2:
                longDisplay(dest, *n);
                break;
            case 3:
                addDest(dest, n);
                break;
            case 4:
                deleteDest(dest, n);
                break;
            case 5:
                editDest(dest, n);
                break;                
        }
    } while (choice!=6);
    
}