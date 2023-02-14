#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STRSIZE 255

typedef char str_t[STRSIZE];

typedef struct Destination {
    str_t shortName;
    str_t longName;
    str_t country;
    str_t geoGroup;
    str_t toDo; 
} Destination;

typedef struct Goals {
    str_t shortName;
    int priorityRank;
    str_t remarks;
    str_t achievedFlag;
} Goals;

struct DailyIte {
    int day;
    str_t morning;
    str_t afternoon;
    str_t evening;
};

typedef struct TravelPlan {
    str_t shortName;
    str_t startDate;
    struct DailyIte* itinerary;
    int rating;
    str_t comment;
} TravelPlan;