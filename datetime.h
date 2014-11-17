#ifndef _DATETIME_H_
#define _DATETIME_H_

#include "datastructure.h"


/******************************************************
* FUNKTION: printTime
*-----------------------------------------------------
* BESCHREIBUNG: Ausgabe des der Dauer eines Titels
*				
* PARAMETER: Zeiger auf eine Zeichenkette
*			  
*			 
* ERGEBNISTYP: void
* Rückgabewert 0 bei Erfolg
* 1 bei Fehlern
*-----------------------------------------------------
* ERSTELLT VON: 
*           AM: 22.10.2014
* ÄNDERUNGEN  : 28.10.2014
******************************************************/


/** Funktions-Pototypen **/


    void printTime(TTime *Zeit);
    void getTime(char *Text, TTime *Zeit);
    void splitstring (TTime *Zeit, char c, char ***arr);
    int checkTime (TTime *Zeit , int legit, char *strTime);
#endif
     
