class Solution {
public:
    int numTrees(vector<int>& nums , vector<vector<int>> &track , int n){
        for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            track[j][0] = nums[i - j];
            track[j][1] = nums[j];  
        }
        int s = 0 ; 
        for(int j = 0 ; j <= i ; ++j){
            s+=track[j][0]*track[j][1];
        }
        nums[i+1] = s ; 

    }

    return nums[n] ; 
    }
    int numTrees(int n) {
    if(n<=2) return n ; 
    vector<int> nums(n+1);
    vector<vector<int>> track(n, vector<int>(n));
    nums[0] = 1;
    nums[1] = 1;
    int result = numTrees(nums, track, n);
        return result ; 
    }
};
