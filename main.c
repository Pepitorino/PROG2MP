#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.c"

int main (){
    Destination *dest=malloc(sizeof(Destination)), 
				*root=dest;
    Goals *list=malloc(sizeof(Goals));
    int destno=0, listno=0;
    FILE *in=NULL, *out=NULL;
    data_init(in, dest, list, &destno, &listno);
    printf("%d", destno);
    return 0;
}
