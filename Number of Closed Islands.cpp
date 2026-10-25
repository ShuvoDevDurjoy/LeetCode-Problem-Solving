class Solution {
private: 
    int m = 0, n = 0;
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; 
private: 
    bool cango(int i, int j){
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    int backtrack(vector<vector<int>> &grid, int i, int j){
        if(!cango(i, j) || grid[i][j] == -1) return 0;
        if(grid[i][j] == 1 || grid[i][j] == 2) return 1;
        int count = 0;
        grid[i][j] = 2;
        for(int x = 0; x < 4; ++x){
            count += backtrack(grid, i + dir[x][0], j + dir[x][1]);
        }
        grid[i][j] = count == 4?1:-1;

        return count == 4;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j]==0){
                    int r = backtrack(grid, i, j);
                    if(r==1) count++;
                }
            }
        }
        return count;
    }
};
