class Solution {
public:
    long long modExp(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) { 
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2; 
        }
        return result;
    }
    int countWays(vector<vector<int>>& ranges) {
        int size = ranges.size();
        int count = 1;
        sort(ranges.begin(), ranges.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            } else {
                return a[0] < b[0];
            }
        });

        int maxEnd = ranges[0][1];
        for (int i = 1; i < size; ++i) {
            if (ranges[i][0] > maxEnd) {
                maxEnd = ranges[i][1];
                count++;
            } else {
                maxEnd = max(maxEnd, ranges[i][1]);
            }
        }

        const int MOD = 1e9 + 7;
        return modExp(2, count, MOD);
    }
};
