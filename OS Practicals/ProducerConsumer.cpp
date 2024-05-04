#include <stdio.h>
#include <stdlib.h>
int full = 0;
int empty = 10;
int x = 0;
int mutex = 1;
void producer()
{
    mutex--;
    full++;
    empty--;
    x++;
    printf("PRODUCER PRODUCES THE ITEM %d \n", x);
    mutex++;
}
void consumer()
{
    mutex--;
    full--;
    empty++;
    printf("CONSUMER CONSUMES THE ITEM %d \n", x);
    x--;
    mutex++;
}
int main()
{
    int n;
    while (1)
    {
        printf("1. PRESS \"1\" FOR PRODUCER\n");
        printf("2. PRESS \"2\" FOR CONSUMER\n");
        printf("3. PRESS \"3\" FOR EXIT\n");
        printf("ENTER THE CHOICE: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            if (mutex == 1 && empty != 0)
            {
                producer();
            }
            else
            {
                printf("BUFFER IS FULL\n");
            }
            break;
        case 2:
            if (mutex == 1 && full != 0)
            {
                consumer();
            }
            else
            {
                printf("BUFFER IS EMPTY\n");
            }
            break;
        case 3:
            printf("\nAditya Dikonda\nS12\n24\n");
            exit(0);
        }
    }
    return 0;
}