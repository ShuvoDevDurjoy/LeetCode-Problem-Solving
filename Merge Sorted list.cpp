class Solution {
public:
    void merge(vector<int> &nums1 , int m , vector<int> &nums2 , int n ){
    int leftIndex = 0 ; 
    int rightIndex = 0 ; 
    vector<int> nums ; 
    while(leftIndex < m && rightIndex < n){
        if(nums1[leftIndex]<nums2[rightIndex])
        {
            nums.push_back(nums1[leftIndex++]);
        }
        else {
            nums.push_back(nums2[rightIndex++]);
        }
    }
    while(leftIndex < m){
        nums.push_back(nums1[leftIndex++]);
    }
    while(rightIndex < n){
        nums.push_back(nums2[rightIndex++]);
    }

    for(int i = 0 ; i < nums.size() ; ++i){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    for(int i = 0 ; i < m+n ; i++){
        nums1[i] = nums[i] ; 
    }
}
};
