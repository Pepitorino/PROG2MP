#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "types.h"
#include "input_validation.c"
#include "data_init.c"
#include "dest_man.c"
#include "trip_man.c"
#include "buck_man.c"
#include "data_save.c"

void
printMenu()
{
    printf("\n\nMENU");
    printf("\nOPTIONS:");
    printf("\n1. SHOW DASHBOARD");
    printf("\n2. DESTINATION LIST MANAGEMENT");
    printf("\n3. BUCKET LIST MANAGEMENT");
    printf("\n4. TRIP MANAGEMENT");
    printf("\n5. QUIT");
}

void 
mainMenu(destination* dest, 
        goal* bucketlist, 
        travelPlan* trips, 
        int *destnum, 
        int *bucketlistnum, 
        int *tripnum)
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
        switch (choice)
        {
        case 1:
            /* code */
            break;
        case 2: destMenu(dest, destnum); break;
        case 3: buckMenu(dest, bucketlist, bucketlistnum, destnum); break;
        case 4: tripMenu(dest, trips, tripnum, destnum); break;
        case 5: break;
        default: printf("\nINVALID\n");
        }

    } while (choice!=5);
    
}

int
main()
{
    int destnum, bucketlistnum, tripnum;
    destination destinations[101];
    goal bucketlist[11];
    travelPlan trips[101];

    printf("%33s", "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\nYET ANOTHER TRAVEL APPLICATION (YATA)\n");
    printf("%33s", "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    init(destinations, 
        bucketlist, 
        trips, 
        &destnum, &bucketlistnum, &tripnum);
    mainMenu(destinations, bucketlist, trips, &destnum, &bucketlistnum, &tripnum);
    save(destinations, 
        bucketlist, 
        trips, 
        &destnum, &bucketlistnum, &tripnum);
    return 0;
}