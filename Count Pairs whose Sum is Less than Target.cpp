class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int left = 0 ; 
        int count = 0 ;
        int right = nums.size()-1 ; 
        for(int i = 0 ; i < nums.size() ; ++i){
            for(int j = i+1 ; j < nums.size() ; ++j)
            {
                if(nums[i]+nums[j]<target){
                    count++ ; 
                }
            }
        }
        return count ; 
    }
};
