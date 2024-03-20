int removeElement(vector<int>& nums, int val) {
        if(val>50){
        return nums.size() ; 
    }
    int index = nums.size()-1;
    for (int i = 0 ; i <= index ; i++)
    {
        if(nums[i]==val){
            nums[i] = nums[index] ; 
            index -- ; 
            i-- ; 
        }
    }
    return index+1 ;
    }
