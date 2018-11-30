#ifndef COVER_H
#define COVER_H

#include"Set.h"

typedef struct KSet_ {
	void *key;
	Set set;
} KSet;

/*
members: all elements needed in the covering
subsets: A1 A2 A3 ... which include some of the elements
covering: includes the least numbers of subsets which include all the elements
*/
int cover(Set *members, Set *subsets, Set *covering);

#endif