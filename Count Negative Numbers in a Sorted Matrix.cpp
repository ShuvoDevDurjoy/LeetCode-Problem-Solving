class Solution {
public:
    int countNegatives(vector<vector<int>>& nums) {
        int m = nums.size() ; 
    int n = nums[0].size()-1 ; 
    int count = 0 ; 
    for(int i = 0 ; i < m ; ++i){
        int left = 0 ; 
        int right = n ; 
        while(left<=right)
        {
            int mid = (left+right)/2; 
            if(nums[i][mid]<0)
            {
                cout<<(right-mid+1)<<endl;
                count += (right-mid+1) ; 
                right = mid-1 ; 
            }
            else if(nums[i][mid]>=0){
                left = mid+1 ; 
            }
        }
    }
    return count ;
    }
};
