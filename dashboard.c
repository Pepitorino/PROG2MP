int
shortNameValidationTempGoal(goal* data, str_t temp)
{
    int i=0;
    for (i=0;i<3;i++)
    {
        if (!strcmp(data[i].shortName, temp)) return 1;
    }
    return 0;
}

int
shortNameValidationTempTrip(travelPlan* data, str_t temp)
{
    int i=0;
    for (i=0;i<3;i++)
    {
        if (!strcmp(data[i].shortName, temp)) return 1;
    }
    return 0;
}

void
topthreebucketlist(destination* dest, 
                    goal* bucketlist, 
                    int dn, 
                    int bn)
{
    int i=0;
    int j=0;
    goal temp[3];
    str_t longname[3];

    for(i=0;i<3;i++)
    {
        temp[i].prioRank=11;
    }

    for(i=0;i<3;i++)
    {
        for(j=0;j<bn;j++)
        {
            if (bucketlist[j].prioRank<temp[i].prioRank&&!shortNameValidationTempGoal(temp, bucketlist[j].shortName)) temp[i]=bucketlist[j];
        }
    }

    for(i=0;i<3;i++)
    {
        for(j=0;j<dn;j++)
        {
            if(!strcmp(temp[i].shortName, dest[j].shortName)) strcpy(longname[i], dest[j].longName);
        }
    }

    printf("\nTOP 3 BUCKETLIST DESTINATIONS");
    printf("\nSHORTNAME\tLONGNAME\tPRIORITY");

    for(i=0;i<3;i++)
    {
        printf("\n%s\t\t%s\t\t%d",temp[i].shortName, longname[i], temp[i].prioRank);
    }
}

void
topthreedest(destination* dest, 
            travelPlan* trips, 
            int dn, 
            int tn)
{
    int i=0;
    int j=0;
    travelPlan temptrip[3];
    destination tempdest[3];

    for(i=0;i<3;i++)
    {
        strcpy(temptrip[i].shortName,"NO DATA AVAILABLE");
        temptrip[i].rating=-1;
    }

    for(i=0;i<3;i++)
    {
        for(j=0;j<tn;j++)
        {
            if(trips[j].rating>temptrip[i].rating&&!shortNameValidationTempTrip(temptrip, trips[j].shortName)) temptrip[i]=trips[j];
        }
    }

    for(i=0;i<3;i++)
    {
        for(j=0;j<dn;j++)
        {
            if(!strcmp(temptrip[i].shortName, dest[j].shortName)) tempdest[i]=dest[j];
        }
    }

    printf("\n\t\t   TOP 3 DESTINATIONS");
    printf("\nRATING\tSHORTNAME\tLONGNAME\tGEOLOCATION");

    for(i=0;i<3&&i<tn;i++)
    {
        printf("\n%.1f\t%s\t%s\t%s", temptrip[i].rating, temptrip[i].shortName, tempdest[i].longName, tempdest[i].geoGroup);
    }
}

void
bucketlistProgress(goal*bucketlist, int bn)
{
    int i=0;
    int counter=0;
    float progress;
    for(i=0;i<bn;i++)
    {
        if (bucketlist[i].flag>0) counter++;
    }
    progress=(float)counter/(float)bn;
    printf("\nBucketlist Progress: %d out of %d or %.0f%% achieved", counter, bn, progress*100);
}

void
dashboard (destination* dest, 
            goal* bucketlist, 
            travelPlan* trips, 
            int dn, 
            int bn, 
            int tn)
{
    topthreebucketlist(dest, bucketlist, dn, bn);
    topthreedest(dest, trips, dn, tn);
    printf("\n");
    bucketlistProgress(bucketlist, bn);
}