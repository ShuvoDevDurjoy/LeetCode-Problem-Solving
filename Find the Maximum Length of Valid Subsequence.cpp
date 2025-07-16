class Solution {
public:
    int maximumLength(vector<int>& nums) {
       vector<vector<int>> dp(nums.size() + 1, vector<int>(2));
       dp[nums.size()][0] = 0;
       dp[nums.size()][1] = 0;
       int maximum = 0;
       int odd = nums.size(), even = nums.size();

       for(int i = nums.size()-1; i >= 0; --i){
        bool isOdd = nums[i]%2;
        if(isOdd){
            int evens = dp[even][1] + 1;
            int odds = dp[odd][1] + 1;
            dp[i][0] = evens;
            dp[i][1] = odds;
            maximum = max(maximum, max(evens, odds));
            odd = i;
        }
        else{
            int evens = dp[even][0] + 1;
            int odds = dp[odd][0] + 1;
            dp[i][0] = evens;
            dp[i][1] = odds;
            maximum = max(maximum, max(evens, odds));
            even = i;
        }
       }
       return maximum;
    }
};
