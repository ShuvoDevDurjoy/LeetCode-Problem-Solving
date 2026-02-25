class Solution {
public:
    int count_bits(int n){
        int count = 0;
        while(n){
            count += (n & 1);
            n = n >> 1;
        }

        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        for(int i = 0; i < arr.size(); ++i){
            int count = count_bits(arr[i]);
            pq.push({count, arr[i]});
        }

        int index = 0;

        while(!pq.empty()){
            auto p = pq.top();
            arr[index] = p.second;
            index++;
            pq.pop();
        }

        return arr;
    }
};
