#ifndef _TOOLS_
#define _TOOLS_
#include <stdio.h>
#include <stdlib.h>
//#include <media.h>
#include <string.h>

/** Funktions-Prototypen **/
void clearBuffer();
void waitForEnter();
void clearScreen();
void printLine(char c, int n);
int askAgain();
int getText(char *prompt, int plength, int allowempty, char **input);


#endif
