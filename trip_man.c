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
        int n)
{

}

void
addTrip(travelPlan* trips, 
        int n)
{

}

void
deleteTrip(travelPlan* trips, 
            int n)
{

}

void
editTrip(travelPlan* trips, 
        int n)
{

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