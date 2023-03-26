#include "types.h"
#include <stdio.h>
#include <string.h>

int
dest_init (Destination* data)
{
    int i=0;
    int n=-1;
    char temp;

    FILE* f1;
    f1 = fopen("destination.txt", "r");

    if (f1==NULL)
    {
        f1=fopen("bucketlist.txt", "w+");
    }

    for (i=0;!feof(f1);i++)
    {
        fscanf(f1, "%s %s", data[i].shortName, data[i].longName);
        fscanf(f1, "%s", data[i].country);
        fscanf(f1, "%s", data[i].geoGroup);
        temp = getc(f1);
        fgets(data[i].toDo, 100, f1);
        n++;
    }

    fclose(f1);

    return n;
}

int
bucketlist_init (Goals* data)
{
    int i=0;
    int n=sizeof(data)/sizeof(data[0]);
    int num=-1;

    FILE* f1;
    f1 = fopen("bucketlist.txt", "r");

    if (f1==NULL)
    {
        f1=fopen("bucketlist.txt", "w+");
    }

    for (i=0;i<n&&!feof(f1);i++)
    {
        fscanf(f1, "%s", data[i].shortName);
        fscanf(f1, "%d", &data[i].priorityRank);
        fscanf(f1, "%[\n]s", data[i].remarks);
        fscanf(f1, "%s", data[i].achievedFlag);
        num++;
    }

    fclose(f1);
    return num;
}
