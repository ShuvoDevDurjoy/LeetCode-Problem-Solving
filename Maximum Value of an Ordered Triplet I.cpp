class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxValue = 0;

        for (int j = 1; j < n - 1; ++j) {
            int max_i = nums[0];
            for (int i = 0; i < j; ++i) {
                max_i = max(max_i, nums[i]);
            }

            for (int k = j + 1; k < n; ++k) {
                long long temp = (long long)(max_i - nums[j]) * nums[k];
                maxValue = max(maxValue, temp);
            }
        }

        return maxValue;
    }
};
