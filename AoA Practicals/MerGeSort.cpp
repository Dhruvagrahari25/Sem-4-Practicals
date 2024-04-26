#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void merge(vector<int>& array, vector<int>& leftarray, vector<int>& rightarray, int leftsize, int rightsize){
	int n=leftsize+rightsize;
	int l=0;
	int r=0;
	int k=0;
	while(r<rightsize && l<leftsize){
		if(rightarray[r]<=leftarray[l]) {
			array[k]=rightarray[r];
			r++;
		}
		else {
			array[k]=leftarray[l];
			l++;
		}
		k++;
	}
	while(r<rightsize){
		array[k]=rightarray[r];
		r++;
		k++;
	}
	while(l<leftsize){
		array[k]=leftarray[l];
		l++;
		k++;
	}
}


void mergeSort(vector<int>& arr, int n){
	if(n<2) return;
	int mid=n/2;

	vector<int> leftarray;
	vector<int> rightarray;

	for(int i=0; i<mid; i++){
		leftarray.push_back(arr[i]);
	}
	for(int i=mid; i<n; i++){
		rightarray.push_back(arr[i]);
	}
	mergeSort(leftarray,mid);
	mergeSort(rightarray,n-mid);

	merge(arr, leftarray, rightarray,n-mid, mid);
}

int main(){
	int n;
	vector<int> arr;
	cout << "Enter the size of list: ";
	cin>>n;
	cout<<"Enter "<<n<<" elements: \n";
	for(int i=0; i<n; i++){
		int temp=0;
		cin>>temp;
		arr.push_back(temp);
	}
	mergeSort(arr,n);
	cout<<"Sorted array:\n";
	for(int i=0; i<n; i++){
		cout<<arr[i]<<"\t";
	}

    return 0;
}
