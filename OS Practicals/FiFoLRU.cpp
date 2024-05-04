#include <stdio.h>
#define MAX 30
void display(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void fifo(int pages[], int n, int capacity)
{
    int frame[MAX], i, j, k, flag = 0, count = 0;
    for (i = 0; i < capacity; i++)
        frame[i] = -1;
    j = 0;
    printf("\nReference string|\tPage Frames\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t|\t", pages[i]);
        for (k = 0; k < capacity; k++)
            if (frame[k] == pages[i])
                flag = 1;
        if (flag == 0)
        {
            frame[j] = pages[i];
            j = (j + 1) % capacity;
            count++;
            display(frame, capacity);
        }
        else
        {
            flag = 0;
            display(frame, capacity);
        }
    }
    printf("\nNumber of page faults = %d\n", count);
}
int findLRU(int time[], int n)
{
    int i, minimum = time[0], pos = 0;
    for (i = 1; i < n; ++i)
    {
        if (time[i] < minimum)
        {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}
void lru(int pages[], int n, int capacity)
{
    int frame[MAX], age[MAX] = {0}, i, k, flag = 0, count = 0, least;
    for (i = 0; i < capacity; i++)
        frame[i] = -1;
    printf("\nReference string|\tPage Frames\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t|\t", pages[i]);
        for (k = 0; k < capacity; k++)
            if (frame[k] == pages[i])
            {
                flag = 1;
                age[k] = i + 1;
            }
        if (flag == 0)
        {
            least = findLRU(age, capacity);
            age[least] = i + 1;
            frame[least] = pages[i];
            count++;
            display(frame, capacity);
        }
        else
        {
            flag = 0;
            display(frame, capacity);
        }
    }
    printf("\nNumber of page faults = %d\n", count);
}
int main()
{
    int pages[MAX], np, nf, i;
    printf("Enter the number of pages: ");
    scanf("%d", &np);
    printf("Enter the reference string values:\n");
    for (i = 0; i < np; i++)
        scanf("%d", &pages[i]);
    printf("Enter the number of frames: ");
    scanf("%d", &nf);
    fifo(pages, np, nf);
    lru(pages, np, nf);
    return 0;
}