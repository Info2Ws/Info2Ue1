#ifndef _MEDIA_H_
#define _MEDIA_H_

#include "datastructure.h"
#include "tools.h"
#include "datetime.h"
#include "menu.h"
#include "sort.h"
#include "search.h"

void createMedia();
void editMedia();
int createTrack(TTrack * pT, char * wI);
void sortTracks();
void list();
void listMedia(unsigned int direction);
void listOneMedia(TMedia *M);
void listOneTrack(TMedia * M, int Tracknum);
void searchTrack();

#endif
