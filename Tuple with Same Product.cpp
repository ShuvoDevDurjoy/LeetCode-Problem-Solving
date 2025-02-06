class Solution {
public:
    int tupleSameProduct(vector<int> &nums) {
        unordered_map<int, int> maps;
        int rowSize = nums.size();
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < rowSize; ++j) {
                if (i != j)
                    maps[nums[i] * nums[j]]++;
            }
        }

        int count = 0;

        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < rowSize; ++j) {
                if (i != j) {
                    count += (maps[nums[i] * nums[j]] - 2);
                }
            }
        }

        return count;
    }
};
