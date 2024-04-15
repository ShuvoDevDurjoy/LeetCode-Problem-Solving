class Solution {
public:
       int uniquePaths(int m, int n) {
        vector<vector<int>> nums( m , vector<int>(n,1)) ; 
        for(int i  = m -2 ; i >= 0 ; --i)
        {
            for(int j = n - 2 ; j >= 0 ; --j )
            {
                nums[i][j] = nums[i][j+1] + nums[i+1][j] ; 
            }
        } 
        return nums[0][0] ;
    }

};
