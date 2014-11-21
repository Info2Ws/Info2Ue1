
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include "datetime.h"

void getTime(char *Text, TTime *lp)
{



    char *strTime[9];
    char *pStd = NULL;
    char *pMin = NULL;
    char *pSek = NULL;
    char *pos = NULL;
    int Std,Min,Sek = 0;
    int c,count = 0;
    int len = 0;





do{
    printf("Bitte geben sie eine Tracklänge im Format HH:MM:SS ein:\n");
    fflush(stdin);
    scanf(" %8[123456789:]",stdin, &strTime);
}
    while(*strTime[0] == NULL || checkTime == '0');



    c = strTime[0];
    {
        len = strlen(strTime);
            while (c < len && c!= '\0') //zählt die Trennzeichen bis zum Ende des Strings
            {
                if (pos == c)
                    count++;
                pos++;
                c++;
            {

                if ((isdigit((strTime[0]) == '1')) && count == '2')
                {
                   pStd = strTime[0];
                   pMin = (strchr(strTime , ':')+1);
                   pSek = (strrchr(strTime, ':')+1);
                   Std= atoi(pStd);
                   Min = atoi(pMin);
                   Sek = atoi(pSek);
                   if((checkTime(Std, Min, Sek, lp)) == 1)
                   {
                   calloc(sizeof(TTime),1);
                   lp->hour = Std;
                   lp->minute = Min;
                   lp->second = Sek;
                   }
        }
           else if(isdigit((strTime) == '1') && count == '1')
        {
              pStd = NULL;
              pMin = strTime[0];
              pSek = ((strrchr(strTime, ':')+1));
              Std = NULL;
              Min = atoi(pMin);
              Sek = atoi(pSek);
              if(Min<60 && Sek<60)
              {
              calloc(sizeof(TTime),1);
              lp->hour   = Std;
              lp->minute = Min;
              lp->second = Sek;
              free(strTime);
              }

        }
        }
        }
    }}


int checkTime(int Std, int Min, int Sek,  TTime *lp)
{
if((lp->hour <24 ||lp->minute<60 || lp->second<60))
    return 1;
else
    return 0;
}

void printTime(TTime * lp)
{
    printf("%02i:%02i:%02i", lp->hour, lp->minute, lp->second);
}
