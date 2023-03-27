#ifndef TYPES
#define TYPES

#define LONG 51
#define SHORT 11
#define TWOLEN 21
#define THREELEN 31
#define TENLEN 101

typedef char longName[LONG];
typedef char shortName[SHORT];
typedef char shortDesc[TWOLEN];
typedef char medDesc[THREELEN];
typedef char longDesc[TENLEN];

typedef struct Destinations
{
    longName longName;
    shortName shortName;
    shortDesc country;
    shortDesc geoGroup;
    longDesc toDo;

} destinations;

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
    medDesc Evening;
    struct Itinerary* next;
} itinerary;

typedef struct TravelPlan 
{
    shortName shortName;
    shortName startDate; //Also used shortname typedef for the start date because it should also be unique;
    itinerary itinerary;
    float rating;
    longDesc comments;
} travelPlan;

#endif  