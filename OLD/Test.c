#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.c"

int main (){
    Destination *dest = malloc(sizeof(Destination)),
				*root = dest;
	Goals* list;
	FILE *in, *out;
	
	strcpy("Hello World!", dest->shortName);
	return 0;
}
