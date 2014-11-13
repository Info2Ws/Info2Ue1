#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "media.h"
#include "datastructure.h"
#include "tools.h"
#include "datetime.h"

int Mediacounter = 0;
TMedia Medias[MAXMEDIA];


/**********************************************************
 * FUNCTION:        createMedia 
 * --------------------------------------------------------
 * DESCRIPTION:
 *********************************************************/
void createMedia()
{
	//Menütitel
    printf("Erfassung eines neuen Mediums\n");
    printLine('-' , 29);
    printf("\n\n");

    //Eingaben
	
    getText("Geben Sie bitte den Titel ein: ", 50 , 0 , &(Medias[MediaCounter].title));
    getText("Geben Sie bitte den Interpreten ein\n(Bei mehreren Interpreten Feld leer lassen):", 
		50 , 1 , &(Medias[MediaCounter].interpret));
	getText("Geben Sie bitte den Typ ein: ", 50 , 0 , &(Medias[MediaCounter].Type));
    getNumber("Geben Sie bitte das Erscheinungsjahr ein: ", &(Medias[MediaCounter].Releasedate), 1950 , 2099);
    Medias[MediaCounter].Totalnumber = 0;

	
    //Erstellung der einzelnen Tracks
    createTrack(&(Medias[MediaCounter]));
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
 * DESCRIPTION: Creates a Track (tracknr, title, interpret, 
 * 				track length)
 *********************************************************/
 
 void createTrack(TMedia *pMedia)
{
    unsigned int i = 0; //Laufvariable
	int repeat = 0; //Rueckgabewert der Funktion askAgain
	TTrack * pTrack = 0;
	unsigned int * pTotalnumber = 0;
	char * pInterpret = 0;
	unsigned int * pTracknr = 0;
	
	pTotalnumber = &(pMedia->Totalnumber);
	pInterpret = &(pMedia->interpret);
	
    printf("Geben Sie bitte die Daten der einzelnen Tracks ein:\n\n");

    // Abfrage der Trackinformationen
    do
    {
		pTrack = &(pMedia->Tracks[pMedia->i]);
		pTracknr = &(pTrack->Tracknr);
		
		printf("Track %i\n\n\n", (i + 1));
        *pTracknr = i + 1; //aktuelle Tracknr zuweisen
		getText("Geben Sie bitte den Titel des Tracks an: ", 50 , 0 ,&pTrack->title);
        if(*pInterpret == '\n') //Falls Medium-Interpret leer -> Einzelne Interpreten abfragen
        {
            getText("Geben Sie bitte den Interpreten an: " , 50 , 0 ,&pTrack->interpret);
        }
        getTime("Geben Sie bitte die Dauer des Tracks ein\n(Format hh:mm:ss oder mm:ss) : ",&pTrack->lp));
		i++; //Zum naechsten Feld von Tracks springen
		
		repeat = askAgain(); //weiteren Track eingeben?
    }while(repeat); //Wiederholen solange askAgain = 1 = Ja
	
	//Gesamtanzahl der Tracks des Mediums = Anzahl der eingegebenen Tracks
	*pTotalnumber = i; 
	
	//Naechstes Medium
    MediaCounter++;

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
	printf("sortTracks");
}
/**********************************************************
 * FUNCTION:        listMedia 
 * --------------------------------------------------------
 * DESCRIPTION:
 *********************************************************/
void listMedia()
{
    int i = 0;//Laufvariable

    //Ausgabe der Ueberschrift
    printf("Liste der Medien\n");
    printLine('-' , 16);
    printf("\n\n");

    if (MediaCounter == 0)
    {
        printf("Keine Medien vorhanden!\n");
        return;
    }

    //Ausgabe aller Medien
    for(i = 0 ; i < MediaCounter ; i++)
    {
        listOneMedia(i);
    }
}

void listOneMedia(int Mediennr)
{
    //laufvariable
    int i = 0;


    //Ausgabe der Medieninformationen
    printf("Titel             : %s\n", Medias[Mediennr].title);
    if(Medias[Mediennr].interpret != '\n')
    {
        printf("Interpret         : %s\n", Medias[Mediennr].interpret);
    }
    printf("Erscheinungsjahr  : %i\n", Medias[Mediennr].Releasedate);
    printf("Anzahl der Tracks : %i\n", Medias[Mediennr].Totalnumber);

    //Auflistung der einzelnen Tracks
    listOneTrack(Mediennr, Medias[Mediennr].Totalnumber);
    printf("\n");

}

void listOneTrack(int Mediennr, int Totalnumber)
{
    //Laufvariable
    int i = 0;

    //Ausgabe der Informationen der einzelnen Tracks
    printf("Tracks\n");
    for( i = 0 ; i < (Totalnumber) ; i++ )
    {

        printf("%i. %s von ",(i + 1), Medias[Mediennr].Tracks[i].title );
        if(Medias[Mediennr].interpret == \n)
        {
            printf("%s ", Medias[Mediennr].Tracks[i].interpret);
        }
        printTime(&(Medias[Mediennr].Tracks[i].lp));
        printf(" )\n");



    }

}