class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int size = arr.size();
        for(int i = 0; i < size; ++i){
            pq.push(arr[i]);
        }
        unordered_map<int, int> maps;
        int rank = 1;
        vector<int> result(arr.size());
        while(!pq.empty()){
            int x = pq.top();
            pq.pop();
            if(!maps[x]){
                maps[x] = rank;
                rank++;
            }
        }

        for(int i = 0; i < size; ++i){
            result[i] = maps[arr[i]];
        }

        return result;

    }
};
