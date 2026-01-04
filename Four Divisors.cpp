class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        unordered_map<int, int> maps;
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int to = (sqrt(nums[i]));
            int dc = 0;
            int sd = 0;
            if (maps[nums[i]] == -1)
                continue;
            if (maps[nums[i]] != 0) {
                ans += maps[nums[i]];
                continue;
            }
            for (int j = 1; j <= to; ++j) {
                if (nums[i] % j == 0) {
                    sd += j;
                    dc++;
                    if (j != (nums[i] / j)) {
                        sd += (nums[i] / j);
                        dc++;
                    }
                    if (dc > 4) {
                        sd = -1;
                        dc = -1;
                        break;
                    }
                }
            }
            maps[nums[i]] = -1;
            if (dc == 4) {
                maps[nums[i]] = sd;
                ans += maps[nums[i]];
            }
        }
        return ans;
    }
};
