#include "types.h"
#include <stdio.h>

void
saveDest (destination* data, int n)
{
    int i=0;

    FILE* f1;
    f1 = fopen("destination.txt", "w");

    for (i=0;i<n;i++)
    {
        fprintf(f1, "%s %s\n", data[i].shortName, data[i].longName);
        fprintf(f1, "%s\n", data[i].country);
        fprintf(f1, "%s\n", data[i].geoGroup);
        fprintf(f1, "%s\n", data[i].toDo);
        fprintf(f1, "\n");
   }

    fclose(f1);
}

void
saveBuck (goal* data, int n)
{
    int i=0;

    FILE* f1;
    f1 = fopen("bucketlist.txt", "w");

    for (i=0;i<n;i++)
    {
        fprintf(f1, "%s\n", data[i].shortName);
        fprintf(f1, "%d\n", data[i].prioRank);
        fprintf(f1, "%s\n", data[i].remarks);
        fprintf(f1, "%d\n\n", data[i].flag);
    }

    fclose(f1);
}

void
saveTrip (travelPlan* trips, int n)
{

}

void
save(destination* dest, 
        goal* bucketlist, 
        travelPlan* trips, 
        int *destnum, 
        int *bucketlistnum, 
        int *tripnum)
{
    saveDest(dest, *destnum);
    saveBuck(bucketlist, *destnum);
    saveTrip(trips, *destnum);
}