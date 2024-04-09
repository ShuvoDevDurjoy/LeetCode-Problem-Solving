class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0 ; 
        int right = matrix.size()-1 ; 
        int size = matrix[0].size()-1 ; 
        while(left<=right)
        {
            int mid = (left+right)/2 ; 
            if(matrix[mid][0]<=target && matrix[mid][size]>=target)
            {
                int l = 0 ; 
                int r = size ; 
                while(l<=r){
                    int m = (l+r)/2 ; 
                    if(matrix[mid][m]==target){
                        return true ; 
                    }
                    else if(matrix[mid][m]>target){
                        r = m - 1 ; 
                    }
                    else{
                        l = m + 1 ; 
                    }

                }
                return false ; 

            }
            else if(matrix[mid][0] > target)
            {
                right = mid - 1 ; 
            }
            else {
                left = mid + 1 ; 
            }
        }
        return false ; 
    }
};
