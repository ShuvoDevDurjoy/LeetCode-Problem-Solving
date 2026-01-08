class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), 0));

        for(int i = nums1.size()-1; i >= 0; i--){
            for(int j = nums2.size()-1; j >= 0; j--){
                int val = nums1[i] * nums2[j];
                if((i<nums1.size()-1) && (j < nums2.size()-1))
                val = max(val + dp[i+1][j+1], val);
                if(i<nums1.size() -1)
                val = max(val, dp[i+1][j]);
                if(j<nums2.size()-1)
                val = max(val, dp[i][j+1]);
                dp[i][j] = val;
            }
        }

        return dp[0][0];
    }
};
