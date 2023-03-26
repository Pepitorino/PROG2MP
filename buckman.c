#include "types.h"
#include <stdio.h>

void
displayBucketList(Goals* bucklist, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nName: %s\n", bucklist[i].shortName);
        printf("Priority Rank: %d\n", bucklist[i].priorityRank);
        printf("Remarks: %s\n", bucklist[i].remarks);
        printf("Status: ");
        if (bucklist[i].achievedFlag) printf("Achieved\n");
        else printf("Yet to be achieved\n");
    }
}

void 
addBuck(Goals* bucklist, int *n)
{
    printf("\nSHORTNAME\t: ");
    scanf("%s", bucklist[*n].shortName);
    printf("\nPRIORITY RANK\t: ");
    scanf("%s", bucklist[*n].priorityRank);
    printf("\nCOUNTRY\t: ");
    scanf("%s", bucklist[*n].remarks);
    printf("\nGEOGROUP\t: ");
    scanf("%[\n]s", bucklist[*n].achievedFlag);
    *n+=1;
}

void
deleteBuck(Goals* bucklist, int *n)
{
    str_t temp;
    int i=0, k=-1;

    do {
        printf("\nWhich destination would you like to delete? ");
        printf("\nENTER SHORTNAME (CASE SENSITIVE):");
        scanf("%s", temp);

        for (i=0;i<*n;i++)
        {
            if (!strcmp(temp, bucklist[i].shortName))
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
        bucklist[k]=bucklist[k+1];
    }

    *n-=1;
}

void
editBuck(Goals* bucklist, int *n)
{

}

void 
markAchieved(int n)
{

}

void 
buckman (Goals* bucklist, int *n)
{
    int choice;
    do
    {
        printf("\n\nBUCKETLIST MANAGEMENT MENU");
        printf("\nOPTIONS:");
        printf("\nDISPLAY LIST (1)");
        printf("\nADD RECORD (2)");
        printf("\nDELETE RECORD (3)");
        printf("\nEDIT RECORD (4)");
        printf("\nBACK TO MAIN MENU (5)");
        printf("\nWHERE WOULD YOU LIKE TO GO? (1-5): ");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
                displayBucketList(bucklist, *n);
                break;
            case 2:
                addBuck(bucklist, n);
                break;
            case 3:
                deleteBuck(bucklist, n);
                break;
            case 4:
                editBuck(bucklist, n);
                break;                
        }
    } while (choice!=5);
}