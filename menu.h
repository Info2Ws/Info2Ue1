#ifndef _MENU_H_
#define _MENU_H_

/******************************************************
* FUNKTION: getMenu
*-----------------------------------------------------
* BESCHREIBUNG: Ausgabe des Men�titels, der Men�punkte
*				und Abfrage der Men�punktauswahl
* PARAMETER: Men�titel (char), Men�punkte (char),
*			 Anzahl der Men�punkte (int), 
*			 Sichtbarkeit des Men�titels (int)
* ERGEBNISTYP: int
* ERGEBNISWERTE:
*   -> NORMALFALL: 1-7 
*   -> FEHLERFALL: -
*-----------------------------------------------------
* ERSTELLT VON: P. Simons
*           AM: 20.10.2014
* �NDERUNGEN  :
******************************************************/

int getMenu(char [], char *[], int, int);

#endif
