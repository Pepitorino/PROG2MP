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
addGoal(destination* destinations, goal* bucketlist, int *n, int *dn)
{
    char choice;
    int i=0;
    str_t temp;

    do
    {
        if (i>0) printf("\nINVALID\n\n");
        printf("Enter Shortname from list of Destinations (10 max length): ");
        scanf(" %10[^\n]%*[^\n]", temp);
        i++;
    } while (!shortNameValidationDestination(destinations, temp, dn));
    strcpy(bucketlist[i].shortName, temp);
    
    do
    {
        printf("Enter Priority Ranking(1-10): ");
        scanf(" %d", &bucketlist[*n].prioRank);
        fflush(stdin);
        if (bucketlist[*n].prioRank>10||bucketlist[*n].prioRank<1) printf("\nINVALID\n");
    } while (bucketlist[*n].prioRank>10||bucketlist[*n].prioRank<1);

    do 
    {
        printf("Enter Remarks (30 max length): ");
        scanf(" %[^\n]", bucketlist[*n].remarks);
    } while(InputValidation(bucketlist[*n].remarks, 30));

    do
    {
        printf("Achieved? (Y/N):");
        scanf(" %c", &choice);
        if (!checkYesOrNo(choice)) printf("\nInvalid\n");
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
                printf("\n3. EXIT");
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
                            scanf(" %d", &bucketlist[i].prioRank);
                            if (bucketlist[i].prioRank>10||bucketlist[i].prioRank<1) printf("\nINVALID\n");
                        } while (bucketlist[i].prioRank>10||bucketlist[i].prioRank<1);
                        break;
                    case 2:
                        printf("\nOLD REMARKS: %s", bucketlist[i].remarks);
                        printf("\nEnter new remarks: "); 
                        scanf(" %30[^\n]%*[^\n]", bucketlist[i].remarks);
                        break;
                    case 3: break;                    
                    default: printf("\nINVALID\n");
                }
            } while (choice!=3);
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
buckMenu(destination* destinations, goal* bucketlist, int *n, int* dn)
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
        scanf(" %d", &choice);
        fflush(stdin);
        switch(choice)
        {
            case 1: displayBucketlist(bucketlist, *n); break;
            case 2: addGoal(destinations, bucketlist, n, dn); break;
            case 3: deleteGoal(bucketlist, n); break;
            case 4: editGoal(bucketlist, n); break;
            case 5: changeAchieved(bucketlist, n); break;
            case 6: break;
            default: printf("\nINVALID\n");
        }
    } while (choice!=6);
}