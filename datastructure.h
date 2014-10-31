#include <stdlib.h>



#define MAXTRACKS  20

typedef struct
{
	int hour;
	int minute;
	int second;
} TTime; //neuer Typ TTime_t


typedef struct  
{ enum{ CD, DVD, Blueray, Sonstiges
	} mediatype;
}TMediatype;

typedef struct
{ 
	int Tracknr;
	char *title;//pointer auf titel
	char *interpret;//pointer auf interpret
	TTime_t  *lp;//lengthpointer
}TTrack; 
	
typedef struct
{
	TTracks_t *title;
	TTracks_t *interpret;
	struct TMediatype *Type;
	unsigned int Releasedate;
	unsigned int Totalnumber;
	//enum=[MAXTRACKS];    schon oben definiert, gibt sonst fehler beim compilen
	
}TMedias;
	
