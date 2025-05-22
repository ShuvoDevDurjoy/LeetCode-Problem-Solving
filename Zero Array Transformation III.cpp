class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> diffArray(nums.size()+1, 0);
        sort(queries.begin(), queries.end(), [](vector<int>&a, vector<int>&b){
            return a[0] < b[0];
        });
        priority_queue<int> pq;
        int operation = 0;

        for(int i = 0, j = 0 ; i < nums.size(); ++i){
            operation += diffArray[i];
            while(j<queries.size() && queries[j][0]==i){
                pq.push(queries[j][1]);
                j++;
            }
            while(operation<nums[i] && !pq.empty() && pq.top()>=i){
                operation++;
                diffArray[pq.top()+1]--;
                pq.pop();
            }

            if(operation < nums[i]){
                return -1;
            }
        }

        return pq.size();

    }
};
