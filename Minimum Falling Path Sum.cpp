class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& paths) {
        int row = paths.size() ; 
    int col = paths[0].size();
    for(int i = row-2 ; i >=0 ; --i)
    {
        for(int j = col-1 ; j >= 0 ; --j)
        {
            if(j==col-1)
            {
                paths[i][j] += min(paths[i+1][j-1],paths[i+1][j]) ; 
            }
            else if(j==0)
            {
                paths[i][j] +=min(paths[i+1][j+1],paths[i+1][j]) ; 
            }
            else 
                paths[i][j] += min(min(paths[i+1][j-1],paths[i+1][j+1]),paths[i+1][j]);
        }
    }
    int minimum = paths[0][0] ; 
    for(int i = 0 ; i < col ; ++i)
    {
        minimum = min(minimum , paths[0][i]) ; 
    }
    return minimum ;  
    }
};
