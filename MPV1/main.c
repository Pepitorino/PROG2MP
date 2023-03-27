#include "types.h"
#include "data_init.c"
#include "destman.c"
#include "buckman.c"
#include "tripman.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
            case 3:
                buckman(bucketlist, bn);
                break;
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

int
main()
{
    Destination travelDestinations[101]; //max 100 elements, extra element is for the space at the bottom of the txt file
    Goals bucketList[11]; //max 11 elements, extra element for last space at the bottom of the txt file
    int destnum, bucketlistnum;

    destnum=dest_init(travelDestinations);
    bucketlistnum=bucketlist_init(bucketList);

    printf("%33s", "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\nYET ANOTHER TRAVEL APPLICATION (YATA)\n");
    printf("%33s", "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    printf("\n%d %d\n", destnum, bucketlistnum);

    mainMenu(travelDestinations, bucketList, &destnum, &bucketlistnum);
    return 0;
}
