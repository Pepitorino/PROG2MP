#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <types.h>

int main (){
    Destination *dest=malloc(sizeof(Destination)), 
				*root=dest;
    Goals *list=NULL;
    FILE *in=NULL, *out=NULL;
    data_init(in, dest, list);
    return 0;
}
