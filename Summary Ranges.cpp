class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> str ; 
        int start = 0 ; 
        int end = 0 ; 
        for(int i = 0 ; i < nums.size() ; ++i)
        {
            if(i+1==nums.size())
            {
                if(start==i)
                {
                    str.push_back(to_string(nums[i])) ; 
                    start = i+1; 
                }
            else {
                str.push_back(to_string(nums[start])+"->"+to_string(nums[i])) ; 
                start = i+1 ; 
            }
            }
            else if(nums[i]+1!=nums[i+1])
            {
                if(start==i)
                {
                    str.push_back(to_string(nums[i])) ; 
                    start = i+1; 
                }
            else {
                str.push_back(to_string(nums[start])+"->"+to_string(nums[i])) ; 
                start = i+1 ; 
            }
        }
        }
        return str ; 
    }
};
