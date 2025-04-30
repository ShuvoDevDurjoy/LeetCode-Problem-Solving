class Solution {
public:
    int helper(int x){
        int m = 1;
        int count = 0;
        while(x/m!=0){
            m = m * 10;
            count++;
        }
        return count;
    }
    int findNumbers(vector<int>& nums) {
        int result = 0;
        for(int i: nums){
            if(helper(i)%2==0){
                ++result;
            }
        }

        return result;
    }
};
