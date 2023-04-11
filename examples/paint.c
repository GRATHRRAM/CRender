#include "CRender.c"
//CRrender 0.35v
int main(void)
{
    CR_RENDER RND;
    CR_RECT RCT;
    RCT.look = '@';
    RCT.x = 2;
    RCT.y = 2;
    RCT.height = 3;
    RCT.width = 2;


    RND.RESOLUTION_X = 40;
    RND.RESOLUTION_Y = 20;
    CR_RENDER_ALOC(&RND);
    CR_RENDER_FILL_ALL_COLOR(&RND,CR_WHITE);

    printf("Press -> a to move left\nPress -> d to move right\nPress -> w to move up\n");
    printf("Press -> s to move down\nPress -> x to exit\nPress -> 1-8 to chage color\n");
    printf("Press -> jkli to chage with and haight of rect\nPress -> f to clear to white\nPress -> enter (two times) to start\n");
    CR_GetInput();

    while (1)
    {
        char input = CR_GetInput();
        system("clear");//on windows system("cls");

        if(CR_Int2Char(input) == 'w')
        {
            RCT.y -= 1;
        }
        if(CR_Int2Char(input) == 's')
        {
            RCT.y += 1;
        }
        if(CR_Int2Char(input) == 'a')
        {
            RCT.x -= 1;
        }
        if(CR_Int2Char(input) == 'd')
        {
            RCT.x += 1;
        }
        if(CR_Int2Char(input) == 'x')
        {
            break;
        }
        if(CR_Int2Char(input) == '1')
        {
            RCT.color = 1;
        }
        if(CR_Int2Char(input) == '2')
        {
            RCT.color = 2;
        }
        if(CR_Int2Char(input) == '3')
        {
           RCT.color = 3;
        }
        if(CR_Int2Char(input) == '4')
        {
           RCT.color = 4;
        }
        if(CR_Int2Char(input) == '5')
        {
            RCT.color = 5;
        }
        if(CR_Int2Char(input) == '6')
        {
            RCT.color = 6;
        }
        if(CR_Int2Char(input) == '7')
        {
            RCT.color = 7;
        }
        if(CR_Int2Char(input) == '8')
        {
            RCT.color = 8;
        }
        if(CR_Int2Char(input) == 'j')//l
        {
            RCT.width -= 1;
            if(RCT.width < 1) RCT.width = 1;
        }
        if(CR_Int2Char(input) == 'i')//up
        {
            RCT.height += 1;
        }
        if(CR_Int2Char(input) == 'l')//r
        {
            RCT.width += 1;
        }
        if(CR_Int2Char(input) == 'k')//dwn
        {
            RCT.height -=1;
            if(RCT.height < 1) RCT.height = 1;
        }
        if(CR_Int2Char(input) == 'f')
        {
            CR_RENDER_FILL_ALL_COLOR(&RND,CR_WHITE);
        }

        CR_RENDER_FILL_ALL(&RND,'#');
        CR_Rect2Render(&RND,RCT);
        CR_RENDER_PRINT(RND);
    }
    return 0;
}