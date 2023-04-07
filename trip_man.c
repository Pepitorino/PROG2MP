void
displayTrips(travelPlan* trips, 
            int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        printf("\n%s", trips[i].shortName);
        if (trips[i].rating>-1) printf("\n- %.1f",  trips[i].rating);
        else printf("\n- No rating available");
    }
    return;
}

void
viewIte(travelPlan* trips, 
        int *n)
{
        str_t temp;
        int i=0, j=0;

        do
        {
                if (i>0) printf("\nINVALID\n");
                printf("\nEnter Shortname of Trip to View: ");
                scanf(" %s%*[^\n]", temp);
                i++;
        } while (!shortNameValidationTrip(trips, temp, n));
        
        for (i=0;i<*n;i++)
        {
                if (!strcmp(trips[i].shortName, temp))
                {
                        printf("\nShort Name: %s", trips[i].shortName);
                        printf("\nStart Date: %s", trips[i].startDate);
                        if (trips[i].rating>=0) printf("\nRating: %.1f", trips[i].rating);
                        else printf("\nRating: No Rating Available");                        
                        printf("\nComments: %s", trips[i].comments);
                        for(j=0; j<trips[i].days; j++)
                        {
                                printf("\nDay %d Itinerary", trips[i].itinerary->day);
                                printf(" \n%s", trips[i].itinerary->morning);
                                printf(" \n%s", trips[i].itinerary->afternoon);
                                printf(" \n%s", trips[i].itinerary->evening);                                
                                trips[i].itinerary=trips[i].itinerary->next;
                        }
                        trips[i].itinerary=trips[i].start;
                        i=*n;
                }
        }
        

}

void
addTrip(destination* destinations,
        travelPlan* trips, 
        int *n,
        int *dn)
{
        int i=0;
        char ans;

        do
        {
                if(i>0) printf("\nINVALID (TYPE \"EXIT\" TO EXIT) \n");
                printf("Enter Shortname from list of Destinations (10 max length): ");
                scanf(" %10[^\n]%*[^\n]", trips[*n].shortName);
                i++;
                if (!strcmp(trips[*n].shortName, "EXIT")) return;
        } while (!shortNameValidationDestination(destinations, trips[*n].shortName, dn)||shortNameValidationTrip(trips, trips[*n].shortName, n));

        i=0;
        do
        {
                if(i>0) printf("\nINVALID (TYPE \"EXIT\" TO EXIT) \n");
                printf("Enter Startdate in mm/dd/yyyy (must be UNIQUE): ");
                scanf(" %s%*[^\n]", trips[*n].startDate);
                i++;
                if (!strcmp(trips[*n].startDate, "EXIT")) return;
        } while (inputDate(trips[*n].startDate)||startDateValidationTrip(trips, trips[*n].startDate, n));

        trips[*n].rating=-1;

        i=0;
        do 
        {
                if(i>0) printf("\nINVALID (TYPE \"EXIT\" TO EXIT)\n");
               printf("Enter comments (100 max length): ");
               scanf(" %[^\n]", trips[*n].comments);
               if (!strcmp(trips[*n].startDate, "EXIT")) return;
        } while(inputValidation(trips[*n].comments, 100));

        trips[*n].itinerary=calloc(1, sizeof(itinerary));
        trips[*n].start=trips[*n].itinerary;
        
        i=0;
        do
        {
                trips[*n].itinerary->day=i+1;
                do
                {
                        printf("Morning activity for day %d: ", trips[*n].itinerary->day);
                        scanf(" %20[^\n]%*[^\n]", trips[*n].itinerary->morning);
                } while (inputValidation(trips[*n].itinerary->morning, 20));
                
                do
                {
                        printf("Afternoon activity for day %d: ", trips[*n].itinerary->day);
                        scanf(" %20[^\n]%*[^\n]", trips[*n].itinerary->afternoon);
                } while (inputValidation(trips[*n].itinerary->afternoon, 20));
                
                do
                {
                        printf("Evening activity for day %d: ", trips[*n].itinerary->day);
                        scanf(" %20[^\n]%*[^\n]", trips[*n].itinerary->evening);
                } while (inputValidation(trips[*n].itinerary->evening, 20));

                trips[*n].itinerary->next=calloc(1, sizeof(itinerary));
                trips[*n].itinerary=trips[*n].itinerary->next;

                do
                {
                        printf("\nCONTINUE TO NEXT DAY? (Y/N): ");
                        scanf(" %c%*[^\n]", &ans);
                        if (ans!='Y'&&ans!='y'&&ans!='N'&&ans!='n') printf("\nINVALID\n");
                } while (ans!='Y'&&ans!='y'&&ans!='N'&&ans!='n');
                i++;

        } while (ans!='N'&&ans!='n') ;
        trips[*n].days=i;
        trips[*n].itinerary=trips[*n].start; 
        *n+=1;
}

void
deleteTrip(travelPlan* trips, 
            int *n)
{
        str_t temp;
        str_t tempdate;
        int i=0;

        do
        {
                if(i>0) printf("\nINVALID (TYPE \"EXIT\" TO EXIT) \n");
                printf("\nEnter shortname of trip you would like to delete");
                printf("\nSHORTNAME (CASE SENSITIVE): ");
                scanf(" %s", temp);
                i++;
                if (!strcmp(temp, "EXIT")) return;
        } while(!shortNameValidationTrip(trips, temp, n));

        i=0;
        do
        {
                if(i>0) printf("\nINVALID (TYPE \"EXIT\" TO EXIT) \n");
                printf("\nEnter start date of %s trip you would like to delete", temp);
                printf("\nSTARTDATE (dd/mm/yyyy): ");
                scanf(" %s", tempdate);
                i++;
                if (!strcmp(tempdate, "EXIT")) return;
        } while(!startDateValidationTrip(trips, tempdate, n));

        for (i=0;i<*n;i++)
        {
                if (!strcmp(trips[i].shortName, temp)&&!strcmp(trips[i].startDate, tempdate))
                {
                        for(i=i;i<*n;i++) trips[i]=trips[i+1];
                        *n-=1;
                }
        }
}

void
addDay(travelPlan* trips, 
        int n)
{
        int i;
        for (i=1;i<trips[n].days;i++)
        {
                trips[n].itinerary=trips[n].itinerary->next;
        }

        i=trips[n].itinerary->day;

        trips[n].itinerary->next=calloc(1, sizeof(itinerary));
        trips[n].itinerary=trips[n].itinerary->next;

        trips[n].itinerary->day=i+1;

        printf("\nNew Day %d", trips[n].itinerary->day);

        printf("\nEnter activity for Morning: ");
        scanf(" %30[^\n]%*[^\n]", trips[n].itinerary->morning);

        printf("Enter activity for Afternoon: ");
        scanf(" %30[^\n]%*[^\n]", trips[n].itinerary->afternoon);

        printf("Enter activity for Evening: ");
        scanf(" %30[^\n]%*[^\n]", trips[n].itinerary->evening);


        trips[n].itinerary=trips[n].start;
        trips[n].days+=1;
}

void
deleteDay(int day, 
        travelPlan* trips, 
        int n)
{
        int i=0;
        itinerary* temp;
        for (i=1;i<day-1;i++)
        {
                trips[n].itinerary=trips[n].itinerary->next;
        }
        temp=trips[n].itinerary;
        temp=temp->next;
        trips[n].itinerary->next=temp->next;
        free(temp);

        trips[n].days-=1;
        
        for(i=trips[n].itinerary->day;i<trips[n].days;i++)
        {
                trips[n].itinerary->day-=1;
        }
        trips[n].itinerary=trips[n].start;
}

void
editDay(int day, 
        travelPlan* trips, 
        int n)
{
        int i=0;
        int choice=0;
        for (i=1;i<day;i++)
        {
                trips[n].itinerary=trips[n].itinerary->next;
        }

        do
        {
                printf("\nCHOOSE ACTIVITY TO EDIT FOR DAY %d", trips[n].itinerary->day);
                printf("\nOLD ACTIVITIES\n:%s\n:%s\n:%s", trips[n].itinerary->morning,trips[n].itinerary->afternoon,trips[n].itinerary->evening);
                printf("\n1. MORNING");
                printf("\n2. AFTERNOON");
                printf("\n3. EVENING");
                printf("\n4. EXIT");
                printf("\nWHERE WOULD YOU LIKE TO GO: ");
                scanf(" %d", &choice);
                fflush(stdin);
                switch (choice)
                {
                        case 1:
                                printf("\nOLD MORNING ACTIVITY: %s", trips[n].itinerary->morning);
                                printf("\nENTER NEW ACTIVITY (30 max length): ");
                                scanf(" %30[^\n]%*[^\n]", trips[n].itinerary->morning);
                                break;
                        case 2:
                                printf("\nOLD AFTERNOON ACTIVITY: %s", trips[n].itinerary->afternoon);
                                printf("\nENTER NEW ACTIVITY (30 max length): ");
                                scanf(" %30[^\n]%*[^\n]", trips[n].itinerary->afternoon);
                                break;
                        case 3:
                                printf("\nOLD EVENING ACTIVITY: %s", trips[n].itinerary->evening);
                                printf("\nENTER NEW ACTIVITY (30 max length): ");
                                scanf(" %30[^\n]%*[^\n]", trips[n].itinerary->evening);
                                break;
                        case 4:
                                break;
                        default: printf("\nINVALID\n");
                }
        } while (choice!=4);
        

        trips[n].itinerary=trips[n].start;
}

void
editIte(travelPlan* trips, 
        int n)
{
        int choice=0;
        int choiceday;
        
        do
        {
                printf("\nEDITING %s ITINERARY", trips[n].shortName);
                printf("\n1. ADD A DAY");
                printf("\n2. DELETE A DAY");
                printf("\n3. EDIT A DAY");
                printf("\n4. BACK TO EDIT TRIP");
                printf("\nWHERE WOULD YOU LIKE TO GO: ");
                scanf(" %d", &choice);
                fflush(stdin);
                switch (choice)
                {
                        case 1:
                                addDay(trips, n);
                                break;
                        case 2:
                                if(trips[n].days==1) 
                                {
                                        printf("\nCAN'T DELETE ONLY DAY\n");
                                        break;
                                }
                                do
                                {
                                        printf("\nDAY TO DELETE : ");
                                        scanf(" %d", &choiceday);
                                        if (choiceday==-1) break;
                                        if (choiceday<0||choiceday>trips[n].days) printf("\nINVALID TYPE -1 TO GO BACK TO MENU\n");
                                } while (choiceday<0||choiceday>trips[n].days);
                                deleteDay(choiceday, trips, n);
                                break;
                        case 3: 
                                do
                                {
                                        printf("\nDAY TO EDIT : ");
                                        scanf(" %d", &choiceday);
                                        if (choiceday==-1) break;
                                        if (choiceday<0||choiceday>trips[n].days) printf("\nINVALID, TYPE -1 TO GO BACK TO MENU\n");
                                } while (choiceday<0||choiceday>trips[n].days);
                                editDay(choiceday, trips, n);
                        case 4: break;
                        default: printf("\nINVALID\n");
                }

        } while (choice!=4);
        
}

void
editTrip(travelPlan* trips, 
        int *n)
{
        str_t temp;
        int i=0;
        int choice;

        do
        {
                if(i>0) printf("\nINVALID (TYPE \"EXIT\" TO EXIT)\n");
                printf("\nEnter shortname of trip you would like to edit");
                printf("\nSHORTNAME (CASE SENSITIVE): ");
                scanf(" %s", temp);
                i++;
                if(!strcmp(temp, "EXIT")) return;
        } while(!shortNameValidationTrip(trips, temp, n));

        for(i=0;i<*n;i++)
        {       
                if (!strcmp(trips[i].shortName, temp)) 
                {
                        do
                        {
                                printf("\nEDIT TRIP %s", trips[i].shortName);
                                printf("\n1. COMMENTS");
                                printf("\n2. ITINERARY CONTENTS");
                                printf("\n3. EXIT");
                                printf("\nWHERE WOULD YOU LIKE TO GO: ");
                                scanf(" %d", &choice);
                                fflush(stdin);
                                switch(choice)
                                {
                                        case 1:
                                                printf("\nOLD COMMENT: %s", trips[i].comments);
                                                printf("\nEnter new comment (100 max length): "); 
                                                scanf(" %100[^\n]%*[^\n]", trips[i].comments);
                                                break;
                                        case 2: editIte(trips, i);
                                        case 3: break;
                                        default: printf("\nINVALID\n");
                                }
                        } while (choice!=3);
                        i=*n;
                }

        }
}


void
rateTrip(travelPlan* trips, 
        int *n)
{
        str_t temp;
        int i=0;

        do
        {
                if(i>0) printf("\nINVALID (TYPE \"EXIT\" TO EXIT)\n");
                printf("\nEnter shortname of trip you would like to rate");
                printf("\nSHORTNAME (CASE SENSITIVE): ");
                scanf(" %s", temp);
                if(!strcmp(temp, "EXIT")) return;
                i++;
        } while(!shortNameValidationTrip(trips, temp, n));

        for (i=0;i<*n;i++)
        {
                if (!strcmp(trips[i].shortName, temp))
                {
                        do
                        {
                                printf("Enter rating (0.0-5.0): ");
                                scanf(" %f", &trips[i].rating);
                                fflush(stdin);
                                if (trips[i].rating==-1) return;
                                if (!inputRatingValidation(trips[i].rating)) printf("\nINVALID ENTER \"-1.0\" TO EXIT\n");
                        } while (!inputRatingValidation(trips[i].rating)); 
                        i=*n;
                }
        }
}

void
tripMenu(destination* destinations, 
        travelPlan* trips, 
        int *n, 
        int *dn)
{
        int choice;
        do
        {
                printf("\n\nTRIPS MENU");
                printf("\nOPTIONS:");
                printf("\n1. VIEW ALL TRIPS");
                printf("\n2. VIEW TRIP ITINERARY");
                printf("\n3. ADD TRIP");
                printf("\n4. DELETE TRIP");
                printf("\n5. EDIT TRIP");
                printf("\n6. RATE TRIP");
                printf("\n7. BACK TO MAIN MENU");
                printf("\nWhat would you like to do: ");
                scanf(" %d", &choice);
                fflush(stdin);
                switch(choice)
                {
                        case 1: 
                                if (*n>0) displayTrips(trips, *n); 
                                else printf("\nNO TRIPS TO DISPLAY\n");
                                break;
                        case 2: viewIte(trips, n); break;
                        case 3: 
                                if (*n<*dn) addTrip(destinations, trips, n, dn);
                                else printf("\nALL DESTINATIONS HAVE A TRIP\n");
                                break;
                        case 4: 
                                if (*n>0) deleteTrip(trips, n); 
                                else printf("\nNO TRIPS TO BE DELETED\n");
                                break;
                        case 5: 
                                if (*n>0) editTrip(trips, n); 
                                else printf("\nNO TRIPS TO BE EDITED\n");
                                break;
                        case 6: 
                                if (*n>0) rateTrip(trips, n);
                                else printf("\nNO TRIPS TO BE RATED\n");
                                break;
                        case 7: break;
                        default: printf("\nINVALID\n");
                }
        } while (choice!=7);
}