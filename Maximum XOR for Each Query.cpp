class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int size = nums.size() ; 
        for(int i = 1 ; i < size ; ++i){
            nums[i] = nums[i-1]^nums[i] ; 
        }
        vector<int> ans ; 
        int e = pow(2,maximumBit) ; 
        for(int i = size-1 ; i >= 0; --i){
            ans.push_back((e-1)^(nums[i])); 
        }
        return ans;
    }
};
