class Solution {
private: 
    int diglen(int n){
        int s = 0;
        while(n){
            s += (n % 10);
            n /= 10;
        }
        return s;
    }
public:
    int smallestIndex(vector<int>& nums) {
        int size = nums.size();
        for(int i = 0; i < size; ++i){
            if(i == diglen(nums[i])){
                return i;
            }
        }
        return -1;
    }
};
