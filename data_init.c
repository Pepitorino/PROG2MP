/* Checks if all files exist, if it doesnt it creates it and prints one(1) newline in it 
Precondition: no precondition
*/
void 
checkFiles ()
{
    FILE *destination;
    FILE *bucketlist;
    FILE *trips;

    destination=fopen("destination.txt", "r");
    if(destination==NULL)
    {
        fclose(destination);
        destination=fopen("destination.txt", "w");
        fprintf(destination, "\n");
    }
    fclose(destination);
    
    bucketlist=fopen("bucketlist.txt", "r");
    if(bucketlist==NULL)
    {
        fclose(bucketlist);
        bucketlist=fopen("bucketlist.txt", "w");
        fprintf(bucketlist, "\n");
    }
    fclose(bucketlist);

    trips=fopen("trips.txt", "r");
    if (trips==NULL)
    {
        fclose(trips);
        trips=fopen("trips.txt", "w");
        fprintf(trips, "\n");
    }
    fclose(trips);
}

/* Initializes information for the array of destinations
@param data - array where data is to be initialized
Precondition: destination.txt exists
*/
int
destInit (destination* data)
{
    int i=0;
    int n=-1;

    FILE* f1;
    f1 = fopen("destination.txt", "r");

    for (i=0;!feof(f1);i++)
    {
        fscanf(f1, " %10s %50[^\n]", data[i].shortName, data[i].longName);
        fscanf(f1, " %30[^\n]", data[i].country);
        fscanf(f1, " %30[^\n]", data[i].geoGroup);
        fscanf(f1, " %100[^\n]", data[i].toDo);
        n++;
    }

    fclose(f1);

    return n;
}

/* Initializes information for the array of goals
@param data - array where data is to be initialized
Precondition: bucketlist.txt exists
*/
int 
buckInit (goal* data)
{
    int i=0;
    int num=-1;

    FILE* f1;
    f1 = fopen("bucketlist.txt", "r");

    for (i=0;!feof(f1);i++)
    {
        fscanf(f1, " %10[^\n]", data[i].shortName);
        fscanf(f1, " %d", &data[i].prioRank);
        fscanf(f1, " %[^\n]", data[i].remarks);
        fscanf(f1, " %d", &data[i].flag);
        num++;
    }

    fclose(f1);
    return num;
}

/* Initializes information for the array of trips
@param data - array where data is to be initialized
Precondition: trips.txt exists
*/
int 
tripInit (travelPlan* data)
{
    int i=0;    
    int num=-1;

    FILE* f1;
    f1 = fopen("trips.txt", "r");

    for (i=0;!feof(f1);i++)
    {
        fscanf(f1, " %[^\n]", data[i].shortName);
        num++;
    }

    return num;
}

/* Initializes information of the itinerary linked list for each trip
@param trips - array where data of itinerary is to be initialized to each element
@param n - number of elements in trips
Precondition: trips.txt exists
*/
void
iteInit (travelPlan* trips, 
        int n)
{
    int i=0, j=0;
    FILE* f1;
    str_t temp;
    str_t tempday;

    for(i=0;i<n;i++)
    {
        strcpy(temp, trips[i].shortName);
        strcat(temp, "-itinerary.txt");
        f1=fopen(temp, "r");

        trips[i].itinerary=calloc(1, sizeof(itinerary));
        trips[i].start=trips[i].itinerary;

        fscanf(f1, " %s", trips[i].startDate);
        fscanf(f1, " %f", &trips[i].rating);
        fscanf(f1, " %[^\n]", trips[i].comments);
        for (j=-1;!feof(f1);j++)
        {
            fscanf(f1, " %s", tempday);
            trips[i].itinerary->day=atoi(&tempday[3]);
            fscanf(f1, " %*[^\n]");
            fscanf(f1, " %30[^\n]", trips[i].itinerary->morning);
            fscanf(f1, " %*[^\n]");
            fscanf(f1, " %30[^\n]", trips[i].itinerary->afternoon);
            fscanf(f1, " %*[^\n]");
            fscanf(f1, " %30[^\n]", trips[i].itinerary->evening);
            trips[i].itinerary->next=calloc(1,sizeof(itinerary));
            trips[i].itinerary=trips[i].itinerary->next;
        }
        trips[i].itinerary=trips[i].start;
        trips[i].days=j;
        fclose(f1);
    }
}

/* Shortcut to initalize all information
@param dest - array of destinations
@param bucketlist - array of goals
@param trips - array of travelPlans
@param destnum - number of destinations
@param bucketlistnum - number of goals
@param tripnum - number of trips
Precondtion: no precondition
*/
void
init (destination* dest, 
        goal* bucketlist, 
        travelPlan* trips, 
        int *destnum, 
        int *bucketlistnum, 
        int *tripnum)
{
    checkFiles();
    *destnum=destInit(dest);
    *bucketlistnum=buckInit(bucketlist);
    *tripnum=tripInit(trips);
    iteInit(trips, *tripnum);
}