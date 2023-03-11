#include "types.h"
#include <stdio.h>

void
dest_init (Destination* data)
{
    int i=0;
    int n=sizeof(data)/sizeof(data[0]);

    FILE* f1;
    f1 = fopen("destination.txt", "r");

    for (i=0;i<n;i++)
    {
        fscanf(f1, "%s %s", data[i].shortName, data[i].longName);
        fscanf(f1, "%s", data[i].country);
        fscanf(f1, "%s", data[i].geoGroup);
        fscanf(f1, "%s", data[i].toDo);
    }
}

void 
bucketlist_init (Goals* data)
{
    int i=0;
    int n=sizeof(data)/sizeof(data[0]);

    FILE* f1;
    f1 = fopen("bucketlist.txt", "r");

    for (i=0;i<n;i++)
    {
        fscanf(f1, "%s", data[i].shortName);
        fscanf(f1, "%d", &data[i].priorityRank);
        fscanf(f1, "%s", data[i].remarks);
        fscanf(f1, "%s", data[i].achievedFlag);
    }
}

void
data_init (Destination* dest, Goals* bucketlist)
{
    dest_init(dest);
    bucketlist_init(bucketlist);
}