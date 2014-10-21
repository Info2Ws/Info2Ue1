#include "tools.h"
#include "stdlib.h"

/**********************************************************
 * HILFSFUNKTIONEN
 * ********************************************************
 */


/**********************************************************
 * FUNCTION:        clearBuffer
 * --------------------------------------------------------
 * DESCRIPTION:     clears keyboard's buffer, 
 *                  reads until '\n'
 */

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
 */

void waitForEnter()
{
    printf("\n\nPlease press ENTER to proceed...");
    clearBuffer();            //maybe wrong that way...
}

/**********************************************************
 * FUNCTION:        clearScreen 
 * --------------------------------------------------------
 * DESCRIPTION:     erases the actual screen
 */

void clearScreen()
{
    system("clear");          //unix only in the moment
}

/**********************************************************
 * FUNCTION:        printLine
 * --------------------------------------------------------
 * DESCRIPTION:     gets a char and an int and prints a
 *                  line with int chars
 */

void printLine(char c, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%c", c);
    }
}
