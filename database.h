#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"

/* Funktions Prototypen */
int saveMedia();
void saveOneMedia(FILE *data, int CurrentMedium);
void saveOneTrack(FILE *data, TMedia *Medium, int TrackNumber);


#endif
