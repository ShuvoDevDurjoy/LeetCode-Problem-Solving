class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = 0 ; 
        int size = candies.size() ; 
    for(int i = 0 ; i < size; ++i){
        if(candies[i]>max){
            max = candies[i] ; 
        }
    }
    vector<bool> result(size) ; 
    for(int i = 0 ; i < size ; ++i){
        if(candies[i]+extraCandies>=max){
            result[i] = true ; 
        }
        else {
            result[i] = false ;
        }
    }
    return result ;
    }
};
