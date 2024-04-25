#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
//Function to find sum of weights of edges of the Minimum Spanning Tree.
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

      if(inMST[node] == true)
          continue;

      inMST[node] = true; //added to mst
      sum += wt;

      for(auto &tmp : adj[node]) {

          int neighbor      = tmp[0];
          int neighbor_wt   = tmp[1];

          if(inMST[neighbor] == false) {
              pq.push({neighbor_wt, neighbor});
          }

      }
  }
  return sum;
}
int main() {
  int V = 5;
  vector<vector<int>> adj[V];

  // Add edges to the graph
  adj[0].push_back({1, 2});
  adj[1].push_back({0, 2});

  adj[1].push_back({2, 3});
  adj[2].push_back({1, 3});

  adj[0].push_back({3, 6});
  adj[3].push_back({0, 6});

  adj[1].push_back({3, 8});
  adj[3].push_back({1, 8});

  adj[1].push_back({4, 5});
  adj[4].push_back({1, 5});

  adj[2].push_back({4, 7});
  adj[4].push_back({2, 7});

  // Call the spanningTree function
  int weight = spanningTree(V, adj);
  cout << "Sum of weights of edges in Minimum Spanning Tree: " << weight << "\n";

  return 0;
}
