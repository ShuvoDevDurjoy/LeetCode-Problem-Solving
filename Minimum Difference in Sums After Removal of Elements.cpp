class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        vector<long long> dpSmall;
        vector<long long> dpLarge;

        priority_queue<int> pqSmall;
        priority_queue<int, vector<int>, greater<int>> pqLarge;

        int size = nums.size();
        int n = size / 3;
        long long smallSum = 0;
        long long largeSum = 0;
        for(int i = 0; i < n; ++i){
            pqSmall.push(nums[i]);
            smallSum += nums[i];
            pqLarge.push(nums[size - 1 - i]);
            largeSum += nums[size - 1 - i];
        }
        dpSmall.push_back(smallSum);
        dpLarge.push_back(largeSum);
        
        for(int i = n, j = size - 1 - n; i < nums.size() - n && j >= n; i++, j--){
            pqSmall.push(nums[i]);
            smallSum += nums[i];
            smallSum -= pqSmall.top();
            pqSmall.pop();
            dpSmall.push_back(smallSum);

            pqLarge.push(nums[j]);
            largeSum += nums[j];
            largeSum -= pqLarge.top();
            pqLarge.pop();
            dpLarge.push_back(largeSum);
        }
        int j = dpLarge.size()-1;
        long long minimum = LLONG_MAX;
        for(int i = 0; i < dpSmall.size() && j >= 0; ++i, j--){
            long long diff = dpSmall[i] - dpLarge[j];
            minimum = min(diff, minimum);
        }

        return minimum;
    }
};
