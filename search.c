#include "search.h"

/**********************************************************
 **********************************************************
 * MODULE: search 
 * --------------------------------------------------------
 * DESCRIPTION: required search function
 * FUNCTIONS:   calcDivisionRest
 *              search
 **********************************************************
 **********************************************************/

/**********************************************************
 * FUNCTION:    calcDivisionRest        
 * --------------------------------------------------------
 * DESCRIPTION: calculates the hash value
 * STATUS:          
 **********************************************************/ 
int calcDivisionRest(char *name)
{
    int wert = 0;

    while(*name)
    {
        wert += *name;
        name++;
    }
    return (wert % MAXINDEX);
}
/**********************************************************
 * FUNCTION:    inserInHashTable         
 * --------------------------------------------------------
 * DESCRIPTION: insert a new Track in the hash table
 *              MediaIndex with the calculated hashIndex
 * STATUS:          
 **********************************************************/ 
void insertInHashTable(TMedia *newM, int Tracknr)
{
    int hashIndex;

    TListElement *newLE = calloc(1, sizeof(TListElement));
    if(!newLE)
        printf("\nFuer die Suchfunktion konnte kein Speicher alloziiert werden!\n");
    newLE->list_medium = newM;            
    newLE->list_track = (newM->Tracks+Tracknr); //adressop????
    hashIndex = calcDivisionRest(newLE->list_track->title);
    appendInIndexList(MediaIndex+hashIndex, newLE);
}

TListElement *search(THashElement *HE, int (*cmp)(TTrack *, TTrack *), TListElement *tmp2)
{
    int Hashwert;
    TListElement *Erg = NULL;
    TTrack *T = tmp2->list_track;

    Hashwert = calcDivisionRest(T->title);
    Erg = (HE + Hashwert)->HFirst;
    while (Erg)
    {
        if (cmp(Erg->list_track, tmp2->list_track) == 0)
            return Erg;
        Erg = Erg->Next;
    }
    return NULL;
}

