class Solution {
public:
    bool isPerfectSquare(int num) {
        long long square = 0 ; 
        while(square*square<num)
        {
            square++ ; 
            if(square*square==num) return true  ; 
        }
        return false ; 
    }
};
