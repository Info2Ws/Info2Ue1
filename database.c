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
<<<<<<< HEAD
 * FUNCTION:        loadMedia  check
=======
 * FUNCTION:        loadMedia 
>>>>>>> origin/master
 * --------------------------------------------------------
 * DESCRIPTION:     checks for existing database, damaged
 *					data and will load all saved media data
 *					from file
 * STATUS:          
 * LAST EDIT:		21.01.2015 PS
 **********************************************************/ 
<<<<<<< HEAD
 void loadMedia(TMedia * mpoint)
 {
    int i;
    FILE *data;
=======
 int loadMedia()
 {
	FILE *data;
>>>>>>> origin/master
    char *text;
    void *dataField;  //Pointer auf den Anfang des Datensatzes
    void *MediaField;  //Pointer auf den Anfang der Medien
    void *dataEnd = NULL;  //Pointer auf das Ende des Datensatzes

    /* Check beim Ã–ffnen der Datei, ob erfolgreich) */
<<<<<<< HEAD
    if((data = fopen("database.dat", "rb")) == NULL)
=======
    if((data = fopen("database.dat", "r")) == NULL)
>>>>>>> origin/master
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
<<<<<<< HEAD
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
 
    
=======
    while (dataEnd == NULL)
    {
        text = calloc(256, sizeof(char));
        fgets(text, 255, data);
        MediaField = strstr(text, "<Media>");
        dataEnd = strstr(text, "</Data>");
        free(text);
        if (MediaField != NULL) /* Medium-Tag gefunden */
        {
            loadOneMedia(data);
        }
    }
>>>>>>> origin/master
    fclose(data);
    printf("Datenbank erfolgreich geladen.\n");
    return 0;
 }
 /**********************************************************
<<<<<<< HEAD
 * FUNCTION:        loadOneMedia  check
=======
 * FUNCTION:        loadOneMedia 
>>>>>>> origin/master
 * --------------------------------------------------------
 * DESCRIPTION:     will load one media from file
 * STATUS:          
 * LAST EDIT:		21.01.2015 PS
 **********************************************************/
<<<<<<< HEAD
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
=======
 void loadOneMedia(FILE * data)
 {
    char * line;
    char * text;
    void * matchTag;
    int MediaEnd = 0;
    int len;
    int TrackNr = 0;

    while (!MediaEnd)
    {
        line = calloc(256, sizeof(char));
        fgets(line, 255, data);
        if (matchTag = strstr(line, "<Interpret>"))
        {
            len = strlen(line);
            line[len - 13] = '\0';
            text = (char *) matchTag;
            text += 11;
            (Medias + MediaCounter)->interpret = calloc(len - 23, sizeof(char));
            strcpy((Medias + MediaCounter)->interpret, text);
        }
        if (matchTag = strstr(line, "<Title>"))
        {
            len = strlen(line);
            line[len - 9] = '\0';
            text = (char *) matchTag;
            text += 7;
            (Medias + MediaCounter)->title = calloc(len - 16, sizeof(char));
            strcpy((Medias + MediaCounter)->title, text);
        }
        if (matchTag = strstr(line, "<Releasedate>"))
        {
            len = strlen(line);
            line[len - 15] = '\0';
            text = (char *) matchTag;
            text += 13;
            (Medias + MediaCounter)->Releasedate = atoi(text);
        }
        if (matchTag = strstr(line, "<Track>"))
        {
            loadOneTrack(data, TrackNr);
            TrackNr++;
        }

        if (matchTag = strstr(line, "</Media>"))
        {
            (Medias + MediaCounter)->Totalnumber = TrackNr;
            MediaEnd = 1;
        }
        free(line);
    }
    MediaCounter++;
 }
/**********************************************************
 * FUNCTION:        loadOneTrack 
>>>>>>> origin/master
 * --------------------------------------------------------
 * DESCRIPTION:     will load one Track from file
 * STATUS:          
 * LAST EDIT:		21.01.2015 PS
 **********************************************************/
<<<<<<< HEAD
 void loadOneTrack(FILE * data, TMedia * mpoint, int trackNr)
=======
 void loadOneTrack(FILE * data, int TrackNr)
>>>>>>> origin/master
 {
    char * line;
    char * text;
    void * matchTag;
    int TrackEnd = 0;
    int len;
<<<<<<< HEAD
    char *pointer = NULL;
    char *pointer2 = NULL;
    int Track;
=======
    TTrack * Tp = ((Medias + MediaCounter)->Tracks)+TrackNr;
>>>>>>> origin/master
    
    while (!TrackEnd)
    {
        line = calloc(256, sizeof(char));
        fgets(line, 255, data);
        if ((matchTag = strstr(line, "<Tracknr>")))
<<<<<<< HEAD
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
=======
        {
            len = strlen(line);
            line[len - 11] = '\0';
            text = (char *) matchTag;
            text += 9;
            (Tp->Tracknr) = (unsigned int) calloc(len - 19, sizeof(unsigned int));
            (Tp->Tracknr) = (unsigned int) atoi(text);
        }
        if ((matchTag = strstr(line, "<Title>")))
        {
            len = strlen(line);
            line[len - 9] = '\0';
            text = (char *) matchTag;
            text += 7;
            (Tp->title) = calloc(len - 16, sizeof(char));
            strcpy((Tp->title), text);
        }
        if (matchTag = strstr(line, "<Interpret>"))
        {
            len = strlen(line);
            line[len - 13] = '\0';
            text = (char *) matchTag;
            text += 11;
            (Tp->interpret) = calloc(len - 16, sizeof(char));
            strcpy((Tp->interpret) , text);
>>>>>>> origin/master

        }
        if (matchTag = strstr(line, "<Duration>"))
        {
<<<<<<< HEAD
            TimeFile(data, &mpoint->Tracks[TrackNr].lp; 
=======
            len = strlen(line);

            line[len - 12] = '\0';
            text = (char *) matchTag;
            text += 10;
            convertStringToTime(text, &(Tp->lp));
>>>>>>> origin/master
        }

        if (matchTag = strstr(line, "</Track>"))
        {
            TrackEnd = 1;
        }
        free(line);
    }
 }

 
/**********************************************************
<<<<<<< HEAD
 * FUNCTION:        saveMedia check
=======
 * FUNCTION:        saveMedia 
>>>>>>> origin/master
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
<<<<<<< HEAD
 * FUNCTION:        saveOneMedia check
 * --------------------------------------------------------
 * DESCRIPTION:     will save a complete medium in a file
 **********************************************************/
void saveOneMedia(FILE *data)
{
    TMedia *Media = tagstart;
=======
 * FUNCTION:        saveOneMedia 
 * --------------------------------------------------------
 * DESCRIPTION:     will save a complete medium in a file
 **********************************************************/
void saveOneMedia(FILE *data, int CurrentMedium)
{
    TMedia *Medium = Medias + CurrentMedium;
>>>>>>> origin/master
    int i;

    /* Schreiben der Eigenschaften des Medium in die Datenbank */
    /* fÃ¼r printf eher kein adressoperator !!!!!!!!!!!!!!!!!!!!!!! checken! */
<<<<<<< HEAD
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
=======
    fprintf(data, "\t<Media>\n");
    if((Medium->interpret) != NULL)
        fprintf(data, "\t\t<Interpret>%s</Interpret>\n", (Medium->interpret));
    fprintf(data, "\t\t<Title>%s</Title>\n", (Medium->title));
    fprintf(data, "\t\t<Totalnumber>%i</Totalnumber>\n", (Medium->Totalnumber));
    fprintf(data, "\t\t<Releasedate>%i</Releasedate>\n", (Medium->Releasedate));
    fprintf(data, "\t\t<Mediatype>%i</Mediatype>\n", (Medium->Type));

    /* Schreiben der Tracks in die Datenbank */
    for(i = 0; i < (Medium->Totalnumber); i++) 
    {
        saveOneTrack(data, Medium, i);
    }
    fprintf(data, "\t</Media>\n");
}

/**********************************************************
 * FUNCTION:        saveOneTrack
 * --------------------------------------------------------
 * DESCRIPTION:     will save a single track in a file
 **********************************************************/
void saveOneTrack(FILE *data, TMedia *Medium, int TrackNumber)
{
    TTrack *Track = ((Medium->Tracks)+TrackNumber);
    TTime *Time = &(Track->lp);

    fprintf(data, "\t\t<Track>\n");
    fprintf(data, "\t\t\t<Tracknr>%i</Tracknr>\n", ((Track->Tracknr)));
    fprintf(data, "\t\t\t<Title>%s</Title>\n", (Track->title));
    if((Track->interpret) != NULL)
        fprintf(data, "\t\t\t<Interpret>%s</Interpret>\n", (Track->interpret));
    fprintf(data, "\t\t\t<Duration>%02i:%02i:%02i</Duration>\n", (Time->hour), (Time->minute), (Time->second));
>>>>>>> origin/master
    fprintf(data, "\t\t</Track>\n");
}

