#ifndef _DATASTRUCTURE_H_
#define _DATASTRUCTURE_H_

#include <stdlib.h>
#include <stdio.h>

#define MAXTRACKS  20


typedef struct
{
	int hour;
	int minute;
	int second;
}TTime; //neuer Typ TTime_t


typedef enum
{ 
	CD, DVD, Blueray, Sonstiges
}TMediatype;

typedef struct
{ 
	unsigned int Tracknr;
	char *title;//pointer auf titel
	char *interpret;//pointer auf interpret
	TTime lp;//lengthpointer    FIXED BUG: May be not a pointer!!!
	
}TTrack; 
	
typedef struct
{
	char *title;
	char *interpret;
	TMediatype *Type;
	unsigned int Releasedate;
	unsigned int Totalnumber;
    	TTrack Tracks[MAXTRACKS];
	struct *Next, *Last;
}TMedia;
	
extern int MediaCounter;
//extern TMedia Medias[];
extern TMedia *First,*Last;

#endif
