#ifndef _DATASTRUCTURE_H_
#define _DATASTRUCTURE_H_

#include <stdlib.h>
#include <stdio.h>

#define MAXTRACKS  30
#define MAXINDEX 30

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
	char * tTitle;//pointer auf titel
	char * tInterpret;//pointer auf interpret
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
     struct medien *Prev, *Next;
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
extern THashElement MediaIndex[MaxIndex];

#endif
