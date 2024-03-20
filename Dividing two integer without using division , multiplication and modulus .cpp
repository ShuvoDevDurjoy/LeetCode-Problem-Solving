int divide(int dividend, int divisor) 
    {
        if( dividend == INT_MIN && divisor == -1 )
            return INT_MAX;
        long long int ans = dividend/divisor;
        if(ans>INT_MAX)
            return INT_MAX;
        if(ans<INT_MIN)
            return INT_MIN;
        return ans;
    }
//here the returning value will always be of size int (32 bit) . if the quoatient of the division is gretter than INT_MAX then it returns teh INT_MAX and if the 
//Quoient is less than INT_MIN , then it returns INT_MIN 
