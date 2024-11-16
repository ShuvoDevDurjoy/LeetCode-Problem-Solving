class Solution {
public:
    int largestCombination(vector<int>& candidates) {
       int size = candidates.size() ; 
       vector<int> result(24) ; 
       for(int i = 0 ; i < size ; ++i){
        bitset<24> binary(candidates[i]) ; 
        for(int i = 23 ; i >= 0 ; i--){
            if(binary[i]==1){
                result[i]++;
            }
        }
       }
       int max = 0 ;  
       for(int i = 0 ; i < 24 ; ++i){
        if(result[i]>max){
            max = result[i] ; 
        }
       }
       return max;
    }
};
