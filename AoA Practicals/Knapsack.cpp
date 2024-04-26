#include <iostream>
using namespace std;
void knapsack(int n, int W, int p[], int wt[])
{
    int val[n + 1][W + 1];
    for (int i = 0; i <= n; i++){
      for (int w = 0; w <= W; w++){
        if (i == 0 || w == 0){
          val[i][w] = 0;
        }
        else if (wt[i - 1] <= w){
          val[i][w] = max(val[i - 1][w], (val[i - 1][w - wt[i - 1]] + p[i - 1]));
        }
        else{
          val[i][w] = val[i - 1][w];
        }
      }
    }
    int solution[n];
    int profit = val[n][W];
    for (int i = n; i > 0; i--){
      int j = 0;
      while (val[i][j] != profit){
          j++;
      }
      if (val[i][j] == val[i - 1][j]){
          solution[i - 1] = 0;
      }
      else{
          solution[i - 1] = 1;
      }
      profit = profit - p[i - 1];
  }
  cout << "Solution : " << endl;
  for (int i = 0; i < n; i++){
    cout << "W" << i + 1 << "\t";
  }
  cout << endl;
  for (int i = 0; i < n; i++){
    cout << solution[i] << " \t";
  }
  cout << "\n"<< "Max Profit = " << val[n][W];
}
int main()
{
    int n = 4;
    int p[] = {6, 60, 100, 120};
    int wt[] = {5, 10, 20, 30};
    int W = 45;
    knapsack(n, W, p, wt);
    return 0;
}
