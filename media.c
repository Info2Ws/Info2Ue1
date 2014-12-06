#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "media.h"
#include "datastructure.h"
#include "tools.h"
#include "datetime.h"

int MediaCounter = 0;
TMedia Medias[MAXMEDIA];


/**********************************************************
 * FUNCTION:        createMedia 
 * --------------------------------------------------------
 * DESCRIPTION:
 *********************************************************/
void createMedia()
{
	TMedia * M = Medias + MediaCounter;

	//Menütitel
    printf("Erfassung eines neuen Mediums\n");
    printLine('-' , 29);
    printf("\n\n");

    //Eingaben
    getText("Geben Sie bitte den Titel ein: ", 50 , 0 , &(M->title));
    getText("Geben Sie bitte den Interpreten ein\n(Bei mehreren Interpreten Feld leer lassen):", 
	50 , 1 , &(M->interpret));
    //getText("Geben Sie bitte den Typ ein: ", 50 , 0 , &(M->Type));
    getNumber("Geben Sie bitte das Erscheinungsjahr ein: ", &(M->Releasedate), 1950 , 2099);
    M->Totalnumber = 0;

	
    //Erstellung der einzelnen Tracks
	printf("Geben Sie bitte die Daten der einzelnen Tracks ein:\n\n");    
	do
	{
		if((createTrack(M->Tracks + M->Totalnumber, M->interpret)) == NULL){
			(M->Totalnumber)++;
			((M->Tracks + M->Totalnumber)->Tracknr) = M->Totalnumber;
		}
		else
		{
			break;
		}
    }while((askAgain()) && (M->Totalnumber < MAXTRACKS));

	//Naechstes Medium
	MediaCounter++;
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
 
int createTrack(TTrack *pT, int wI)
{
	// Abfrage der Trackinformationen	
	printf("Track %i\n\n\n", pT->Tracknr + 1);
    
	getText("Geben Sie bitte den Titel des Tracks an: ", 50 , 0 , &(pT->title));
        if(!wI) //Falls Medium-Interpret leer -> Einzelne Interpreten abfragen
        {
            getText("Geben Sie bitte den Interpreten an: " , 50 , 0 , &(pT->interpret));
        }
        getTime("Geben Sie bitte die Dauer des Tracks ein\n(Format hh:mm:ss oder mm:ss) : ",&(pT->lp));	 

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
    }
	else
	{
    	//Ausgabe aller Medien
    	for(i = 0 ; i < MediaCounter ; i++)
    	{
    	    listOneMedia(i);
    	}
	}
}

void listOneMedia(int Mediennr)
{
    int i = 0; //Laufvariable


    //Ausgabe der Medieninformationen
    printf("Titel             : %s\n", Medias[Mediennr].title);
    if(Medias[Mediennr].interpret != NULL)
    {
        printf("Interpret         : %s\n", Medias[Mediennr].interpret);
    }
    printf("Erscheinungsjahr  : %i\n", Medias[Mediennr].Releasedate);
    printf("Anzahl der Tracks : %i\n", Medias[Mediennr].Totalnumber);

    //Auflistung der einzelnen Tracks
    listOneTrack(Mediennr, Medias[Mediennr].Totalnumber);
    printf("\n");

}

void listOneTrack(int Mediennr, unsigned int Totalnumber)
{
    //Laufvariable
    int i = 0;

    //Ausgabe der Informationen der einzelnen Tracks
    printf("Tracks\n");
    for( i = 0 ; i < (Totalnumber) ; i++ )
    {

        printf("%i. %s ",(i + 1), Medias[Mediennr].Tracks[i].title );
        if(Medias[Mediennr].interpret == NULL)
        {
            printf("von %s ", Medias[Mediennr].Tracks[i].interpret);
        }
        printTime(&(Medias[Mediennr].Tracks[i].lp));
        printf(" )\n");



    }

}
