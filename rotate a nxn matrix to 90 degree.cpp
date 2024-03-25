class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       int size = matrix.size()-1 ; 
    int index = size ; 
    for(int i = 0 ; i <= size ; i++ ){
        for(int j = i ;  j < size ; j++)
        {
            int temp1 = matrix[j][size] ; 
            int temp2 = matrix[size][index-j] ; 
            int temp3 = matrix[index-j][i] ; 
            cout<<"temp1 : " <<temp1<<endl;
            cout<<"temp2 : "<<temp2<<endl;
            cout<<"temp3 : "<<temp3<<endl;
            cout<<endl;
            matrix[j][size] = matrix[i][j] ; 
            matrix[size][index-j] = temp1 ; 
            matrix[index-j][i] = temp2 ; 
            matrix[i][j] = temp3 ;
        }
        size-- ;
    } 
    }
};
