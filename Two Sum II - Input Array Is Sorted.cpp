class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0 ; 
        int right = nums.size()-1 ; 
        vector<int> result(2,0) ; 
        while(left<right){
            if(nums[left]+nums[right]==target)
            {
                result[0] = left+1 ; 
                result[1] = right+1 ; 
                break ;
            }
            else if(nums[left]+nums[right]>target)
            {
                right-- ; 
            }
            else {
                left++ ; 
            }
        }
        return result ;
    }
};
