 void swap(vector<int> &nums , int begin , int end ){
    while(begin<end){
        int temp = nums[begin] ; 
        nums[begin] = nums[end] ; 
        nums[end] = temp ;
        begin++ ; 
        end-- ; 
    }
}

int findingNext(vector<int> &nums , int index){
    if(index==0){
        return index ; 
    }
    int i = index-1 ; 
    while(index>0 && nums[index-1]>=nums[index])
    {   
        index-- ; 
    }

    return index-1 ; 
}

int FindNearest(vector<int> &nums , int index , int size ){
    int min = 100; 
    int traceIndex = index; 
    int secondtrace = -1 ; 
    int trace = index ;
    cout<<"Here trace index at beginning is : "<<traceIndex<<endl;
    index = index ;  
    while(index <= size){
        if(nums[trace]<nums[index] && (nums[index]-nums[trace])<=min){
            traceIndex = index ; 
            min = nums[index] - nums[trace] ; 
        }
        else if(nums[trace]==nums[index])
        {
            secondtrace  = index ; 
        }
        ++index ; 
    }
    cout<<"Here trace is : "<<traceIndex<<endl;
    cout<<"Here second trace is : "<<secondtrace<<endl;
    if(traceIndex == trace && secondtrace !=-1 )
        return secondtrace ; 
    return traceIndex ;  
} 

void nextPermutation(vector<int> &nums){
    int size = nums.size()-1; 
    if(size == 0 || size == -1){
    }
    else if(size==1){
        int temp = nums[size] ; 
        nums[size] = nums[size-1] ; 
        nums[size-1] = temp ; 
    }
    else if(nums[size-1]<nums[size]){
        int temp = nums[size];
        nums[size] = nums[size-1] ; 
        nums[size-1] = temp ; 
    }
    else{
        if(nums[size-2]>=((nums[size-1]>nums[size]?nums[size-1]:nums[size])))
        {
            if(size-2 == 0){
                swap(nums,0,size) ;  
                return ; 
            }
            else 
            {
            int index = findingNext(nums,size-2) ;
            if(index==-1){
                swap(nums,0,size) ; 
                return ; 
            }
            int temp = nums[index] ; 
            int swapingIndex = FindNearest(nums , index , size); 
            swapingIndex = (swapingIndex)<0 ? size : swapingIndex ; 
            nums[index] = nums[swapingIndex];
            nums[swapingIndex] = temp ; 
            swap(nums,index+1,size) ;
            }
        }
        else{
             if(nums[size-2]>=nums[size])
             {
                int temp = nums[size-2] ; 
                nums[size-2] = nums[size-1] ; 
                nums[size-1] = temp ; 
                temp = nums[size-1] ; 
                nums[size-1] = nums[size] ; 
                nums[size] = temp ; 
             }
             else {
                int temp = nums[size] ; 
                nums[size] = nums[size-1] ; 
                nums[size-1] = temp ; 
                temp = nums[size-2] ; 
                nums[size-2] = nums[size-1] ; 
                nums[size-1] = temp ; 
             }
        }
    }
    cout<<"exiting the code "<<endl;
}
