class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> track(*max_element(nums.begin(),nums.end())+1,0);
        int oddCount = 0;
        for(auto &val : nums){
            track[val]++;
            if(track[val]&1){
                oddCount++;
            }
            else{
                oddCount--;
            }
        }
        return !oddCount;
    }
};
