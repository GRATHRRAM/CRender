//CRender 0.50v BY GRATHRRAM-SCRIPTGUY ON GNU GPL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#define CR_TO_PRINT_BLACK "\033[0;30m"              //1
#define CR_TO_PRINT_RED "\033[0;31m"                //2
#define CR_TO_PRINT_GREEN "\033[0;32m"              //3
#define CR_TO_PRINT_BROWN "\033[0;33m"              //4
#define CR_TO_PRINT_BLUE "\033[0;34m"               //5
#define CR_TO_PRINT_PURPLE "\033[0;35m"             //6
#define CR_TO_PRINT_CYAN "\033[0;36m"               //7
#define CR_TO_PRINT_WHITE "\033[0;38m"              //8
#define CR_TO_PRINT_BACK_BLACK "\033[0;40m"         //9
#define CR_TO_PRINT_BACK_RED "\033[0;41m"           //10
#define CR_TO_PRINT_BACK_GREEN "\033[0;42m"         //11
#define CR_TO_PRINT_BACK_BROWN "\033[0;43m"         //12
#define CR_TO_PRINT_BACK_BLUE "\033[0;44m"          //13
#define CR_TO_PRINT_BACK_PURPLE "\033[0;45m"        //14
#define CR_TO_PRINT_BACK_CYAN "\033[0;46m"          //15
#define CR_TO_PRINT_BACK_WHITE "\033[0;47m"         //16

#define CR_TO_PRINT_BLACK_BRIGHT "\033[0;90m"       //17
#define CR_TO_PRINT_RED_BRIGHT "\033[0;91m"         //18
#define CR_TO_PRINT_GREEN_BRIGHT "\033[0;92m"       //19
#define CR_TO_PRINT_YELLOW "\033[0;93m"             //20
#define CR_TO_PRINT_BLUE_BRIGHT "\033[0;94m"        //21
#define CR_TO_PRINT_PURPLE_BRIGHT "\033[0;95m"      //22
#define CR_TO_PRINT_CYAN_BRIGHT "\033[0;96m"        //23
#define CR_TO_PRINT_WHITE_BRIGHT "\033[0;97m"       //24
#define CR_TO_PRINT_BACK_BLACK_BRIGHT "\033[0;100m" //25
#define CR_TO_PRINT_BACK_RED_BRIGHT "\033[0;101m"   //26
#define CR_TO_PRINT_BACK_GREEN_BRIGHT "\033[0;102m" //27
#define CR_TO_PRINT_BACK_YELLOW "\033[0;103m"       //28
#define CR_TO_PRINT_BACK_BLUE_BRIGHT "\033[0;104m"  //28
#define CR_TO_PRINT_BACK_PURPLE_BRIGHT "\033[0;105m"//30
#define CR_TO_PRINT_BACK_CYAN_BRIGHT "\033[0;106m"  //31
#define CR_TO_PRINT_BACK_WHITE_BRIGHT "\033[0;107m" //32

#define CR_TO_PRINT_GRAY "\033[0;2m"                //33
#define CR_PRINT_NON "\033[0;0m"


#define CR_BLACK               1
#define CR_RED                 2
#define CR_GREEN               3
#define CR_BROWN               4
#define CR_BLUE                5
#define CR_PURPLE              6
#define CR_CYAN                7
#define CR_WHITE               8
#define CR_BACK_BLACK          9
#define CR_BACK_RED            10
#define CR_BACK_GREEN          11
#define CR_BACK_BROWN          12
#define CR_BACK_BLUE           13
#define CR_BACK_PURPLE         15
#define CR_BACK_CYAN           16
#define CR_BACK_WHITE          17
#define CR_BLACK_BRIGHT        18
#define CR_RED_BRIGHT          19
#define CR_GREEN_BRIGHT        20
#define CR_BROWN_BRIGHT        21
#define CR_BLUE_BRIGHT         22
#define CR_PURPLE_BRIGHT       23
#define CR_CYAN_BRIGHT         24
#define CR_WHITE_BRIGHT        25
#define CR_BACK_BLACK_BRIGHT   26
#define CR_BACK_RED_BRIGHT     27
#define CR_BACK_GREEN_BRIGHT   28
#define CR_BACK_BROWN_BRIGHT   29
#define CR_BACK_BLUE_BRIGHT    30
#define CR_BACK_PURPLE_BRIGHT  31
#define CR_BACK_CYAN_BRIGHT    32
#define CR_BACK_WHITE_BRIGHT   33

//dodaj miganie debilu


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
    int color;
    char look;
} CR_POINT;

typedef struct CR_RECT
{
    int x;
    int y;
    int width;
    int height;
    int color;
    char look;
} CR_RECT;

typedef struct CR_CRECT
{
    int x;
    int y;
    int width;
    int height;
    int color;
} CR_CRECT;


typedef struct CR_TEXT
{
    int x;
    int y;
    int width;
    int height;
    int color;
    char *text;
} CR_TEXT;


/*
typedef struct CR_CIRCLE
{
    int x;
    int y;
    int radius;
    char look;
} CR_CIRCLE;
*/

//typedef 
void CR_RENDER_ALOC(CR_RENDER *RENDER)
{
    RENDER->RND = malloc(RENDER->RESOLUTION_X * RENDER->RESOLUTION_Y);
    RENDER->COLOR_INF = (int*) malloc(sizeof(int) * RENDER->RESOLUTION_X * RENDER->RESOLUTION_Y);
}

void CR_RENDER_REALOC(CR_RENDER *RENDER)
{
    RENDER->RND = realloc(RENDER->RND,RENDER->RESOLUTION_X * RENDER->RESOLUTION_Y);
    RENDER->COLOR_INF = (int*) realloc(RENDER->COLOR_INF,sizeof(int) * RENDER->RESOLUTION_X * RENDER->RESOLUTION_Y);
}

void CR_TEXT_SET(CR_TEXT *TEXT,char *SET_TO)
{
    TEXT->text = malloc(strlen(SET_TO) + 1);
    TEXT->text = SET_TO;
}

void CR_TEXT_RESET(CR_TEXT *TEXT,char *SET_TO)
{
    TEXT->text = realloc(TEXT->text,strlen(SET_TO) + 1);
    TEXT->text = SET_TO;
}


//ALLOC/REALLOC
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
            if(RENDER.COLOR_INF[gc] == 1) printf(CR_TO_PRINT_BLACK);
            else if(RENDER.COLOR_INF[gc] == 2) printf(CR_TO_PRINT_RED);
            else if(RENDER.COLOR_INF[gc] == 3) printf(CR_TO_PRINT_GREEN);
            else if(RENDER.COLOR_INF[gc] == 4) printf(CR_TO_PRINT_BROWN);
            else if(RENDER.COLOR_INF[gc] == 5) printf(CR_TO_PRINT_BLUE);
            else if(RENDER.COLOR_INF[gc] == 6) printf(CR_TO_PRINT_PURPLE);
            else if(RENDER.COLOR_INF[gc] == 7) printf(CR_TO_PRINT_CYAN);
            else if(RENDER.COLOR_INF[gc] == 8) printf(CR_TO_PRINT_BACK_WHITE);
            else if(RENDER.COLOR_INF[gc] == 9) printf(CR_TO_PRINT_BACK_BLACK);
            else if(RENDER.COLOR_INF[gc] == 10) printf(CR_TO_PRINT_BACK_RED);
            else if(RENDER.COLOR_INF[gc] == 11) printf(CR_TO_PRINT_BACK_GREEN);
            else if(RENDER.COLOR_INF[gc] == 12) printf(CR_TO_PRINT_BACK_BROWN);
            else if(RENDER.COLOR_INF[gc] == 13) printf(CR_TO_PRINT_BACK_BLUE);
            else if(RENDER.COLOR_INF[gc] == 14) printf(CR_TO_PRINT_BACK_PURPLE);
            else if(RENDER.COLOR_INF[gc] == 15) printf(CR_TO_PRINT_BACK_CYAN);
            else if(RENDER.COLOR_INF[gc] == 16) printf(CR_TO_PRINT_WHITE_BRIGHT);
            else if(RENDER.COLOR_INF[gc] == 17) printf(CR_TO_PRINT_BLACK_BRIGHT);
            else if(RENDER.COLOR_INF[gc] == 18) printf(CR_TO_PRINT_RED_BRIGHT);
            else if(RENDER.COLOR_INF[gc] == 19) printf(CR_TO_PRINT_GREEN_BRIGHT);
            else if(RENDER.COLOR_INF[gc] == 20) printf(CR_TO_PRINT_YELLOW);
            else if(RENDER.COLOR_INF[gc] == 21) printf(CR_TO_PRINT_BLUE_BRIGHT);
            else if(RENDER.COLOR_INF[gc] == 22) printf(CR_TO_PRINT_PURPLE_BRIGHT);
            else if(RENDER.COLOR_INF[gc] == 23) printf(CR_TO_PRINT_CYAN_BRIGHT);
            else if(RENDER.COLOR_INF[gc] == 24) printf(CR_TO_PRINT_BACK_WHITE_BRIGHT);
            else if(RENDER.COLOR_INF[gc] == 25) printf(CR_TO_PRINT_BACK_BLACK_BRIGHT);
            else if(RENDER.COLOR_INF[gc] == 26) printf(CR_TO_PRINT_BACK_RED_BRIGHT);
            else if(RENDER.COLOR_INF[gc] == 27) printf(CR_TO_PRINT_BACK_GREEN_BRIGHT);
            else if(RENDER.COLOR_INF[gc] == 28) printf(CR_TO_PRINT_BACK_YELLOW);
            else if(RENDER.COLOR_INF[gc] == 29) printf(CR_TO_PRINT_BACK_BLUE_BRIGHT);
            else if(RENDER.COLOR_INF[gc] == 30) printf(CR_TO_PRINT_BACK_PURPLE_BRIGHT);
            else if(RENDER.COLOR_INF[gc] == 31) printf(CR_TO_PRINT_BACK_CYAN_BRIGHT);
            else if(RENDER.COLOR_INF[gc] == 32) printf(CR_TO_PRINT_GRAY);
            else printf(CR_TO_PRINT_WHITE);
            printf("%c",RENDER.RND[gc]);
            printf(CR_PRINT_NON);
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

void CR_RENDER_SET_DIRECT_COLOR_OF_PIXEL(CR_RENDER *RENDER,int POSITION,int COLOR)
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


//render
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
                if(!POINT.color) RENDER->COLOR_INF[gc] = POINT.color;
                else RENDER->COLOR_INF[gc] = CR_WHITE;
            }
            gc++;
        }
    }
}

/*
void CR_Circle2Render(CR_RENDER *RENDER,CR_CIRCLE CIRCLE)
{
    //printf("CR_Circle2Render not working yet...\n");
    if(CIRCLE.radius == 1)
    {
        CR_RENDER_SET_PIXEL(RENDER,CIRCLE.x,CIRCLE.y,CIRCLE.look);
        return;
    }
    if(CIRCLE.radius < 1)
    {                                                          
        return;
    }

    int CurentRadius = 0;

    for(int Y = CIRCLE.y - CIRCLE.radius; Y < CIRCLE.y + CIRCLE.radius;Y++)
    {
        for(int x = CIRCLE.x;x < CurentRadius + CIRCLE.x;x++)
        {
            CR_RENDER_SET_PIXEL(RENDER,x,Y,CIRCLE.look);
        }
        CurentRadius++;
        if (CurentRadius > CIRCLE.radius)
        {
            CurentRadius = 0;
            break;
        }
        
    }
    for(int Y = CIRCLE.y + CIRCLE.radius; Y > CIRCLE.y;Y--)
    {
        for(int x = CIRCLE.x;x < CurentRadius + CIRCLE.x;x++)
        {
            CR_RENDER_SET_PIXEL(RENDER,x,Y,CIRCLE.look);
        }
        CurentRadius++;
        if (CurentRadius > CIRCLE.radius)
        {
            CurentRadius = CIRCLE.radius;
            break;
        }
        
    }
    //up is right
    //down is left
    for(int Y = CIRCLE.y - CIRCLE.radius; Y < CIRCLE.y + CIRCLE.radius;Y++)
    {
        for(int x = CIRCLE.x;x < CurentRadius;x++)
        {
            CR_RENDER_SET_PIXEL(RENDER,CIRCLE.x - CurentRadius,Y,CIRCLE.look);
        }
        CurentRadius++;
        if (CurentRadius > CIRCLE.radius)
        {
            CurentRadius = 0;
            break;
        }
        
    }
}
*/

void CR_Rect2Render(CR_RENDER *RENDER,CR_RECT RECT)
{
    for(int y = 0;y < RECT.height;y++)
    {
        for(int cw = 0;cw < RECT.width;cw++)
        {
            CR_RENDER_SET_PIXEL(RENDER,RECT.x + cw,RECT.y + y,RECT.look);
        }
    }
   
    for(int h = RECT.y;h < RECT.height + RECT.y;h++)
    {
        for(int w = RECT.x;w < RECT.width + RECT.x;w++)
        {
            int gc = 0;
            for(int y = 0;y < RENDER->RESOLUTION_Y; y++)
            {   
                for(int x = 0;x < RENDER->RESOLUTION_X; x++)
                {
                    if(x == w && y == h)
                    {
                        RENDER->COLOR_INF[gc] = RECT.color;
                    }
                    gc++;
                }
            }   
        }
    }
        
    
}


//undef2render
char *CR_RENDER_SAVE_CHAR_GLOBAL(CR_RENDER RENDER,char *PATH,char *NAME)
{
    char *FLO = malloc(strlen(PATH) + strlen(NAME) + 1);
    strcat(FLO,PATH);strcat(FLO,NAME);
    FILE *FL; FL = fopen(FLO,"w"); free(FLO);
    if(!FL) return "CANT OPEN FILE!";

    fprintf(FL,"%i\n%i\n",RENDER.RESOLUTION_X,RENDER.RESOLUTION_Y);
    int gc = 0;
    for(int y = 0;y < RENDER.RESOLUTION_Y;y++)
    {
        for(int x = 0;x < RENDER.RESOLUTION_X;x++)
        {
            fprintf(FL,"%c\n",RENDER.RND[gc]);
            gc++;
        }
    }
    fclose(FL);
}

char *CR_RENDER_SAVE_CHAR_LOCAL(CR_RENDER RENDER,char *NAME)
{
    FILE *FL; FL = fopen(NAME,"w");
    if(!FL) return "CANT OPEN FILE!";

    fprintf(FL,"%i\n%i\n",RENDER.RESOLUTION_X,RENDER.RESOLUTION_Y);
    int gc = 0;
    for(int y = 0;y < RENDER.RESOLUTION_Y;y++)
    {
        for(int x = 0;x < RENDER.RESOLUTION_X;x++)
        {
            fprintf(FL,"%c\n",RENDER.RND[gc]);
            gc++;
        }
    }
    fclose(FL);
}

char *CR_RENDER_LOAD_CHAR_GLOBAL_ALLOC(CR_RENDER *RENDER,char *PATH,char *NAME)
{
    char *FLO = malloc(strlen(PATH) + strlen(NAME) + 1);
    strcat(FLO,PATH);strcat(FLO,NAME);
    FILE *FL; FL = fopen(FLO,"r"); free(FLO);
    if(!FL) return "CANT OPEN FILE!";
    
    fscanf(FL,"%i",&RENDER->RESOLUTION_X);
    fscanf(FL,"%i",&RENDER->RESOLUTION_Y);

    RENDER->RND = malloc(RENDER->RESOLUTION_X * RENDER->RESOLUTION_Y);
    RENDER->COLOR_INF = (int*) malloc(sizeof(int) * RENDER->RESOLUTION_X * RENDER->RESOLUTION_Y);

    int gc = 0;char *buff = malloc(2);
    for(int y = 0; y < RENDER->RESOLUTION_Y;y++)
    {
        for(int x = 0;x < RENDER->RESOLUTION_X;x++)
        {
            fscanf(FL,"%s",buff);
            RENDER->RND[gc] = buff[0];
            gc++;
        }
    }

    free(buff);

    fclose(FL);
    return "ALL DONE!";
}

char *CR_RENDER_LOAD_CHAR_GLOBAL_REALLOC(CR_RENDER *RENDER,char *PATH,char *NAME)
{
    char *FLO = malloc(strlen(PATH) + strlen(NAME) + 1);
    strcat(FLO,PATH);strcat(FLO,NAME);
    FILE *FL; FL = fopen(FLO,"r"); free(FLO);
    if(!FL) return "CANT OPEN FILE!";
    
    fscanf(FL,"%i",&RENDER->RESOLUTION_X);
    fscanf(FL,"%i",&RENDER->RESOLUTION_Y);

    RENDER->RND = realloc(RENDER->RND,RENDER->RESOLUTION_X * RENDER->RESOLUTION_Y);
    RENDER->COLOR_INF = (int*) realloc(RENDER->COLOR_INF,sizeof(int) * RENDER->RESOLUTION_X * RENDER->RESOLUTION_Y);


    int gc = 0;char *buff = malloc(2);
    for(int y = 0; y < RENDER->RESOLUTION_Y;y++)
    {
        for(int x = 0;x < RENDER->RESOLUTION_X;x++)
        {
            fscanf(FL,"%s",buff);
            RENDER->RND[gc] = buff[0];
            gc++;
        }
    }

    free(buff);

    fclose(FL);
    return "ALL DONE!";
}

char *CR_RENDER_LOAD_CHAR_LOCAL_ALLOC(CR_RENDER *RENDER,char *NAME)
{
    FILE *FL; FL = fopen(NAME,"r");
    if(!FL) return "CANT OPEN FILE!";
    

    fscanf(FL,"%i",&RENDER->RESOLUTION_X);
    fscanf(FL,"%i",&RENDER->RESOLUTION_Y);

    RENDER->RND = malloc(RENDER->RESOLUTION_X * RENDER->RESOLUTION_Y);
    RENDER->COLOR_INF = (int*) malloc(sizeof(int) * RENDER->RESOLUTION_X * RENDER->RESOLUTION_Y);

    int gc = 0;char *buff = malloc(2);
    for(int y = 0; y < RENDER->RESOLUTION_Y;y++)
    {
        for(int x = 0;x < RENDER->RESOLUTION_X;x++)
        {
            fscanf(FL,"%s",buff);
            RENDER->RND[gc] = buff[0];
            gc++;
        }
    }

    free(buff);
    fclose(FL);
    return "ALL DONE!";
}

char *CR_RENDER_LOAD_CHAR_LOCAL_REALLOC(CR_RENDER *RENDER,char *NAME)
{
    FILE *FL; FL = fopen(NAME,"r");
    if(!FL) return "CANT OPEN FILE!";
    

    fscanf(FL,"%i",&RENDER->RESOLUTION_X);
    fscanf(FL,"%i",&RENDER->RESOLUTION_Y);

    RENDER->RND = realloc(RENDER->RND,RENDER->RESOLUTION_X * RENDER->RESOLUTION_Y);
    RENDER->COLOR_INF = (int*) realloc(RENDER->COLOR_INF,sizeof(int) * RENDER->RESOLUTION_X * RENDER->RESOLUTION_Y);

    int gc = 0;char *buff = malloc(2);
    for(int y = 0; y < RENDER->RESOLUTION_Y;y++)
    {
        for(int x = 0;x < RENDER->RESOLUTION_X;x++)
        {
            fscanf(FL,"%s",buff);
            RENDER->RND[gc] = buff[0];
            gc++;
        }
    }

    free(buff);
    fclose(FL);
    return "ALL DONE!";
}


//save/load
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
//input
