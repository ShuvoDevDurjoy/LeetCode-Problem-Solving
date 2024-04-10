class Solution {
public:
    int arrange(int n , int row){
        if(row>n){
            return 0 ; 
        }
        else return 1 + arrange(n-row,row+1) ; 
    }
    int arrangeCoins(int n) {
        return arrange(n,1) ; 
    }
};
