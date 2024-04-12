class Solution {
public:
    void rotate(vector<int>& nums, int target) {
        target = target % nums.size() ; 
    reverse(nums.begin(),nums.end()) ; 
    int index = target-1 ; 
    int left = 0 ; 
    int right = target -1 ; 
    while(left<right){
        swap(nums[left],nums[right]) ; 
        left++ ;
        right-- ;  
    }
    left = target ; 
    right = nums.size()-1 ;
    while(left<right){
        swap(nums[left],nums[right]) ; 
        left++ ;
        right-- ;
    }

    }
};
