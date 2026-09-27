class Solution {
public:
    int rob(vector<int>& nums) {
        int s = nums.size();
        int p0 = 0, p1 = nums[0];
        int maximum = 0;
        for(int i = 1; i < (s - 1); ++i){
            int pp = p0;
            p0 = max(p0, p1);
            p1 = pp + nums[i];
        }
        maximum = max(p0, p1);

        p0 = 0;
        p1 = 0;
        for(int i = 1; i < s; ++i){
            int pp = p0;
            p0 = max(p0, p1);
            p1 = pp + nums[i];
        }
        maximum = max(maximum, max(p0, p1));
        return maximum;
    }
};
