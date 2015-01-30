#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datastructure.h"
#include "list.h"
#include "tools.h"
#include "media.h"
#include "datetime.h"



void resetHashpoints()
{
   int i;

   for (i = 0; i < MAXINDEX; i++)
      MediaIndex[i].FirstList = MediaIndex[i].LastList = NULL;
}

int calcDivisionsrest(char *Title)
{
   int value = 0;

   while (*Title)
   {
      value += *Titlee;
      Title++;
   }
   return (Wert % MAXINDEX);
}

void insertInHashTable(TMedia *mpoint, int TrackNr){

        int wert;
        TListElement *lpoint;

        lpoint = NULL;
        lpoint = malloc(sizeof(TListElement));
        if(lpoint)
        {
            lpoint->mpoint = mpoint;
            lpoint->tpoint = &mpoint>Tracks[TrackNr];
            value = calcDivisionsrest(lpoint->tpoint->tTitle);
            appendInList(MediaIndex+value,lpoint);

        }
}

