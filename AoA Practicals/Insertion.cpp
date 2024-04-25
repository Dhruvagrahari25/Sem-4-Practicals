#include<iostream>
#include<vector>
using namespace std;

void InserstionSort(vector<int>& list, int n){
    for(int i=1; i<n; i++){
        int temp=list[i];
        int j=i-1;
        while(j >= 0 && list[j] > temp){
            list[j+1] = list[j];
            j--;
        }
        list[j+1] = temp;
    }
}
int main(){
    system("cls");
    vector<int> list;
    int n=0;
    cout<<"Enter an size of array : ";
    cin>>n;
    cout<<"Enter an array of integers : ";
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        list.push_back(temp);
    }
    InserstionSort(list,n);
    cout<<"Elements of array after sorting : \n";
    for(int i=0; i<n; i++){
        cout<<list[i]<<"\t";
    }
    return 0;
}