#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "types.h"
#include "data_init.c"
#include "dest_man.c"
#include "trip_man.c"
#include "buck_man.c"
#include "input_validation.c"

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
}

void 
mainMenu(destination* dest, 
        goal* bucketlist, 
        travelPlan* trips, 
        int destnum, 
        int bucketlistnum, 
        int tripnum)
{
    int choice;
    do
    {
        printMenu();
        do {
        printf("\nWHERE WOULD YOU LIKE TO GO? (1-5): ");
        scanf("%d", &choice);
        if (choice<1||choice>5) printf("\nINVALID CHOICE\n");
        } while (choice<1||choice>5);

    } while (choice!=5);
    
}

int
main()
{
    int destnum, bucketlistnum, tripnum;
    destination destinations[101];
    goal bucketlist[11];
    travelPlan* trips=calloc(1, sizeof(travelPlan));

    printf("%33s", "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\nYET ANOTHER TRAVEL APPLICATION (YATA)\n");
    printf("%33s", "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    init(destinations, 
        bucketlist, 
        trips, 
        &destnum, &bucketlistnum, &tripnum);
    // mainMenu(destinations, bucketlist, trips, destnum, bucketlistnum, tripnum);

    longDisplay(destinations, destnum);
    return 0;
}