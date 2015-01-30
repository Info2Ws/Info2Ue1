#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "media.h"

int MediaCounter = 0;
//TMedia Medias[MAXMEDIA];
//TMedia *Medias = &Media[0];
//TODO: put in freeList


/**********************************************************
 * FUNCTION:        createMedia 
 * --------------------------------------------------------
 * DESCRIPTION:		Creates an Interface to enter Media 
 * 			related data (title, interpret, Type, 
 *			Releasedate)
 * LAST EDIT:		21.01.2015 PS
 *********************************************************/
void createMedia()
{
    int i;
	TMedia * M = calloc(1, sizeof(TMedia));
    TTrack * T;                      //pointer for actual track 

	//Menütitel
    printf("Erfassung eines neuen Mediums\n");
    printLine('-' , 29);
    printf("\n\n");

    //Eingaben
    getText("Geben Sie bitte den Titel ein: ", 50 , 0 , &(M->title));
    getText("Geben Sie bitte den Interpreten ein\n(Bei mehreren Interpreten Feld leer lassen):", 
	50 , 1 , &(M->interpret));
    //getText("Geben Sie bitte den Typ ein: ", 50 , 0 , &(M->Type));
    getNumber("Geben Sie bitte den Medientyp ein:\n1: CD\n2: DVD\n3: Blueray\n4: Sonstiges\n", &(M->Type), 1 , 4);
    getNumber("Geben Sie bitte das Erscheinungsjahr ein: ", &(M->Releasedate), 1950 , 2099);
    M->Totalnumber = 0;

	
    //Erstellung der einzelnen Tracks
	printf("Geben Sie bitte die Daten der einzelnen Tracks ein:\n\n");

    for(i = 0; i < MAXTRACKS; i++)
    {
        T = (M->Tracks) + i; 
        createTrack(T, M->interpret);
        T->Tracknr = i + 1; 
        M->Totalnumber = i + 1;

        if(!askAgain())
            break;
    }
	//Naechstes Medium
	MediaCounter++;

    //In Doppelt-Verkettete Liste einfügen und anschließen Medias wieder leeren
    insertInList(M);
    //memset(Medias, 0, sizeof(TMedia)); 
}
/**********************************************************
 * FUNCTION:        editMedia 
 * --------------------------------------------------------
 * DESCRIPTION:
 *********************************************************/
void editMedia()
{
	printf("editMedia");
}
/**********************************************************
 * FUNCTION:        deleteMedia 
 * --------------------------------------------------------
 * DESCRIPTION:
 *********************************************************/
void deleteMedia()
{
	printf("deleteMedia");
}
/**********************************************************
 * FUNCTION:        createTrack 
 * --------------------------------------------------------
 * DESCRIPTION: 	Creates a Track (tracknr, title, interpret, 
 * 					track length)
 * LAST EDIT:		21.01.2015 PS
 *********************************************************/
 
int createTrack(TTrack *pT, char * wI)
{
	getText("Geben Sie bitte den Titel des Tracks an: ", 50 , 0 , &(pT->title));
        if(!wI) //Falls Medium-Interpret leer -> Einzelne Interpreten abfragen
        {
            getText("Geben Sie bitte den Interpreten an: " , 50 , 0 , &(pT->interpret));
        }
        getTime("Geben Sie bitte die Dauer des Tracks ein\n(Format hh:mm:ss oder mm:ss): ", &(pT->lp));

	return 0;
}
/**********************************************************
 * FUNCTION:        searchTrack 
 * --------------------------------------------------------
 * DESCRIPTION:
 *********************************************************/
void searchTrack()
{
	printf("searchTrack");
}
/**********************************************************
 * FUNCTION:        sortTracks 
 * --------------------------------------------------------
 * DESCRIPTION:
 *********************************************************/
void sortTracks()
{	
	char * submenutitle = "Sortieren";
    char * menu[5] = {"1. Tracks nach Tracknr. sortieren", "2. Tracks nach Titel sortieren", 
	"3. Tracks nach Interpret sortieren", "4. Tracks nach Dauer sortieren", "5. zurueck zum Hauptmenue"};
    int choice = 0; //Auswahlvariable
    int exit = 1; //Abbruchvariable für fußgesteuerte Schleife
	    do
	{
        choice = getMenu(submenutitle, menu, 5, 1); //Aufruf des Submenüs

        switch(choice) //Ausgabe des Menüpunktes
        {
                case 1: kuhsort(Medias, 0); exit = 0; break; //Tracknr
                case 2: kuhsort(Medias, 1); exit = 0; break; //Titel
                case 3: kuhsort(Medias, 2); exit = 0; break; //Interpret
                case 4: kuhsort(Medias, 3); exit = 0; break; //Trackdauer
                case 5: exit = 0;		break;
        }
    }while(exit);
}
/**********************************************************
 * FUNCTION:        listMedia 
 * --------------------------------------------------------
 * DESCRIPTION:		Creates Menuetitle and checks if there
 *					is at least 1 Media
 * LAST EDIT:		21.01.2015 PS
 *********************************************************/
void listMedia()
{
    int i = 0;//Laufvariable

    //Ausgabe des Menuetitels
    printf("Liste der Medien\n");
    printLine('-' , 16);
    printf("\n\n");

    if (MediaCounter == 0)
    {
        printf("Keine Medien vorhanden!\n");
    }
    else
    {
        //Auflistung aller Medien
        for(i = 0 ; i < MediaCounter ; i++)
        {
            listOneMedia(i);
        }
    }
}
/**********************************************************
 * FUNCTION:        listMedia 
 * --------------------------------------------------------
 * DESCRIPTION:		Listing Mediainformations (title,
 *					interpret, Releasedate, Totalnumber)
 * LAST EDIT:		21.01.2015 PS
 *********************************************************/
void listOneMedia(int Mediennr)
{	
    TMedia * M = First;
    int i = 0, j = 0; //Laufvariable

    //Abhängig von Mediennr durch die Liste springen
    for(; j < Mediennr; j++)
    {
        M = M->Next;
    }
    //Ausgabe der Medieninformationen
    printf("Titel             : %s\n", M->title);
    if(M->interpret != NULL)
    {
        printf("Interpret         : %s\n", M->interpret);
    }
    switch(M->Type) //Medientyp
    {
        case 1: printf("Medientyp         : CD\n");        break;
        case 2: printf("Medientyp         : DVD\n");       break;
        case 3: printf("Medientyp         : Blueray\n");   break;
        case 4: printf("Medientyp         : Sonstiges\n"); break;
    }
    printf("Erscheinungsjahr  : %i\n", M->Releasedate);
    printf("Anzahl der Tracks : %i\n", M->Totalnumber);

    //Auflistung aller Tracks
    printf("Tracks\n");
    for(i = 0 ; i < (M->Totalnumber) ; i++)
    {
        listOneTrack(M, i);
    }
    printf("\n");
}
/**********************************************************
 * FUNCTION:        listMedia 
 * --------------------------------------------------------
 * DESCRIPTION:		Listing Trackinformations (Tracknr, title,
 *					interpret (if not in Media), lp)
 * LAST EDIT:		21.01.2015 PS
 *********************************************************/
void listOneTrack(TMedia * M, int Tracknum)
{
	/*Pointer auf den Anfang des Tracks-Arrays*/
	 TTrack * T = M->Tracks;

    //Ausgabe der Informationen der einzelnen Tracks

        printf("%u. %s ",(T+Tracknum)->Tracknr, (T+Tracknum)->title);
        if(M->interpret == NULL) //Interpret listen wenn nicht in Media vorhanden
        {
            printf("von %s ", (T+Tracknum)->interpret);
        }
        printf("( ");
        printTime(&((T+Tracknum)->lp));
        printf(" )\n");
}
