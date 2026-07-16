class Solution {
private: 
    int gcd(int a, int b){
        return b == 0? a: gcd(min(a, b), (max(a, b) % min(a, b)));
    }
public:
    long long gcdSum(vector<int>& nums) {
        int mx = 0;
        int size = nums.size();
        vector<int> gc(size);

        for(int i = 0; i < size; ++i){
            mx = max(mx, nums[i]);
            gc[i] = gcd(mx, nums[i]);
        }

        if(size == 1) return 0;

        sort(gc.begin(), gc.end());

        int left = 0, right = size - 1;
        long long c_sum = 0;
        c_sum += gcd(max(gc[left], gc[right]), min(gc[right], gc[left])) * 1LL;
        left++;
        right--;
        while(left < right){
            long long g = gcd(max(gc[left], gc[right]), min(gc[right], gc[left])) * 1LL;
            c_sum += g;
            left++;
            right--;
        }
        return c_sum;
    }
};
