class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int size = nums.size();
        vector<long long> dp(size+1, 0);
        dp[1] = nums[0];
        for(int i = 2; i <= size; ++i){
            long long maximum = dp[i-1];
            if(colors[i-1] != colors[i-2]){
                maximum += nums[i-1];
            }
            maximum = max(maximum, dp[i-2] + nums[i-1]);
            dp[i] = maximum;
        }
        return dp[size];
    }
};
