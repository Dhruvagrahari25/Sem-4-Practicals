#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int v, vector<vector<int>> adj[], int src){
  //initializing the min heap with source vertex
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  vector<int> result(v,INT_MAX);
  result[src]=0;
  pq.push({0,src});

  while(!pq.empty()){
    int dist=pq.top().first;
    int node=pq.top().second;
    pq.pop();
    for(auto& vec:adj[node]){
      int adjNode=vec[0];
      int wt=vec[1];

      if(dist+wt<result[adjNode]){
        result[adjNode]=dist+wt;
        pq.push({dist+wt,adjNode});
      }
    }
  }
  return result;
}
int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> adj[V];

    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter the edges (source destination weight): \n";
    for (int i = 0; i < E; ++i) {
        int src, dest, wt;
        cin >> src >> dest >> wt;
        adj[src].push_back({dest, wt});
    }

    // Source node
    int src;
    cout << "Enter the source node: ";
    cin >> src;

    // Call the dijkstra function
    vector<int> shortestPaths = dijkstra(V, adj, src);

    // Print the shortest paths
    cout << "Shortest paths from node " << src << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "Node " << i << ": " << shortestPaths[i] << '\n';
    }

    return 0;
}
//Sample input:
/*
5
7
0 1 2
0 2 4
1 2 1
1 3 7
2 4 3
3 4 2
4 3 2
0
*/
