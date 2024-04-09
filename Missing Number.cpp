class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end()) ; 
        if(nums[0]!=0) return 0 ; 
        else if(nums[nums.size()-1]!=nums.size()) return nums.size() ; 
        int i = 0 ; 
        for(i = 0 ; i < nums.size()-1 ; ++i){
            if(nums[i]+1==nums[i+1])continue ; 
            else return nums[i]+1; 
        }
        return 0 ; 
    }

};
