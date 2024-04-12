class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maximum = 0 ;
        int minSofar = prices[0] ;  
        for(int i = 0 ; i < prices.size() ; ++i )
        {
            minSofar = min(minSofar,prices[i]) ; 
            maximum = max (maximum , prices[i]-minSofar) ; 
        }
        return maximum ;
    }
};
