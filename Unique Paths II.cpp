class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        int m =  nums.size() ; 
        int n = nums[0].size() ; 
        vector<vector<long long>> grid(m,vector<long long>(n)) ; 
        if(nums[m-1][n-1]==1) return 0 ; 
        for(int i = 0 ; i < m ; ++ i ){
            for(int j = 0 ; j < n ; ++j ){
                if(nums[i][j]==0)
                grid[i][j] = 1 ; 
                else grid[i][j] = 0 ; 
            }
        }

        for(int i = m-2 ; i >= 0 ; i--)
        {
            if(grid[i][n-1]==0) continue ; 
            grid[i][n-1] = grid[i+1][n-1] ; 
        }

        for(int i = n-2 ; i >= 0 ; i--){
            if(grid[m-1][i]==0) continue ; 
            grid[m-1][i] = grid[m-1][i+1] ; 
        }

        for(int i  = m -2 ; i >= 0 ; --i)
        {
            for(int j = n - 2 ; j >= 0 ; --j )
            {
                if(grid[i][j]!=0) grid[i][j] = grid[i][j+1] + grid[i+1][j] ; 
            }
        } 
        return grid[0][0] ;
    }
};
