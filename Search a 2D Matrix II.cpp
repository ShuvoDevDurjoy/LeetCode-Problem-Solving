class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        for(int i = 0 ; i < matrix.size() && matrix[i][0] <= target ; ++i){
                int l = 0 ; 
                int r = matrix[0].size()-1 ; 
                while(l<=r){
                    int m = (l+r)/2 ; 
                    if(matrix[i][m]==target) return true ; 
                    else if(matrix[i][m]<target)
                    {
                        l = m + 1 ; 
                    }
                    else {
                        r = m - 1; 
                    }
                }
        }

        return false ;
    }
};
