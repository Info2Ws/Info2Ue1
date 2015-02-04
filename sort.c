#include "sort.h"

/**********************************************************
 **********************************************************
 * MODULE: sort 
 * --------------------------------------------------------
 * DESCRIPTION: contains functions for sorting 
 * FUNCTIONS:   kuhsort
 *              ksort
 *              partition
 *              cmpTracknr
 *              cmpTitle
 *              cmpInterpret
 *              cmpDuration
 **********************************************************
 **********************************************************/

/**********************************************************
 * FUNCTION:        kuhsort 
 * --------------------------------------------------------
 * DESCRIPTION:     uses cmp-functions and partition
 *                  to sort data like qsort
 *                  calls the cmp-funcs from an function
 *                  pointer array
 *                  will automatically go through all media
 *                  and tracks
 * PARAMETER:       data  - data to sort
 *                  count - number of fields
 *                  type  - which sorting action, chooses
 *                          the cmp function:
 *                          0 -> tracknumber
 *                          1 -> title
 *                          2 -> interpret
 *                          3 -> duration
 * STATUS:          WIP
 **********************************************************/ 
 int (*cmp[4])(TTrack *, TTrack *);     //function pointer array

 void kuhsort(int type)
 {
     TMedia *actual_medium = First; //will point on actual medium
     //fill array with compare functions
     cmp[0] = cmpTracknr;
     cmp[1] = cmpTitle;
     cmp[2] = cmpInterpret;
     cmp[3] = cmpDuration;

     //sort and jump to next medium in List as long as there is an element
     while(actual_medium != NULL)
     {
         printf("\nTrack des Mediums %s sortieren ... ", actual_medium->title);
         //sort actual medium, with [type] comparing function, from 0 to Mediums Totalnumber
         ksort((actual_medium->Tracks), cmp[type], 0, ((actual_medium->Totalnumber) - 1)); 
         printf("ok");
         actual_medium = actual_medium->Next;       //actual medium is next medium
     }  
 }

/**********************************************************
 * FUNCTION:        ksort 
 * --------------------------------------------------------
 * DESCRIPTION:     uses partition to set a border in the 
 *                  middle an then recalls itself to do
 *                  the same for the left and right part
 *                  of the border
 * STATUS:          WIP
 **********************************************************/ 
 void ksort(TTrack *data, int (*cmp)(TTrack *, TTrack*), int ui, int oi)
 {
    int idx;

    if(ui >= oi)
        return;
    else
    {
        idx = partition(data, *cmp, ui, oi);
        ksort(data, *cmp, ui, idx - 1); //sort left part
        ksort(data, *cmp, idx + 1, oi); //sort right part
    }
 }
/**********************************************************
 * FUNCTION:        partition 
 * --------------------------------------------------------
 * DESCRIPTION:     makes data ready to sort
 *                  splits the data in two parts that
 *                  all the values on the left side are
 *                  smaller
 *                  used for kuhsort
 * PARAMETER:       data - data to sort
 *                  cmp  - compare function to use
 *                  ui   - lower index
 *                  oi   - upper index
 * RETURN:          index of the border (int)
 * STATUS:          WIP
 **********************************************************/ 
 int partition(TTrack *data, int (*cmp)(TTrack *, TTrack *), int ui, int oi)
 {
     int i = ui, j = oi;
     TTrack temp = {0};
     //border is first element at beginning
     TTrack *border = data + ui;

     while(i <= j)
     {
         //search next element bigger than border
         while((i <= j) && ((cmp(data + i, border)) <= 0))
             i++;
         //search next element smaller than border
         while((j >= i) && ((cmp(data + j, border)) > 0))
             j--;
         //if the indices havent met
         if(i < j)
         {
             temp = *(data + i);
             *(data + i) = *(data + j);
             *(data + j) = temp;
             i++; j--;
         }
     }
     i--;
     //put the border between both parts
     temp = *(data + ui);
     *(data + ui) = *(data + i);
     *(data + i) = temp;

     return i;
 }

/**********************************************************
 * FUNCTION:        cmpTracknr 
 * --------------------------------------------------------
 * DESCRIPTION:     compares two tracks depending on the
 *                  Tracknumber
 *                  returns < 0, if t1 < t2
 *                  returns   0, if t1 = t2
 *                  returns > 0, if t1 > t2
 * STATUS:          WIP
 **********************************************************/ 
int cmpTracknr(TTrack *t1, TTrack *t2)
{
    return (t1->Tracknr) - (t2->Tracknr);
}

/**********************************************************
 * FUNCTION:        cmpTitle 
 * --------------------------------------------------------
 * DESCRIPTION:     compares two track titles
 *                  returns < 0, if t1 < t2 (eg a < b)
 *                  returns   0, if t1 = t2
 *                  returns > 0, if t1 > t2
 * STATUS:          WIP, upper and lower case are different
 *                  at the moment
 **********************************************************/ 
int cmpTitle(TTrack *t1, TTrack *t2)
{
    //get chars only
    char *str1 = (t1->title);
    char *str2 = (t2->title);
    int i = 0;

    //read and compare chars, as string1 and 2 are not at end
    while((*(str1 + i) != '\0' && (*(str2 + i)) != '\0'))
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
 * FUNCTION:        cmpInterpret 
 * --------------------------------------------------------
 * DESCRIPTION:     compares two track interprets 
 *                  returns < 0, if t1 < t2
 *                  returns   0, if t1 = t2
 *                  returns > 0, if t1 > t2
 * STATUS:          WIP, same as function above
 **********************************************************/ 
int cmpInterpret(TTrack *t1, TTrack *t2)
{

    //get chars only
    char *str1 = (t1->interpret);
    char *str2 = (t2->interpret);
    int i = 0;

    //if adress of both interprets is NULL return 0
    if((str1 == '\0') && (str2 == '\0'))
    {
        return 0;
    }
    //if adress of one is NULL: change value of that str to \0
    if(str1 == NULL)
        *str1 = '\0';
    if(str2 == NULL)
        *str2 = '\0';

    //read and compare chars, as string1 and 2 are not at end
    while((*(str1 + i) != '\0' && (*(str2 + i)) != '\0'))
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
 * FUNCTION:        cmpDuration
 * --------------------------------------------------------
 * DESCRIPTION:     compares duration between tracks
 *                  returns < 0, if t1 < t2
 *                  returns   0, if t1 = t2
 *                  returns > 0, if t1 > t2
 * STATUS:          WIP
 **********************************************************/ 
int cmpDuration(TTrack *t1, TTrack *t2)
{
    //make pointer on time structures
    //adressop???
    TTime *lp1 = &(t1->lp);
    TTime *lp2 = &(t2->lp);

    //sum up hour minutes and seconds in a long number
    long duration1 = ((lp1->hour) * 60 * 60) + ((lp1->minute) * 60) + (lp1->second);
    long duration2 = ((lp2->hour) * 60 * 60) + ((lp2->minute) * 60) + (lp2->second);
    
    //cast value back to int before return
    return (int)(duration1 - duration2);
}
