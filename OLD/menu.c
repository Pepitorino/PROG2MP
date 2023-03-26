#include "types.h"
#include <stdio.h>

void
printMenu()
{
    printf("\n\nMENU");
    printf("\nOPTIONS:");
    printf("\nSHOW DASHBOARD(1)");
    printf("\nDESTINATION LIST MANAGEMENT(2)");
    printf("\nBUCKET LIST MANAGEMENT(3)");
    printf("\nTRIP MANAGEMENT(4)");
    printf("\nQUIT (5)");
    printf("\nWHERE WOULD YOU LIKE TO GO? (1-5): ");
}

void 
mainMenu(Destination* dest, Goals* bucketlist, int *dn, int *bn)
{
    int choice;
    do
    {
        printf("\n\nMENU");
        printf("\nOPTIONS:");
        printf("\nSHOW DASHBOARD(1)");
        printf("\nDESTINATION LIST MANAGEMENT(2)");
        printf("\nBUCKET LIST MANAGEMENT(3)");
        printf("\nTRIP MANAGEMENT(4)");
        printf("\nQUIT (5)");
        printf("\nWHERE WOULD YOU LIKE TO GO? (1-5): ");
        scanf("%d", &choice);

        switch(choice)
        {
            // case 1: 
            //     printDashboard();
            //     break;
            case 2:
                destman(dest, dn);
                break;
            // case 3:
            //     buckman();
            //     break;
            // case 4:
            //     tripman();
            //     break;
            case 5:
                printf("GOODBYE");
                break;
            default:
                printf("\nINVALID");
        }
    } while (choice!=5);
    
}

