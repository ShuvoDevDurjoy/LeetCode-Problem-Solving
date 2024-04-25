class Solution {
public:
    void setZeroes(vector<vector<int>>& nums) {
    int col = 1 ;  
    
    for(int i = 0 ; i < nums.size() ; ++i)
    {
        if(nums[i][0]==0) col = 0 ; 
        for(int j = 1 ; j < nums[0].size() ; ++j)
        {
            if(nums[i][j]==0)
            {
                nums[i][0] = 0 ; 
                nums[0][j] = 0 ; 
            }
        }
    }

    for(int i = nums.size()-1 ; i >= 0 ; --i)
    {
        for(int j = nums[0].size()-1 ; j >= 1 ; --j)
        {
            if(nums[i][0]==0 || nums[0][j]==0)
            nums[i][j] = 0 ; 
        }
        if(col==0) nums[i][0] = 0 ; 
    }
    
    }
};
