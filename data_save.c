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
saveIte (travelPlan* trips, int n)
{
    int i=0, j=0;
    FILE* f1;
    str_t temp;

    for(i=0;i<n;i++)
    {
        strcpy(temp, trips[i].shortName);
        strcat(temp, "-itinerary.txt");
        f1=fopen(temp, "w");

        fprintf(f1, "%s\n", trips[i].startDate);
        fprintf(f1, "%f\n", trips[i].rating);
        fprintf(f1, "%s\n", trips[i].comments);
        for (j=0;j<trips[i].days;j++)
        {
            fprintf(f1, "Day%d\n", trips[i].itinerary->day);
            fprintf(f1, "Morning\n");
            fprintf(f1, "%s\n", trips[i].itinerary->morning);
            fprintf(f1, "Afternoon\n");
            fprintf(f1, "%s\n", trips[i].itinerary->afternoon);
            fprintf(f1, "Evening\n");
            fprintf(f1, "%s\n\n", trips[i].itinerary->evening);
            trips[i].itinerary=trips[i].itinerary->next;
        }
        trips[i].itinerary=trips[i].start;
        trips[i].days=j;
        fclose(f1);
    }
}

void
saveTrip (travelPlan* trips, int n)
{
    int i=0;    

    FILE* f1;
    f1 = fopen("trips.txt", "w");

    for (i=0;i<n;i++)
    {
        fprintf(f1, " %s\n", trips[i].shortName);
    }

    fclose(f1);
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
    saveBuck(bucketlist, *bucketlistnum);
    saveTrip(trips, *tripnum);
    saveIte(trips, *tripnum);
}