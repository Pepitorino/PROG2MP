#include "types.h"

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
                        for(j=0; j<trips[i].days; j++)
                        {
                                printf(" \n%s", trips[i].itinerary->morning);
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

        do
        {
                if (i>0) printf("\nINVALID\n\n");
                printf("Enter Shortname from list of Destinations (10 max length): ");
                scanf(" %10[^\n]%*[^\n]", trips[*n].shortName);
                i++;
        } while (!shortNameValidationDestination(destinations, trips[*n].shortName, dn));


        i=0;
        do
        {
                if (i>0) printf("\nINVALID\n");
                printf("Enter Startdate (mm/dd/yyyy): ");
                scanf(" %[^\n]", trips[*n].startDate);
                i++;
        } while (inputDate(trips[*n].startDate));

        do
        {
                printf("Enter rating (0.0-5.0): ");
                scanf(" %f", &trips[*n].rating);
                fflush(stdin);
                if (!inputRatingValidation(trips[*n].rating)) printf("\nINVALID\n");
        } while (!inputRatingValidation(trips[*n].rating));


        do 
        {
               printf("\nEnter comments (100 max length): ");
               scanf(" %[^\n]", trips[*n].comments);
        } while(InputValidation(trips[*n].comments, 100));

        do
        {
                printf("How many days will the itinerary be? ");
                scanf(" %d", &trips[*n].days);
                fflush(stdin);
                if (trips[*n].days<=0) printf("\nINVALID\n");
        } while(trips[*n].days<=0);

        trips[*n].itinerary=calloc(1, sizeof(itinerary));
        trips[*n].start=trips[*n].itinerary;
        for (i=0;i<trips[*n].days;i++)
        {
                trips[*n].itinerary->day=i+1;
                do
                {
                        printf("Morning activity for day %d: ", trips[*n].itinerary->day);
                        scanf(" %20[^\n]%*[^\n]", trips[*n].itinerary->morning);
                } while (InputValidation(trips[*n].itinerary->morning, 20));
                
                do
                {
                        printf("Afternoon activity for day %d: ", trips[*n].itinerary->day);
                        scanf(" %20[^\n]%*[^\n]", trips[*n].itinerary->afternoon);
                } while (InputValidation(trips[*n].itinerary->afternoon, 20));
                
                do
                {
                        printf("Evening activity for day %d: ", trips[*n].itinerary->day);
                        scanf(" %20[^\n]%*[^\n]", trips[*n].itinerary->evening);
                } while (InputValidation(trips[*n].itinerary->evening, 20));

                trips[*n].itinerary->next=calloc(1, sizeof(itinerary));
                trips[*n].itinerary=trips[*n].itinerary->next;
        }
        trips[*n].itinerary=trips[*n].start; 
        *n+=1;
}

void
deleteTrip(travelPlan* trips, 
            int *n)
{
        str_t temp;
        int i=0;

        printf("\nEnter shortname of trips you would like to delete");
        do
        {
                if(i>0) printf("\nINVALID\n");
                printf("\nSHORTNAME (CASE SENSITIVE): ");
                scanf(" %s", temp);
                i++;
        } while(!shortNameValidationTrip(trips, temp, n));

        for (i=0;i<*n;i++)
        {
                if (!strcmp(trips[i].shortName, temp))
                {
                for(i=i;i<*n;i++) trips[i]=trips[i+1];
                *n-=1;
                }
        }
}

void
editIte(travelPlan* trip)
{

}

void
editTrip(travelPlan* trips, 
        int *n)
{

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
                                if (*n<=0) deleteTrip(trips, n); 
                                else printf("\nNO TRIPS TO BE DELETED\n");
                                break;
                        case 5: 
                                if (*n>0) editTrip(trips, n); 
                                else printf("\nNO TRIPS TO BE EDITED\n");
                                break;
                        case 6: 
                                if (*n>0) rateTrip(trips, *n);
                                else printf("\nNO TRIPS TO BE EDITED\n");
                                break;
                        case 7: break;
                        default: printf("\nINVALID\n");
                }
        } while (choice!=7);
}