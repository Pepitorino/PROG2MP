#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.c"

void print_dest(Dest* dest)
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

void erase_lastdest(Dest* dest)
{
    while(dest->next->next!=NULL)
    {
        dest=dest->next;
    }
    free(dest);
    dest->next=NULL;
    return;
}

int dest_init(FILE* in, Dest* dest)
{
    int x=1, num=0;
    char temp;
    in = fopen("destination.txt", "r");
    while(x){
        fscanf(in, "%s %s %s %s", 
                dest->shortName, dest->longName, dest->country, dest->geoGroup);
        temp = getc(in);
        
        if (temp==EOF)
        {
            num--;
            x=0;
        }
        fgets(dest->toDo, 100, in);
        dest->next=malloc(sizeof(Dest));
        dest->prev=dest;
        dest=dest->next;
        num++;
    }
    fclose(in);
    return num;
}

void bucketlist_init(FILE* in, Goals* list)
{
    int x=1;
    in = fopen("bucketlist.txt", "r");
    return;
    while(x){

    }

}

int data_init(FILE* in, Dest* dest, Goals* bucket, int *destno, int *listno)
{
    *destno = dest_init(in, dest);
    bucketlist_init(in, bucket);
    erase_lastdest(dest);
    return 0;
}