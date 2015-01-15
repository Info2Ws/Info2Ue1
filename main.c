/******************************************************
* PROGRAMM: main.c
*-----------------------------------------------------
* BESCHREIBUNG: Ruft die Hauptmenü-Funktion und die 
*				Funktion des ausgewählten Menüpunktes 
*				auf.
*-----------------------------------------------------
* ERSTELLT VON: 
*           AM: 19.10.2014
* ÄNDERUNGEN  : 12.12.2014
******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"
#include "media.h"
#include "menu.h"
#include "tools.h"
#include "datetime.h"
#include "database.h"
#include "sort.h"

int main()
{
    char * menutitle = "Medien-Verwaltung Deluxe";      //wir brauchen einen besseren namen..
    char * menu[9] = {"1. Neues Medium anlegen", "2. Medium bearbeiten", 
	"3. Medium loeschen", "4. nach Tracks suchen", "5. Tracks sortieren", 
	"6. Medien auflisten", "7. Medien speichern", "8. Medien laden", "9. Programm beenden"};
    int choice = 0;            //Auswahlvariable
    int exit = 1;   //Abbruchvariable für fußgesteuerte Schleife

	loadMedia(); //Laden der Datenbank von Datei
	
    do
	{
        choice = getMenu(menutitle, menu, 9, 1); //Aufruf des Menüs

        switch(choice) //Ausgabe des Menüpunktes
        {
                case 1: createMedia();	break;
                case 2: editMedia();	break;
                case 3: deleteMedia();	break;
                case 4: searchTrack();	break;
                case 5: sortTracks();	break;
                case 6: listMedia();	break;
                case 7: saveMedia();	break;
                case 8: loadMedia();    break;  //Für Tests, falls es da bleibt muss das db immer davor gelöscht werden
                case 9: exit = 0;    	break;
        }
        waitForEnter();
    }while(exit);

	return 0;
}
