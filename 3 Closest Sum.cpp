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
int minimumValue(vector<int>& nums , int size , int target) {
    int n = size ; 
    int min = 100000 ; 
    int returning ; 

    for (int i = 0; i < n - 2; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; 

        int value = nums[i] ; 
        int left = i + 1, right = n - 1;

        while (left < right) {
            int sum = value +nums[left]+nums[right] ;
            if(sum > target){
                if(sum-target < min){
                    min = sum-target ; 
                    returning = sum ; 
                }
                right-- ; 
            while (left < right && nums[right] == nums[right + 1]) right--;
            }
            else if(sum < target){
                if(target-sum < min ){
                    min =target-sum ;
                    returning = sum ;  
                }
                left++ ; 
            while (left < right && nums[left] == nums[left - 1]) left++;
            }
            else {
                return target ; 
            }
            

        }
    }

    return returning;
}
    int threeSumClosest(vector<int>& nums, int target) {
        mergeSort(nums , 0 , nums.size()-1) ;
        return minimumValue(nums , nums.size() , target) ;  
    }
};
