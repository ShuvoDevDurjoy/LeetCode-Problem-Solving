class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
    int size = nums.size();
    if(size<3)
    return false;
    int minimum = min(nums[0],nums[1]) ; 
    int maximum = max(nums[0],nums[1]) ;
    int maxIndex = 0 ; 
    int minIndex = 0 ; 
    if(nums[0]<nums[1]) {minIndex = 0 ; maxIndex = 1 ; }
    else {minIndex = 1 ; maxIndex = 0 ; }
    for(int i = 2 ; i < size ; ++i){
        if(nums[i]>minimum && nums[i]>maximum && minIndex<maxIndex) {
            return true ; 
        }
        if(nums[i]<minimum && i+3<=size){
            minimum = nums[i] ; 
        }
        else if(nums[i]>minimum && i+2<=size){
            maximum = nums[i] ;
            maxIndex = i ;  
        }
    }
    return false ;    
    }
};
