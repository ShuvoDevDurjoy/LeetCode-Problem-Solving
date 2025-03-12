class Solution {
public:
    int maximumCount(vector<int>& nums) {
       int size = nums.size();
       int negPos = -1;
       int posPos = -1;

       int left = 0;
       int right = size-1;
       while(left<=right){
        int mid = left + (right-left)/2;
        if(nums[mid]<0){
            negPos = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
       } 
        left = 0;
        right = size - 1 ;
       while(left<=right){
        int mid = left + (right-left)/2;
        if(nums[mid]>0){
            posPos = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
       } 

       negPos = negPos!=-1?negPos+1:0;
       posPos = posPos!=-1?size-posPos:0;
       return max(negPos, posPos);
    }
};
