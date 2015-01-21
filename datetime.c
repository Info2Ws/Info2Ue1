#include"datastructure.h"
#include"datetime.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"tools.h"
#include<ctype.h> //wegen isdigit

/**********************************************************
 * FUNCTION:        getTime 
 * --------------------------------------------------------
 * DESCRIPTION:     reads time input
 * STATUS:          
 * LAST EDIT:		16.01.2015 PS
 **********************************************************/
void getTime(char * Text, TTime * lp)
{
	char strTime[9];
	int len;
	
	do{
		printf("%s", Text);
		fgets(strTime, 9, stdin);
		waitForEnter();
		if(convertStringToTime(strTime, lp)) //evtl. Rückgabewert False = convert...
		{
			printf("Falsche Eingabe! Format beachten!\n");
			waitForEnter();
		}
	}while(convertStringToTime(strTime, lp));
}
/**********************************************************
 * FUNCTION:        convertStringToTime
 * --------------------------------------------------------
 * DESCRIPTION:     checks time format and writes time data
 *					into "Medias.Tracks.lp"
 * STATUS:          
 * LAST EDIT:		16.01.2015 PS
 **********************************************************/
int convertStringToTime(char * strTime , TTime * lp)
{
	int len = strlen(strTime);
	int slot1, slot2, slot3;
    
    //lp = (TTime *)(malloc(sizeof(TTime)));
	/*Formatprüfung*/
	if((len == 8) || (len == 6)) //Formatlänge hh:mm:ss oder mm:ss 
	{
		/*Zahlen oder ':' an korrekter Stelle*/
		if((isdigit(strTime[0])) && (isdigit(strTime[1])) && (strTime[2] == ':') && (isdigit(strTime[3])) && (isdigit(strTime[4])))
		{
			/*Falls Format hh:mm:ss und ':ss' nicht korrekt dann Fehlermeldung*/
			if((len == 8) && (strTime[5] != ':') && (!(isdigit(strTime[6]))) && (!(isdigit(strTime[7]))))
				return 1;
			slot1 = atoi(strTime); //erster Slot als Integer speichern
			slot2 = atoi(strTime+3); //zweiter Slot als Integer speichern
			if(len == 6)
			{
				/*Falls mm:ss Format und Zahlen nicht zwischen 0-59 -> Fehlermeldung*/
				if(!((slot1 >= 0) && (slot1 <= 59)) || !((slot2 >= 0) && (slot2 <= 59)))
					return 1;
				lp->minute = slot1; //slot1 auf Min innerhalb der struct schreiben
				lp->second = slot2; //slot2 auf Sek innerhalb der struct schreiben
				return 0;
			}else //Wenn nicht 6 Felder dann auf 8 Felder Werte prüfen
			{
				slot3 = atoi(strTime+6); //dritter Slot als Integer speichern
				if(!((slot1 >= 0) && (slot1 <= 99)) || !((slot2 >= 0) && (slot2 <= 59)) || !((slot3 >= 0) && (slot3 <= 59)))
					return 1;
				lp->hour = slot1; //slot1 auf Std innerhalb der struct schreiben
				lp->minute = slot2; //slot2 auf Min innerhalb der struct schreiben
				lp->second = slot3; //slot3 auf Sek innerhalb der struct schreiben
				return 0;
			}
		}else
		{
			return 1;
		}
	}else
	{
		return 1;
	}
}
/**********************************************************
 * FUNCTION:        printTime
 * --------------------------------------------------------
 * DESCRIPTION:     prints time in 2 different formats
 * STATUS:          
 * LAST EDIT:		
 **********************************************************/
void printTime(TTime * lp)
{
	//Ausgabe der Zeit
	if((lp->hour) == 0)
	{
		printf("%02i:%02i", lp->minute , lp->second );
	}else{
		printf("%02i:%02i:%02i", lp->hour, lp->minute , lp->second );
	}
}
