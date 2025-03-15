class Solution {
public:
    bool check(vector<int> &nums, int size, int mid, int count){
        int count1 = 0;
        for(int i = 0; i < size ; i++){
            if(nums[i]<=mid){
                count1++;
                i++;
            }
        }
        return count1 >= count;
    }
    int minCapability(vector<int>& nums, int k) {
        vector<int> track = nums;
        sort(track.begin(),track.end());
        int left = 0;
        int right = track.size()-1;
        int result = -1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(check(nums,track.size(), track[mid],k)){
                right = mid - 1;
                result = track[mid];
            }
            else{
                left = mid + 1;
            }
        }
        return result;
    }
};
