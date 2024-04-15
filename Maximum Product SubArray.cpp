class Solution {
public:
    int maxProduct(vector<int>& nums) {
    int minEndingHere = nums[0] ; 
    int maxEndingHere = nums[0] ;
    int product = nums[0] ; 
    for(int i = 1 ; i < nums.size() ; ++i){
        int temp = max({nums[i],nums[i]*maxEndingHere , nums[i]*minEndingHere}); 
        minEndingHere = min({nums[i],nums[i]*maxEndingHere,nums[i]*minEndingHere});
        maxEndingHere = temp ; 
        product = max(product , maxEndingHere) ; 
    }

    return product ;  
    }
};
