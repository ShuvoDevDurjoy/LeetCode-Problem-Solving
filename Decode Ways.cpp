class Solution {
public:
    int fibonacciNumber(int n,vector<int> &track){
    if(n <= 2){
        return n; 
    }
    if(track[n]!=0){
        return track[n] ; 
    }
    track[n] = fibonacciNumber(n-1,track) + fibonacciNumber(n-2,track) ; 
    return track[n] ; 
}


int numDecodings(string s) {
    if(s[0]=='0')
    return 0 ; 
    int size = s.length() ; 
    vector<int> dp(size) ; 
    dp[0]++ ; 
    for(int i = 1 ; i < size ; ++i){
        if(s[i]=='0' && (s[i-1]=='0' || s[i-1]>'2') ) return 0 ; 
        else if(s[i]=='0') continue ; 
        else if (s[i]<='6'){
            if(s[i-1]!='0' && s[i-1]<='2') dp[i-1]++ ; 
            if(i+1<size && s[i+1]=='0' && dp[i-1]==2) dp[i-1]-- ;  
        }
        else if(s[i-1]=='1'){
            dp[i-1]++ ; 
        }
        dp[i]++ ; 
    }

    vector<int> nums ; 
    int t = 0 ; 
    for(int i = 0 ; i < size ; ++i){
        if(dp[i]==2){
            t+=2 ; 
        }
        else{
            if(t==0) continue ;
            else{
                vector<int> track((t/2)+2) ; 
                int x = fibonacciNumber((t/2)+1,track) ; 
                nums.push_back(x) ; 
                t= 0 ; 
            }
        }
    }

    size = nums.size() ; 
    int m = 1 ; 
    for(int i = 0 ; i < size ; ++i){
        m*=nums[i] ;
    }
    return m ; 
}
};
