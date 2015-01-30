#ifndef _DATASTRUCTURE_H_
#define _DATASTRUCTURE_H_

#include <stdlib.h>
#include <stdio.h>

#define MAXTRACKS  30
<<<<<<< HEAD
#define MAXINDEX 30
=======
//#define MAXMEDIA 30
>>>>>>> origin/master

typedef struct
{
	int hour;
	int minute;
	int second;
}TTime; 


typedef enum
{ CD, DVD, Blueray, Sonstiges
}TMediatype;

typedef struct
{ 
	unsigned int Tracknr;
<<<<<<< HEAD
	char * tTitle;//pointer auf titel
	char * tInterpret;//pointer auf interpret
=======
	char *title;//pointer auf titel
	char *interpret;//pointer auf interpret
>>>>>>> origin/master
	TTime lp;//lengthpointer    FIXED BUG: May be not a pointer!!!
}TTrack; 
	
typedef struct medien
{
	int Index;
	int mnumber;
	char * mTitle;
	char * mInterpret;
	TMediatype mType;
	unsigned int Releasedate;
	unsigned int Totalnumber;
   	TTrack Tracks[MAXTRACKS];
<<<<<<< HEAD
     struct medien *Prev, *Next;
=======
    struct medien *Prev, *Next;
>>>>>>> origin/master
}TMedia;
	
typedef struct listcontent
{
	TMedia *mpoint;
	TTrack *tpoint;
	struct listcontent *Next;
}TlistElement;

typedef struct Hash
{
	TListElement *FirstList;
	TListElement *LastList;
}THashElement

extern int MediaCounter;
extern TMedia *First, *Last;
<<<<<<< HEAD
extern THashs MediaIndex[MaxIndex];
=======
//extern TMedia Medias[];
extern TMedia *Medias;
>>>>>>> origin/master

#endif
