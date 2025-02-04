class Solution {
public:
    bool check(vector<int>& nums) {
        int breakIndex = -1 ;
        int size = nums.size(); 
        for(int i = 1 ; i < size ; ++i){
            if(nums[i]<nums[i-1]){
                breakIndex=i;
                break;
            }
        }
        if(breakIndex==-1){
            return true;
        }

        int s = breakIndex+1;

        for(int i = breakIndex+1 ; i < size ; ++i){
            if(nums[i]>=nums[i-1]){
                s++;
            }
        }

        return s==size && nums[size-1]<=nums[0];
    }
};
