class Solution {
private: 
    int gcd(int a, int b){
        return a == 0? b: gcd(min(a, b % a), max(a, b % a));
    }
public:
    int findGCD(vector<int>& nums) {
        int max_num = 0, min_num = INT_MAX;
        for(int i: nums){
            max_num = max(max_num, i);
            min_num = min(min_num, i);
        }
        return gcd(min_num, max_num);
    }
};
