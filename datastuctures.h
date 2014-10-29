#include <stdlib.h>



#define MAXTRACKS  20

typedef struct TTime
{
	int hour;
	int minute;
	int second;
} TTime_t; //neuer Typ TTime_t


typedef struct Tmediatype  
{ enum{ CD, DVD, Blueray, Sonstiges
	} mediatype;
}TMediatype_;

typedef struct TTracks
{ 
	int Tracknr;
	char *title;//pointer auf titel
	char *interpret;//pointer auf interpret
	TTime_t  *lp;//lengthpointer
}TTracks_t; 
	
typedef struct TMedias
{
	TTracks_t *title;
	TTracks_t *interpret;
	struct TMediatype *Type;
	unsigned int Releasedate;
	unsigned int Totalnumber;
	enum=[MAXTRACKS];
	
}TMedias_t;
	
