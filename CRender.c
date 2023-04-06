//CRender 0.25v BY GRATHRRAM-SCRIPTGUY ON GNU GPL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#define CR_BLACK "\033[0;30m" //1
#define CR_RED "\033[0;31m"   //2
#define CR_GREEN "\033[0;32m" //3
#define CR_YELOW "\033[0;33m" //4
#define CR_BLUE "\033[0;34m"  //5
#define CR_PURPLE "\033[0;35m"//6
#define CR_CYAN "\033[0;36m"  //7
#define CR_WITHE "\033[0;37m" //8
//#define NULL ((void *)0)


typedef struct CR_RENDER
{
    int RESOLUTION_Y;
    int RESOLUTION_X;
    int *COLOR_INF;
    char *RND;
} CR_RENDER;

typedef struct CR_POINT
{
    int x;
    int y;
    char look;
} CR_POINT;

typedef struct CR_RECT
{
    int x;
    int y;
    int width;
    int height;
    char look;
} CR_RECT;


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
    RENDER->COLOR_INF = malloc(RENDER->RESOLUTION_X * RENDER->RESOLUTION_Y);
}

void CR_RENDER_REALOC(CR_RENDER *RENDER)
{
    RENDER->RND = realloc(RENDER->RND,RENDER->RESOLUTION_X * RENDER->RESOLUTION_Y);
    RENDER->COLOR_INF = realloc(RENDER->RND,RENDER->RESOLUTION_X * RENDER->RESOLUTION_Y);
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

void CR_RENDER_FILL_ALL_COLOR(CR_RENDER *RENDER,int COLOR)
{
    int gc = 0;
    for(int y = 0;y < RENDER->RESOLUTION_Y; y++)
    {
        for(int x = 0;x < RENDER->RESOLUTION_X; x++)
        {
            RENDER->COLOR_INF[gc] = COLOR;
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
            if(RENDER.COLOR_INF[gc] == 1)
            {
                printf(CR_BLACK);
            }
            else if(RENDER.COLOR_INF[gc] == 2)
            {
                printf(CR_RED);
            }
            else if(RENDER.COLOR_INF[gc] == 3)
            {
                printf(CR_GREEN);
            }
            else if(RENDER.COLOR_INF[gc] == 4)
            {
                printf(CR_YELOW);
            }
            else if(RENDER.COLOR_INF[gc] == 5)
            {
                printf(CR_BLUE);
            }
            else if(RENDER.COLOR_INF[gc] == 6)
            {
                printf(CR_PURPLE);
            }
            else if(RENDER.COLOR_INF[gc] == 7)
            {
                printf(CR_CYAN);
            }
            else if(RENDER.COLOR_INF[gc] == 8)
            {
                printf(CR_WITHE);
            }
            else
            {
                printf(CR_WITHE);
            }
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

void CR_RENDER_SET_COLOR_OF_PIXEL(CR_RENDER *RENDER,int X,int Y,int COLOR)
{
    int gc = 0;
    for(int y = 0;y < RENDER->RESOLUTION_Y; y++)
    {
        for(int x = 0;x < RENDER->RESOLUTION_X; x++)\
        {
            if(x == X && y == Y)
            {
                RENDER->COLOR_INF[gc] = COLOR;
            }
            gc++;
        }
    }
}

void CR_RENDER_SET_DIRECT_COLOR_of_PIXEL(CR_RENDER *RENDER,int POSITION,int COLOR)
{
    RENDER->COLOR_INF[POSITION] = COLOR;
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

void CR_Circle2Render(CR_RENDER *RENDER,CR_CIRCLE CIRCLE)
{
    printf("CR_Circle2Render not working yet...");
    if(CIRCLE.radius == 1)
    {
        CR_RENDER_SET_PIXEL(RENDER,CIRCLE.x,CIRCLE.y,CIRCLE.look);
        return;
    }
    if(CIRCLE.radius < 1)
    {                                                          
        return;
    }

    for(int cout = -1;cout < CIRCLE.radius;cout++)
    {
        CR_RENDER_SET_PIXEL(RENDER,CIRCLE.x,CIRCLE.y + cout,CIRCLE.look);
        for(int X_TO_FILL = CIRCLE.x;X_TO_FILL < CIRCLE.radius + CIRCLE.x;X_TO_FILL++)
        {
            CR_RENDER_SET_PIXEL(RENDER,X_TO_FILL,cout + CIRCLE.y,CIRCLE.look);
        }
    }
    for(int cout = 1 - CIRCLE.radius;cout < CIRCLE.radius;cout++)
    {
        CR_RENDER_SET_PIXEL(RENDER,CIRCLE.x,CIRCLE.y + cout,CIRCLE.look);
    }   
}

void CR_Rect2Render(CR_RENDER *RENDER,CR_RECT RECT)
{
    for(int y = 0;y < RECT.height;y++)
    {
        for(int cw = 0;cw < RECT.width;cw++)
        {
            CR_RENDER_SET_PIXEL(RENDER,RECT.x + cw,RECT.y + y,RECT.look);
        }
    }
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