void 
displayBucketlist(goal* bucketlist, int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        printf("\n%s", bucketlist[i].shortName);
        printf("\n- %d",  bucketlist[i].prioRank);
        printf("\n- %s",  bucketlist[i].remarks);
        if (bucketlist[i].flag )printf("\n- Achieved");
        else printf("\n- Yet to be Achieved");
    }
    return;
}

void
addGoal(goal* bucketlist, int n)
{

}

void
deleteGoal(goal* bucketlist, int *n)
{
    str_t temp;
    int i=0;

    printf("\nEnter shortname of goal you would like to delete");
    do
    {
        if(i>0) printf("\nINVALID\n");
        printf("\nSHORTNAME (CASE SENSITIVE): ");
        scanf(" %s", temp);
        i++;
    } while(!shortNameValidationGoal(bucketlist, temp, n));

    for (i=0;i<*n;i++)
    {
        if (!strcmp(bucketlist[i].shortName, temp))
        {
            for(i=i;i<*n;i++) bucketlist[i]=bucketlist[i+1];
            *n-=1;
        }
    }
}

void
editGoal(goal* bucketlist, int *n)
{
    str_t temp;
    int i=0;

    printf("\nEnter shortname of goal you would like to delete");
    do
    {
        if(i>0) printf("\nINVALID\n");
        printf("\nSHORTNAME (CASE SENSITIVE): ");
        scanf(" %s", temp);
        i++;
    } while(!shortNameValidationGoal(bucketlist, temp, n));

    for (i=0;i<*n;i++)
    {
        if (!strcmp(bucketlist[i].shortName, temp))
        {
            
        }
    }
}

void
changeAchieved(goal* bucketlist, int n)
{

}

void
buckMenu(goal* bucketlist, int n)
{
    
}