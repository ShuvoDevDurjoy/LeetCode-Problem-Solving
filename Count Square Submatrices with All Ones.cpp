class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
       int rowsize = matrix.size();
       int columnsize = matrix[0].size() ; 
       for(int i = 0 ; i < rowsize ; ++i){
        for(int j = 0 ; j < columnsize ; ++j){
                if(i==0 || j==0) continue; 
                else if(matrix[i][j]==1){
                    matrix[i][j] = min({matrix[i][j-1],matrix[i-1][j],matrix[i-1][j-1]})+1;
                }
            }
        }
        
        int sum  = 0 ; 
       for(int i = 0 ; i < rowsize ; ++i){
        for(int j = 0 ; j < columnsize ; ++j){
            cout<<matrix[i][j]<<" ";
            sum+=matrix[i][j] ; 
        }
        cout<<endl;
       }
       return sum ; 
    }
};
