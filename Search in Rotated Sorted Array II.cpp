class Solution {
public:
bool finding(vector<int> &nums , int left , int right , int target){

    while(left<=right){
        int mid = (left+right)/2 ; 
        if(nums[mid]==target){
            return true ; 
        }
        else if(nums[mid]<target){
            left = mid+1 ; 
        }
        else{
            right = mid-1 ; 
        }
    }
    return false ; 
}
int finding(vector<int> &x){
    int n = x.size() ; 
    if (n==1) return 0;
        if (n==2) return (x[0]<x[1])?1:0;
        int l = 0, r = n, m;
        while (l < r) {
            while (l < r-1 && x[l] == x[l+1]) l++;
            m = (r+l) / 2;
            if (m == n-1 || x[m] > x[m+1]) return m;
            if (x[m] > x[l]) l = m;
            else r=m;  
    } 
    return m ; 
}
    bool search(vector<int>& nums, int target) {
        int k = finding(nums) ; 
    if(finding(nums ,0, k,target))
    return true ; 
    if(finding(nums, (k==nums.size()-1)?k:k+1 , nums.size()-1,target))
    return true ; 
    return false ; 
    }
};
