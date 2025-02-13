class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int size = nums.size();
        priority_queue<long long int,vector<long long int>,greater<long long int>> minPq;
        for(int i = 0 ; i < size ; ++i ){
            minPq.push(nums[i]);
        }
        int count = 0;
        long long int a,b;
        while(size>=2 && minPq.top()<k ){
            a = minPq.top();
            minPq.pop();
            b = minPq.top();
            minPq.pop();
            a = min(a,b) * 2 + max(a,b);
            minPq.push(a);
            size--;
            count++;
        }

        return count;
    }
};
