class Solution {
public:
    bool isSubsequence(string s, string str) {
        int index = 0 ; 
    int size1 = str.size() ; 
    int size2 = s.size() ; 
    for(int i = 0 ; i < size1 ; ++i){
        if(index==size2){
            return true ; 
        }
        if(str[i]==s[index]){
            index++ ; 
        }
    }
    if(index==size2)return true ; 
    return false ; 
    }
};
