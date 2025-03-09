class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int size = colors.size();
        int s = size + k-2;
        int left = 0;
        int count = 0;
        for(int right = 1; right <= s; ++right    ){
            if(colors[(right)%size]==colors[(right-1)%size]){
                left = right;
            }

            if(right-left+1 == k){
                left++;
                count++;
            }
        }

        return count;
    }
};
