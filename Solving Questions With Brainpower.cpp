class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int size = questions.size();
        vector<long long int> result(size,0);
        result[size-1] = questions[size-1][0];
        for(int i = size-2; i >= 0; i--){
            // cout<<(i+questions[i][1]+1)<<endl;
            long long int m = i+questions[i][1]+1 >= size?0:result[i+questions[i][1]+1];
            result[i] = max(m+questions[i][0], result[i+1]);
        }
        // cout<<endl;
        return result[0];
    }
};
