/* Saves destinations by writing to destination.txt file
@param data - array of destinations to be saved
@param n - number of destinations to be saved
Precondition: N is a number equal to the number of elements present in data or 0
            it cannot be 0
*/
void
saveDest (destination* data, 
            int n)
{
    int i=0;

    FILE* f1;
    f1 = fopen("destination.txt", "w");

    for (i=0;i<n;i++)
    {
        fprintf(f1, "%s %s\n", data[i].shortName, data[i].longName);
        fprintf(f1, "%s\n", data[i].country);
        fprintf(f1, "%s\n", data[i].geoGroup);
        fprintf(f1, "%s\n", data[i].toDo);
        fprintf(f1, "\n");
   }

    fclose(f1);
}

/* Saves goals by writing to bucketlist.txt file
@param data - array of goals to be saved
@param n - number of goals to be saved
Precondition: N is a number equal to the number of elements present in data or 0
            it cannot be 0
*/
void
saveBuck (goal* data, 
            int n)
{
    int i=0;

    FILE* f1;
    f1 = fopen("bucketlist.txt", "w");

    for (i=0;i<n;i++)
    {
        fprintf(f1, "%s\n", data[i].shortName);
        fprintf(f1, "%d\n", data[i].prioRank);
        fprintf(f1, "%s\n", data[i].remarks);
        fprintf(f1, "%d\n\n", data[i].flag);
    }

    fclose(f1);
}

/* Saves itineraries by writing to respective <shortName>-itinerary.txt file
@param trips - array of travelPlans who's itineraries are to be saved
@param n - number of travelPlans to be saved
Precondition: N is a number equal to the number of elements present in trips or 0
            it cannot be 0
*/
void
saveIte (travelPlan* trips, 
            int n)
{
    int i=0, j=0;
    FILE* f1;
    str_t temp;

    for(i=0;i<n;i++)
    {
        strcpy(temp, trips[i].shortName);
        strcat(temp, "-itinerary.txt");
        f1=fopen(temp, "w");

        fprintf(f1, "%s\n", trips[i].startDate);
        fprintf(f1, "%f\n", trips[i].rating);
        fprintf(f1, "%s\n", trips[i].comments);
        for (j=0;j<trips[i].days;j++)
        {
            fprintf(f1, "Day%d\n", trips[i].itinerary->day);
            fprintf(f1, "Morning\n");
            fprintf(f1, "%s\n", trips[i].itinerary->morning);
            fprintf(f1, "Afternoon\n");
            fprintf(f1, "%s\n", trips[i].itinerary->afternoon);
            fprintf(f1, "Evening\n");
            fprintf(f1, "%s\n\n", trips[i].itinerary->evening);
            trips[i].itinerary=trips[i].itinerary->next;
        }
        trips[i].itinerary=trips[i].start;
        trips[i].days=j;
        fclose(f1);
    }
}

/* Saves trips by writing to trips.txt file
@param data - array of travelPlans to be saved
@param n - number of travelPlans to be saved
Precondition: N is a number equal to the number of elements present in data or 0
            it cannot be 0
*/
void
saveTrip (travelPlan* data, 
            int n)
{
    int i=0;    

    FILE* f1;
    f1 = fopen("trips.txt", "w");

    for (i=0;i<n;i++)
    {
        fprintf(f1, " %s\n", data[i].shortName);
    }

    fclose(f1);
}

/* Calls all "saving" functions found above
@param dest - array of destinations to be saved
@param bucketlist - array of goals to be saved
@param trips - array of travelPlans to be saved
@param destnum - number of destinations
@param bucketlistnum - number of goals
@param tripnum - number of travelPlans
Precondition: No precondition
*/
void
save(destination* dest, 
        goal* bucketlist, 
        travelPlan* trips, 
        int *destnum, 
        int *bucketlistnum, 
        int *tripnum)
{
    saveDest(dest, *destnum);
    saveBuck(bucketlist, *bucketlistnum);
    saveTrip(trips, *tripnum);
    saveIte(trips, *tripnum);
}