#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


//https://codeforces.com/problemset/problem/1598/A
bool dfs(int x, int y, vector<vector<char>> &grid, vector<vector<bool>> &visited, int n) {
    if (x == 1 && y == n - 1){
      return true;
    } 
    
    visited[x][y] = true; 

    int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
    int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 and nx < 2 and ny >= 0 and ny < n and grid[nx][ny] == '0' and !visited[nx][ny]) {
            if (dfs(nx, ny, grid, visited, n)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<char>> grid(2, vector<char>(n)); 
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j]; 
            }
        }

        vector<vector<bool>> visited(2, vector<bool>(n, false));

        if (dfs(0, 0, grid, visited, n)) {
            cout << "YES" << endl;
        } 
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
