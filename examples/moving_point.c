#include "CRender.c"
//CRrender 0.20v
int main(void)
{
    CR_RENDER RND;
    CR_POINT PNT;
    PNT.look = '@';
    PNT.x = 2;
    PNT.y = 2;

    RND.RESOLUTION_X = 10;
    RND.RESOLUTION_Y = 5;
    CR_RENDER_ALOC(&RND);

    printf("Press -> a to move left\nPress -> d to move right\nPress -> w to move up\nPress -> s to move down\nPress -> x to exit\nPress -> enter (two times) to start\n");
    getchar();

    while (1)
    {
        char input = CR_Int2Char(CR_GetInput());
        system("clear");//on windows system("cls");

        if(input == 'w')
        {
            PNT.y -= 1;
        }
        if(input == 's')
        {
            PNT.y += 1;
        }
        if(input == 'a')
        {
            PNT.x -= 1;
        }
        if(input == 'd')
        {
            PNT.x += 1;
        }
        if(input == 'x')
        {
            break;
        }

        CR_RENDER_FILL_ALL(&RND,'#');
        CR_Point2Render(&RND,PNT);
        CR_RENDER_PRINT(RND);
    }
    return 0;
}