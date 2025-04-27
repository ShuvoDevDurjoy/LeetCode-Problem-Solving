class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count = 0LL;
        int size = nums.size();
        
        // Two pointers for tracking the last valid indices of minK and maxK
        int lastMinK = -1, lastMaxK = -1, lastInvalid = -1;
        
        for (int i = 0; i < size; ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                lastInvalid = i;  // update the last invalid position
            }
            if (nums[i] == minK) {
                lastMinK = i;  // update the last position of minK
            }
            if (nums[i] == maxK) {
                lastMaxK = i;  // update the last position of maxK
            }

            // Count the valid subarrays that end at index i
            if (lastMinK != -1 && lastMaxK != -1) {
                // Subarrays are valid between max(lastMinK, lastMaxK) and i
                count += max(0, min(lastMinK, lastMaxK) - lastInvalid);
            }
        }

        return count;
    }
};
