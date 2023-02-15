#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
} Destination;

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

void print_dest(Destination* dest)
{
    while(dest->next!=NULL){
    	printf("\n%s", dest->shortName);
    	printf("\t%s", dest->longName);
    	printf("\n%s", dest->country);
    	printf("\n%s", dest->geoGroup);
    	printf("\n%s", dest->toDo);
        dest=dest->next;
	}
}

int data_init(FILE* in, Destination* dest, Goals* bucket)
{
    int x=1;
    char temp;
    in = fopen("destination.txt", "r");
    while(x){
        fscanf(in, "%s %s %s %s", 
                dest->shortName, dest->longName, dest->country, dest->geoGroup);
        temp = getc(in);
        
        if (temp==EOF)
        {
            x=0;
        }
        fgets(dest->toDo, 100, in);
        dest->next=malloc(sizeof(Destination));
        dest->prev=dest;
        dest=dest->next;
    }
    fclose(in);
    return 0;
}

void erase_lastdest(Destination* dest){
    while(dest->next->next!=NULL)
    {
        dest=dest->next;
    }
    free(dest);
    dest->next=NULL;
    return;
}