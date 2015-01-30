#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "media.h"


int MediaCounter = 0;
THashElement MediaIndex[MAXINDEX];
TMedia *First = NULL;
TMedia *Prev = NULL;

/**********************************************************
 * FUNCTION:        createMedia 
 * --------------------------------------------------------
 * DESCRIPTION:		Creates an Interface to enter Media 
 * 			related data (title, interpret, Type, 
 *			Releasedate)
 * LAST EDIT:		21.01.2015 PS
 *********************************************************/
void createMedia(TMedia *mpoint)
{
    char userselection[5];
    int choice=0;
    clearscreen();
    printf("Erfassung eines neuen Mediums\n");
    printLine('-' , 29);
    printf("\n\n");
    printf("Medium waehlen:\n1. CD\n2. DVD\n3. Blueray\n4. Sonstiges\n5. Zurueck\n"

    	    
    	    
    do
    {
        scanf("%2[^\n]", userselection);        
        choice = atoi(eingabe);
        clearBuffer();
        if(choice<1 || choice>5)
            printf("Versuchen wir es noch einmal.\n");

    } while(choice<1 || choice>5);
    if(auswahl==5)  
        return;

    mpoint = malloc(sizeof(TMedia));
    if(mpoint) {
    } else {
        printf("Fehler bei der Speicherreservierung. \n");
        exit(0);
    }
   
    getText("Geben Sie bitte den Titel ein: ", 50 , 0 , &mpoint->mTitle));
    getText("Geben Sie bitte den Interpreten ein\n(Bei mehreren Interpreten Feld leer lassen):", 50 , 1 , &mpoint->mInterpret);
    getNumber("Geben Sie bitte das Erscheinungsjahr ein: ", &(M->Releasedate), 1950 , 2099);
    M->Totalnumber = 0;

	
    printf("\n");
    waitForEnter();
    clearScreen();
    createTrack(mpoint);
    mpoint->Index = alphasort(mpoint); 1
    insertInList(mpoint);
    MediaCounter++;
    mpoint->MediaNr = MediaCounter;
}
    
    
  /***************************************************
* Funktion createTrack zum Erstellen eines Tracks  *
***************************************************/
void createTrack(TMedia *mpoint) {
    int schleife;
    int TrackNr = 0;

    do {
        printf("Eingabe der Tracks\n");
        printLine('/', 20);
        if(mpoint->mInterpret == NULL) {
            getText("Geben Sie bitte den Interpreten des Tracks ein:\n->",50,0,&mpoint->Tracks[TrackNr].tInterpret);
        } else
            mpoint->Tracks[TrackNr].tInterpret = NULL;
        getText("Geben Sie bitte den Namen des Tracks ein:\n->",50,0,&mpoint->Tracks[TrackNr].tTitle);
        getTime("Geben Sie bitte die Dauer des Tracks ein:\n(Eingabe bitte mit hh:mm:ss oder mm:ss)\n->", &mpoint->Tracks[TrackNr].lp);
        schleife = askAgain();
        mpoint->Tracks[TrackNr].TrackNr = TrackNr+1;
        insertInHashTable(mpoint, TrackNr);  /* Track[TrackNr] in hashtable einsortieren */
        TrackNr++;
        if( TrackNr >=19 ) {
            clearScreen();
            printf("ACHTUNG: Zu viele Tracks bei Medium %d\nWeitere Tracks werden nicht hinzugefuegt.\nBitte Premium Edition kaufen.\n\n", MediaCounter+1);
            waitForEnter();
            break;
        }
    } while(schleife==1);
    mpoint->MediaNr = TrackNr;
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
 * FUNCTION:        deleteMedia  check
 * --------------------------------------------------------
 * DESCRIPTION:
 *********************************************************/
void deleteMedia() {
    TMedia *mpoint = Anfang;
    TMedia *del = NULL;
    int i, hash;
    char userinput[10];

    clearScreen();
    if(First==NULL) {
        printf("Keine Medien zum loeschen vorhanden.\n");
        waitForEnter();
        return;
    }
    printf("Liste der Medien:\n");
    printLine('-',17);
    printf("\n");

    for(i=0; i<MediaCounter; i++) {
        printf("  %d:  %s\n", i+1, mpoint->mTitle);

        mpoint = mpoint->Next;
    }
    printf("  0:  Zurueck zum Hauptmenue\n\n");
    printf("Welches Medium moechten Sie loeschen?\n-> ");
    do {
        scanf("%19[^\n]", userinput);
        i = atoi(userinput);
        clearBuffer();    
        if(i<0 || i>MediaCounter)
            printf("Keine gueltige Eingabe. Bitte wiederholen.\n");
    } while(i<0 || i>MediaCounter);

    if(i==0)   /* zurück zum Hauptmenü? */
        return;
    else {
        del=removeFromList(i);  /* Aus der Verkettung entfernen und Zeiger auf Adresse */
        for(i=0; i<del->mTrackNr; i++) { /* aus Mediaindex entfernen */
            hash = calcDivisionsrest(del->Tracks[i].tTitle);
            deleteFromList(MediaIndex+hash,del->Tracks+i);
        }
        if(del) /* Speicher freigeben */
            freeOneMedia(del);
        MediaCounter--;
    }
    printf("\n\n");
    waitForEnter();
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
void searchTrack() {
    clearScreen();
    printf("Nach welchem Track steht ihnen der Sinn?\n-> ");
    char userinput[70];
    int value;
    TListElement *data;

    scanf("%69[^\n]", userinput);     /* eingabe Track */
    wert = calcDivisionsrest(userinput);
    clearBuffer();

    if( (MediaIndex+value)->FirstList ) { /* Wenn Index !=0, suche nach Track in der verketteten Liste */
        data = (MediaIndex+value)->FirstList;
        while( data ) {
            if(strcmp(userinput,data->mpoint->tTitle)) 
                data = data->Next;
            else
                break;
        }
        printf("\n\nSuchergebnis:\n");  /* Ausgabe */
        printLine('-',13);
        if(data) {
            printf("\nIn folgendem Medium befand sich der Track: %s\n  ", data->mpoint->mTitle);
            listOneTrack(data->mpoint);
            printf("\n");
        }

    } else
        printf("\nTrack nicht gefunden.\n\n");
    waitForEnter();
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
    int exit = 1; //Abbruchvariable fÃ¼r fuÃŸgesteuerte Schleife
	    do
	{
        choice = getMenu(submenutitle, menu, 5, 1); //Aufruf des SubmenÃ¼s

        switch(choice) //Ausgabe des MenÃ¼punktes
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
 * FUNCTION:        listMedia check
 * --------------------------------------------------------
 * DESCRIPTION:		Sorts Media naow
 *					
 * LAST EDIT:		21.01.2015 PN
 *********************************************************/
void listMedia()
{
    int ascordesc = 0;//Aufwaerts oder abwaerts
    char *ausgabe = {"Ausgabe"};
    char *menu[3] = {"1. Aufwaerts",
                     "2. Abwaerts",
                     "3. Zurueck zum Hauptmenue"
                    };
    TMedia *data = First;

    if(First==NULL) { /* Medien vorhanden? */
        printf("Keine Medien zum Ausgeben vorhanden.\n");
        waitForEnter();
        return;
    }
    ascordesc = getMenu(menu,ausgabe,1,3); /* Menü ausgeben */
    if(ascordesc==3) /* Hauptmenü */
        return;
    clearScreen();
    printf("Liste der Medien\n");
    sortListbyMedia(data, data->Next); /* Medien Sortieren */
    if(ascordesc==1) { /* Aufwärts */
        data = Ende;
        while(data) {
            listOneMedia(data);
            data = data->Prev;
        }
    } else { /* Abwärts */
        while(data) {
            listOneMedia(data);
            data = data->Next;
        }

    }
    waitForEnter();
}
/**********************************************************
 * FUNCTION:        listOneMedia check
 * --------------------------------------------------------
 * DESCRIPTION:		Listing Mediainformations (title,
 *					interpret, Releasedate, Totalnumber)
 * LAST EDIT:		21.01.2015 PN
 *********************************************************/
void listOneMedia(TMedia * mpoint)
{	
    int i;

    printLine('-', 16);
    switch((pMedia)->MediumTYP)
    {
    	    
  	 case 1:printf("\nMedientyp          : CD\n");	 break;
   	 case 2:printf("\nMedientyp          : DVD\n"); break;
   	 case 3:printf("\nMedientyp          : Blueray\n");break;
   	 case 4:printf("\nMedientyp          : Sonstiges\n");break;
    }
    printf("Name               : %s\n", (mpoint)->mTitle);
    if(mpoint->mInterpret != NULL)
    printf("Interpret          : %s\n", (mpoint)->mInterpret);
    printf("Erscheinungsjahr   : %d\n", (mpoint)->Releasedate);
    printf("Anzahl Tracks      : %d\n", (mpoint)->mTracknr);
    printf("Tracks:\n");

    for( i = 0; i < ( mpoint->mTrackNr ); i++) {
        listOneTrack( mpoint->Tracks+i );
    }
    printf("\n");
}


/**********************************************************
 * FUNCTION:        listIndex check
 * --------------------------------------------------------
 * DESCRIPTION:		Listing Hashes, Medias, Tracks
 *					
 * LAST EDIT:		21.01.2015 PN
 *********************************************************/
void listIndex() {

    int i;
    TListElement *data;

    clearScreen();
    for(i=0; i<MAXINDEX; i++) {
        if( (MediaIndex+i)!= NULL) {
            data = (MediaIndex+i)->FirstList;
            while( data ) { /* Gehe die ganze (einfach verkettete) Liste durch */
                if( data == (MediaIndex+i)->FirstList )
                    printf("Hash = %03d: M = %s; T = %s\n", i , data->mpoint->mTitle, data->tpoint->tTitle );
                else
                    printf("            M = %s; T = %s\n", data->mpoint->mTitle, data->tpoint->tTitle );
                data = data->Next;
            }
        }

    }
    printf("\n");
    waitForEnter();
    return;
}
