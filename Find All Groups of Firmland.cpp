class Solution {
public:
void DFS(vector<vector<int>> &grid ,vector<vector<int>> &coordinates , int i , int j , int index )
{
    if(i<0 || i>=grid.size() ||j<0 || j>=grid[0].size())
    {
        return ; 
    }
    if(grid[i][j]==0) return ; 
    grid[i][j]=0 ; 
    if(i>=coordinates[index][2] && j >= coordinates[index][3] )
    {
        coordinates[index][2] = i ; 
        coordinates[index][3] = j ;
    }
    DFS(grid,coordinates,i,j+1,index) ; 
    DFS(grid,coordinates,i,j-1,index) ; 
    DFS(grid,coordinates,i+1,j,index) ; 
    DFS(grid,coordinates,i-1,j,index) ; 
}
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> coordinates ; 
    int size = 0 ; 
    for(int i = 0 ; i < land.size() ; ++i)
    {
        for(int j = 0 ; j < land[0].size() ; ++j)
        {
            if(land[i][j]==1)
            {
                coordinates.push_back({i,j,0,0}) ; 
                DFS(land,coordinates,i,j,size++);
            }
        }
    }   
    return coordinates ;
    }
};
