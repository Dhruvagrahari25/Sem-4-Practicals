#include <stdio.h>
#include <stdlib.h>
#define MAX 20
void sort(int queue[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (queue[i] > queue[j])
            {
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }
}
void fcfs(int head, int queue[], int n)
{
    int i, seek_count = 0;
    for (i = 0; i < n; i++)
    {
        seek_count += abs(head - queue[i]);
        head = queue[i];
    }
    printf("Total number of seek operations = %d\n", seek_count);
}
void scan(int head, int queue[], int n)
{
    int i, seek_count = 0, distance, cur_track;
    sort(queue, n);
    for (i = 0; i < n; i++)
    {
        cur_track = queue[i];
        distance = abs(cur_track - head);
        seek_count += distance;
        head = cur_track;
    }
    printf("Total number of seek operations = %d\n", seek_count);
}
void cscan(int head, int queue[], int n)
{
    int i, seek_count = 0, distance, cur_track, max = 200;
    sort(queue, n);
    seek_count = abs(head - 0);
    seek_count += abs(max - queue[0]);
    printf("Total number of seek operations = %d\n", seek_count);
}
int main()
{
    int queue[MAX], n, i, head;
    printf("Enter the number of disk locations: ");
    scanf("%d", &n);
    printf("Enter the disk locations to read: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &queue[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    printf("\nFCFS Disk Scheduling:\n");
    fcfs(head, queue, n);
    printf("\nSCAN Disk Scheduling:\n");
    scan(head, queue, n);
    printf("\nC-SCAN Disk Scheduling:\n");
    cscan(head, queue, n);
    return 0;
}