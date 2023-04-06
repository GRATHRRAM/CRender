//CRender 0.25v BY GRATHRRAM-SCRIPTGUY ON GNU GPL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
//#define NULL ((void *)0)


typedef struct CR_RENDER
{
    int RESOLUTION_Y;
    int RESOLUTION_X;
    char *RND;
} CR_RENDER;

typedef struct CR_POINT
{
    int x;
    int y;
    char look;
} CR_POINT;

typedef struct CR_CIRCLE
{
    int x;
    int y;
    int radius;
    char look;
} CR_CIRCLE;


void CR_RENDER_ALOC(CR_RENDER *RENDER)
{
    RENDER->RND = malloc(RENDER->RESOLUTION_X * RENDER->RESOLUTION_Y);
}

void CR_RENDER_REALOC(CR_RENDER *RENDER)
{
    RENDER->RND = realloc(RENDER->RND,RENDER->RESOLUTION_X * RENDER->RESOLUTION_Y);
}

void CR_RENDER_FILL_ALL(CR_RENDER *RENDER,char FILL_WITH)
{
    int gc = 0;
    for(int y = 0;y < RENDER->RESOLUTION_Y; y++)
    {
        for(int x = 0;x < RENDER->RESOLUTION_X; x++)
        {
            RENDER->RND[gc] = FILL_WITH;
            gc++;
        }
    }
}

void CR_RENDER_PRINT(CR_RENDER RENDER)
{
    int gc = 0;
    for(int y = 0;y < RENDER.RESOLUTION_Y; y++)
    {
        for(int x = 0;x < RENDER.RESOLUTION_X; x++)
        {
            printf("%c",RENDER.RND[gc]);
            gc++;
        }
        printf("\n");
    }
}

void CR_RENDER_SET_PIXEL(CR_RENDER *RENDER,int X,int Y,char SET_WITH)
{
    int gc = 0;
    for(int y = 0;y < RENDER->RESOLUTION_Y; y++)
    {
        for(int x = 0;x < RENDER->RESOLUTION_X; x++)
        {
            if(x == X && y == Y)
            {
                RENDER->RND[gc] = SET_WITH;
            }
            gc++;
        }
    }
}

void CR_RENDER_SET_DIRECT_PIXEL(CR_RENDER *RENDER,int POSITION,char SET_WITH)
{
    RENDER->RND[POSITION] = SET_WITH;
}


void CR_RENDER_DRAW_LINE(CR_RENDER *RENDER,int FROM_X,int FROM_Y,int TO_X,int TO_Y,char WITH)
{
    int CURENTPOSITON[2] = {FROM_X,FROM_Y};
    while(1)
    {
        CR_RENDER_SET_PIXEL(RENDER,CURENTPOSITON[0],CURENTPOSITON[1],WITH);
        if(CURENTPOSITON[0] < TO_X) CURENTPOSITON[0]++;
        if(CURENTPOSITON[0] > TO_X) CURENTPOSITON[0]--;
        if(CURENTPOSITON[1] < TO_Y) CURENTPOSITON[1]++;
        if(CURENTPOSITON[1] > TO_Y) CURENTPOSITON[1]--;
        if(CURENTPOSITON[0] == TO_X && CURENTPOSITON[1] == TO_Y) break;
        //printf("CX -> %i CY -> %i\n",CURENTPOSITON[0],CURENTPOSITON[1]); debug staff
    }
}

void CR_Point2Render(CR_RENDER *RENDER,CR_POINT POINT)
{
    int gc = 0;
    for(int y = 0;y < RENDER->RESOLUTION_Y; y++)
    {
        for(int x = 0;x < RENDER->RESOLUTION_X; x++)
        {
            if(x == POINT.x && y == POINT.y)
            {
                RENDER->RND[gc] = POINT.look;
            }
            gc++;
        }
    }
}

/*
void CR_Circle2Render(CR_RENDER *RENDER,CR_CIRCLE CIRCLE)
{
    if(CIRCLE.radius == 1)
    {
        CR_RENDER_SET_PIXEL(RENDER,CIRCLE.x,CIRCLE.y,CIRCLE.look);
        return;
    }
    if(CIRCLE.radius < 1)
    {                                                               IGNORE
        return;
    }

    for(int line = CIRCLE.radius;line < CIRCLE.radius - CIRCLE.radius;line--)
    {
        CR_RENDER_SET_PIXEL(RENDER,CIRCLE.x,line,CIRCLE.look);
    }
    
}
*/

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