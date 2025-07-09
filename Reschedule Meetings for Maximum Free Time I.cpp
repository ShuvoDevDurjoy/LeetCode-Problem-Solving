class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,vector<int>& endTime) {
        vector<int> dp(startTime.size() + 1, 0);
        dp[0] = startTime[0] - 0;
        for(int i = 1; i < startTime.size(); ++i){
            dp[i] = startTime[i] - endTime[i-1];
        }
        dp[startTime.size()] = eventTime - endTime[endTime.size()-1];

        int maximum = dp[0];

        for(int i = 1; i < k+1 ; ++i){
            maximum += dp[i];
        }

        int right = k+1;
        int left = 0;
        int currentSum = maximum;
        while(right <= endTime.size()){
            currentSum = currentSum + dp[right];
            currentSum = currentSum - dp[left];
            left++;
            ++right;
            maximum = max(maximum, currentSum);
        }

        return maximum;
    }
};
