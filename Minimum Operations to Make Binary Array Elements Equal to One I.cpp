class Solution {
public:
    int minOperations(vector<int>& nums) {
        int summation = 0;
        summation += nums[0] + nums[1];
        int size = nums.size();
        int count = 0;
        int s = 0;
        for(int i = 2; i < size; ++i){
            summation += nums[i];
            if(summation < 3 && nums[i-2]==0){
                nums[i-2] = !nums[i-2];
                nums[i-1] = !nums[i-1];
                nums[i] = !nums[i];
                ++count;
            }
            summation = nums[i] + nums[i-1];
            // for(int x = 0; x < size; ++x){
            //     cout<<nums[x]<<" ";
            // }
            s += nums[i-2];
            // cout<<endl;
            // cout<<summation<<endl;
        }

        return s==size-2 && nums[size-1] && nums[size-2]?count:-1;
    }
};
