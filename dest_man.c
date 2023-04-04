void
shortDisplay(destination* dest, 
            int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        printf("\n%s", dest[i].shortName);
        printf("\n- %s",  dest[i].longName);
    }
    return;
}

void
longDisplay(destination* dest, 
            int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        printf("\n%s", dest[i].shortName);
        printf("\n- %s",  dest[i].longName);
        printf("\n- %s",  dest[i].country);
        printf("\n- %s",  dest[i].geoGroup);
        printf("\n- %s",  dest[i].toDo);
    }
    return;
}

void
addDestination(destination* dest,
            int *n)
{
    printf("Enter Short name: ");
    scanf(" %10[^\n]%*[^\n]", dest[*n].shortName);

    printf("Enter Long name: ");
    scanf(" %50[^\n]%*[^\n]", dest[*n].longName);

    printf("Enter Country: ");
    scanf(" %20[^\n]%*[^\n]", dest[*n].country);

    printf("Enter Geographic Group: ");
    scanf(" %20[^\n]%*[^\n]", dest[*n].geoGroup);

    printf("Enter \"Activites to do\": ");
    scanf(" %100[^\n]%*[^\n]", dest[*n].toDo);

    *n+=1;
}

void
deleteDestination(destination* dest,
            int *n)
{
    str_t temp;
    int i=0;

    printf("\nEnter shortname of destination you would like to delete");
    do
    {
        if(i>0) printf("\nINVALID\n");
        printf("\nSHORTNAME (CASE SENSITIVE): ");
        scanf(" %s", temp);
        i++;
    } while(!shortNameValidationDestination(dest, temp, n));

    for (i=0;i<*n;i++)
    {
        if (!strcmp(dest[i].shortName, temp))
        {
            for(i=i;i<*n;i++) dest[i]=dest[i+1];
            *n-=1;
        }
    }
    
}

void
editDestination(destination* dest,
            int *n)
{
    str_t temp;
    int i=0;
    int choice=0;

    printf("\nEnter shortname of destination you would like to edit");
    do
    {
        if(i>0) printf("INVALID\n");
        printf("\nSHORTNAME (CASE SENSITIVE): ");
        scanf(" %s", temp);
        i++;
    } while(!shortNameValidationDestination(dest, temp, n));

     for (i=0;i<*n;i++)
    {
        if (!strcmp(dest[i].shortName, temp))
        {
            do
            {
                printf("\nEDIT DESTINATION %s", temp);
                printf("\n1. LONG NAME");
                printf("\n2. COUNTRY");
                printf("\n3. GEOGRAPHIC GROUP");
                printf("\n4. ACTIVITIES TO DO");
                printf("\n5. EXIT");
                printf("\nWHERE WOULD YOU LIKE TO GO: ");
                scanf(" %d%*[^\n]", &choice);
                switch(choice)
                {
                    case 1:
                        printf("\nOLD LONGNAME: %s", dest[i].longName);
                        printf("\nEnter new longname: "); 
                        scanf("%s", dest[i].longName);
                        break;
                    case 2:
                        printf("\nOLD COUNTRY: %s", dest[i].country);
                        printf("\nEnter new country: "); 
                        scanf("%s", dest[i].country);
                        break;
                    case 3:
                        printf("\nOLD GEOGRAPHIC GROUP: %s", dest[i].geoGroup);
                        printf("\nEnter new geographic group: "); 
                        scanf("%s", dest[i].geoGroup);
                        break;
                    case 4:
                        printf("\nOLD ACTIVITIES TO DO: %s", dest[i].toDo);
                        printf("\nEnter new activities to do: "); 
                        scanf("%s", dest[i].toDo);
                    case 5: break;                    
                    default: printf("\nINVALID\n");
                }
            } while (choice!=5);
            i=*n;
        }
    }
}

void
destMenu(destination* dest,
        int *n)
{
    int choice;
    do
    {
        printf("\n\nDESTINATION MENU");
        printf("\nOPTIONS:");
        printf("\n1. DISPLAY LIST (SHORT)");
        printf("\n2. DISPLAY LIST (LONG)");
        printf("\n3. ADD DESTINATION");
        printf("\n4. DELETE DESTINATION");
        printf("\n5. EDIT DESTINATION");
        printf("\n6. EXIT");
        printf("\nWhat would you like to do: ");
        scanf(" %d%*[^\n]", &choice);
        switch(choice)
        {
            case 1: shortDisplay(dest, *n); break;
            case 2: longDisplay(dest, *n); break;
            case 3: addDestination(dest, n); break;
            case 4: deleteDestination(dest, n); break;
            case 5: editDestination(dest, n); break;
            case 6: break;
            default: printf("\nINVALID\n");
        }
    } while (choice!=6);
}