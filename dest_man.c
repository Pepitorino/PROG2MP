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
    int i=0;
    do
    {
        if(i>0) printf("\nINVALID\n");
        printf("Enter Shortname (10 max length and must be UNIQUE): ");
        scanf(" %[^\n]", dest[*n].shortName);
        i++;
    } while (InputValidation(dest[*n].shortName, 10)&&!shortNameValidationDestination(dest, dest[*n].shortName, n));

    i=0;
    do
    {
        if(i>0) printf("\nINVALID\n");
        printf("Enter Longname (50 max length): ");
        scanf(" %[^\n]", dest[*n].longName);
        i++;
    } while (InputValidation(dest[*n].longName, 50));
    
    i=0;
    do
    {
        if (i>0) printf("\nINVALID\n");
        printf("Enter Country (20 max length): ");
        scanf(" %[^\n]", dest[*n].country);
        i++;
    } while (InputValidation(dest[*n].country, 20));
    
    i=0;
    do
    {
        if (i>0) printf("\nINVALID\n");
        printf("Enter Geographic Group (20 max length): ");
        scanf(" %[^\n]", dest[*n].geoGroup);
        i++;
    } while (InputValidation(dest[*n].geoGroup, 20));

    i=0;
    do
    {
        if (i>0) printf("\nINVALID\n");
        printf("Enter Activities to Do (100 max length): ");
        scanf(" %[^\n]", dest[*n].toDo);
        i++;
    } while (InputValidation(dest[*n].toDo, 100));

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
                scanf(" %d", &choice);
                fflush(stdin);
                switch(choice)
                {
                    case 1:
                        do
                        {
                            printf("\nOLD LONGNAME: %s", dest[i].longName);
                            printf("\nEnter new longname (50 max length): ");
                            scanf(" %[^\n]", dest[i].longName);
                            if(InputValidation(dest[i].longName, 50)) printf("\nINVALID\n");
                        } while (InputValidation(dest[i].longName, 50));
                        break;
                    case 2:
                        do
                        {
                            printf("\nOLD COUNTRY: %s", dest[i].country);
                            printf("\nEnter new country (20 max length): ");
                            scanf("%[^\n]", dest[i].country);
                            if(InputValidation(dest[i].country, 20)) printf("\nINVALID\n");
                        } while (InputValidation(dest[i].country, 20));
                        break;
                    case 3:
                        do
                        {
                            printf("\nOLD GEOGRAPHIC GROUP: %s", dest[i].geoGroup);
                            printf("\nEnter new geographic group (20 max length): ");
                            scanf(" %[^\n]", dest[i].geoGroup);
                            if(InputValidation(dest[i].geoGroup, 20)) printf("\nINVALID\n");
                        } while (InputValidation(dest[i].geoGroup, 20));
                        break;
                    case 4:
                        do
                        {
                            printf("\nOLD ACTIVTIES TO DO: %s", dest[i].toDo);
                            printf("\nEnter activities to do (100 max length): ");
                            scanf(" %[^\n]", dest[i].toDo);
                            if(InputValidation(dest[i].toDo, 100)) printf("\nINVALID\n");
                        } while (InputValidation(dest[i].toDo, 100));
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
        printf("\n6. BACK TO MAIN MENU");
        printf("\nWhat would you like to do: ");
        scanf(" %d", &choice);
        fflush(stdin);
        switch(choice)
        {
            case 1: shortDisplay(dest, *n); break;
            case 2: longDisplay(dest, *n); break;
            case 3: 
                if (*n<100) addDestination(dest, n); 
                else printf("\nMAX DESTINATIONS REACHED\n");
                break;
            case 4: deleteDestination(dest, n); break;
            case 5: editDestination(dest, n); break;
            case 6: break;
            default: printf("\nINVALID\n");
        }
    } while (choice!=6);
}