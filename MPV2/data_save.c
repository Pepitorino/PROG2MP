#include "types.h"

void
saveDest (destination* dest, int n)
{

}

void
saveBuck (goal* bucketlist, int n)
{

}

void
saveTrip (travelPlan* trips, int n)
{

}

void
save(destination* dest, 
        goal* bucketlist, 
        travelPlan* trips, 
        int *destnum, 
        int *bucketlistnum, 
        int *tripnum)
{
    saveDest(dest, *destnum);
    saveBuck(bucketlist, *destnum);
    saveTrip(trips, *destnum);
}