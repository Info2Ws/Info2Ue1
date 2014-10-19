/******************************************************
* PROGRAMM: main.c
*-----------------------------------------------------
* BESCHREIBUNG: Ruft die Hauptmenü-Funktion und die 
*				Funktion des ausgewählten Menüpunktes 
*				auf.
*-----------------------------------------------------
* ERSTELLT VON: P. Simons
*           AM: 19.10.2014
* ÄNDERUNGEN  : 
******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"
#include "media.h"
#include "menu.h"
#include "tools.h"

int main()
{
    char * menutitle = "Medien-Verwaltung Deluxe";
    char * menu[7] = {"1. Neues Medium anlegen", "2. Medium bearbeiten", 
	"3. Medium loeschen", "4. nach Tracks suchen", "5. Tracks sortieren", 
	"6. Medien auflisten", "7. Programm beenden"};
    int choice = 0;            //Auswahlvariable
    int exit = 1;   //Abbruchvariable für fußgesteuerte Schleife


    do
	{
        choice = getMenu(menutitle, menu, 7); //Aufruf des Menüs

        switch(choice) //Ausgabe des Menüpunktes
        {
                case 1: createMedia();	break;
                case 2: editMedia();	break;
                case 3: deleteMedia();	break;
                case 4: searchTrack();	break;
                case 5: sortTracks();	break;
                case 6: listMedia();	break;
                case 7: exit = 0;		break;
        }

        printf("\n\n");
        waitForEnter();
    }while(exit);

	return 0;
}