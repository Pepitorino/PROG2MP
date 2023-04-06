void
displayTrips(travelPlan* trips, 
            int n)
{

}

void
viewIte(travelPlan* trips, 
        int *n)
{

}

void
addTrip(destination* destinations,
        travelPlan* trips, 
        int *n,
        int *dn)
{

}

void
deleteTrip(travelPlan* trips, 
            int *n)
{

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