#include "types.h"
#include "menu.c"
#include "data_init.c"
#include "destman.c"
#include <stdio.h>
#include <string.h>

int
main()
{
    int i=0;
    Destination travelDestinations[101]; //max 100 elements, extra element is for the space at the bottom of the txt file
    Goals bucketList[11]; //max 11 elements, extra element for last space at the bottom of the txt file
    int destnum, bucketlistnum;

    destnum=dest_init(travelDestinations);
    bucketlistnum=bucketlist_init(bucketList);

    int option;

    printf("%33s", "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\nYET ANOTHER TRAVEL APPLICATION (YATA)\n");
    printf("%33s", "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    printMenu();
    return 0;
}
