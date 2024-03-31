class Solution {
public:
    int climbing(int n ,int m, vector<int> &nums){
        if(m+1==n){
            return 1 ; 
        }
        else if(m+2==n){
            return 2 ; 
        }
        else if(m+3==n){
            return 3 ; 
        }
        if(nums[m]!=0){
            return nums[m] ; 
        }
        nums[m] = climbing(n,m+1,nums) + climbing(n,m+2,nums) ; 
        return nums[m] ; 
    }
    int climbStairs(int n) {
        vector<int> nums(n,0) ; 
        int times = climbing(n,0,nums) ; 
        return times ; 
    }
};
