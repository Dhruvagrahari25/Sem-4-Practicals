#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;
void QuickSort(vector<int>& array, int low, int high){
    if(high<=low) return;

    int pivot = array[high/2];

    int left = low;
    int right = high;

    while (left<right)
    {
        while (array[left]<=pivot && left<right) left++;
        while (array[right]>=pivot && left<right) right--;
        swap(array[left],array[right]);
    }
    swap(array[left],array[high]);

    QuickSort(array,low,left-1);
    QuickSort(array,left+1,high);
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