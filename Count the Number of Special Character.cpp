class Solution {
public:
    int numberOfSpecialChars(string s) {
        int count = 0 ; 
    unordered_map<char,int> maps ; 
    for(int i = 0 ; i < s.length() ; ++i){
        maps[s[i]]++ ; 
    }

    for(int i = 0 ; i < s.length() ; ++i)
    {
        if(s[i] < 93 && maps[s[i]+32]>0)
        {
            maps[s[i]] = 0 ; 
            maps[s[i]+32] = 0 ; 
            count++ ; 
        }
        else if(s[i]>93 && maps[s[i]-32]>0)
        {
            maps[s[i]] = 0 ; 
            maps[s[i]-32] = 0 ; 
            count++ ; 
        }
    }
    return count ;
    }
};
