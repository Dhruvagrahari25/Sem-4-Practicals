#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int BinarySearch(vector<int> arr,int n, int x){
    if (x>arr[n-1] || x<arr[0])
    {
        return -1;
    }
    
    int l,m,r;
    l=0;
    r=n-1;
    while(l<=r)
    {
        m=l+(r-1)/2;
        if (arr[m]==x){
            return m;
        }else if (arr[m]>x){
            r=m-1;
        }else if (arr[m]<x){
            l=m+1;
        }
        
    }
    return -1;
    
}
int main(){
    system("cls");
    vector<int> arr;
    int n=0;
    cout<<"Enter the No. of elements : ";
    cin>>n;
    cout<<"Enter a sorted list : ";
    int temp;
    for(int i=0; i<n; i++){
        cin>>temp;
        arr.push_back(temp);
    }
    sort(arr.begin(),arr.end());
    cout<<"Enter the element to be searched : ";
    cin>>temp;
    int index=BinarySearch(arr,n,temp);
    if (index==-1)
    {
        cout<<"Element not found in given array!\n";
    }
    else
    {
        cout<<temp<<" found at index : "<<index;
    }
        
    return 0;
}