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
 * FUNCTION:        loadMedia 
 * --------------------------------------------------------
 * DESCRIPTION:     will load all saved media from file
 * STATUS:          
 **********************************************************/ 
 int loadMedia()
 {
	FILE *data;
    char *text;
    void *dataField;
    void *MediaField;
    void *dataEnd = NULL;

    /* Check beim Öffnen der Datei, ob erfolgreich) */
    if((data = fopen("database.dat", "r")) == NULL)
    {
        fprintf(stderr, "FEHLER: Datei konnte nicht geöffnet werden!\n");
        return 0;
    }

    /* Pointer auf <Data> */
    text = calloc(256, sizeof(char));
    fgets(text, 255, data);
    dataField = strstr(text, "<Data>");
    free(text);

    /* Fehlerprüfung: Pointer auf <Data> nicht vorhanden? */
    if (dataField == NULL)
    {
        fprintf(stderr, "FEHLER: Datenbank fehlerhaft!\n");
        return 0;
    }
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
    fclose(data);
    printf("Datenbank erfolgreich geladen.\n");
    return 1;
 }

 /**********************************************************
 * FUNCTION:        loadOneMedia 
 * --------------------------------------------------------
 * DESCRIPTION:     will load one media from file
 * STATUS:          
 **********************************************************/
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
 * --------------------------------------------------------
 * DESCRIPTION:     will load one Track from file
 * STATUS:          
 **********************************************************/
 void loadOneTrack(FILE * data, int TrackNr)
 {
    char * line;
    char * text;
    void * matchTag;
    int TrackEnd = 0;
    int len;
    int * Tp = ((Medias + MediaCounter)->Tracks)+TrackNr;
    

    while (!TrackEnd)
    {
        line = calloc(256, sizeof(char));
        fgets(line, 255, data);
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

        }

        if (matchTag = strstr(line, "<Duration>"))
        {
            len = strlen(line);

            line[len - 12] = '\0';
            text = (char *) matchTag;
            text += 10;
            convertStringToTime(text, &(Tp->lp));
        }

        if (matchTag = strstr(line, "</Track>"))
        {
            TrackEnd = 1;
        }
        free(line);
    }

    return 1;
 }

 
/**********************************************************
 * FUNCTION:        saveMedia 
 * --------------------------------------------------------
 * DESCRIPTION:     will save all entered media in a file
 * STATUS:          WIP, in this version it will always
 *                  create a new database
 **********************************************************/
int saveMedia()
{
    FILE *data;
    int i;

    /* Check beim Öffnen der Datei, ob erfolgreich) */
    if((data = fopen("database.dat", "w")) == NULL)
    {
        fprintf(stderr, "FEHLER: Datei konnte nicht geöffnet werden!\n");
        return 0;
    }
    else
    {
        /* Drucke <Data> für Anfang der Datenbank */
        fprintf(data, "<Data>\n");
        /* Beginne einzelne Medien zu speichern */
        for(i = 0; i < MediaCounter; i++)
        {
            saveOneMedia(data, i);
        }

        /* Drucke </Data> für Ende der Datenbank */
        fprintf(data, "</Data>");
        /* Schließen der Datenbank */
        fclose(data);
    }
    return 1;
}

/**********************************************************
 * FUNCTION:        saveOneMedia 
 * --------------------------------------------------------
 * DESCRIPTION:     will save a complete medium in a file
 **********************************************************/
void saveOneMedia(FILE *data, int CurrentMedium)
{
    TMedia *Medium = Medias + CurrentMedium;
    int i;

    /* Schreiben der Eigenschaften des Medium in die Datenbank */
    /* für printf eher kein adressoperator !!!!!!!!!!!!!!!!!!!!!!! checken! */
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
    fprintf(data, "\t\t</Track>\n");
}

