class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maximum = *max_element(nums.begin(), nums.end());
        int size = nums.size();
        long long count = 0;
        queue<int> track;
        track.push(-1);
        for (int i = 0, j = 0; j < size; ++j) {
            if (nums[j] == maximum) {
                track.push(j);
            }

            while (track.size() > k) {
                track.pop();
            }

            count += track.front() + 1;
        }

        return count;
    }
};
