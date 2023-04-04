#ifndef TYPES
#define TYPES

#define LONG 51
#define SHORT 11
#define TWOLEN 21
#define THREELEN 31
#define TENLEN 101
#define STRING 127

typedef char shortName[SHORT];
typedef char longName[LONG];
typedef char shortDesc[TWOLEN];
typedef char medDesc[THREELEN];
typedef char longDesc[TENLEN];
typedef char str_t[STRING];

typedef struct Destination
{
    shortName shortName;
    longName longName;
    shortDesc country;
    shortDesc geoGroup;
    longDesc toDo;

} destination;

typedef struct Goal 
{
    shortName shortName;
    int prioRank;
    medDesc remarks;
    int flag;
} goal;

typedef struct Itinerary
{
    int day;
    medDesc morning;
    medDesc afternoon;
    medDesc evening;
    struct Itinerary* next;
} itinerary;

typedef struct TravelPlan 
{
    shortName shortName;
    shortName startDate; //Also used shortname typedef for the start date because they are both 10 characters and should also be unique;
    float rating;
    longDesc comments;
    itinerary itinerary;
    struct TravelPlan* next;
} travelPlan;

#endif  