#include <bits/stdc++.h>
using namespace std;

//sample input
/*
4
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0
*/

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