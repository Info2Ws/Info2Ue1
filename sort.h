#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"

/* Funktions Prototypen */
void kuhsort(int type);
void ksort(TTrack *data, int (*)(TTrack *, TTrack *), int ui, int oi);
int partition(TTrack *data, int (*)(TTrack *, TTrack *), int ui, int oi);
int cmpTracknr(TTrack *t1, TTrack *t2);
int cmpTitle(TTrack *t1, TTrack *t2);
int cmpInterpret(TTrack *t1, TTrack *t2);
int cmpDuration(TTrack *t1, TTrack *t2);

#endif
