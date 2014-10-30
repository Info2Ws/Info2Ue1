#include "tools.h"
#include "stdlib.h"

/**********************************************************
 **********************************************************
 * MODULE: tools
 * --------------------------------------------------------
 * DESCRIPTION: auxillary functions
 **********************************************************
 **********************************************************/

/**********************************************************
 * FUNCTION:        clearBuffer
 * --------------------------------------------------------
 * DESCRIPTION:     clears keyboard's buffer, 
 *                  reads until '\n'
 **********************************************************/
void clearBuffer()
{
    char dummy;

    do
    {
        scanf("%c", &dummy);
    }while(dummy != '\n');
}

/**********************************************************
 * FUNCTION:        waitForEnter 
 * --------------------------------------------------------
 * DESCRIPTION:     prints a prompt to press '/n'
 **********************************************************/
void waitForEnter()
{
    printf("\n\nPlease press ENTER to proceed...");
    clearBuffer();            //maybe wrong that way... <- it's ok that way
}

/**********************************************************
 * FUNCTION:        clearScreen 
 * --------------------------------------------------------
 * DESCRIPTION:     erases the actual screen
 **********************************************************/
void clearScreen()
{
    system("clear");          //unix only at the moment
}

/**********************************************************
 * FUNCTION:        printLine
 * --------------------------------------------------------
 * DESCRIPTION:     gets a char and an int number and 
 *                  prints a line with number * chars
 **********************************************************/
void printLine(char c, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%c", c);       //should it produce an '\n' at the end??
    }
}
