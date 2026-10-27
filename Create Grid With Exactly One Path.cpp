class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> result;
        string s;
        for(int i = 0; i < n; ++i) s += '#';
        for(int i = 0; i < m; ++i){
            result.push_back(s);
            result[i][0] = '.';
            if(i == (m - 1)){
                for(int x = 1; x < n; ++x){
                    result[i][x] = '.';
                }
            }
        }
        return result;
    }
};
