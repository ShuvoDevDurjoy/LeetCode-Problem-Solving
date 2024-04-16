class Solution {
public:
    vector<int> getRow(int row) {
        row = row+1 ; 
        vector<int> ans(row , 1) ;  
    ans[0] = 1 ; 
    if(row==1) return ans ; 
    for(int i = 2 ; i < row ; ++i){
        int temp = ans[0] ; 
        for(int j = 1 ; j < i ; ++j){
            int temp1 = ans[j] ; 
            ans[j] = temp+ans[j] ; 
            temp = temp1 ; 
        }
    }
    return ans ; 
    }
};
