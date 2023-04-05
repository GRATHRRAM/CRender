//CRender 0.20v BY GRATHRRAM-SCRIPTGUY ON GNU GPL
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

//void CR_RENDER_DRAW_LINE(CR_RENDER *RENDER,int FROM_X,int FROM_Y,int TO_X,int TO_Y,char WITH)
//{
//    int setin[FROM_X - TO_X + FROM_Y - FROM_Y][2];    IGNORE!!!!!!!
//}

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