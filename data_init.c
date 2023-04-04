#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void 
checkFiles ()
{
    FILE *destination;
    FILE *bucketlist;
    FILE *trips;

    destination=fopen("destination.txt", "r");
    if(destination==NULL)
    {
        fclose(destination);
        destination=fopen("destination.txt", "w");
        fprintf(destination, "\n");
        fclose(destination);
    }
    
    bucketlist=fopen("bucketlist.txt", "r");
    if(bucketlist==NULL)
    {
        fclose(bucketlist);
        bucketlist=fopen("bucketlist.txt", "w");
        fprintf(bucketlist, "\n");
        fclose(bucketlist);
    }

    trips=fopen("trips.txt", "r");
    if (trips==NULL)
    {
        fclose(trips);
        trips=fopen("trips.txt", "w");
        fprintf(trips, "\n");
        fclose(trips);
    }
}

int
destInit (destination* data)
{
    int i=0;
    int n=-1;

    FILE* f1;
    f1 = fopen("destination.txt", "r");

    for (i=0;!feof(f1);i++)
    {
        fscanf(f1, " %s %s", data[i].shortName, data[i].longName);
        fscanf(f1, " %s", data[i].country);
        fscanf(f1, " %[^\n]", data[i].geoGroup);
        fscanf(f1, " %[^\n]", data[i].toDo);
        n++;
    }

    fclose(f1);

    return n;
}

int 
buckInit (goal* data)
{
    int i=0;
    int num=-1;

    FILE* f1;
    f1 = fopen("bucketlist.txt", "r");

    for (i=0;!feof(f1);i++)
    {
        fscanf(f1, " %s", data[i].shortName);
        fscanf(f1, " %d", &data[i].prioRank);
        fscanf(f1, " %[^\n]", data[i].remarks);
        fscanf(f1, " %d", &data[i].flag);
        num++;
    }

    fclose(f1);
    return num;
}

int 
tripInit (travelPlan* trips)
{
    int i=0;    
    int num=-1;
    travelPlan* start;

    start=trips;

    FILE* f1;
    f1 = fopen("trips.txt", "r");

    for (i=0;!feof(f1);i++)
    {
        fscanf(f1, " %s", trips->shortName);
        trips->next=calloc(1, sizeof(travelPlan));
        trips=trips->next;
        num++;
    }

    trips=start;

    return num;
}

void
iteInit (travelPlan* trips, 
        int n)
{
    int i=0;
    FILE* f1;
    str_t temp;
    travelPlan* start;
    start=trips;

    trips=start;
}


void
init (destination* dest, 
        goal* bucketlist, 
        travelPlan* trips, 
        int *destnum, 
        int *bucketlistnum, 
        int *tripnum)
{
    checkFiles();
    *destnum=destInit(dest);
    *bucketlistnum=buckInit(bucketlist);
    *tripnum=tripInit(trips);
    iteInit(trips, *tripnum);
}