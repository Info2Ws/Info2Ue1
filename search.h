#ifndef _SEARCH_H_
#define _SEARCH_H_

#include <stdlib.h>
#include <stdio.h>
#include "datastructure.h"

int calcDivisionRest(char *name);
void insertInHashTable(TMedia *newM, int Tracknr);
TListElement *search(THashElement *HE, int (*cmp)(TTrack *, TTrack *), TListElement *Such);

#endif
