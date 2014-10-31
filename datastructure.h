#include <stdlib.h>



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
	int Tracknr;
	char *title;//pointer auf titel
	char *interpret;//pointer auf interpret
	TTime  *lp;//lengthpointer
}TTrack; 
	
typedef struct
{
	TTrack *title;
	TTrack *interpret;
	TMediatype *Type;
	unsigned int Releasedate;
	unsigned int Totalnumber;
	//enum {MAXTRACKS};    //schon oben definiert, gibt sonst fehler beim compilen
    TTrack Tracks[MAXTRACKS];
	
}TMedia;
	
extern int MediaCounter;
extern TMedia Medias[];
