class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum = 0;
        int left = 0;
        int maximum = 0;
        int right = 0;
        unordered_map<int,int> maps;
        while(right < nums.size()){
            sum += nums[right];
            maps[nums[right]]++;
            while(left < right && maps[nums[right]] > 1){
                sum -= nums[left];
                maps[nums[left]]--;
                left++;
            }
            maximum = max(maximum, sum);
            right++;
        }

        return maximum;
    }
};
