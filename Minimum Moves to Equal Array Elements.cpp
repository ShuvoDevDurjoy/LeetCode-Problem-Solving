class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int diff = 0;
        int s = 0;
        for(int i = 1; i < nums.size(); ++i){
            int cd = nums[i] - nums[i-1];
            s = s + diff + cd;
            diff += cd;
        }
        return s;
    }
};
