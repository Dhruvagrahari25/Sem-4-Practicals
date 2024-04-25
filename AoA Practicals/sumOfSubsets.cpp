#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;
void displaySubset(vector<int>& SubSets){
  cout<<"{";
for (size_t i = 0; i < SubSets.size(); i++) {
    cout<<SubSets[i]<<" ";
  }
  cout<<"}\n";
}
void findSubsets(vector<int>& array, vector<int> SubSets, int target, int sum, int index) {
  if(sum>target || index>=array.size()) return;
  if(sum==target) {
    displaySubset(SubSets);
    return;
  }
  SubSets.push_back(array[index]);
  findSubsets(array,SubSets,target,sum+array[index],index+1);
  SubSets.pop_back();
  findSubsets(array,SubSets,target,sum,index+1);
}

int main(){
  vector<int> v;
  vector<int> SubSets;
  int n=0,target;
  cout << "Enter the no. of elements: ";
  cin >> n;
  cout << "Enter "<<n<<" elements"<< '\n';
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    v.push_back(temp);
  }
  sort(v.begin(),v.end());
  cout << "Enter target : ";
  cin >> target;
  findSubsets(v, SubSets, target, 0, 0);
  return 0;
}
