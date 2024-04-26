#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int v, vector<vector<int>> adj[], int src, vector<int>& parent){
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
        parent[adjNode] = node; // Keep track of the parent node
        pq.push({dist+wt,adjNode});
      }
    }
  }
  return result;
}

void printPath(vector<int>& parent, int node) {
    if (node == -1) {
        return;
    }
    printPath(parent, parent[node]);
    cout << node << " ";
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

    vector<int> parent(V, -1);
    // Call the dijkstra function
    vector<int> shortestPaths = dijkstra(V, adj, src, parent);

    // Print the shortest paths
    cout << "Shortest paths from node " << src << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "Node " << i << ": " << shortestPaths[i] << '\n';
    }

    // Print the path from source to each node
    cout << "Paths from node " << src << ":\n";
    for (int i = 0; i < V; ++i) {
      cout << "Path to node " << i << ": ";
      printPath(parent, i);
      cout << '\n';
    }

    return 0;
}

// //Sample input:
// /*
// 5
// 7
// 0 1 2
// 0 2 4
// 1 2 1
// 1 3 7
// 2 4 3
// 3 4 2
// 4 3 2
// 0
// */
