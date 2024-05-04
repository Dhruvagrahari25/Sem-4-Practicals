#include <stdio.h>
int main()
{
  int p, c, count = 0, i, j, alc[5][3], max[5][3], need[5][3], safe[5], available[3], finish[5], terminate = 0;
  printf("Enter the number of processes and resources: ");
  scanf("%d %d", &p, &c);
  printf("Enter allocation of resources for all processes (%d x %d matrix):\n", p, c);
  for (i = 0; i < p; i++)
  {
    for (j = 0; j < c; j++)
    {
      scanf("%d", &alc[i][j]);
    }
  }
  printf("Enter the maximum resources required by each process (%d x %d matrix):\n", p, c);
  for (i = 0; i < p; i++)
  {
    for (j = 0; j < c; j++)
    {
      scanf("%d", &max[i][j]);
    }
  }
  printf("Enter the available resources: ");
  for (i = 0; i < c; i++)
  {
    scanf("%d", &available[i]);
  }
  printf("\nNeed resources matrix:\n");
  for (i = 0; i < p; i++)
  {
    for (j = 0; j < c; j++)
    {
      need[i][j] = max[i][j] - alc[i][j];
      printf("%d\t", need[i][j]);
    }
    printf("\n");
  }
  for (i = 0; i < p; i++)
  {
    finish[i] = 0;
  }
  while (count < p)
  {
    for (i = 0; i < p; i++)
    {
      if (finish[i] == 0)
      {
        for (j = 0; j < c; j++)
        {
          if (need[i][j] > available[j]){
            break;
          }
        }
        if (j == c)
        {
          safe[count] = i;
          finish[i] = 1;
          for (j = 0; j < c; j++)
          {
            available[j] += alc[i][j];
          }
          count++;
          terminate = 0;
        }
        else
        {
          terminate++;
        }
      }
    }
    if (terminate == (p - 1))
    {
      printf("Safe sequence does not exist\n");
      break;
    }
  }
  if (terminate != (p - 1))
  {
    printf("\nAvailable resources after completion:\n");
    for (i = 0; i < c; i++)
    {
      printf("%d\t", available[i]);
    }
    printf("\nSafe sequence:\n");
    for (i = 0; i < p; i++)
    {
      printf("p%d\t", safe[i]);
    }
    printf("\n");
  }
  return 0;
}
