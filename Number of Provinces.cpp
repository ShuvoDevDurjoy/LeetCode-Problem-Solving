class Solution {
public:
    int size = 0 ; 

    void finding(vector<vector<int>> &connection ,vector<bool> &visited ,  int index )
    {
        if(visited[index] == false)
        {
            cout<<"Here index is : "<<index<<endl;
            size++ ; 
            visited[index] = true ; 
        }
        for(int i = 0 ; i < connection.size() ; ++i){
            if(connection[index][i] == 1){
                if(visited[i]==false) {
                // cout<<"Here is : "<<index <<" "<<i<<endl;
                    visited[i] = true ; 
                    finding(connection , visited , i) ; 
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(),false) ;
        for(int i = 0 ; i < isConnected.size() ; i++) 
        finding(isConnected , visited , i) ; 
        return size ;
    }
};
