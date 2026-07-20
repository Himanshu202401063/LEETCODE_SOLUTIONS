class Solution {
public:


void solve(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> temp = grid;

    for (int i = 0; i < m; i++) {
        for (int j = n - 1; j >= 1; j--) {
            temp[i][j] = grid[i][j - 1];
        }
    }

    for (int i = 0; i < m - 1; i++) {
        temp[i + 1][0] = grid[i][n - 1];
    }

    temp[0][0] = grid[m - 1][n - 1];

    grid = temp;
}
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        while(k--){
            solve(grid);

        }
         return grid;
        
    }
};