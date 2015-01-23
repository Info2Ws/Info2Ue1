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



void appendInList(TMedia *eingabe)
{
	struct medien *zeiger, *zeiger1; //Zeiger auf einzelne Elemente der Struktur

	if(Last == NULL)
	{
		if((Last=(TMedia *)(calloc(1, sizeof(TMedia))== NULL)
		{
			printf("Kauf dir mal mehr RAM!!\n")
			return;
		}
	}
	if(First == NULL){
		if((First =(struct medien *) malloc(sizeof(struct medien)))== bNULL)
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
		while(zeiger->next != NULL)
			zeiger=zeiger->next;
		if((zeiger->next = malloc(sizeof(struct medien))) == NULL)
		{
			fprintf(stderr,"Konnte keinen Speicherplatz fuer das letzte Element reservieren!\n");
			return;
		}
		zeiger1 = zeiger;
		zeiger = zeiger->Next;
		*zeiger = *eingabe
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
 **********************************************************/ 
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

/**********************************************************
 * FUNCTION:        cmpMediaTitleDesc 
 * --------------------------------------------------------
 * DESCRIPTION:     compares two mediatitles
 *
 *                  returns < 0, if t2 < t1 (eg b < a)
 *                  returns   0, if t2 = t1
 *                  returns > 0, if t2 > t1
 * STATUS:          
 **********************************************************/
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
int insertInList(TMedia *eingabe)
{
	struct medien *zeiger,*zeiger1;
	if(*eingabe == NULL)
	{

		return 0;
	}
	if(First == NULL)
		appendInList(eingabe);
	else
	{
		zeiger=First;
		while(zeiger != NULL &&(strcmp(zeiger->title,Neu->title)<0))
			zeiger=zeiger->Next;
		if(zeiger==NULL)
			appendInList(eingabe)
			else if (zeiger == First)
			{
				First=(TMedia *)(calloc(1, sizeof(TMedia));
				if(NULL == First)
				{
					fprintf(stderr,"Kein Speicher zum alloziieren verfuegbar!\n");
					return 0;
				}
				First->title=t;
				First->interpret=i;
				First->Next=zeiger;
				First->Prev=NULL;
				else
				{
					zeiger1=First;

					while(zeiger1->Next != zeiger)
						zeiger1=zeiger1->Next;
					zeiger=(TMedia *)(calloc(1, sizeof(TMedia));
					if(NULL == zeiger)
					{
						fprintf(stderr, "Kein Speicher zum alloziieren verfuegbar!\n");
						return;
					}

					zeiger->title=t;
					zeiger->interpret=i;;
					zeiger->Next=zeiger1->Next;
					zeiger->Prev=zeiger1;
					zeiger1->Next=zeiger;
					zeiger1->Next->Prev=zeiger;
				} 
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
}
