#include "types.h"
#include <stdio.h>

void
displayList(Goals* bucklist, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Name: \n%s\n", bucklist[i].shortName);
        printf("Priority Rank: %d\n", bucklist[i].priorityRank);
        printf("Remarks: %s\n", bucklist[i].remarks);
        printf("Status: ");
        if (bucklist[i].achievedFlag) printf("Achieved\n");
        else printf("Yet to be achieved\n");
    }
}

void 
addBuck(int n)
{

}

void
deleteBuck(int n)
{

}

void
editBuck(int n)
{

}

void 
markAchieved(int n)
{

}

void 
buckman (int n)
{

}