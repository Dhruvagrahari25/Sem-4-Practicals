#include <iostream>
#include<vector>

using namespace std;

int minOfArr(vector<int>& list, int i, int n){
    int temp=list[i];
    int index=i;
    for(int j=i; j<n; j++){
        if(list[j]<temp){
            temp=list[j];
            index=j;
        }
    }
    return index;
}
void SelectionSort(vector<int>& list, int n){
    for(int i=0; i<n; i++){
        swap(list[minOfArr(list,i,n)],list[i]);
    }
}
int main(){
    system("cls");
    vector<int> list;
    int n=0;

    cout<<"Enter the length of list : ";
    cin>>n;
    cout<<"Enter the elements : ";
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        list.push_back(temp);
    }
    SelectionSort(list,n);
    cout<<"Sorted List : \n";
    for(int i=0; i<n; i++){
        cout<<list[i]<<"\t";
    }

    return 0;
}