class Solution {
public:
    int trailingZeroes(int index) {
        int n = 5 ;
    int number = 0 ;  
    while(index/n!=0)
    {
        number+=index/n ; 
        n*=5 ; 
    }
    return number ;
    }
};
