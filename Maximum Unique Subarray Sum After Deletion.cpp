class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums[nums.size()-1] < 0) return nums[nums.size()-1];
        unordered_map<int,bool> maps;
        int sum = 0;
        for(int i = nums.size()-1; i >= 0 && nums[i] > 0; --i){
            if(! maps[nums[i]]){
                sum += nums[i];
            }
            maps[nums[i]] = true;
        }

        return sum;
    }
};
