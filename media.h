#ifndef _MEDIA_H_
#define _MEDIA_H_

#include "datastructure.h"

void createMedia();
void editMedia();
void deleteMedia();
int createTrack(TTrack * pT, int wI);
void searchTrack();
void sortTracks();
void listMedia();
void listOneMedia(int Mediennr);
void listOneTrack(int Mediennr, unsigned int Totalnumber);

#endif
