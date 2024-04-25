#include <bits/stdc++.h>
using namespace std;
void apsp(vector<vector<int>>& grid){
  int n=grid.size();
  for(int via=0; via<n; via++){
    for(int row=0; row<n; row++){
      for(int col=0; col<n; col++){
        grid[row][col]=min(grid[row][col],grid[row][via]+grid[via][col]);
      }
    }
  }
}
int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    cout << "Enter the adjacency matrix: \n";
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    apsp(grid);

    cout << "The shortest path matrix is: \n";
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
//sample input:
/*
9
0 4 0 0 3 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
9 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0
*/
