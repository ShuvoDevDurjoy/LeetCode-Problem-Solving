class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int size = nums.size();

        int count = 0;

        for(int i = 1; i < size-1; ++i){
            if(nums[i]&1) continue;
            int x = nums[i]/2;
            if(nums[i-1]+nums[i+1]==x) count++;
        }
        return count;
    }
};
