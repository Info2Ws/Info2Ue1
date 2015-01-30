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
/**********************************************************
 * FUNCTION:        insertInList
 * --------------------------------------------------------
 * DESCRIPTION:     inserts new media into list
 *                  after comparing the mediatitle
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

}
