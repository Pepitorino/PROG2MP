#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <types.h>

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
    return;
}

void erase_lastdest(Destination* dest)
{
    while(dest->next->next!=NULL)
    {
        dest=dest->next;
    }
    free(dest);
    dest->next=NULL;
    return;
}

void dest_init(FILE* in, Destination* dest){
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

int data_init(FILE* in, Destination* dest, Goals* bucket)
{
    dest_init(in, dest);
    erase_lastdest(dest);
    return 0;
}