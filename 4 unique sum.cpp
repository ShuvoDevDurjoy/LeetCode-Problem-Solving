class Solution {
public:
void merge(vector<int> &nums , int left , int right , int mid ){
    int l = mid - left + 1; 
    int r = right - mid ; 

    int arr1[mid-left+1] ; 
    for(int i = 0 ; i < mid-left+1 ; ++i){
        arr1[i] = nums[left+i] ; 
    }

    int arr2[right - mid] ; 
    for(int i = 0 ;i < right-mid ; ++i){
        arr2[i] = nums[mid+i+1] ; 
    }


    int leftIndex = 0 ; 
    int rightIndex = 0 ; 

    int index = left ; 
    while(leftIndex < l && rightIndex < r){
        if(arr1[leftIndex] < arr2[rightIndex])
        {
            nums[index++] = arr1[leftIndex++] ; 
        }
        else {
            nums[index++] = arr2[rightIndex++] ; 
        }
    }

    while(leftIndex<l){
        nums[index++] = arr1[leftIndex++] ; 
    }
    while(rightIndex< r){
        nums[index++] = arr2[rightIndex++] ; 
    }
}


void mergeSort(vector<int> &nums ,int left , int right){
    if(left<right){
        int mid = (left+right)/2 ; 
        mergeSort(nums,left,mid) ; 
        mergeSort(nums,mid+1 , right) ; 
        merge(nums , left , right , mid) ; 
    }

}


vector<vector<int>> finding(vector<int>& nums , int size , int target) {
    vector<vector<int>> result;
    int n = size ; 

    for (int i = 0; i < n - 3; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; 

        for(int j = i+1 ; j < n-2 ; ++j ){
            if(j-i!=1 && nums[j]==nums[j-1] ) continue ; 

            int left = j+1 ; 
            int right = size-1 ;

            while(left<right){
                long int value = 0 ; 
                value += nums[left];
                value +=nums[right] ; 
                value +=nums[i] ; 
                value +=nums[j] ; 
                if(value>target){
                    right-- ; 
                }
                else if(value<target){
                    left++ ; 
                }
                else {
                    result.push_back({nums[i],nums[j],nums[left],nums[right]}) ; 
                    left++ ; 
                    right-- ; 
                    while(left<right && nums[left]==nums[left-1]){
                        left++ ; 
                    }
                    while(left<right && nums[right]==nums[right+1]){
                        right-- ; 
                    }
                }
            } 
        }
    }

    return result;
}
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        mergeSort(nums,0,nums.size()-1) ; 
        return finding(nums,nums.size() , target) ; 
    }
};
