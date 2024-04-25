#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int n;
vector<vector<int>> dist;
vector<vector<int>> dp;

int tsp(int mask, int pos) {
    if(mask == (1 << n) - 1)
        return dist[pos][0]; // return to starting city

    if(dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INF;
    for(int i = 0; i < n; i++) {
        if((mask & (1 << i)) == 0) // city not yet visited
            ans = min(ans, dist[pos][i] + tsp(mask | (1 << i), i));
    }

    return dp[mask][pos] = ans;
}

int main() {
    cout << "Enter the number of cities: ";
    cin >> n;

    dist.assign(n, vector<int>(n));
    dp.assign((1 << n), vector<int>(n, -1));

    cout << "Enter the distance matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> dist[i][j];

    cout << "The minimum travelling cost is " << tsp(1, 0) << '\n';

    return 0;
}
//sample input
/*
4
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0
*/
/*
Dikonda wala:
#include <stdio.h>
#include <limits.h>

#define V 4


int min(int a, int b) {
    return (a < b) ? a : b;
}


int tsp(int graph[V][V], int start, int visited[], int curr_pos, int n, int count, int cost) {
    if (count == n && graph[curr_pos][start])
        return cost + graph[curr_pos][start];


    int min_cost = INT_MAX;
    for (int i = 0; i < V; i++) {
        if (!visited[i] && graph[curr_pos][i]) {
            visited[i] = 1;
            int new_cost = tsp(graph, start, visited, i, n, count + 1, cost + graph[curr_pos][i]);
            min_cost = min(min_cost, new_cost);
            visited[i] = 0; // Backtrack
        }
    }
    return min_cost;
}


int main() {

    int graph[V][V] = {{0, 5, 0, 10},
                       {0, 0, 1, 0},
                       {0, 0, 0, 1},
                       {2, 0, 0, 0}};

    // Starting vertex
    int start = 0;
    int visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = 0;
    visited[start] = 1;
    printf("Minimum cost of traversal: %d\n", tsp(graph, start, visited, start, V, 1, 0));

    return 0;
}
*/
