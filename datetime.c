#include"datastructure.h"
#include"datetime.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"tools.h"
#include<ctype.h>
//char *pStd;
//char *pMin;
//char *pSek;
char *pos;
////char *lp;
int count;
char c;
int len;
int i;
char *zeit;
char strTime[9];
int checkZeit;
int checkZeit2;
void getTime(char * Text,TTime * lp)
{
	do
	{
		//Eingabeaufforderung
		printf("%s", Text);
		//Eingabe des Benutzers
		fgets(strTime,9,stdin);
		clearBuffer();
		//Konvertierung der Zeichenkette zu Integer werten
		convertStringToTime(strTime,lp);
		//Kontrollieren ob zeit gültige eingabe
		checkZeit2 = (checkTime(lp, 1 , strTime));
		checkZeit = (checkTime(lp, 0 , strTime));
		printf("%04i",checkZeit2);//0001
		printf("%04i",checkZeit);//0000
		if(!checkZeit2)
		{
			printf("Falsche Eingabe! Format (hh:mm:ss oder mm:ss) \n Fortfahren mit Enter");
			clearBuffer();
		}
		//Kontrollieren ob zeit gültige integer werte
		if(!checkZeit)
		{
			printf("Falsche Eingabe! Format (hh:mm:ss oder mm:ss)\n Fortfahren mit Enter");
			clearBuffer();
		}
	}
	while(checkZeit != checkZeit2 );
}
void convertStringToTime(char * strTime , TTime * lp)
{
	//Zeiger deklaration
	char * pStd = NULL ;
	char * pMin = NULL ;
	char * pSek = NULL;
	int Std,Min,Sek;
	len=strlen(strTime);
	if (isdigit(*strTime) && len > 2 )
	{
		if((strchr(strTime, ':')) && (strrchr(strTime,':')) != (strchr(strTime,':')))
		{
			pStd = strTime;
			pMin = ((strchr(strTime, ':')+1));
			pSek = ((strrchr(strTime, ':')+1));
			Std = atoi(pStd);
			Min = atoi(pMin);
			Sek = atoi(pSek);
			printf("%02i:%02i:%02i",Std,Min,Sek);//Aufspaltung der Zeit in stunde minute sekunde
		}
		else if((strchr(strTime, ':')) && (strrchr(strTime,':')) == (strchr(strTime,':')))
		{
			pMin = strTime;
			pSek = ((strrchr(strTime, ':')+1));
			Std = 0;
			Min = atoi(pMin);
			Sek = atoi(pSek);
			printf("%02i:%02i",Min,Sek);//Aufspaltung der Zeit in stunde minute sekunde
		}
		//wandern der pointer bei std = 0
		//Konvertieren der strings zu
		lp->hour = Std;
		lp->minute = Min;
		lp->second = Sek;
        printf("\nsecond %i\n", lp->second);
	}
}
int checkTime(TTime * lp ,int truth, char * strTime)
{
	//Laufvariable
	int i= 0;
	//Kontrolle der Integerwerte
	if(truth == 0)
	{
		if((lp->second < 60)&&(lp->minute < 60 )&&(lp->hour <99))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	//Kontrolle der string eingabe
	if(truth == 1)
	{
		if(strchr(strTime,':'))
		{
			for(i = 0; i < strlen(strTime); i++) //while(*(strTime + i))
			{
				if(((*(strTime + i) < '0') || (*(strTime + i) > '9' )) && (*(strTime + i) != ':'))
				{
					return 0;
					i++;
				}
				if(((*(strTime + i) >= '0') && (*(strTime + i) <= '9' )))
				{
					return 1;
					i++;
				}
			}
		}
	}
}
void printTime(TTime * lp)
{
	//Ausgabe der Zeit
	printf("%02i:%02i:%02i", lp->hour, lp->minute , lp->second );

}
