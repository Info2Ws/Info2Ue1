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
    fprintf(data, "\t\t\t<Tracknr>%i</Tracknr>\n", (Track->Tracknr));
    fprintf(data, "\t\t\t<Title>%s</Title>\n", (Track->title));
    if((Track->interpret) != NULL)
        fprintf(data, "\t\t\t<Interpret>%s</Interpret>\n", (Track->interpret));
    fprintf(data, "\t\t\t<Duration>%i:%i:%i</Duration>\n", (Time->hour), (Time->minute), (Time->second));
    fprintf(data, "\t\t</Track>\n");
}

