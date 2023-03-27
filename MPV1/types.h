#include <stdio.h>

#ifndef TYPES

#define TYPES
#define STRSIZE 127

typedef char str_t[STRSIZE];

typedef struct Destination 
{
    str_t longName;
    str_t shortName;
    str_t country;
    str_t geoGroup;
    str_t toDo;
} Destination;

typedef struct Goals
{
    str_t shortName;
    int priorityRank;
    str_t remarks;
    int achievedFlag;
} Goals;

typedef struct DailyIte 
{
    int day;
    str_t morning;
    str_t afternoon;
    str_t evening;
    struct DailyIte* next;
} DailyIte;

typedef struct TravelPlan 
{
    str_t shortName;
    str_t startDate;
    DailyIte itinerary;
    int rating;
    str_t comment;
} TravelPlan;   

#endif