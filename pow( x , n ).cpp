class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)return 1 ; 
        if(x==1||x==-1)
    {
        if(n==INT_MIN){
            return 1 ; 
        } 
        else if(n==INT_MAX){
            if(x==-1) return -1 ; 
            return 1 ;  
        }
        else {
            if(n%2==0){
                return 1 ; 
            }
            else {
                if(x=-1)return -1 ; 
                else return 1 ; 
            }
        }
    }
    bool sign = false ; 
    double result = 1 ; 
    long int power = n ; 
    if(n<0){
        sign = true ; 
        if(n==INT_MIN){
            power = INT_MAX ; 
        } 
        else {
            power = n*-1 ; 
        }
    }
    else {
        power = n ; 
    }
    result = x ; 
    double mainResult = 1 ; 
     while(power!=1){
        if(power%2 == 1 ){
            power = power-1 ; 
            mainResult *= result ; 
        }
        result = result * result; 
        power = power/2   ; 
    }
    result = result*mainResult ; 
    if(n == INT_MIN){
        result = result*x ; 
    }
    if(sign){
        return 1/result ; 
    }
    else {
        return result ; 
    }
    }
};
