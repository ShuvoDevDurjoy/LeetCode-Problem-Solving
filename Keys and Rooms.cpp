class Solution {
public:

    void visiting(vector<vector<int>> &rooms ,vector<bool> &visited , int index){
        if(visited[index]) return; 
        visited[index] = true ; 
        for(int i : rooms[index])
        {
            visiting(rooms , visited , i ) ; 
        }
        
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size() , false) ; 
        visiting(rooms , visited , 0) ; 

        for (bool vis : visited)
        {
            if(vis==false) return false ; 
        }

        return true ; 
    }
};
