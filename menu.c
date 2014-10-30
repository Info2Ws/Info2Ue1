#include<stdlib.h>
#include<stdio.h>
#include"menu.h"
#include"tools.h"

int getMenu(char *menutitle, char *menu[], int anz, int visibility)
{
	int i   = 0; //Zählervariable
    int choice = 0; //Auswahl des Benutzers

    do
	{	
		/*Ausgabe des Menütitels*/
		if(visibility)
		{
			clearScreen();      //system("clear");
			printf("%s\n", menutitle);
			printLine('=',24);
			printf("\n\n");
		}
		 
		/*Ausgabe der Menüpunkte*/
		for(i = 0; i < anz; i++)
		{
			printf("%s\n", menu[i]); //
		}

        /*Eingabeaufforderung*/
        printf("\nIhre Wahl: ");
        scanf("%i", &choice);
        clearBuffer();

        /*Fehlermeldung für falsche Eingabe*/
        if((choice > anz) || (1 > choice))
        {
			printf("Geben Sie eine Zahl zwischen 1 und 7 ein!");
			waitForEnter();
		}


    }while((choice > anz) || (1 > choice));

    return choice;
}
