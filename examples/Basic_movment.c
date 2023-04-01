#include "CRender.c"
//resolution any

int main(void)
{
    CR_RENDER rnd;
    CR_POINT pnt;
    char cc = '\0';
    pnt.look = '@';pnt.x = 2;pnt.y = 2;
    
    printf("Press -> a to move left\nPress -> d to move right\nPress -> w to move up\nPress -> s to move down\nPress -> x to exit\nPress -> enter (two times) to start\n");
    getchar();

    while (1)
    {
        cc = CR_Int2Char(CR_GetInput());
        system("clear"); // if windows -> system("cls");
        if(cc == 's')
        {
            pnt.y++;//if player y > res_y or y < res_y its going to y = 0 i dont know why?
        }
        else if(cc == 'w')
        {
            pnt.y--;
        }
        else if(cc == 'a')
        {
            pnt.x--;
        }
        else if(cc == 'd')
        {
            pnt.x++;
        }
        else if(cc == 'x')
        {
            break;
        }
        CR_Fill_All(rnd,'#');
        CR_Point2Render(rnd,pnt);
        CR_Print_Render(rnd);
    }

    return 0;
}
