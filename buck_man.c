void 
displayBucketlist(goal* bucketlist, int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        printf("\n%s", bucketlist[i].shortName);
        printf("\n- %d",  bucketlist[i].prioRank);
        printf("\n- %s",  bucketlist[i].remarks);
        if (bucketlist[i].flag==1)printf("\n- Achieved");
        else printf("\n- Yet to be Achieved");
    }
    return;
}

void
addGoal(goal* bucketlist, int *n)
{
    char choice;

    printf("Enter Shortname: ");
    scanf(" %10[^\n]%*[^\n]", bucketlist[*n].shortName);

    do
    {
    printf("Enter Priority Ranking(1-10): ");
    scanf(" %d", &bucketlist[*n].prioRank);
    fflush(stdin);
    if (bucketlist[*n].prioRank>10||bucketlist[*n].prioRank<1) printf("\nINVALID\n");
    } while (bucketlist[*n].prioRank>10||bucketlist[*n].prioRank<1);

    printf("Enter Remarks: ");
    scanf(" %30[^\n]%*[^\n]", bucketlist[*n].remarks);

    do
    {
        printf("Achieved? (Y/N):");
        scanf(" %c", &choice);
        if (!checkYesOrNo(choice)) printf("\nInvalid");
    } while (!checkYesOrNo(choice));

    bucketlist[*n].flag=checkYesOrNo(choice);

    *n+=1;
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
    int choice;

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
            do
            {
                printf("\nEDIT GOAL %s", temp);
                printf("\n1. PRIORITY RANK");
                printf("\n2. REMARKS");
                printf("\nWHERE WOULD YOU LIKE TO GO: ");
                scanf(" %d", &choice);
                fflush(stdin);
                switch(choice)
                {
                    case 1:
                        do
                        {
                            printf("\nOLD PRIORITY RANK: %d", bucketlist[i].prioRank);
                            printf("\nEnter new priority rank(1-10): "); 
                            scanf(" %d", bucketlist[i].prioRank);
                            if (bucketlist[i].prioRank>10||bucketlist[i].prioRank<1) printf("\nINVALID\n");
                        } while (bucketlist[i].prioRank>10||bucketlist[i].prioRank<1);
                        break;
                    case 2:
                        printf("\nOLD REMARKS: %s", bucketlist[i].remarks);
                        printf("\nEnter new remarks: "); 
                        scanf(" %30[^\n]", bucketlist[i].remarks);
                        break;
                    case 5: break;                    
                    default: printf("\nINVALID\n");
                }
            } while (choice!=5);
            i=*n;
        }
    }
}

void
changeAchieved(goal* bucketlist, int *n)
{
    str_t temp;
    int i=0;

    printf("\nEnter shortname of goal to mark/unmark as achieved");
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
            bucketlist[i].flag=-(bucketlist[i].flag);
        }
    }

}

void
buckMenu(goal* bucketlist, int *n)
{
    int choice;
    do
    {
        printf("\n\nBUCKETLIST MENU");
        printf("\nOPTIONS:");
        printf("\n1. DISPLAY LIST");
        printf("\n2. ADD GOAL");
        printf("\n3. DELETE GOAL");
        printf("\n4. EDIT GOAL");
        printf("\n5. MARK/UNMARK AS ACHIEVED");
        printf("\n6. BACK TO MAIN MENU");
        printf("\nWhat would you like to do: ");
        scanf(" %d%*[^\n]", &choice);
        switch(choice)
        {
            case 1: displayBucketlist(bucketlist, *n); break;
            case 2: addGoal(bucketlist, n); break;
            case 3: deleteGoal(bucketlist, n); break;
            case 4: editGoal(bucketlist, n); break;
            case 5: changeAchieved(bucketlist, n); break;
            case 6: break;
            default: printf("\nINVALID\n");
        }
    } while (choice!=6);
}