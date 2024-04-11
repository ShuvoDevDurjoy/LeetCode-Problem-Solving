class Solution {
public:
    int hIndex(vector<int>& nums) {
        int left = 0 ; 
    int right = nums.size()-1 ; 
    int maximum = 0 ; 
    while(left<=right){
        int mid = (left+right)/2 ; 
        if(nums[mid]>=(nums.size()-mid))
        {
            maximum = maximum>(nums.size()-mid)?maximum : nums.size()-mid ; 
            right = mid-1 ; 
        }
        else {
            left = mid+1 ; 
        }
    } 
    return maximum ;
    }
};
