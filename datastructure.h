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
	TTime  *lp;//lengthpointer
}TTrack; 
	
typedef struct
{
	TTracks *title;
	TTracks *interpret;
	struct TMediatype *Type;
	unsigned int Releasedate;
	unsigned int Totalnumber;
	enum={MAXTRACKS};    //schon oben definiert, gibt sonst fehler beim compilen
	
}TMedias;
	
