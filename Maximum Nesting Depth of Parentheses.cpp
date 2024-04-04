class Solution {
public:
    int maxDepth(string s) {
     int counter = 0 ;  
    int maxdepth = 0 ; 
    for(int i = 0 ; i < s.length() ; ++i){
        if(s[i]=='(') { counter ++ ; }
        else if(s[i]==')' && s[i-1]=='(') {maxdepth = max(counter , maxdepth) ; counter--; } 
        else if(s[i]==')') counter-- ; 
        else {
            maxdepth = max(maxdepth,counter);
        }
    }
    return maxdepth ; 
    }
};
