#include "types.h"

void
inputDate()
{

}

void 
inputRating()
{

}

void
inputText(char* text, int length)
{

}

int shortNameValidationDestination(destination* data, 
                        str_t temp, 
                        int *n)
{
    int i=0;
    for (i=0;i<*n;i++)
    {
        if (!strcmp(data[i].shortName, temp)) return 1;
    }
    return 0;
}

int shortNameValidationGoal(goal* data, 
                        str_t temp, 
                        int *n)
{
    int i=0;
    for (i=0;i<*n;i++)
    {
        if (!strcmp(data[i].shortName, temp)) return 1;
    }
    return 0;
}

int shortNameValidationTrip(travelPlan* trips,
                            str_t temp,
                            int *n)
{
    int i=0;
    travelPlan* start;
    start=trips;

    for(i=0;i<*n;i++)
    {
        if (!strcmp(trips->shortName, temp)) 
        {
            trips=start;
            return 1;
        }
        trips=trips->next;
        i++;
    }
    trips=start;
    return 0;
}

int checkYesOrNo(char c)
{
    switch(c)
    {
        case 'y':
        case 'Y':
        return 1;
        case 'n':
        case 'N':
        return -1;
    }
    return 0;
}