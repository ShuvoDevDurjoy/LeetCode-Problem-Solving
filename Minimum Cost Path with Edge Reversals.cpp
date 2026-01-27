class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> nodes(n);
        
        for(int i = 0; i < edges.size(); ++i){
            nodes[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            nodes[edges[i][1]].push_back({edges[i][0], edges[i][2] * 2});
        }

        // for(int i = 0; i < n; ++i){
        //     cout<<"For node "<<i<<endl;
        //     for(int j = 0; j < nodes[i].size(); ++j){
        //         cout<<nodes[i][j].first<<", "<<nodes[i][j].second<<endl;
        //     }
        //     cout<<endl;
        // }

        vector<int> dist(n, INT_MAX);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        pq.push({0, 0});
        dist[0] = 0;

        while(!pq.empty()){
            pair<int,int> top = pq.top();
            pq.pop();

            if(top.second == n-1) return top.first;

            if(top.first > dist[top.second]) continue;

            for(auto g: nodes[top.second]){
                 if(dist[top.second] + g.second < dist[g.first]){
                    dist[g.first] = dist[top.second] + g.second;
                    pq.push({dist[g.first], g.first});
                }
            }
        }

        return -1;
    }
};
