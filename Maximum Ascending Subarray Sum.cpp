class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int size = nums.size();
        int maxSum = nums[0] ; 
        int currentSum = nums[0] ; 
        for(int i = 1 ; i < size ; ++i){
            if(nums[i]>nums[i-1]){
                currentSum += nums[i];
            }
            else{
                currentSum = nums[i];
            }
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};
