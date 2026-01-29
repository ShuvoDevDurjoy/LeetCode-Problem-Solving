class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int, int>>> g(26);
        vector<vector<long long>> dc(26, vector<long long>(26, INT_MAX));

        for (int i = 0; i < cost.size(); ++i) {
            int index = original[i] - 'a';
            g[index].push_back({changed[i] - 'a', cost[i]});
        }

        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < 26; ++i) {
            pq.push({0, i});
            dc[i][i] = 0;
            while (!pq.empty()) {
                pair<int, int> top = pq.top();
                pq.pop();

                if (top.first > dc[i][top.second])
                    continue;

                for (auto& gt : g[top.second]) {
                    if (top.first + gt.second < dc[i][gt.first]) {
                        dc[i][gt.first] = top.first + gt.second;
                        pq.push({dc[i][gt.first], gt.first});
                    }
                }
            }
        }

        long long totalCost = 0;

        for (int i = 0; i < source.size(); ++i) {
            if (dc[source[i] - 'a'][target[i] - 'a'] != INT_MAX) {
                totalCost += dc[source[i] - 'a'][target[i] - 'a'];
            } else {
                return -1;
            }
        }

        return totalCost;
    }
};
