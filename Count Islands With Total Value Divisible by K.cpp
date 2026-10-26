class Solution {
private:
    int m = 0, n = 0;
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool cango(int i, int j) { return i >= 0 && i < m && j >= 0 && j < n; }
    long long backtrack(vector<vector<int>>& grid, int i, int j) {
        if (!cango(i, j) || grid[i][j] == 0)
            return 0;
        long long sum = grid[i][j];
        grid[i][j] = 0;
        for (int x = 0; x < 4; ++x) {
            sum += backtrack(grid, i + dir[x][0], j + dir[x][1]);
        }
        return sum;
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0) {
                    long long s = backtrack(grid, i, j);
                    if (s % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
