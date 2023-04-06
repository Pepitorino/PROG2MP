void
displayTrips(travelPlan* trips, 
            int n)
{
        int i=0;
        travelPlan* start=trips;

        for (i=0;i<n;i++)
        {
                printf("\n%s", trips->shortName);
                printf("\nStart Date: %s", trips->startDate);
                if (trips->rating>0) printf("\n%.1f", trips->rating);
                else printf("\nRating: No rating available");
                trips=trips->next;
        }

        trips=start;
}

void
viewIte(travelPlan* trips, 
        int *n)
{
        int i=0;
        str_t temp;
        itinerary* daily;
        printf("\nEnter shortname of trip to view");
        do
        {
                if(i>0) printf("\nINVALID\n");
                printf("\nSHORTNAME (CASE SENSITIVE): ");
                scanf(" %10[^\n]%*[^\n]", temp);
                i++;
        } while(!shortNameValidationTrip(trips, temp, n));

        printf("\nShortname: %s", trips->shortName);
        printf("\nStartdate: %s", trips->startDate);
        printf("\nRating: %.1f", trips->rating);
        printf("\nRemarks: %s", trips->comments);

        daily=&(trips->itinerary);
        for(i=0;i<trips->days;i++)
        {
                printf("\nDay %d", daily->day);
                printf("\nMorning: %s", daily->morning);
                printf("\nAfternoon: %s", daily->afternoon);
                printf("\nEvening: %s", daily->evening);
                daily=daily->next;
        }
}

void
addTrip(destination* destinations,
        travelPlan* trips, 
        int *n,
        int *dn)
{
        int i=0;
        str_t temp;
        travelPlan* start=trips;
        itinerary* iteStart, *ite;

        for(i=0;i<*n;i++)
        {
                trips=trips->next;
        }

        trips=calloc(1, sizeof(travelPlan));
        iteStart=&(trips->itinerary);
        ite=iteStart;

        do
        {
                if (i>0) printf("\nINVALID\n\n");
                printf("Enter Shortname from list of Destinations (10 max length): ");
                scanf(" %10[^\n]%*[^\n]", trips->shortName);
                i++;
        } while (!shortNameValidationDestination(destinations, trips->shortName, dn));


        i=0;
        do
        {
                if (i>0) printf("\nINVALID\n");
                printf("Enter Startdate (mm/dd/yyyy): ");
                scanf(" %[^\n]", trips->startDate);
        } while (inputDate(trips->startDate));

        printf("\n%s\n", trips->startDate);

        printf("Enter rating (0.0-5.0): ");

        do 
        {
               printf("\nEnter comments (100 max length): ");
               scanf(" %[^\n]", trips->comments);
        } while(InputValidation(trips->comments, 100));

        do
        {
                printf("How many days will the itinerary be? ");
                scanf(" %d", &trips->days);
                if (trips->days<=0) printf("\nINVALID\n");
        } while(trips->days<=0);

        for (i=0;i<trips->days;i++)
        {       
                do
                {
                        printf("Morning activity for day N");
                        scanf("%20[^\n]%*[^\n]", trips->itinerary.morning);
                } while (InputValidation(ite->morning, 20));
                
                do
                {
                        printf("Afternoon activity for day N");
                        scanf("%20[^\n]%*[^\n]", trips->itinerary.afternoon);
                } while (InputValidation(ite->afternoon, 20));
                
                do
                {
                        printf("Evening activity for day N");
                        scanf("%20[^\n]%*[^\n]", trips->itinerary.evening);
                } while (InputValidation(ite->evening, 20));
                ite->next=calloc(1, sizeof(itinerary));
                ite=ite->next;
        }

        trips=start;

        *n+=1;
}

void
deleteTrip(travelPlan* trips, 
            int *n)
{
        int i=0;
        str_t temp;
        travelPlan* start;
        travelPlan* prev;
        travelPlan* delete;
        start = trips;

        printf("\nEnter shortname of trip to delete");
        do
        {
                if(i>0) printf("\nINVALID\n");
                printf("\nSHORTNAME (CASE SENSITIVE): ");
                scanf(" %10[^\n]%*[^\n]", temp);
                i++;
        } while(!shortNameValidationTrip(trips, temp, n));

        prev=trips;
        trips=trips->next;
        for(i=0;i<*n;i++)
        {       
                if (!strcmp(trips->shortName, temp)) 
                {
                        delete=trips;
                        prev->next=trips->next;
                        free(delete);
                        i=*n;
                }
                prev=trips;
                trips=trips->next;
                i++;
        }
        trips=start;
        *n-=1;  
}

void
editIte(travelPlan* trip)
{
        int i=0;
        int choice=0;
        do
        {
                
        } while (choice!=0);
        

}

void
editTrip(travelPlan* trips, 
        int *n)
{
        int i=0;
        int choice;
        str_t temp;
        travelPlan* start;
        start=trips;

        printf("\nEnter shortname of trip to edit");
        do
        {
                if(i>0) printf("\nINVALID\n");
                printf("\nSHORTNAME (CASE SENSITIVE): ");
                scanf(" %10[^\n]%*[^\n]", temp);
                i++;
        } while(!shortNameValidationTrip(trips, temp, n));

        
        for(i=0;i<*n;i++)
        {       
                if (!strcmp(trips->shortName, temp)) 
                {
                        do
                        {
                                printf("\nEDIT TRIP %s");
                                printf("\n1. COMMENTS");
                                printf("\n2. ITINERARY CONTENTS");
                                printf("\n3. EXIT");
                                printf("\nWHERE WOULD YOU LIKE TO GO: ");
                                scanf(" %d", &choice);
                                fflush(stdin);
                                switch(choice)
                                {
                                        case 1:
                                                printf("\nOLD COMMENT: %s", trips->comments);
                                                printf("\nEnter new comment (100 max length): "); 
                                                scanf(" %100[^\n]%*[^\n]", trips->comments);
                                        case 2: editIte(trips);
                                        case 3: break;
                                        default: printf("\nINVALID\n");
                                }
                        } while (choice!=3);
                        
                }
                trips=trips->next;
        }
        
        trips=start;
}


void
rateTrip(travelPlan* trips, 
        int n)
{

}

void
tripMenu(destination* destinations, travelPlan* trips, 
        int *n, int *dn)
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
                case 1: displayTrips(trips, *n); break;
                case 2: viewIte(trips, n); break;
                case 3: addTrip(destinations, trips, n, dn); break;
                case 4: deleteTrip(trips, n); break;
                case 5: editTrip(trips, n); break;
                case 6: rateTrip(trips, *n); break;
                case 7: break;
                default: printf("\nINVALID\n");
                }
        } while (choice!=7);
}