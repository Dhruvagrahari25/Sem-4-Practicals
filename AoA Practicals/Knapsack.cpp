#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

void sortByRatio(vector<int>& weight, vector<int>& profit, vector<float>& ratio, int n){
  for(int i=0; i<n; i++){
    ratio.push_back(profit[i]/weight[i]);
  }
  for (size_t i = 0; i < n-1; i++) {
    for (size_t j = 0; j < n; j++) {
      if(ratio[j] < ratio[j+1]){
        swap(ratio[j],ratio[j+1]);

        swap(weight[j],weight[j+1]);

        swap(profit[j],profit[j+1]);
      }
    }
  }
}
void knapsack(vector<int>& weight,vector<int>& profit, int n, int maxCapacity){
  vector<float> ratio;
  sortByRatio(weight,profit,ratio,n);
  cout<<"Weights taken : \n";
  for(auto& w:weight){
    if(maxCapacity-w > 0) {
      cout<<w<<" ";
      maxCapacity-=w;
    }
    else break;
  }
  cout<<"\n";
}

int main(){
  system("cls");
  int n,maxCapacity;
  vector<int> weight;
  vector<int> profit;
  cout<<"Enter no of weights : ";
  cin>>n;
  cout<<"Enter max Capacity : ";
  cin>>maxCapacity;
  cout<<"Enter "<<n<<" weights and profits:\n";
  for (size_t i = 0; i < n; i++) {
    int temp;
    cin>>temp;
    weight.push_back(temp);
    cin>>temp;
    profit.push_back(temp);
  }
  knapsack(weight,profit,n,maxCapacity);
  return 0;
}
