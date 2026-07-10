class Solution {
private: 
    vector<int> parent, rank;
    int size = 0;
    void init(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i = 0; i < n; ++i){
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int i){
        int p = parent[i];
        if(p == i) return p;
        return find(p);
    }

    void make_union(int i, int j){
        int p1 = find(i);
        int p2 = find(j);
        if(p1==p2) return;
        if(rank[p1] >= rank[p2]){
            parent[p2] = p1;
            if(rank[p1]==rank[p2]){
                rank[p1]++;
            }
        }
        else{
            parent[p1] = p2;
        }
    }


public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        size = n;
        
        init(n);

        priority_queue<pair<int,int>> pq;
        for(int i = 0; i < n; ++i){
            pq.push({nums[i], i});
        }

        pair<int,int> temp = pq.top();
        while(!pq.empty()){
            pair<int,int> curr = pq.top();
            pq.pop();

            if(abs(temp.first - curr.first) <= maxDiff){
                make_union(temp.second, curr.second);
            }
            temp = curr;
        }
        
        size = queries.size();
        vector<bool> result(size);
        for(int i = 0; i < size; ++i){
            int a = queries[i][0];
            int b = queries[i][1];

            result[i] = (find(a)==find(b));
        }

        return result;


    }
};
