#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;
int partition(vector<int>& array, int low, int high){
  int pivot=low;
  int left = low;
  int right = high;

  while (left<right)
  {
    while (array[left]<=array[pivot] && left<high) left++;
    while (array[right]>array[pivot] && right>low) right--;
    if(left < right) swap(array[left],array[right]);
  }
  swap(array[pivot],array[right]);
  return right;
}
void QuickSort(vector<int>& array, int low, int high){
    if(high < low) return;

    int pivot = (low+(high-1)/2);

    int partitionIdx = partition(array,low,high);

    QuickSort(array,low,partitionIdx-1);
    QuickSort(array,partitionIdx+1,high);
}
int main(){
    system("cls");
    vector<int> array;
    int n=0;

    cout<<"Enter the no of elements : ";
    cin>>n;
    cout<<"Enter "<<n<<" Elements : ";

    for(int i=0; i<n; i++){
      int temp;
      cin>>temp;
      array.push_back(temp);
    }

    QuickSort(array,0,n-1);

    cout<<"Sorted Array : \n";

    for(auto i:array){
        cout<<i<<"\t";
    }

    return 0;
}
