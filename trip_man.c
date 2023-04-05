void
displayTrips(travelPlan* trips, 
            int n)
{
        int i=0;

        for (i=0;i<n;i++)
        {
                printf("\n%s", trips->shortName);
                printf("\nStart Date: %s", trips->startDate);
                if (trips->rating>0) printf("\n%.1f", trips->rating);
                else printf("\nRating: No rating available");
                trips=trips->next;
        }
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
addTrip(travelPlan* trips, 
        int *n)
{
        printf("Enter Shortname (10 max length): ");
        printf("Enter Startdate (dd/mm/yyyy): ");
        printf("Enter rating (0.0-5.0): ");
        printf("Enter comments (100 max length): ");
        printf("How many days will the itinerary be? ");
        printf("Morning activity for day N");
        printf("Afternoon activity for day N");
        printf("Evening activity for day N");
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
                                                printf("\nOLD COMMENTAku: %s", trips->comments);
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
tripMenu(travelPlan* trips, 
        int n)
{

}