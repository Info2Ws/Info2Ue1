#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


/**********************************************************
 * FUNCTION:        appendinList
 * --------------------------------------------------------
 * DESCRIPTION:     appends data into list
 *                  after userinput via stdin
 * STATUS:          
 **********************************************************/ 



<<<<<<< HEAD
int appendInList(THashElement *HashElement, TListElement *Neu)
{
   if (HashElement && Neu)                  
   {
      Neu->Next = NULL;

      if (HashElement->FirstList == NULL)       
      {
         HashElement->FirstList = HashElement->LastList = Neu;
         return 1;
      }

      HashElement->LastList->Next = Neu;        
      HashElement->LastListt = Neu;
      return 1;
   }
   return 0;
}


void sortListbyMediaTitle(TMedia *secondL, TMedia *lastL)
{
    int comparison; //will be used for strcmpresult
    int swap = 0;
    TMedia *data = NULL;
    TMedia *data2 = First;

    while(secondL!= NULL && lastL!=NULL) 
    {
        comparison = 2;
        comparison = strcmp(secondL->MediumTITEL,lastL->MediumTITEL); 
        if(comparison == 1)    //returns -1 for 1<2 0 for same value and guess what for 2>1/
        {
            secondL->Next = lastL->Next; 
            lastL->Next->Prev = secondL;

            secondL->Prev->Next = lastL; 
            lastL->Prev = secondL->Prev;
            lastL->Next = secondL;
            secondL->Prev = lastL;

            if(First == secondL && Last == lastL) 
                data = First;
                First = Last;
                Last = data;
            }
            else if(Last == lastL) 
            {
                Last = secondL;
            }

            secondL = secondL->Next; 
            lastL = lastL->Next;
            data = secondL;                  
            secondL = lastL;
            lastL = secondL;
            wurdeGetauscht = 1;
        }
        else                                        
        {
            secondL = secondL->Next;
            lastL = lastL->Next;
        }
    }
    if(swap==1)                           
        sortListbyMediatitle(data2,data2->Next);
}
=======
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
	if(First == NULL){
		if((First =(TMedia *)(calloc(1, sizeof(TMedia))))== NULL)
		{
			fprintf(stderr, "Konnte keinen Speicherplatz fuer das erste Element reservieren!\n");
			return ;
		}
		*First = *eingabe;		
		First -> Next = NULL;
		Last = First;
		Last -> Prev = NULL;
	}

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
		zeiger1 = zeiger;
		zeiger = zeiger->Next;
		*zeiger = *eingabe;
		zeiger -> Next = NULL;
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
*/
>>>>>>> origin/master
/**********************************************************
 * FUNCTION:        insertInList
 * --------------------------------------------------------
 * DESCRIPTION:     inserts new media into list
 *                  after comparing the mediatitle
<<<<<<< HEAD
 *		    Checks for:
 *		    List empty?
 *		    Insert as First
 *		    Insert as Last 	
 *		    Insert inbetween	
 * STATUS:          
 **********************************************************/ 
int insertInList(TMedia *Neu)
{
    TMedia *data = First;
    if (Neu == NULL)
        return 0;
    if (First == NULL)
    {
        
        Neu->Next = Neu->Prev = NULL;
        First = Last = Neu;
        return 1;
    }
    if (First->Index >= Neu->Index)
    {
        
        Neu->Next = First;
        Neu->Prev = NULL;
        First = First->Prev = Neu;
        return 1;
    }
    if (Last->Index <= Neu->Index)
    {
        
        Neu->Prev = Last;
        Neu->Next = NULL;
        Last = Last->Next = Neu;
        return 1;
    }
    
    while (data->Next != NULL)
    {
        if (data->Next->Index >= Neu->Index)
        {
            Neu->Next = data->Next;
            Neu->Prev = data;
            data->Next = data->Next->Prev = Neu;
            return 1;
        }
        data = data->Next;
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
 **********************************************************/ 
TMedia *removeFromList(int delIndex)
{
    TMedia *data = NULL, *prev = NULL;
    int i;
    
    if (First == NULL)
        return NULL;
    
    if (delIndex == 1)
    {
        data = First;
        First = First->Next;
        
        if (First == NULL)
            Last = NULL;
        else
            First->Prev = NULL;
        return data;
    }
   
    if (delIndex == MediaCounter)
    {
        data = Last;
        Last = Last->Prev;
        Last->Next = NULL;
        return data;
    }
    
    data = First;
    for(i=1; i<delIndex; i++)
    {
        data = data->Next;
    }
    if(data != NULL)
    {
        prev = data->Prev;
        prev->Next = data->Next;
        prev->Next->Prev = prev;
        return data;
    }

    printf("Der gewuenschte Titel konnte nicht entfernt werden");
    exit(0);
}

=======
 * STATUS:          
 **********************************************************/ 
int insertInList(TMedia *eingabe)
{
	struct medien *zeiger,*zeiger1;
/*	if(*(eingabe) == NULL)
	{

		return 0;
	} */
	if(First == NULL)
		appendInList(eingabe);
	else
	{
		zeiger=First;
		while(zeiger != NULL &&(strcmp(zeiger->title,eingabe->title)<=0))
			zeiger=zeiger->Next;
		if(zeiger==NULL)
			appendInList(eingabe);
			else if (zeiger == First)
			{
				First=(TMedia *)(calloc(1, sizeof(TMedia)));
				if(First == NULL)
				{
					fprintf(stderr,"Kein Speicher zum alloziieren verfuegbar!\n");
					return 0;
				}
				*First = *eingabe;
				First->Next=zeiger;
				First->Prev=NULL;
            }
				else
				{
					zeiger1=First;

					while(zeiger1->Next != zeiger)
						zeiger1=zeiger->Next;
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
				} 
			
	}
}
/**********************************************************
* FUNCTION:        freeMe
* --------------------------------------------------------
* DESCRIPTION:     frees Memory according to deleted Data
* STATUS:          
**********************************************************/ 


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
>>>>>>> origin/master
}
