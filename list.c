#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


/**********************************************************
 * FUNCTION:        
 * --------------------------------------------------------
 * DESCRIPTION:     
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
    

   /* if(cmpResult < 0)
    {
        //Fall3: Nach dem letzen Element
        Neu->Prev = Last;
        Neu->Next = NULL;
        Last = Last->Next = Neu;
        return 1;
    }*/
    
    while(temp->Next != NULL && (cmpResult = cmpMediaTitleAsc(temp, Neu)) < 0)
    {
        //cmpResult = cmpMediaTitleAsc(temp, Neu); 


        if(cmpResult <= 0 && (temp->Next != NULL))
        {   //Fall4: Dazwischen
            Neu->Next = temp->Next;
            Neu->Prev = temp;
            temp->Next = temp->Next->Prev = Neu;
            return 1;
        }

        if(cmpResult < 0 && (temp->Next == NULL))
        {
            //Fall3: Nach dem letzen Element
            Neu->Prev = Last;
            Neu->Next = NULL;
            Last = Last->Next = Neu;
            return 1;
        }

        temp = temp->Next;
    }
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
	char *str1 = &(t1->title);
	char *str2 = &(t2->title);
	int i = 0;

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
 * FUNCTION:        removeFromList
 * --------------------------------------------------------
 * DESCRIPTION:     deletes items from list
 *		    checks for:
 *		    Empty List
 *		    First Element
 *		    Last Element
 *		    Somewhere inbetween
 *                  
 * STATUS:          
 ********************************************************** 
TMedia * removeFromList(int delIndex)
{
    TMedia * M = NULL, * Prev = NULL;
    
    if (First == NULL) //bei leerer Liste
        return NULL;
    
    if (First->Index == delIndex)
    {
        M = First;
        First = First->Next;
        if (First == NULL) //Nur ein Element?
            Last = NULL;
        else
            First->Prev = NULL;
        return M;
    }
	//Letztes Element entfernen
    if (Last->Index == delIndex)
    {
        M = Last;
        Last = Last->Prev;
        Last->Next = NULL;
        return M;
    }
    //Gesuchtes Element mittig
    M = First->Next;
    while (M != NULL)
    {
		if (M->Index == delIndex)
		{
			Prev = M->Prev;
			Prev->Next = M->Next;
			Prev->Next->Prev = Prev;
			return M;
		}
		M = M->Next;
	}
    printf("Der gewuenschte Titel konnte nicht gefunden werden");
    return NULL;
} 

*/

//=============================================================
/*
void appendInList(TMedia *eingabe)
{
	struct medien *zeiger, *zeiger1; //Zeiger auf einzelne Elemente der Struktur

	if(Last == NULL)
	{
		if((Last=(TMedia *)(calloc(1, sizeof(TMedia))))== NULL)
		{
			printf("Kauf dir mal mehr RAM!!\n");
			return;
		}
	}
    //Fall1: Liste ist leer
	if(First == NULL){
		if((First =(TMedia *)(calloc(1, sizeof(TMedia))))== NULL)
		{
			fprintf(stderr, "Konnte keinen Speicherplatz fuer das erste Element reservieren!\n");
			return ;
		}
		*First = *eingabe;		
		First -> Next = First->Prev = NULL;
		Last = First;
		//Last -> Prev = First;
	}
    //Fall2: Liste ist nicht leer
	else
	{
		zeiger = First;
		while(zeiger->Next != NULL)
			zeiger=zeiger->Next;
		if((zeiger->Next = (calloc(1, sizeof(TMedia)))) == NULL)
		{
			fprintf(stderr,"Konnte keinen Speicherplatz fuer das letzte Element reservieren!\n");
			return;
		}
		//zeiger1 = zeiger;
		//zeiger = zeiger->Next;
		*zeiger = *eingabe;
		zeiger -> Next = NULL;
        zeiger -> Prev = Last;
        Last = zeiger;
        //Last = Last->Next = zeiger; //
	}
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
 ********************************************************** 
int cmpMediaTitleAsc(TMedia *t1, TMedia *t2)
{
	//vorsicht, adressoperator ????
	char *str1 = &(t1->title);
	char *str2 = &(t2->title);
	int i = 0;

	//work, as string1 and 2 are not at end
	while((*(str1 + i) != '\0' && (*str2 + i) != '\0'))
	{
		if(*(str1 + i) < *(str2 + i))
			return *(str1 + i) - *(str2 + i);
		else if(*(str1 + i) > *(str2 + i))
			return *(str1 + i) - *(str2 + i);
		i++;
	}
	return 0;
}
**********************************************************
 * FUNCTION:        cmpMediaTitleDesc 
 * --------------------------------------------------------
 * DESCRIPTION:     compares two mediatitles
 *
 *                  returns < 0, if t2 < t1 (eg b < a)
 *                  returns   0, if t2 = t1
 *                  returns > 0, if t2 > t1
 * STATUS:          
 **********************************************************
int cmpMediaTitle(TMedia *t1, TMedia *t2)
{
	//vorsicht, adressoperator ????
	char *str1 = &(t1->title);
	char *str2 = &(t2->title);
	int i = 0;

	//work, as string1 and 2 are not at end
	while(*(str1 + i) != '\0')
	{
		if(*(str2 + i) < *(str1 + i))
			return *(str2 + i) - *(str1 + i);
		else if(*(str2 + i) > *(str1 + i))
			return *(str2 + i) - *(str1 + i);
		i++;
	}
	return 0;
}

/**********************************************************
 * FUNCTION:        insertInList
 * --------------------------------------------------------
 * DESCRIPTION:     inserts new media into list
 *                  after comparing the mediatitle
 * STATUS:          
 **********************************************************/ 
    /*
	struct medien *zeiger,*zeiger1, *tmp;

    if(eingabe == NULL)
    {
        printf("\nÜbergebenes Element existiert nicht!\n");
        return 0;
    }
    eingabe->Next = eingabe->Prev = NULL;
    //Fall1: Liste ist leer
	if(First == NULL)
    {
        First = Last = eingabe;
		//appendInList(eingabe);
        return 1;
    }
	else
	{
		zeiger=First;
    //Fall2: Vor dem ersten Element einfügen
        if(strcmp(zeiger->title, eingabe->title) > 0)
        {
            zeiger = (TMedia *)(calloc(1, sizeof(TMedia)));
            *zeiger = *First;           //Werte von First nach zeiger kopieren
            zeiger->Next = First->Next; //zeiger->Next von First übernehmen
            *First = *eingabe;          //Werte von eingabe nach First kopieren
            First->Prev = NULL;         //Prev zeigt von First auf NULL
            First->Next = zeiger;       //Next von First auf neuen zeiger
            zeiger->Prev = First;       //Prev von zeiger auf First
            //falls First = Last
            if(First = Last)
            {
                Last = zeiger;
                Last->Next = NULL;
            }
            return 1;
        }
		while(zeiger->Next != NULL &&(strcmp(zeiger->title,eingabe->title)<=0))
			zeiger=zeiger->Next;
    //Fall3: Hinten anfügen
		if(zeiger == Last)
        {
             
            zeiger = (TMedia *)(calloc(1, sizeof(TMedia)));
            *zeiger = *Last;
            zeiger->Prev = Last->Prev;
            *Last = *eingabe;
            Last->Next = NULL;
            Last->Prev = zeiger;
            zeiger->Next = Last;
            return 1;
        }
     //Fall4: Dazwischen einfügen
        else
        {
            zeiger1=First;
            while((zeiger1->Next != zeiger)) // && (zeiger1 != zeiger))
                zeiger1=zeiger1->Next;
            zeiger=(TMedia *)(calloc(1, sizeof(TMedia)));
            if(NULL == zeiger)
            {
                fprintf(stderr, "Kein Speicher zum alloziieren verfuegbar!\n");
                return 0;
            }

            *zeiger = *eingabe;
            zeiger->Next=zeiger1->Next;
            zeiger->Prev=zeiger1;
            zeiger1->Next=zeiger;
            zeiger1->Next->Prev=zeiger;
            return 1;
        } 
    
	}
} 
/**********************************************************
* FUNCTION:        freeMe
* --------------------------------------------------------
* DESCRIPTION:     frees Memory according to deleted Data
* STATUS:          
**********************************************************/ 

/*
void freeMe(char *removeme)
{
	struct medien *zeiger, *zeiger1, *zeiger2;

	if(First != NULL)
	{
		if(strcmp(First->title,removeme) == 0)
		{
			zeiger=First->Next;
			if(zeiger == NULL)
			{
				free(First);
				First=NULL;
				Last=NULL;
				return;
			}
			zeiger->Prev=NULL;
			free(First);
			First=zeiger;
		}

		else if(strcmp(Last->title,removeme) == 0)
		{
			zeiger=Last->Prev;
			zeiger->Next=NULL;
			zeiger1=Last;
			Last=zeiger;
			free(zeiger1);
		}
		else
		{
			zeiger=First;
			while(zeiger->Next != NULL)
			{
				zeiger1 = zeiger->Next;
				if(strcmp(zeiger1->title,removeme) == 0)
				{
					zeiger->Next=zeiger1->Next;
					zeiger2=zeiger1->Next;
					zeiger2->Prev=zeiger;
					free(zeiger1);
					break;
				}
				zeiger=zeiger1;
			}
		}
	}
	else
		printf("Der zu loeschende Datensatz wurde nicht gefunden!\n"); 
}
*/
