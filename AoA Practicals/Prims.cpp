#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

int spanningTree(int V, vector<vector<int>> adj[]) {
  priority_queue<P, vector<P>, greater<P>> pq;
  pq.push({0, 0});
  vector<bool> inMST(V, false);
  int sum = 0;

  while(!pq.empty()) {
    auto p = pq.top();
    pq.pop();

    int wt     = p.first;
    int node   = p.second;

    if(inMST[node] == true) continue;

    inMST[node] = true; //added to mst
    sum += wt;

    for(auto &tmp : adj[node]) {

      int neighbor      = tmp[0];
      int neighbor_wt   = tmp[1];

      if(inMST[neighbor] == false) pq.push({neighbor_wt, neighbor});
    }
  }
  return sum;
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
    adj[dest].push_back({src, wt}); // Assuming undirected graph
  }

  // Call the spanningTree function
  int weight = spanningTree(V, adj);
  cout << "Sum of weights of edges in Minimum Spanning Tree: " << weight << "\n";

  return 0;
}
