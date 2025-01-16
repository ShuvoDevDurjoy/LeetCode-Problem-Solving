class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor_nums1 = 0;
        int xor_nums2 = 0;
        int nums1size = nums1.size();
        int nums2size = nums2.size();
        // if(nums1size==nums2size) return 0 ;
        for (int i = 0; i < nums1size; ++i) {
            xor_nums1 ^= nums1[i];
        }
        for (int i = 0; i < nums2size; ++i) {
            xor_nums2 ^= nums2[i];
        }
        cout << xor_nums1 << endl;
        cout << xor_nums2 << endl;
        cout << nums1size << endl;
        cout << nums2size << endl;
        if (nums1size % 2 == 1 && nums2size % 2 == 1)
            return xor_nums1 ^ xor_nums2;
        else if ((nums1size == 1 && nums2size != 1) ||
                 (nums2size == 1 && nums1size != 1)) {
            return nums1size == 1 ? xor_nums2 : xor_nums1;
        } else if (nums1size % 2 == 0 && nums2size % 2 == 1)
            return xor_nums1;
        else if (nums1size % 2 == 1 && nums2size % 2 == 0)
            return xor_nums2;
        else
            return 0;
    }
};
