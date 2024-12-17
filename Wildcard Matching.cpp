class Solution {
public:
    bool isMatch(string s, string p) {
        int psize = p.length() ; 
        int ssize = s.length() ; 
        if(psize==0){
            return ssize==0;
        }
        vector<vector<bool>> dp(ssize+1,vector<bool>(psize+1,false)) ; 
        dp[0][0] = true ; 
        for(int i = 1 ; i <= psize ; ++i){
            if(p[i-1]=='*'){
                dp[0][i] = dp[0][i-1] ; 
            }
        }

        for(int i = 1 ; i <= ssize ; ++i){
            for(int j = 1 ; j <=psize ; ++j){
                if(p[j-1]=='?' || p[j-1]==s[i-1]){
                    dp[i][j] = dp[i-1][j-1] ; 
                }
                else if(p[j-1]=='*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1] ; 
                }
            }
        }
        return dp[ssize][psize];
    }
};
