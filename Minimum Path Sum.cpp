class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size() ;
        int column = grid[0].size() ;
        for(int i = row-2 ; i >= 0 ; --i){
            grid[i][column-1] += grid[i+1][column-1] ; 
        } 

        for(int i = column-2 ; i >= 0 ; i--)
        {
            grid[row-1][i] += grid[row-1][i+1] ; 
        }

        for(int i = row-2 ; i >= 0 ; i--)
        {
            for(int j = column-2 ; j >= 0 ; --j){
                grid[i][j]+=min(grid[i][j+1],grid[i+1][j]) ; 
            }
        }
         
         return grid[0][0] ; 
    }
};
