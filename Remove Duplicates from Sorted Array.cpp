int removeDuplicates(vector<int>& nums) {
    int index = 1 ; 
    for (int start = index ; start < nums.size() ; ++start){
        if(nums[start] != nums[start-1])
            nums[index++] = nums[start];
        
    }
    return index ; 
    }
