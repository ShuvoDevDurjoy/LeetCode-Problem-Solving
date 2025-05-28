class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        // defining adj matrix for two trees
        vector<vector<int>> adj1(edges1.size()+1);
        vector<vector<int>> adj2(edges2.size()+1);

        for(auto &edge: edges1){
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }

        for(auto &edge: edges2){
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }

        vector<int> dp1(edges1.size()+1);
        int maximum = 0;

        for (int i = 0; i <= edges1.size(); ++i) {
            queue<int> q;
            q.push(i);
            int level = 0;
            unordered_map<int, bool> visited;
            int count = 0;
            while (!q.empty() && level <= k) {
                int size = q.size();
                for (int j = 0; j < size; ++j) {
                    int x = q.front();
                    q.pop();
                    if (visited[x] == false) {
                        for(int &d: adj1[x]){
                            q.push(d);
                        }
                        count++;
                    }
                    visited[x] = true;
                }
                level++;
            }
            dp1[i] = count;
        }

        for (int i = 0; i <= edges2.size(); ++i) {
            queue<int> q;
            q.push(i);
            int level = 0;
            unordered_map<int, bool> visited;
            int count = 0;
            while (!q.empty() && level < k) {
                int size = q.size();
                for (int j = 0; j < size; ++j) {
                    int x = q.front();
                    q.pop();
                    if (visited[x] == false) {
                        for(int &d: adj2[x]){
                            q.push(d);
                        }
                        count++;
                    }
                    visited[x] = true;
                }
                level++;
            }
            maximum = max(maximum, count);
        }
        
        vector<int> result(edges1.size()+1);
        for(int i = 0; i < result.size(); ++i){
            result[i] = dp1[i]+maximum;
        }

        return result;
    }
};
