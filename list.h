#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"

/* Funktionsprototypen */
int insertInList(TMedia *Neu);
int cmpMediaTitleAsc(TMedia *t1, TMedia *t2);
TMedia * removeFromList(int delIndex);


#endif
