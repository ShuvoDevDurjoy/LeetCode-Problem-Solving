class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.length() ; 
        unordered_map<string,int> str ; 
        int size2 = wordDict.size() ; 
        for(int i = 0 ; i < size2 ; ++i){
            str[wordDict[i]] = i ; 
        }
        vector<bool> dp(size+1) ; 
        for(int i = 0 ; i < size+1 ; ++i){
            dp[i] = false ; 
        }
        dp[0] = true ; 
        unordered_map<string , int >::iterator it ; 
        for(int i = 0 ; i < size ; ++i){
            for(int j = 0 ;  j <= i ; ++j){
                string t = s.substr(j,i-j+1) ; 
                if(str.find(t)!=str.end()){
                    dp[i+1] = dp[j] && true ; 
                    if(dp[i+1]==true){
                        break ; 
                    }
                }
            }
        }
        return dp[size] ; 
    }
};
