/* Prints out all the information of the elements in the bucketlist
@param bucketlist - array of goals
@param n - number of elements in the bucketlist
@return none
Precondition: all parameters are initialized
*/
void 
displayBucketlist(goal* bucketlist, 
                    int n)
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
    if (n=0) printf("\nNO GOALS\n");
    return;
}

/* Adds a goal to the front of the bucketlist
@param destinations - used to check if the goal to be added is present in destinations
@param bucketlist - array to which the goal will be added to
@param n - number of elements in the bucketlist, incremented by one afterwards
@param dn - number of elements in destinations
Precondition: bucketlist is not already full
*/
void
addGoal(destination* destinations, 
        goal* bucketlist, 
        int *n, 
        int *dn)
{
    char choice;
    int i=0;
    str_t temp;

    do
    {
        if(i>0) printf("\nINVALID (TYPE \"EXIT\" TO EXIT) \n");
        if (shortNameValidationGoal(bucketlist, temp, n)) printf("GOAL ALREADY EXISTS\n");
        printf("Enter Shortname from list of Destinations (10 max length): ");
        scanf(" %10[^\n]%*[^\n]", temp);
        i++;
        if (!strcmp(temp, "EXIT")) return;
    } while (!shortNameValidationDestination(destinations, temp, dn)||shortNameValidationGoal(bucketlist, temp, n));
    strcpy(bucketlist[*n].shortName, temp);
    
    do
    {
        printf("Enter Priority Ranking(1-10): ");
        scanf(" %d", &bucketlist[*n].prioRank);
        fflush(stdin);
        if (bucketlist[*n].prioRank>10||bucketlist[*n].prioRank<1) printf("\nINVALID\n");
    } while (bucketlist[*n].prioRank>10||bucketlist[*n].prioRank<1);

    i=0;
    do 
    {
        if(i>0) printf("\nINVALID (TYPE \"EXIT\" TO EXIT) \n");
        printf("Enter Remarks (30 max length): ");
        scanf(" %[^\n]", bucketlist[*n].remarks);
        if (!strcmp(temp, "EXIT")) return;
    } while(inputValidation(bucketlist[*n].remarks, 30));

    do
    {
        printf("Achieved? (Y/N):");
        scanf(" %c", &choice);
        if (!checkYesOrNo(choice)) printf("\nInvalid\n");
    } while (!checkYesOrNo(choice));

    bucketlist[*n].flag=checkYesOrNo(choice);

    *n+=1;
}

/* Deletes a goal from the bucketlist 
@param bucketlist - array with the goal to be deleted
@param n - number of elements in the bucketlist, decremented by one after deletion
Precondition: bucketlist is not empty
*/
void
deleteGoal(goal* bucketlist, 
            int *n)
{
    str_t temp;
    int i=0;

    printf("\nEnter shortname of goal you would like to delete");
    do
    {
        if(i>0) printf("\nINVALID (TYPE \"EXIT\" TO EXIT) \n");
        printf("\nSHORTNAME (CASE SENSITIVE): ");
        scanf(" %s", temp);
        if (!strcmp(temp, "EXIT")) return;
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

/* Edits a goal from the bucketlist 
@param bucketlist - array of goals
@param n - number of elements in the bucketlist
Precondition: bucketlist is not empty
*/
void
editGoal(goal* bucketlist, 
            int *n)
{
    str_t temp;
    int i=0;
    int choice;

    printf("\nEnter shortname of goal you would like to delete");
    do
    {
        if(i>0) printf("\nINVALID (TYPE \"EXIT\" TO EXIT) \n");
        printf("\nSHORTNAME (CASE SENSITIVE): ");
        scanf(" %s", temp);
        if (!strcmp(temp, "EXIT")) return;
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

/* Marks a goal from the bucketlist as achieved or unachieved
@param bucketlist - array with goal to be marked
@param n - number of elements in the bucketlist
Precondition: bucketlist is not empty
*/
void
changeAchieved(goal* bucketlist, 
                int *n)
{
    str_t temp;
    int i=0;

    printf("\nEnter shortname of goal to mark/unmark as achieved");
    do
    {
        if(i>0) printf("\nINVALID (TYPE \"EXIT\" TO EXIT) \n");
        printf("\nSHORTNAME (CASE SENSITIVE): ");
        scanf(" %s", temp);
        i++;
        if (!strcmp(temp, "EXIT")) return;
    } while(!shortNameValidationGoal(bucketlist, temp, n));

    for (i=0;i<*n;i++)
    {
        if (!strcmp(bucketlist[i].shortName, temp))
        {
            bucketlist[i].flag=-(bucketlist[i].flag);
        }
    }

}

/*Menu to access functions to add/delete/edit elements in the bucketlist
@param destinations - array of destinations
@param bucketlist - array of goals
@param n - number of elements in bucketlist
@param dn - number of elements in destinations
Precondition: all parameters are initialized
*/
void
buckMenu(destination* destinations, 
            goal* bucketlist, 
            int *n, 
            int* dn)
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
            case 1: 
                displayBucketlist(bucketlist, *n); 
                break;
            case 2: 
                if(*n<10) addGoal(destinations, bucketlist, n, dn); 
                else printf("MAX NUMBER OF GOALS REACHED");
                break;
            case 3: 
                if (*n>0) deleteGoal(bucketlist, n); 
                else printf("NO GOALS TO DELETE");
                break;
            case 4: 
                if (*n>0) editGoal(bucketlist, n); 
                else printf("NO GOALS TO EDIT");
                break;
            case 5: 
                if (*n>0) changeAchieved(bucketlist, n); 
                else printf("NO GOALS TO EDIT");
                break;
            case 6: break;
            default: printf("\nINVALID\n");
        }
    } while (choice!=6);
}