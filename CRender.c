#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#define RESOLUTION_Y 5  //change this to change resolurion y
#define RESOLUTION_X 10 //change this to change resolurion x
#define CR_KEY_A 0


typedef char CR_RENDER[RESOLUTION_X + 1][RESOLUTION_Y + 1];

typedef struct CR_POINT
{
    int x;
    int y;
    char look;
} CR_POINT;



void CR_Fill_All(CR_RENDER RENDER,char FILL_WITH)
{
    for (int y = 0; y < RESOLUTION_Y; y++)
    {
        for (int x = 0; x < RESOLUTION_X; x++)
        {
            RENDER[x][y] = FILL_WITH;
        }
    }
}

void CR_Print_Render(CR_RENDER RENDER)
{
    for (int y = 0; y < RESOLUTION_Y; y++)
    {
        for (int x = 0; x < RESOLUTION_X; x++)
        {
            printf("%c",RENDER[x][y]);
        }
        printf("\n");
    }
}

void CR_Point2Render(CR_RENDER RENDER,CR_POINT POINT)
{
    RENDER[POINT.x][POINT.y] = POINT.look;
}

int CR_GetInput(void)
{
    int ch;
    struct termios oldt;
    struct termios newt;
  
    tcgetattr(STDIN_FILENO, &oldt); 
    newt = oldt; 
    newt.c_lflag &= ~(ICANON | ECHO); 
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

char CR_Int2Char(int INPUT)
{
    return (char) INPUT;
}