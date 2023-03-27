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
    char temp;
    printf("\nSHORTNAME\t: ");
    scanf("%s", bucklist[*n].shortName);
    printf("\nPRIORITY RANK\t: ");
    scanf("%d", &bucklist[*n].priorityRank);
    printf("\nREMARKS\t: ");
    scanf("%s", bucklist[*n].remarks);
    printf("\nACHIEVED (Y/N)\t: ");
    scanf(" %c", &temp);
    if (temp=='Y'||temp=='y') bucklist[*n].achievedFlag=1;
    else bucklist[*n].achievedFlag=0;
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

    while(k<*n)
    {
        bucklist[k]=bucklist[k+1];
        k++;
    } 

    *n-=1;
}

void
editBuck(Goals* bucklist, int *n)
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

    do {
        printf("\nWhat would you like to edit? :");
        printf("\nPRIORITY RANK\t(1)");
        printf("\nREMARKS\t(2)");
        printf("\nEXIT\t\t(3)");
        printf("\nENTER OPTION: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                printf("\nENTER NEW PRIORITY RANK: ");
                scanf("%d", &bucklist[k].priorityRank);
                break;
            case 2:
                printf("\nENTER REMARKS: ");
                scanf("%[\n]s", bucklist[k].remarks);
                break;
        }

    } while (option!=3);
}

void 
changeAchieved(Goals* bucklist, int *n)
{
    str_t temp;
    int i=0;

    printf("\nWhich item would you like to mark as achieved? ");
    printf("\nENTER SHORTNAME (CASE SENSITIVE):  ");
    scanf("%s", temp);

    for (i=0;i<*n;i++)
        {
            if (!strcmp(temp, bucklist[i].shortName))
            {
                if (!(bucklist[i].achievedFlag)) bucklist[i].achievedFlag=1;
                else bucklist[i].achievedFlag=0;
            }
        }
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
        printf("\nMARK RECORD AS ACHIEVED (5)");
        printf("\nBACK TO MAIN MENU (6)");
        printf("\nWHERE WOULD YOU LIKE TO GO? (1-6): ");
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
            case 5:
                changeAchieved(bucklist, n);
                break;
            case 6:
                break;
            default:
                printf("\nINVALID CHOICE\n");
        }
    } while (choice!=6);
}