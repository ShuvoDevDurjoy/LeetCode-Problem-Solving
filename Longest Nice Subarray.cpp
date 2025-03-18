class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int size = nums.size();
        int left = 0;
        int sumMask = nums[0];
        int maxSize = 1;
        for(int i = 1; i < size; ++i){
            if((sumMask & nums[i]) == 0){
                maxSize = max(maxSize, i - left + 1);
                sumMask |= nums[i];
            }
            else{
                while((sumMask & nums[i]) != 0){
                    sumMask ^= nums[left];
                    left++;
                }
                maxSize = max(maxSize, i - left + 1);
                sumMask |= nums[i];
            }
        }

        return maxSize;
    }
};
