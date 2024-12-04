#include "stdio.h"
#include "./conio.h"
#include "string.h"

#define MAX_INT_SLOTS 8

#define NUMB_START 48
#define NUMB_END 57
#define ENTER_KEY 10
#define MINUS_KEY 45
#define BACKSPACE_KEY 127

int prompt_int(char *message)
{
    printf("%s", message);
    char buffer[MAX_INT_SLOTS];
    int index = 0;
    int done = 0;
    while (!done)
    {
        // printf("\n---\n%d %d %d\n---\n", index, index + 1, MAX_INT_SLOTS);
        int x = 0, y = 0;
        char hit = getch();
        switch (hit)
        {
        case NUMB_START ... NUMB_END:
            if (index < MAX_INT_SLOTS)
            {
                printf("%c", hit);
                buffer[index] = hit;
                index++;
            }
            break;
        case BACKSPACE_KEY:
            if (index > 0)
            {
                printf("\b ");
                wherexy(&x, &y);
                gotox(x - 1);
                buffer[index] = 0;
                index--;
                // system("sleep 0.0680");
            }
            break;
        case ENTER_KEY:
            return atoi(&buffer[0]);
            break;
            // case MINUS_KEY:
            //     if(index == 0){
            //         buffer[index] = '-';
            //         index++;
            //     }
        }
    }
}