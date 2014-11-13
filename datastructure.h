#ifndef DATASTRUCTURE_H_
#define DATASTRUCTURE_H_

#define MAXTRACKS  20
#define MAXMEDIA 20

typedef struct
{
	int hour;
	int minute;
	int second;
} TTime; //neuer Typ TTime_t


typedef enum
{ CD, DVD, Blueray, Sonstiges
}TMediatype;

typedef struct
{ 
	unsigned int Tracknr;
	char *title;//pointer auf titel
	char *interpret;//pointer auf interpret
	TTime  *lp;//lengthpointer
}TTrack; 
	
typedef struct
{
	char *title;
	char *interpret;
	TMediatype *Type;
	unsigned int Releasedate;
	unsigned int Totalnumber;
    	TTrack Tracks[MAXTRACKS];
}TMedia;
	
extern int MediaCounter;
extern TMedia Medias[];

#endif
