#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

void printt(vector<int>& processes, vector<int>& memBlocks, vector<int>& alloc){
    cout<<"Process:"<<"\t"<<"Process Size:"<<"\t"<<"Block No.:\n";
    for(int i=0; i<processes.size(); i++){
        cout<<i+1<<"\t\t"<<processes[i]<<"\t\t";
        if(alloc[i]) cout<<alloc[i]<<"\n";
        else cout<<"Not Allocated!\n";
    }
}

void bestFit(vector<int>& processes, vector<int>& memBlocks){
    int p = processes.size();
    int m = memBlocks.size();
    vector<int> alloc(p,-1);
    for(int i=0; i<p; i++){
        int bestIdx = -1;
        for(int j=0; j<m; j++){
            if(memBlocks[j] > processes[i]){
                if(bestIdx==-1) bestIdx=j;
                else if(memBlocks[bestIdx] > memBlocks[j]){
                    bestIdx=j;
                }
            }
        }
        if(bestIdx!=-1){
            alloc[i]=bestIdx;
            memBlocks[bestIdx]-=processes[i];
        }
    }
    printt(processes,memBlocks,alloc);
}

int main(){
    vector<int> processes = {1,3,2,4,1,2,3};
    vector<int> memBlocks = {8,4,2,3,7,13,6,9,32};
    bestFit(processes,memBlocks);
    return 0;
}