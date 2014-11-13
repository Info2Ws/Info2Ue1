#ifndef MEDIA_H_
#define MEDIA_H_

void createMedia();
void editMedia();
void deleteMedia();
void createTrack(TMedia * pMedia);
void searchTrack();
void sortTracks();
void listMedia();
void listOneMedia(int Mediennr);
void listOneTrack(int Mediennr, int Totalnumber);

#endif