class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int size = nums.size();
        int maxSum = nums[0];
        int minSum = nums[0];
        int maxEnding = nums[0];
        int minEnding = nums[0];

        for(int i = 1 ;i < size ; ++i){
            maxEnding = max(maxEnding+nums[i], nums[i]);
            maxSum = max(maxEnding, maxSum);
            minEnding = min(minEnding+nums[i], nums[i]);
            minSum = min(minEnding, minSum);
        }

        return max(abs(maxSum), abs(minSum));
    }
};
