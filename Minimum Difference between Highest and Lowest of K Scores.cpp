class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(nums.size()==1) return 0;
        sort(nums.begin(), nums.end());
        int minimum = INT_MAX;
        int left = 0, right = k - 1;
        while(right < nums.size()){
            minimum = min(minimum, nums[right] - nums[left]);
            left++;
            right++;
        }

        return minimum;
    }
};
