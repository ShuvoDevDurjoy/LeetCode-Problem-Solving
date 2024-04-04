class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int count = 0 ; 
    int size = grid.size(); 
    for(int x = 0 ; x < size ; ++x){
        for(int i = 0 ; i < size ; ++i){
            int  j ; 
            for(j = 0 ; j < size ; ++j){
                if(grid[x][j] == grid[j][i] ) continue ; 
                else break ; 
            }
        if(j==size){count++ ; }
        }
    }
    return count ; 
    }
};
