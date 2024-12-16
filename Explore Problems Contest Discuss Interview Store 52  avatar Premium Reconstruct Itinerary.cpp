class Solution {
public:
    void DFS(unordered_map< string, priority_queue<string,vector<string>, greater<string> > > &maps,vector<string> &result, string index){
        while(!maps[index].empty()){
            string next = maps[index].top();
            maps[index].pop();
            DFS(maps,result,next);
        }
        result.push_back(index);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,int> in ; 
        unordered_map<string,int> out ; 
        unordered_map< string, priority_queue<string, vector<string>, greater<string>> > maps ; 
        int size = tickets.size() ; 
        for(int i = 0 ; i < size ; ++i){
            maps[tickets[i][0]].push(tickets[i][1]);
        }
        string startingIndex = "JFK";
        vector<string> result;;

        DFS(maps,result,startingIndex);
        reverse(result.begin(),result.end());
        return result;
        

    }
};
