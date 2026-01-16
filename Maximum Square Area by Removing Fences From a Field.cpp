class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        int prevSum = 0;
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        hFences.push_back(m);
        vFences.push_back(n);
        int prev = hFences[0] - 1;
        unordered_map<int,int> maps;
        int maxSide = -1;
        prev = 1;
        for(int i = 0; i < hFences.size(); ++i){
            for(int j = i ; j < hFences.size(); ++j){
                maps[hFences[j] - prev] = 1;
            }
            prev = hFences[i];
        }

        prev = 1;
        for(int i = 0; i < vFences.size(); ++i){
            for(int j = i; j < vFences.size(); ++j){
                if(maps[vFences[j] - prev]){
                    maxSide = max(maxSide, vFences[j] - prev);
                }
            }
            prev = vFences[i];
        }
        long long MOD = 1e9 + 7;
        return maxSide == -1? -1: ((maxSide % MOD) * (maxSide % MOD)) % MOD;
    }
};
