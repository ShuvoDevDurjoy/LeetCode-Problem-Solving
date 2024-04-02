class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int size = nums.size() ;
    int sum = 0 ;
    double maxAvg = -10000 ;   
    for(int i = 0 ; i < k ; ++i){
        sum+=nums[i] ; 
    }
    maxAvg = (sum*1.0)/k ; 

    for(int i = 1 ; i <= size-k ; ++i )
    {
        sum = (sum-nums[i-1])+nums[i+k-1] ; 
        if((sum*1.0)/k > maxAvg){
            maxAvg = (sum*1.0)/k ; 
        }
    }
    return maxAvg ;
    }
};
