class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if(multiplier==1) return nums;
        auto compare = [](array<int,2> &a, array<int,2> &b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]>b[0];
        };
        priority_queue<array<int,2>, vector<array<int,2>>, decltype(compare)> pq(compare);
        int size = nums.size();
        for(int i = 0 ; i < size ; ++i){
            pq.push({nums[i],i});
        }

        array<int,2> temp ; 
        while(k){
            temp = pq.top();
            pq.pop();
            pq.push({temp[0]*multiplier,temp[1]});
            nums[temp[1]] = temp[0]*multiplier;
            k--;
        }
        return nums;
    }
};
