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


    void getTime(char * Text, TTime * lp);
    void convertStringToTime(char * strTime , TTime * lp);
    void printTime(TTime * lp);
    int checkTime(TTime * lp, int truth , char * strTime);
#endif

