class Solution {
public:
    int maximumSum = 0 ;
    int y = 0 ;  
    int dfs(vector<vector<int>> &track, int k){
        int sum = 0 ; 
        for(int i = 1 ; i < track[k].size() ; ++i){
            int x = dfs(track,track[k][i]);
            if(x!=0){
                track[k][0]+=track[k][i];
            }
        }
        if(sum>maximumSum){
            maximumSum = sum ; 
        }
        if(track[k][0]%y==0){
            return 0;
        }
        return sum ; 
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> track(n) ; 
        y = k ; 
        for(int i = 0 ; i < n ; ++i){
            track[i].push_back(values[i]);
        }

        for(int i = 0 ; i < n-1 ; ++i){
            track[edges[i][0]].push_back(edges[i][1]);
        }

        dfs(track,0);
        return maximumSum;
    }
};
