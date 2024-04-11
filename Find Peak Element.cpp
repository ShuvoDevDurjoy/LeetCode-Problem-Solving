class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0 ; 
        int right = nums.size()-1 ; 
        if(right==0) return 0 ; 
        else if(right==1) return (nums[0]>nums[1])? 0 : 1;
        while(left<=right){
            int mid = (left+right)/2 ; 
            if(mid==0 && nums[0]>nums[1])
            return 0 ; 
            else if(mid==nums.size()-1 && nums[nums.size()-1]>nums[nums.size()-2])
            {
                return nums.size()-1 ; 
            }
            else if(nums[mid]>nums[mid-1]&& nums[mid]>nums[mid+1])
            {
                return mid ; 
            }
            else if(nums[mid]<nums[mid+1])
            left = mid+1 ; 
            else{
                right = mid ; 
            }
        }
        return - 1; 
    }
};
