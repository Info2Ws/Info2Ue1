#ifndef _MEDIA_H_
#define _MEDIA_H_

#include "datastructure.h"
#include "tools.h"
#include "datetime.h"
#include "menu.h"
#include "sort.h"

void createMedia();
void editMedia();
void deleteMedia();
int createTrack(TTrack * pT, char * wI);
void searchTrack();
void sortTracks();
void listMedia();
void listOneMedia(int Mediennr);
void listOneTrack(TMedia * M, int Tracknum);

#endif
