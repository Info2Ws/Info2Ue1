#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"

/* Funktionsprototypen */
int insertInList(TMedia *Neu);
int cmpMediaTitleAsc(TMedia *t1, TMedia *t2);
void deleteMedia();
TMedia *removeFromList(int delIndex, int direction);
int appendInIndexList(THashElement *hash, TListElement *Neu);
int deleteFromIndexList(THashElement *hash, TTrack *trash);


#endif
