class Solution {
public:
    int search (vector<int> &nums , int target){
        int left = 0 ; 
        int right = nums.size()-1 ; 
        if(right==0 && nums[0]>=target) return 0 ;  
        if(right>=1)
        {
            if(nums[0]>=target) return 0 ; 
            if(nums[1]>=target) return 1 ; 
        }
        // cout<<"Here target is : "<<target<<endl;
        while(left<=right){
            int mid = (left+right)/2 ; 
            // if(mid<=1) return -1 ; 
            if(mid>1 && nums[mid] >= target && nums[mid-1]<=target)
            {
                if(nums[mid-1]<target) return mid ; 
                else if(nums[mid-1]==target) right = mid-1 ; 
            }
            else if(nums[mid] > target){
                right = mid-1 ; 
            }
            else {
                left = mid+1  ;
            }
        }
        return -1 ; 
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> result;
        for (int i = 0; i < spells.size(); ++i) {
            long long  to_find = (success + spells[i] - 1) / spells[i];
            auto it = lower_bound(potions.begin(), potions.end(), to_find);
            if (it != potions.end()) {
                result.push_back(potions.size() - (it - potions.begin()));
            }
            else {
                result.push_back(0);
            }
        }
        return result;
    }
};
