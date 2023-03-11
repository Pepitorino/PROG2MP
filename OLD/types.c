#define STRSIZE 127

typedef char str_t[STRSIZE];

typedef struct Destination 
{
    str_t shortName;
    str_t longName;
    str_t country;
    str_t geoGroup;
    str_t toDo;
    struct Destination* next;
    struct Destination* prev;
} Dest;

typedef struct Goals 
{
    str_t shortName;
    int priorityRank;
    str_t remarks;
    str_t achievedFlag;
    struct Goals* next;
    struct Goals* prev;
} Goals;

struct DailyIte 
{
    int day;
    str_t morning;
    str_t afternoon;
    str_t evening;
};

typedef struct TravelPlan 
{
    str_t shortName;
    str_t startDate;
    struct DailyIte* itinerary;
    int rating;
    str_t comment;
} TravelPlan;   
