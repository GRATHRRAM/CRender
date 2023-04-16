#include "CRender.c"
//for v50

int main(void)
{
    CR_RENDER rnd; rnd.RESOLUTION_X = 40; rnd.RESOLUTION_Y = 20;
    CR_RENDER_ALOC(&rnd);
    char *str = malloc(9);
    str = "!@#$%^&*";

    while (1)
    {
        CR_RENDER_FILL_ALL(&rnd,str[rand() % 8]);
        for(int i = 0;i < rnd.RESOLUTION_X * rnd.RESOLUTION_Y;i++)
        {
            CR_RENDER_SET_DIRECT_COLOR_OF_PIXEL(&rnd,i,rand() % 32);
        }
        system("clear");//on windows system("cls");
        CR_RENDER_PRINT(rnd);
        printf("To exit -> Type EOF for ex-> CTRL + C\nPress any key...\n");
        CR_GetInput();

    }
    return 0;
}