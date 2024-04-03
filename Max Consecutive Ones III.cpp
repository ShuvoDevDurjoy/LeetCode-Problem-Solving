class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxsize = 0 ; 
    int size = nums.size() ; 
    int nz = k ; 
    int left = 0 ; 
    for(int i = 0 ; i < size ; ++i){
        if(nums[i] == 0 ){
            nz-- ; 
        }
        while(nz<0){
            if(nums[left]==0)
                nz++ ; 
            left++ ; 
        }

        maxsize = max(maxsize , i-left+1) ; 

    }
    return maxsize ;
    }
};
