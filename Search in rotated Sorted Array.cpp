class Solution {
public:
        int search(vector<int> &nums , int target){
    int left = 0 ; 
    int right = nums.size() - 1 ; 
    int size = right ; 
    while(left<=right){
        int mid = (left+right)/2 ; 
        if(nums[mid] == target){
            return mid ; 
        }
        else if(nums[left] <= nums[mid == left ? left : mid - 1]){
            if(nums[left]<=target && nums[mid == left ? left : mid -1]>=target)
            {
              right = mid - 1 == -1 ? 0 : mid -1; 
            }
            else {
                left = mid + 1 ; 
            }
        }
        else if(nums[mid == right ? right : mid + 1] <= nums[right]){
            if(target >= nums[mid == right ? right : mid + 1] && target <= nums[right]){
                left = mid + 1 > right ? right : mid + 1 ; 
            }
            else {
                right = mid - 1 ; 
            }
            }
            }
    return -1 ; 
}
};
