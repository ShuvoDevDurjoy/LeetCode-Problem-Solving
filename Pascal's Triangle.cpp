class Solution {
public:
    vector<vector<int>> generate(int row)
{
    vector<vector<int>> ans = {{1}} ; 
    if(row==1) return ans ; 
    for(int i = 1 ; i < row ; ++i){
        ans.push_back({1}) ; 
        for(int j = 0 ; j < i-1 ; ++j){
            ans[i].push_back(ans[i-1][j]+ans[i-1][j+1]) ;
        }
        ans[i].push_back(1) ;
    }
    return ans ; 
}
};
