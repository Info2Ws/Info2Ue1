	

    #include"time.h"
    #include"datastructure.h"
    #include<stdlib.h>
    #include<stdio.h>
    #include<string.h>
    #include"tools.h"
     
    void printTime(TTime * Zeit);
    void getTime(char *Text, TTime *Zeit);
    void splitstring (TTime *Zeit, char c, char ***arr);
    int checkTime (TTime * Zeit , int legit, char *strTime);
     
     
    void getTime(char *Text, TTime *Zeit)
    {
    char strtime[9];
    int checkZeit = 0;
    int checkZeit2 = 0;
    do
    {
        printf("Bitte geben sie die Laenge des Titels im Format HH:MM:SS ein:\n");
     
        Zeit->hour = NULL;
        Zeit->minute = NULL;
        Zeit->second = NULL;
     
        scanf("%9s", &strTime);
        clearBuffer();
     
     
        checkZeit2 = checkTime(Zeit, 1, strTime);
     
        convertString(strTime, Zeit);
     
        if(!checkZeit2)
        {
            printf("Falsche Eingabe! Format (hh:mm:ss oder mm:ss)\n Fortfahren mit Enter");
            clearBuffer();
        }
     
        //Kontrollieren ob zeit gültige integer werte
        checkZeit = checkTime(Zeit, 0 , strTime);
     
    //        Fehlermeldung
        if(!checkZeit)
        {
            printf("Falsche Eingabe! Format (hh:mm:ss oder mm:ss)\n Fortfahren mit Enter");
            clearBuffer();
        }
     
    }
    while(checkZeit != checkZeit2 );
     
     
    }
     
     
    void splitstring (TTime *Zeit, char c, char ***arr) //zerlegt den string anhand von Doppelpunkten
    {
        int count = 1; //anzahl der Doppelpunkte
        int token_len = 1; //Länge des betrachteten Tokens
        int i,j,k = 0;
        char *pos; //cursorposition als pointer
        char *t;   //position des tokens
        char c = ':'; //Trennzeichen
        char **arr[3];
     
        pos = lp;
     
        {
            while (*pos != '\0') //zählt die Trennzeichen bis zum Ende des Strings
            {
                if (*pos == c)
                    count++;
                pos++;
            }
            if(count < 3)
            {
                *arr = (char**) malloc(sizeof(char*) * count);  //dynamische speicherreservierung für Die  Segmente (zählen der Doppelpunkte)
                if (*arr == NULL)
                    exit 1;
                {
                    if (*pos == c)
                    {
                        (*arr)[i] = (char*) malloc( sizeof(char) * token_len );  //ermittlung der Tokenlängen
                        if ((*arr)[i] == NULL)
                            exit 1;
     
                        token_len = 0;
                        i++;
                    }
                    pos++;
                    token_len++;
                }
                (*arr)[i] = (char*) malloc( sizeof(char) * token_len );
                if ((*arr)[i] == NULL)
                    exit 1;
     
                i = 0;
                pos = str;
                t = ((*arr)[i]);
                <<<
                while (*pos != '\0')  //kopieren der Token in arr[i] bis zum nächsten Trennzeichen
                {
                    if (*pos != c && *p != '\0') //falls pointer noch kein Trennzeichen erreicht hat und der String nicht beendet ist
                    {
                        *t = *pos
                             t++;
                    }
                    else
                    {
                        *t = '\0';
                        i++;
                        t = ((*arr)[i]);
                    }
                    p++;
                }
                if(count == 1)
                {
                    strhour   = NULL;
                    strminute = *arr[0];
                    strsecond = *arr[1];
                }
                else
                {
                    strhour = *arr[0]:
                    strminute = *arr[1];
                    strsecond = *arr[2];
                }
                if(strhour)
                    Zeit->hour = atoi(strhour);
                if(strminute)
                    Zeit->minute = atoi(strminute)
                    Zeit->second = atoi(strseconds)
     
     
                }
        }
     
        int checkTime (TTime * Zeit , int legit, char *strTime)
        {
            //Laufvariable
            int k = 0;
     
            //Kontrolle der Integerwerte
            if(legit == 0)
            {
     
                if((Zeit->second > 60)||(Zeit->minute > 60 )||(Zeit->hour >24))
                    return 0;
                else
                    return 1;
            }
     
            //Kontrolle der string eingabe
            if(legit == 1)
            {
     
                while(*(strTime + k)
            {
                if(((*(strTime + k) < '0') || (*(strTime + k) > '9' )) && (*(strTime + k) != ':'))
                    {
     
                        return 0;
     
                    }
     
                    k++;
                }
     
                return 1;
            }
     
     
        }
     
     
        void printTime(TTime * Zeit)
        {
            printf("%02i:%02i:%02i", Zeit->hour, Zeit->minute, Zeit->second);
        }

