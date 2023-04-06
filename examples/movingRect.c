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


    RND.RESOLUTION_X = 20;
    RND.RESOLUTION_Y = 20;
    CR_RENDER_ALOC(&RND);

    printf("Press -> a to move left\nPress -> d to move right\nPress -> w to move up\nPress -> s to move down\nPress -> x to exit\nPress -> enter (two times) to start\n");
    getchar();

    while (1)
    {
        char input = CR_Int2Char(CR_GetInput());
        system("clear");//on windows system("cls");

        if(input == 'w')
        {
            RCT.y -= 1;
        }
        if(input == 's')
        {
            RCT.y += 1;
        }
        if(input == 'a')
        {
            RCT.x -= 1;
        }
        if(input == 'd')
        {
            RCT.x += 1;
        }
        if(input == 'x')
        {
            break;
        }

        CR_RENDER_FILL_ALL(&RND,'#');
        for(int gc = 0; gc < RND.RESOLUTION_X * RND.RESOLUTION_Y;gc++)
        {
           RND.COLOR_INF[gc] = rand()% 6 + 2;
        }
        CR_Rect2Render(&RND,RCT);
        for(int i = 0;i < RND.RESOLUTION_X * RND.RESOLUTION_Y + 1;i++)
        {
            printf("COLOR_INF[%i] = %i;\n",i,RND.COLOR_INF[i]);
        }
        CR_RENDER_PRINT(RND);
    }
    return 0;
}