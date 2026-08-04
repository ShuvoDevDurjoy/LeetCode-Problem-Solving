class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        size_t size = nums.size();
        int maximum = INT_MIN;
        int minimum = INT_MAX;
        vector<int> result;
        unordered_map<int,bool> maps;
        for(size_t i = 0; i < size; ++i){
            maps[nums[i]] = true;
            maximum = max(maximum, nums[i]);
            minimum = min(minimum, nums[i]);
        }

        for(int i = minimum; i <= maximum; ++i){
            if(!maps[i]){
                result.push_back(i);
            }
        }

        return result;
    }
};
