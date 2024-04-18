class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==1) return nums[0] ; 
        int floor = nums.size()/2 ; 
        sort(nums.begin(),nums.end()) ; 
        int size = 1 ; 
        for(int i = 1 ; i < nums.size() ; ++i){
            if(nums[i]==nums[i-1]) ++size ; 
            else size = 1 ; 
            if(size>floor) return nums[i] ; 
        }
        return 0 ; 
    }
};
