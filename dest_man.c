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
        if(i>0) printf("\nINVALID (TYPE \"EXIT\" TO EXIT) \n");
        printf("Enter Shortname (10 max length and must be UNIQUE): ");
        scanf(" %[^\n]", dest[*n].shortName);
        i++;
        if (!strcmp(dest[*n].shortName, "EXIT")) return;
    } while (inputValidation(dest[*n].shortName, 10)&&!shortNameValidationDestination(dest, dest[*n].shortName, n));

    i=0;
    do
    {
        if(i>0) printf("\nINVALID (TYPE \"EXIT\" TO EXIT) \n");
        printf("Enter Longname (50 max length): ");
        scanf(" %[^\n]", dest[*n].longName);
        i++;
        if (!strcmp(dest[*n].longName, "EXIT")) return;
    } while (inputValidation(dest[*n].longName, 50));
    
    i=0;
    do
    {
        if(i>0) printf("\nINVALID (TYPE \"EXIT\" TO EXIT) \n");
        printf("Enter Country (20 max length): ");
        scanf(" %[^\n]", dest[*n].country);
        i++;
        if (!strcmp(dest[*n].country, "EXIT")) return;
    } while (inputValidation(dest[*n].country, 20));
    
    i=0;
    do
    {
        if(i>0) printf("\nINVALID (TYPE \"EXIT\" TO EXIT) \n");
        printf("Enter Geographic Group (20 max length): ");
        scanf(" %[^\n]", dest[*n].geoGroup);
        i++;
        if (!strcmp(dest[*n].geoGroup, "EXIT")) return;
    } while (inputValidation(dest[*n].geoGroup, 20));

    i=0;
    do
    {
        if(i>0) printf("\nINVALID (TYPE \"EXIT\" TO EXIT) \n");
        printf("Enter Activities to Do (100 max length): ");
        scanf(" %[^\n]", dest[*n].toDo);
        i++;
        if (!strcmp(dest[*n].toDo, "EXIT")) return;
    } while (inputValidation(dest[*n].toDo, 100));

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
        if(i>0) printf("\nINVALID (TYPE \"EXIT\" TO EXIT) \n");
        printf("\nSHORTNAME (CASE SENSITIVE): ");
        scanf(" %s", temp);
        i++;
        if (!strcmp(temp, "EXIT")) return;
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
        if(i>0) printf("\nINVALID (TYPE \"EXIT\" TO EXIT) \n");
        printf("\nSHORTNAME (CASE SENSITIVE): ");
        scanf(" %s", temp);
        i++;
        if (!strcmp(temp, "EXIT")) return;
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
                            if(inputValidation(dest[i].longName, 50)) printf("\nINVALID\n");
                        } while (inputValidation(dest[i].longName, 50));
                        break;
                    case 2:
                        do
                        {
                            printf("\nOLD COUNTRY: %s", dest[i].country);
                            printf("\nEnter new country (20 max length): ");
                            scanf("%[^\n]", dest[i].country);
                            if(inputValidation(dest[i].country, 20)) printf("\nINVALID\n");
                        } while (inputValidation(dest[i].country, 20));
                        break;
                    case 3:
                        do
                        {
                            printf("\nOLD GEOGRAPHIC GROUP: %s", dest[i].geoGroup);
                            printf("\nEnter new geographic group (20 max length): ");
                            scanf(" %[^\n]", dest[i].geoGroup);
                            if(inputValidation(dest[i].geoGroup, 20)) printf("\nINVALID\n");
                        } while (inputValidation(dest[i].geoGroup, 20));
                        break;
                    case 4:
                        do
                        {
                            printf("\nOLD ACTIVTIES TO DO: %s", dest[i].toDo);
                            printf("\nEnter activities to do (100 max length): ");
                            scanf(" %[^\n]", dest[i].toDo);
                            if(inputValidation(dest[i].toDo, 100)) printf("\nINVALID\n");
                        } while (inputValidation(dest[i].toDo, 100));
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
            case 4: 
                if (*n<=0) deleteDestination(dest, n); 
                else printf("\nNO DESTINATIONS TO DELETE\n");
                break;
            case 5: 
                if (*n<=0) editDestination(dest, n);
                else printf("\nNO DESTINATIONS TO EDIT\n");
                break;
            case 6: break;
            default: printf("\nINVALID\n");
        }
    } while (choice!=6);
}