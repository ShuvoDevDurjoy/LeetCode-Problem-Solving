class Solution {
public:
    void countingSort(vector<int>& nums, int exp) {
    const int n = nums.size();
    vector<int> output(n);
    vector<int> count(10, 0);

    for (int i = 0; i < n; ++i) {
        int digit = (nums[i] / exp) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; --i) {
        int digit = (nums[i] / exp) % 10;
        output[count[digit] - 1] = nums[i];
        count[digit]--;
    }

    for (int i = 0; i < n; ++i) {
        nums[i] = output[i];
    }
}

void radixSort(vector<int>& nums) {
    int maxVal = *max_element(nums.begin(), nums.end());
    int exp = 1;

    while (maxVal / exp > 0) {
        countingSort(nums, exp);
        exp *= 10;
    }
}
    int maximumGap(vector<int>& nums) {
     radixSort(nums) ; 
    int maximum = 0 ; 
    for(int i = 1 ; i < nums.size(); ++i)
    {
        maximum = max(maximum , nums[i]-nums[i-1]) ; 
    }
    return maximum ; 
    }
};
