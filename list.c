#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


/**********************************************************
 * FUNCTION:    insertInList        
 * --------------------------------------------------------
 * DESCRIPTION: insert Media in the doubly linked list
 *                  
 * STATUS:          
 **********************************************************/ 
int insertInList(TMedia *Neu)
{
    TMedia *temp = First;
    int cmpResult;
    if(Neu == NULL)
        return 0;

    if(First == NULL)
    {
        //Fall1: Liste leer
        Neu->Next = Neu->Prev = NULL;
        First = Last = Neu;
        return 1;
    }
    
    cmpResult = cmpMediaTitleAsc(First, Neu); 

    if(cmpResult >= 0)
    {
        //Fall2: Vor dem ersten Element
        Neu->Next = First;
        Neu->Prev = NULL;
        First = First->Prev = Neu;
        return 1;
    }

    while(temp->Next != NULL)
    {
        cmpResult = cmpMediaTitleAsc(temp, Neu);

        //if(cmpResult >= 0 && (temp->Next != NULL))
        if(cmpResult >= 0)
        {   //Fall4: Dazwischen
            Neu->Next = temp->Next;
            Neu->Prev = temp;
            temp->Next = temp->Next->Prev = Neu;
            return 1;
        }

        temp = temp->Next;
    }

    if(cmpResult <= 0 && (temp->Next == NULL))
    {
        //Fall3: Nach dem letzen Element
        Neu->Prev = Last;
        Neu->Next = NULL;
        Last = Last->Next = Neu;
        return 1;
    }
    else
        printf("\nDa blieb ein Fall wohl unbeachtet bei insertInList!\n");
    return 0;
}

/**********************************************************
 * FUNCTION:        cmpMediaTitleAsc 
 * --------------------------------------------------------
 * DESCRIPTION:     compares two mediatitles
 *
 *                  returns < 0, if t1 < t2 (eg a < b)
 *                  returns   0, if t1 = t2
 *                  returns > 0, if t1 > t2
 * STATUS:          
 **********************************************************/ 
int cmpMediaTitleAsc(TMedia *t1, TMedia *t2)
{
	char *str1 = (t1->title);  //doch bloß kein & davor!
	char *str2 = (t2->title);  //denn title ist eine adresse
	int i = 0;

    //if adress of both titles is NULL return 0
    if((str1 == '\0') && (str2 == '\0'))
    {
        return 0;
    }
    //if adress of one is NULL: change value of that str to \0
    if(str1 == NULL)
        *str1 = '\0';
    if(str2 == NULL)
        *str2 = '\0';
	//work, as string1 and 2 are not at end
	while((*(str1 + i) != '\0'))
	{
		if(*(str1 + i) < *(str2 + i))
			return *(str1 + i) - *(str2 + i);
		else if(*(str1 + i) > *(str2 + i))
			return *(str1 + i) - *(str2 + i);
		i++;
	}
	return 0;
}

/**********************************************************
 * FUNCTION:        deleteMedia 
 * --------------------------------------------------------
 * DESCRIPTION:     lists media forward or backward
 *                  and passes the chosen Media (int) to the
 *                  removeFromList function which passes
 *                  a pointer (TMedia *) to free()
 *********************************************************/
void deleteMedia()
{
    char *list_menutitle = "Ausgabe Medien";
    char *list_menu[3] = {"1. Vorwaerts ausgeben", "2. Rueckwaerts ausgeben", "3. Zurueck zum Hauptmenu"};
    int choice, direction, delchoice;
    int exit = 1;
    TMedia *trash = NULL;  //Zeiger auf ein zu loeschendes Medium

    do
    {
        choice = getMenu(list_menutitle, list_menu, 3, 1);
        switch(choice)
        {
            case 1: direction = 0; exit = 0; break;
            case 2: direction = 1; exit = 0; break;
            case 3: direction = 2; exit = 0; break;
        }
    }while(exit);

    if(direction == 2)  //missbraucht die direction variable zum vorzeitigen Beenden
        return;
    clearScreen();

    TMedia *tmp = (direction == 0) ? First : Last; //beginne je nach Richtung vorn oder hinten
    int i = 0;      //Laufvariable

    //Ausgabe des Menuetitels
    printf("Liste der Medien:\n");
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
            printf("\n%i: %s", i+1, tmp->title);
            tmp = (direction == 0) ? tmp->Next :tmp->Prev;
        }
    }
    //Lese von Nutzer Index des zu loeschenden Medium ein
    getNumber("\nGeben Sie bitte die Nummer des zu loeschenden Mediums an ", &delchoice, 1, MediaCounter);
    trash = removeFromList(delchoice - 1, direction); 
    free(trash);
    MediaCounter--;
}
/**********************************************************
 * FUNCTION:        removeFromList
 * --------------------------------------------------------
 * DESCRIPTION:     deletes items from list
 *		    checks for:
 *		    Empty List
 *		    First Element
 *		    Last Element
 *		    Somewhere inbetween
 * STATUS:          
 **********************************************************/ 
TMedia *removeFromList(int delIndex, int direction)
{
    int i;
    TMedia *tmp = (direction == 0) ? First : Last;
    TMedia *pretmp;
    for(i = 0; i < delIndex; i++)   //durchlaufe Liste bis zum passenden Element
        tmp = (direction == 0) ? tmp->Next : tmp->Prev;
    //Fall1: Liste leer 
    if (tmp == NULL)
        return NULL;
    //Fall2: Erstes Element
    if (tmp == First)
    {
        tmp = First;
        First = First->Next;
        if (First == NULL) //Nur ein Element?
            Last = NULL;
        else
            First->Prev = NULL;
        return tmp;
    }
	//Letztes Element entfernen
    else if (tmp == Last)
    {
        tmp = Last;
        Last = Last->Prev;
        Last->Next = NULL;
        return tmp;
    }
    //Gesuchtes Element mittig
    else 
    {
        pretmp = tmp->Prev;
        pretmp->Next = tmp->Next;
        pretmp->Next->Prev = pretmp;
        return tmp;
    }
    return NULL;
} 
