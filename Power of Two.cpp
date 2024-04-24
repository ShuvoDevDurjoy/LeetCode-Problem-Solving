class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0) return false ;
        if(n==INT_MIN) return false ; 
        if(n<0) return false ;  
        double d = log2(n) ; 
        int i = d ; 
        if(i-d==0) return true; 
        return false ; 
    }
};
