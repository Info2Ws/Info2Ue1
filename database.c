#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"
#include "media.h"
#include "datetime.h"
#include "datastructure.h"
#include "database.h"


/**********************************************************
 **********************************************************
 * MODULE: database 
 * --------------------------------------------------------
 * DESCRIPTION: required for saving and loading medias
 * FUNCTIONS:   saveMedia
 *              saveOneMedia
 *              saveOneTrack
 *              loadMedia
 *              loadOneMedia
 *              loadOneTrack
 **********************************************************
 **********************************************************/

/**********************************************************
 * FUNCTION:        loadMedia  check
 * --------------------------------------------------------
 * DESCRIPTION:     checks for existing database, damaged
 *					data and will load all saved media data
 *					from file
 * STATUS:          
 * LAST EDIT:		21.01.2015 PS
 **********************************************************/ 
 void loadMedia(TMedia * mpoint)
 {
    int i;
    FILE *data;
    char *text;
    void *dataField;  //Pointer auf den Anfang des Datensatzes
    void *MediaField;  //Pointer auf den Anfang der Medien
    void *dataEnd = NULL;  //Pointer auf das Ende des Datensatzes

    /* Check beim Ã–ffnen der Datei, ob erfolgreich) */
    if((data = fopen("database.dat", "rb")) == NULL)
    {
        fprintf(stderr, "FEHLER: Datei konnte nicht geÃ¶ffnet werden!\n");
        return 1;
    }

    /* Pointer auf <Data> */
    text = calloc(256, sizeof(char));
    fgets(text, 255, data);
    dataField = strstr(text, "<Data>");
    free(text);

    /* FehlerprÃ¼fung: Pointer auf <Data> nicht vorhanden? */
    if (dataField == NULL)
    {
        fprintf(stderr, "FEHLER: Datenbank fehlerhaft!\n");
        return 1;
    }
    while (fscanf(data, "80[^\n]", text)!= EOF)
    {
    	    
        mpoint = calloc(256, sizeof(char));
        if(mpoint){
        	mpoint->minterpret = NULL;
        for(i=0;i<20;i++)
        	mpoint->Tracks[i].tInterpret = NULL;
        }
        else{
        	printf("Fehler bei der Speicherreservierung!\n");
        	exit;
        }
        loadOneMedia(data, mpoint);
        mpoint->Index = Sortierkram(mpoint);
        MediaCounter++;
        mpoint->medianr = Mediacounter;
        insertInList(mpoint);
    
 }
 
    
    fclose(data);
    printf("Datenbank erfolgreich geladen.\n");
    return 0;
 }
 /**********************************************************
 * FUNCTION:        loadOneMedia  check
 * --------------------------------------------------------
 * DESCRIPTION:     will load one media from file
 * STATUS:          
 * LAST EDIT:		21.01.2015 PS
 **********************************************************/
 void loadOneMedia(FILE * data, TMedia * mpoint, int trackNo)
 {
    int trackNo = 0;
    int releaseyear = 0;
    int mediatype = 0;
    int MediaEnd= 1;
    char Media[90];
    char MTag[] = {"</Media>"};
    char TrackTag[] = {"<Track>"};
    char MInterpretTag[] = {"<MediaINTERPRET>"};
    char MTitleTag[] = {"<MediaTITEL>"};
    char ReleaseTag[] = {"<Releasedate>"};
    char MTypeTag[] = {"<Mediatype>"};
    char *tagstart= NULL;
    char *tagend = NULL;
   
    
    while (!MediaEnd)
    {
    do{
    fscanf(data, "%89[^\n]\n", Medium);
    if(strstr(Media, MInterpretTag) != NULL)
    {
    	    tagstart = strchr(Medium, '>'); //Zeiger aufs erste Medium
    	    tagend = strrchr(Medium, '<'); //"		" letzte Medium
    	    tagstart++;
    	    *tagend ='0';
    	    
    	    copyToFile(tagstart, &mpoint->mInterpret);
    	    
    	    tagstart = NULL;
    }
    if( strstr(Media, MTitleTag) != NULL)   
        {

            tagstart = strchr(Media, '>'); 
            tagend = strrchr(Media, '<'); 
            tagstart++;
            *tagend = '\0';   

            copyToFile(tagstart, &mpoint->mTitle);

            tagstart = NULL;
        }
        if( strstr(Medium, ReleaseTag) != NULL)   /* <Erscheinungsjahr> in der eingelesenen Zeile? */
        {
            tagstart = strchr(Media, '>'); /* Adresse vom ersten > */
            tagstart++;    /* nächstes zeichen */
            releaseyear=atoi(tagstart);
            mpoint->Mreleaseyear = Releasedate;
            tagstart = NULL; /* zurücksetzen für nächste if-abfrage */
        }
        if( strstr(Medium, MTypeTag) != NULL)   /* <Mediatype> in der eingelesenen Zeile? */
        {
            tagstart = strchr(Media, '>'); /* Adresse vom ersten > */
            tagstart++;    /* nächstes zeichen */
            mediatype=atoi(tagstart);
            mpoint->MType = mType;
            tagstart = NULL; /* zurücksetzen für nächste if-abfrage */
        }
    
/* SUCHE UND SPEICHERE MEDIA-TAGS ENDE */
        if(strcmp(Media, TrackTag)==0)
        {
            loadOneTrack(data, mpoint, trackNo );
            insertInHashTable(mpoint, trackNo);              /* Track[TrackNo] in hashtable einsortieren */
            trackNo++;
            mpoint->Mrackno = trackNo;
            if(mpoint->MtrackNo >= 20){
                clearScreen();
                printf("ACHTUNG: Zu viele Tracks bei Medium %d\nWeitere Tracks werden nicht hinzugefuegt bevor sie das Premiumupdate für 9€ 99 kaufen.\nBitte Premium Edition kaufen.\n\n", MediaCounter+1);
                waitForEnter();
                break;
            }
        }
        if(strcmp(Media, MTag)==0)
        {
            break;
        }
    }
/**********************************************************
 * FUNCTION:        loadOneTrack check
 * --------------------------------------------------------
 * DESCRIPTION:     will load one Track from file
 * STATUS:          
 * LAST EDIT:		21.01.2015 PS
 **********************************************************/
 void loadOneTrack(FILE * data, TMedia * mpoint, int trackNr)
 {
    char * line;
    char * text;
    void * matchTag;
    int TrackEnd = 0;
    int len;
    char *pointer = NULL;
    char *pointer2 = NULL;
    int Track;
    
    while (!TrackEnd)
    {
        line = calloc(256, sizeof(char));
        fgets(line, 255, data);
        if ((matchTag = strstr(line, "<Tracknr>")))
         {
            pointer = strchr(data, '>'); /* Adresse vom ersten > */
            pointer++;    /* nächstes zeichen */
            Track=atoi(ptr);
            mpoint->Tracks[TrackNr].Tracknr = Track;
            ptr = NULL; /* zurücksetzen für nächste if-abfrage */
        }
        if ((matchTag = strstr(line, "<Title>")))
        {
            pointer = strchr(data, '>'); 
            pointer2 = strrchr(data, '<'); 
            pointer++;
            *pointer2 = '\0';  
            copyToFile(pointer, &mpoint->Tracks[TrackNr].tTitle);
            pointer = NULL;
        }
        
        if (matchTag = strstr(line, "<Interpret>"))
        {
            pointer = strchr(tmp, '>'); 
            pointer2 = strrchr(tmp, '<'); 
            pointer++;
            *pointer2 = '\0';  
            copyToFile(pointer, &mpoint->Tracks[TrackNr].tInterpret);
            pointer = NULL;

        }
        if (matchTag = strstr(line, "<Duration>"))
        {
            TimeFile(data, &mpoint->Tracks[TrackNr].lp; 
        }

        if (matchTag = strstr(line, "</Track>"))
        {
            TrackEnd = 1;
        }
        free(line);
    }
 }

 
/**********************************************************
 * FUNCTION:        saveMedia check
 * --------------------------------------------------------
 * DESCRIPTION:     will save all entered media in a file
 * STATUS:          WIP, in this version it will always
 *                  create a new database
 **********************************************************/
int saveMedia()
{
    FILE *data;
    int i;

    /* Check beim Ã–ffnen der Datei, ob erfolgreich) */
    if((data = fopen("database.dat", "w")) == NULL)
    {
        fprintf(stderr, "FEHLER: Datei konnte nicht geÃ¶ffnet werden!\n");
        return 0;
    }
    else
    {
        /* Drucke <Data> fÃ¼r Anfang der Datenbank */
        fprintf(data, "<Data>\n");
        /* Beginne einzelne Medien zu speichern */
        for(i = 0; i < MediaCounter; i++)
        {
            saveOneMedia(data, i);
        }

        /* Drucke </Data> fÃ¼r Ende der Datenbank */
        fprintf(data, "</Data>");
        /* SchlieÃŸen der Datenbank */
        fclose(data);
    }
    return 1;
}

/**********************************************************
 * FUNCTION:        saveOneMedia check
 * --------------------------------------------------------
 * DESCRIPTION:     will save a complete medium in a file
 **********************************************************/
void saveOneMedia(FILE *data)
{
    TMedia *Media = tagstart;
    int i;

    /* Schreiben der Eigenschaften des Medium in die Datenbank */
    /* fÃ¼r printf eher kein adressoperator !!!!!!!!!!!!!!!!!!!!!!! checken! */
    while (Medium){
    fprintf(data, "\t<Media>\n");
    if((Medium->interpret) != NULL)
        fprintf(data, "\t\t<Interpret>%s</Interpret>\n", (Media->mInterpret));
    fprintf(data, "\t\t<Title>%s</Title>\n", (Media->mTitle));
    fprintf(data, "\t\t<Totalnumber>%i</Totalnumber>\n", (Media->Totalnumber));
    fprintf(data, "\t\t<Releasedate>%i</Releasedate>\n", (Media->Releasedate));
    fprintf(data, "\t\t<Mediatype>%i</Mediatype>\n", (Media->Type));

    /* Schreiben der Tracks in die Datenbank */
    for(i = 0; i < (Media->Totalnumber); i++) 
    {
        saveOneTrack(data, Media, i);
    }
    fprintf(data, "\t</Media>\n");
    Media = Media ->Next;
}
}
/**********************************************************
 * FUNCTION:        saveOneTrack check
 * --------------------------------------------------------
 * DESCRIPTION:     will save a single track in a file
 **********************************************************/
void saveOneTrack(FILE *data, TMedia *mpoint, int TrackNr)
{
    

    fprintf(data, "\t\t<Track>\n");
    fprintf(data, "\t\t\t<Tracknr>%i</Tracknr>\n", mpoint->Tracks[TrackNr].TrackNr);
    fprintf(data, "\t\t\t<Title>%s</Title>\n", mpoint->Tracks[TrackNr].tTitle;
    if((Track->interpret) != NULL)
        fprintf(data, "\t\t\t<Interpret>%s</Interpret>\n",  mpoint->Tracks[TrackNr].tInterpret;
    fprintf(data, "\t\t\t<Duration>%02i:%02i:%02i</Duration>\n", mpoint->Tracks[TrackNr].lp->hour), mpoint->Tracks[TrackNr].lp->min, mpoint->Tracks[TrackNr].lp->second;
    fprintf(data, "\t\t</Track>\n");
}

