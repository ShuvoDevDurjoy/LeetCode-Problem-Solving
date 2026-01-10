class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));

        int index = s1.size()-1;
        for(int i = s1.size()-1; i >= 0; i--){
            dp[i][s2.size()] = dp[i+1][s2.size()] + s1[index--];
        }

        index = s2.size()-1;
        for(int i = s2.size() - 1; i>=0; i--){
            dp[s1.size()][i] = dp[s1.size()][i + 1] + s2[index--]; 
        }

        for(int i = s2.size() - 1; i >= 0; i--){
            for(int j = s1.size()-1; j >= 0; j--){
                if(s1[j] == s2[i]){
                    dp[j][i] = dp[j+1][i+1];
                }
                else{
                    int bottom = s1[j] + dp[j+1][i];
                    int right = s2[i] + dp[j][i+1];
                    dp[j][i] = min(right, bottom);
                }
            }
        }
       
        return dp[0][0];
    }
};
