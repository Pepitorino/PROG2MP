#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.c"

int main (){
    Destination *dest=malloc(sizeof(Destination)), 
				*root=dest;
    Goals *list=NULL;
    FILE *in=NULL, *out=NULL;
    data_init(in, out, dest, list);
    dest=root;
    print_dest(dest);
    return 0;
}
