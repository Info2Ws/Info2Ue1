#ifndef _MENU_H_
#define _MENU_H_

/******************************************************
* FUNKTION: getMenu
*-----------------------------------------------------
* BESCHREIBUNG: Ausgabe des Menütitels, der Menüpunkte
*				und Abfrage der Menüpunktauswahl
* PARAMETER: Menütitel (char), Menüpunkte (char),
*			 Anzahl der Menüpunkte (int), 
*			 Sichtbarkeit des Menütitels (int)
* ERGEBNISTYP: int
* ERGEBNISWERTE:
*   -> NORMALFALL: 1-7 
*   -> FEHLERFALL: -
*-----------------------------------------------------
* ERSTELLT VON: 
*           AM: 20.10.2014
* ÄNDERUNGEN  : 28.10.2014
******************************************************/

int getMenu(char menutitle[], char *menu[], int anz, int visibility);

#endif
