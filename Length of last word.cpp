class Solution {
public:
    int lengthOfLastWord(string s) {
    int length = 0 ; 
    bool begin = true ; 
    for(int i = 0 ; i < s.length(); ++i){
        if(s[i]==' '){
            begin = true ; 
            continue ; 
        }
        else {
            if(begin){
                length = 0 ; 
            }
            length++ ; 
            begin = false ; 
        }
    }
    return length ;
    }
};
