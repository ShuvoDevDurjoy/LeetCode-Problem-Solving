class Solution {
public:
int findingleft(vector<int> &nums , int left , int right , int target){
    while(left<=right){
        int mid = (left+right)/2 ;
        if(nums[mid]==target){
            if(mid-1>=left&&nums[mid-1]==target){
                right = mid-1  ;
            }
            else {
                return mid ; 
            }
        }
        else {
            left = mid+1 ; 
        }
    }
    return -1 ; 
}

int findingright(vector<int> &nums , int left , int right , int target){
    while(left<=right){
        int mid = (left+right)/2 ; 
        if(nums[mid] == target){
            if(mid+1<=right&&nums[mid+1]==target){
                left = mid+1;
            }
            else {
                return mid ; 
            }
        }
        else{
            right = mid-1 ; 
        }
    }
    return -1  ;
}


vector<int> searchRange(vector<int> &nums ,int target){

    vector<int> v ;
    int left = 0 ; 
    int size = nums.size() ; 
    int right = size-1 ;  

    while(left <= right){
        int mid = (right+left)/2;
        if(nums[mid] == target){
            v = {mid , mid} ; 
            int leftmost = findingleft(nums,left , mid-1 , target);
            int rightmost = findingright(nums,mid+1,right,target) ; 
            if(leftmost!=-1){
                v[0] = leftmost ; 
            }
            if(rightmost!=-1){
                v[1] = rightmost ; 
            }
            return v ; 
        }
        else if(nums[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return {-1, -1};
}

};
