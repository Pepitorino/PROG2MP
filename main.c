/************************************************************************************************************************
This is to certify that this project is my own work, based on my personal efforts in studying and applying the
concepts learned. I have constructed the functions and their respective algorithms and corresponding code
by myself. The program was run, tested, and debugged with my own efforts. I further certify that I have not
copied in part or whole or otherwise plagiarized the work of other students and/or persons.
Ambrosio, Carlos Felipe Q. , DLSU ID# 12275964
************************************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "types.h"
#include "input_validation.c"
#include "data_init.c"
#include "dest_man.c"
#include "trip_man.c"
#include "buck_man.c"
#include "dashboard.c"
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
    printf("\n5. SAVE CHANGES");
    printf("\n6. QUIT");
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
        do {
        printMenu();
        printf("\nWHERE WOULD YOU LIKE TO GO? (1-5): ");
        scanf("%d", &choice);
        if (choice<1||choice>6) printf("\nINVALID CHOICE\n");
        } while (choice<1||choice>6);

        switch (choice)
        {
            case 1: dashboard(dest, bucketlist, trips, *destnum, *bucketlistnum, *tripnum); break;
            case 2: destMenu(dest, destnum); break;
            case 3: buckMenu(dest, bucketlist, bucketlistnum, destnum); break;
            case 4: tripMenu(dest, trips, tripnum, destnum); break;
            case 5: 
                save(dest, bucketlist, trips, destnum, bucketlistnum, tripnum);
                printf("\nCHANGES SAVED\n");
                break;
            case 6: break;
            default: printf("\nINVALID\n");
        }

    } while (choice!=6);
    
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