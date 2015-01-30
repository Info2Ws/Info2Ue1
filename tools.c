#include <stdlib.h>
#include "tools.h"

/**********************************************************
 **********************************************************
 * MODULE: tools
 * --------------------------------------------------------
 * DESCRIPTION: auxillary functions
 * FUNCTIONS:
 *              clearBuffer
 *              waitForEnter
 *              clearScreen
 *              printLine
 *              askAgain
 *              getText
 **********************************************************
 **********************************************************/

/**********************************************************
 * FUNCTION:        clearBuffer
 * --------------------------------------------------------
 * DESCRIPTION:     clears keyboard's buffer, 
 *                  reads until '\n'
 **********************************************************/
void clearBuffer()
{
    char dummy;

    do
    {
        scanf("%c", &dummy);
    }while(dummy != '\n');
}

/**********************************************************
 * FUNCTION:        waitForEnter 
 * --------------------------------------------------------
 * DESCRIPTION:     prints a prompt to press '/n'
 **********************************************************/
void waitForEnter()
{
    printf("\n\nBitte ENTER drücken um fortzufahren...");
    clearBuffer();            //maybe wrong that way... <- it's ok that way
}

/**********************************************************
 * FUNCTION:        clearScreen 
 * --------------------------------------------------------
 * DESCRIPTION:     erases the actual screen
 **********************************************************/
void clearScreen()
{
    system("clear");          //unix only at the moment
}

/**********************************************************
 * FUNCTION:        printLine
 * --------------------------------------------------------
 * DESCRIPTION:     gets a char and an int number and 
 *                  prints a line with number amount of chars
 **********************************************************/
void printLine(char c, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%c", c);       //should it produce an '\n' at the end??
    }
}

/**********************************************************
 * FUNCTION:        askAgain
 * --------------------------------------------------------
 * DESCRIPTION:     asks, if the user wants to enter
 *                  another track
 * STATUS:          WIP 
 **********************************************************/
int askAgain()
{
    char choice;
    while(1)
    {
        printf("\nWeiteren Track eingeben? (J/n): ");
        scanf("%c", &choice);
        if (choice != '\n')
            clearBuffer();
        if(choice == 'J' || choice == 'j'|| choice == '\n')
        {
            return 1;
        }
        if(choice == 'N' || choice == 'n')
        {   
            return 0;
        }
        else
        {
            printf("\nBitte Frage mit Ja (j) oder Nein (n) beantworten.\nDer Großbuchstabe zeigt die Standartwahl an.\n");
            continue;
        }
    }
}

/**********************************************************
 * FUNCTION:        getText
 * --------------------------------------------------------
 * DESCRIPTION:     allocates memory for entered strings
 * PARAMETER:       name of prompt (char *)
 *                  max. length (int)
 *                  emtpy string allowed (int) (0 = false)
 *                  string to store (char **)
 * RESULT:          int
 * STATUS:          WIP 
 **********************************************************/
int getText(char *prompt, int plength, int allowempty, char **input)
{
    //Variablen
    *input = NULL;
    char *tempinput;
    int templength;
    char format[20];
    int scanreturn;

    //Speicherzuweisung der temp. Lesevariable
    tempinput = calloc(plength+1, sizeof(char));

    if(tempinput)
    {
        //Drucken des Format-Strings für scanf
        sprintf(format, "%%%i[^\n]", plength);

        do
        {
            //Eingabeaufforderung ausgeben
            printf("\n%s (max. %i Zeichen): ", prompt, plength);
            //Einlesen des Aufgeforderten
            scanreturn = scanf(format, tempinput);
            clearBuffer();
            if(scanreturn == 1)
            {
                templength = strlen(tempinput);
                if(templength > 1)
                {
                    *input = calloc(templength+1, sizeof(char));
                    if(*input)
                    {
                        strcpy(*input, tempinput);
                        free(tempinput);
                        //TODO: save pointer (*input) in a free-list, which will 
                        //      be used, when the programm will end
                        return 1;
                    }
                    else
                    {
                        fprintf(stderr, "\nFEHLER: Zu wenig Speicher!\n");
                        return 0;
                    }
                    
                }
            }
            if((scanreturn == 0) && (allowempty == 1))
            {
                free(tempinput);
                return 1;
            }
            else
            {
                printf("\nDas Feld darf nicht leer bleiben!\n");
            }
                
        }while(scanreturn == 0);
    }
    return 0;
}

/**********************************************************
 * FUNCTION:        getNumber
 * --------------------------------------------------------
 * DESCRIPTION:     prompts a number
 * PARAMETER:       name of prompt (char *)
 *                  string to store (char **)
 *                  from (int)
 *                  to (int)
 * RESULT:          int
 * STATUS:          WIP 
 **********************************************************/
int getNumber(char *prompt, int **input, int from, int to)
{
    //Variablen
    int scanreturn = NULL;
    do
    {
        //Eingabeaufforderung und Einlesen
        printf("\n%s(von %i bis %i): ", prompt, from, to);
        scanreturn = scanf("%i", input);
        clearBuffer();
        
        //Test gegen unzulässige Eingaben
        if((scanreturn == NULL) || (*input < from) || (*input > to))
        {
            printf("Bitte korrekten Wert innerhalb der Grenzen eingeben!");
        }
    }while((scanreturn == NULL) || (*input < from) || (*input > to));

    return 1;
}

/**********************************************************
 * FUNCTION:        copyToFile
 * --------------------------------------------------------
 * DESCRIPTION:     copies data into file
 **********************************************************/
void copyToFile( char *data, char **txpoint)
{
    *txpoint=NULL;


    *txpoint=calloc(strlen(text)+1,sizeof(char)); /* Speicher reservieren */
    if(*txpoint)  /* NULLzeiger? */
    {
        strcpy(*txpoint,data); /* Text ins Ziel schreiben */
    }
    else
    {
        printf("Konnte keinen Speicher zum Datei beschreiben alloziieren");
        free(*txpoint);
        exit(0);
    }
    
}
/**********************************************************
 * FUNCTION:        alphasort
 * --------------------------------------------------------
 * DESCRIPTION:     easy index
 **********************************************************/

int alphasort(TMedia *mpoint)
{

    char letter;
    int value = 0;

    value = mpoint->mTitle[0];
    value = letter;

    if(value == 0)
    {
        printf("Fehler beim einsortieren");
        exit(0);
    }
    else return value;
}


/**********************************************************
 * FUNCTION:        freeMedia
 * --------------------------------------------------------
 * DESCRIPTION:     sets Media free forever
 **********************************************************/
void freeMedia()
{
    int i;
    TListElement *list;
    TListElement *list2;
    TMedia *list = Ende;
    TMedia *list2 = NULL;
    if(MediaCounter==0)
    {
        printf("Keine Medien vorhanden.\n\n");
        waitForEnter();
        return;
    }
    while(list)      
    {
        list2 = list->Prev;
        freeOneMedia(lista);
        free(list);
        list = list2;
    }
    for(i=0; i<MAXINDEX; i++)  
    {
        if( (MediaIndex+i)!= NULL )
        {
            list = (MediaIndex+i)->FirstList;
            while(list)
            {
                list2 = list->Next;
                free(list);
                list = list2;
            }
        }
    }
    printf("\nSpeicher wieder freigegeben.\n");
}

void freeOneMedia(TMedia *mpoint)
{
    int i;

    if(mpoint->mTitle != NULL)
        free(mpoint->mTitle);
    if(mpoint->mInterpret != NULL)
        free(mpoint->mInterpret);

    for( i = 0; i < ( mpoint->mTrackNr ); i++) 
    {
        freeOneTrack( mpoint->Tracks+i );
    }
}

void freeOneTrack(TTrack *tpoint)
{

    if(tpoint->tInterpret!=NULL)
        free(tpoint->tInterpret);
    if(tpoint->tTitle != NULL)
        free(tpoint->tTitle);
    if(tpoint->lp != NULL)
        free(tpoint->lp);
}



