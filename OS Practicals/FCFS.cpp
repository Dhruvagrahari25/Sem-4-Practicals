#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int at;
  int bt;
  int pid;
} Process;

int compare(const void *a, const void *b){
  Process *pa = (Process *)a;
  Process *pb = (Process *)b;
  return (pa->at - pb->at);
}

int main(){
  int n;
  printf("Enter Number of processes: ");
  scanf("%d", &n);
  Process at_bt[n];
  int i;
  printf("Enter arrival time, burst time and process id:\n");

  for (i = 0; i < n; i++){
    scanf("%d %d %d", &at_bt[i].at, &at_bt[i].bt, &at_bt[i].pid);
  }
  qsort(at_bt, n, sizeof(Process), compare);
  int ct[n];
  int tat[n];
  int wt[n];
  double total_tat = 0;
  double total_wt = 0;
  int count = at_bt[0].at;

  for (i = 0; i < n; i++){
    if (at_bt[i].at <= count){
      count += at_bt[i].bt;
      ct[i] = count;
      tat[i] = ct[i] - at_bt[i].at;
      total_tat += tat[i];
      wt[i] = tat[i] - at_bt[i].bt;
      total_wt += wt[i];
    }
    else{
      count++;
      i--;
    }
  }
  printf("\n%-5s%-5s%-5s%-5s%-5s%-5s\n", "PID", "AT", "BT", "CT", "TAT", "WT");
  for (i = 0; i < n; i++){
    printf("%-5d%-5d%-5d%-5d%-5d%-5d\n", at_bt[i].pid, at_bt[i].at,at_bt[i].bt, ct[i], tat[i], wt[i]);
  }
  printf("Avg WT : %.2f\n", (total_wt / n));
  printf("Avg TAT : %.2f\n", (total_tat / n));
  return 0;
}
