class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int size = prices.size() ; 
        for(int i = 0 ; i < size ; ++i){
            int j = i + 1 ; 
            while(j<size && prices[j]>prices[i]){
                ++j;
            }
            if(j<size){
                prices[i] -= prices[j] ; 
            }
        }
        return prices;
    }
};
