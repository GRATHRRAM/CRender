#include "CRender.c"
#define LINE_START_X 10
#define LINE_START_Y 10
//on CRender 0.25v

int main(void)
{
    CR_RENDER RND;
    RND.RESOLUTION_X = 20;
    RND.RESOLUTION_Y = 20;
    CR_RENDER_ALOC(&RND);

    int LINE_POSITION[2] = {11,11};


    printf("Press -> a to move left\nPress -> d to move right\nPress -> w to move up\nPress -> s to move down\nPress -> x to exit\nPress -> Any key to start\n");
    CR_GetInput();

    while (1)
    {
        char input = CR_Int2Char(CR_GetInput());
        system("clear");//on windows system("cls");

        
        if(input == 'w')
        {
            LINE_POSITION[1] -= 1;
        }
        if(input == 's')
        {
            LINE_POSITION[1] += 1;
        }
        if(input == 'a')
        {
            LINE_POSITION[0] -= 1;
        }
        if(input == 'd')
        {
            LINE_POSITION[0] += 1;
        }
        if(input == 'x')
        {
            break;
        }
        
        CR_RENDER_FILL_ALL(&RND,'#');
        CR_RENDER_DRAW_LINE(&RND,LINE_START_X,LINE_START_Y,LINE_POSITION[0],LINE_POSITION[1],'$');
        CR_RENDER_PRINT(RND);
    }
    
}