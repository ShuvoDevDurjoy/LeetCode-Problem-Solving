class Solution {
public:
    int differenceOfSums(int n, int m) {
        int amount = n/m;
        int nums2 = (2*m*amount + amount*(amount-1)*m)/2;
        int nums1 = ((n*(n+1))/2) - nums2;
        return nums1-nums2;
    }
};
