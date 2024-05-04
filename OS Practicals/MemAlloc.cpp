#include <stdio.h>
void bestFit(int blockSize[], int m, int processSize[], int n)
{
  int allocation[n], i, j;

  for (i = 0; i < n; i++) allocation[i] = -1;

  for (i = 0; i < n; i++)
  {
    int bestIdx = -1;
    for (j = 0; j < m; j++)
    {
      if (blockSize[j] >= processSize[i])
      {
        if (bestIdx == -1)
          bestIdx = j;
        else if (blockSize[bestIdx] > blockSize[j])
          bestIdx = j;
      }
    }
    if (bestIdx != -1)
    {
      allocation[i] = bestIdx;
      blockSize[bestIdx] -= processSize[i];
    }
  }
  printf("\nProcess No.\tProcess Size\tBlock no.\n");
  for (i = 0; i < n; i++)
  {
    printf("%d\t\t%d\t\t", i + 1, processSize[i]);
    if (allocation[i] != -1)
      printf("%d\n", allocation[i] + 1);
    else
      printf("Not Allocated\n");
  }
}
void firstFit(int blockSize[], int m, int processSize[], int n)
{
  int allocation[n], i, j;
  for (i = 0; i < n; i++) allocation[i] = -1;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      if (blockSize[j] >= processSize[i])
      {
        allocation[i] = j;
        blockSize[j] -= processSize[i];
        break;
      }
    }
  }
  printf("\nProcess No.\tProcess Size\tBlock no.\n");
  for (i = 0; i < n; i++)
  {
    printf("%d\t\t%d\t\t", i + 1, processSize[i]);
    if (allocation[i] != -1)
      printf("%d\n", allocation[i] + 1);
    else
      printf("Not Allocated\n");
  }
}
void worstFit(int blockSize[], int m, int processSize[], int n)
{
  int allocation[n], i, j;
  for (i = 0; i < n; i++)
    allocation[i] = -1;
  for (i = 0; i < n; i++)
  {
    int wstIdx = -1;
    for (j = 0; j < m; j++)
    {
      if (blockSize[j] >= processSize[i])
      {
        if (wstIdx == -1)
          wstIdx = j;
        else if (blockSize[wstIdx] < blockSize[j])
          wstIdx = j;
      }
    }
    if (wstIdx != -1)
    {
      allocation[i] = wstIdx;
      blockSize[wstIdx] -= processSize[i];
    }
  }
  printf("\nProcess No.\tProcess Size\tBlock no.\n");
  for (i = 0; i < n; i++)
  {
    printf("%d\t\t%d\t\t", i + 1, processSize[i]);
    if (allocation[i] != -1)
      printf("%d\n", allocation[i] + 1);
    else
      printf("Not Allocated\n");
  }
}
int main()
{
  int blockSize[] = {100, 500, 200, 300, 600};
  int processSize[] = {212, 417, 112, 426};
  int m = sizeof(blockSize) / sizeof(blockSize[0]);
  int n = sizeof(processSize) / sizeof(processSize[0]);

  printf("First Fit:\n");
  firstFit(blockSize, m, processSize, n);

  printf("\nBest Fit:\n");
  bestFit(blockSize, m, processSize, n);

  printf("\nWorst Fit:\n");
  worstFit(blockSize, m, processSize, n);

  return 0;
}
