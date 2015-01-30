/******************************************************
* PROGRAMM: main.c
*-----------------------------------------------------
* BESCHREIBUNG: Ruft die Hauptmenü-Funktion und die 
*				Funktion des ausgewählten Menüpunktes 
*				auf.
*-----------------------------------------------------
* ERSTELLT VON: 
*           AM: 19.10.2014
* ÄNDERUNGEN  : 21.01.2015 PS
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
<<<<<<< HEAD
#include "list.h"
=======
>>>>>>> origin/master

//TMedia Medias[MAXMEDIA];
TMedia *Medias;
TMedia *First, *Last;

int main()
{
<<<<<<< HEAD
	TMedia *Media = NULL;
	
=======
>>>>>>> origin/master
    
    Medias = (TMedia*)(calloc(1, sizeof(TMedia)));
    First = Last = NULL;

    char * menutitle = "Medien-Verwaltung Deluxe";
<<<<<<< HEAD
    char * menu[9] = {	"1. Neues Medium anlegen",
    	    		"2. Medium bearbeiten", 
    	    		"3. Medium loeschen",
    	    		"4. nach Tracks suchen",
    	    		"5. Tracks sortieren",
    	    		"6. Medien auflisten",
    			"7. Medien speichern",
    			"8. Medien laden",
    			"9. Programm beenden"};
    			
    			
    			
=======
    char * menu[9] = {"1. Neues Medium anlegen", "2. Medium bearbeiten", 
	"3. Medium loeschen", "4. nach Tracks suchen", "5. Tracks sortieren", 
	"6. Medien auflisten", "7. Medien speichern", "8. Medien laden", "9. Programm beenden"};
>>>>>>> origin/master
    int choice = 0;            //Auswahlvariable
    int exit = 1;   //Abbruchvariable für fußgesteuerte Schleife

	loadMedia(); //Laden der Datenbank von Datei
	
    do
    {
        choice = getMenu(menutitle, menu, 9, 1); //Aufruf des Menüs

        switch(choice) //Ausgabe des Menüpunktes
        {
                case 1: createMedia(Media);	break;
                case 2: editMedia();	break;
                case 3: deleteMedia();	break;
                case 4: searchTrack();	break;
<<<<<<< HEAD
                case 5: sortTracks(Media);	break;
                case 6: listMedia(Media);	break;
                case 7: saveMedia();	break;
                case 8: loadMedia();    break;  //Für Tests, falls es da bleibt muss das db immer davor gelöscht werden
                case 9: saveMedia(); freeMe(); exit = 0;    	break;
=======
                case 5: sortTracks();	break;
                case 6: listMedia();	break;
                case 7: saveMedia();	break;
                case 8: loadMedia();    break;  //Für Tests, falls es da bleibt muss das db immer davor gelöscht werden
                case 9: exit = 0;    	break;
>>>>>>> origin/master
        }
        waitForEnter();
    }while(exit);

	return 0;
}
