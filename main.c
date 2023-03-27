#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

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
mainMenu()
{
    int choice;
    do
    {
        printMenu();
        scanf("%d", &choice);

    } while (choice!=5);
    
}

int
main()
{
    int destnum, bucketlistnum;

    printf("%33s", "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\nYET ANOTHER TRAVEL APPLICATION (YATA)\n");
    printf("%33s", "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    DIR* dir = opendir(".");
    struct dirent* entity;

    entity = readdir(dir);
    while (entity=readdir(dir))
    {
        printf("%s\n", entity->d_name);
    }

    return 0;
}