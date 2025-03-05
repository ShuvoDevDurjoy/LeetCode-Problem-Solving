class Solution {
public:
    long long coloredCells(int n) {
        return 1L + 2*(n-1) + 2*(pow(n-1,2));
    }
};
