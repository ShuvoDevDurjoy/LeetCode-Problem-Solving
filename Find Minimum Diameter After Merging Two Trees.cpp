class Solution {
public:
    void createAdjList(vector<vector<int>>& adjList, vector<vector<int>>& edges,
                       int size) {
        for (int i = 0; i < size; ++i) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
    }

    int findFarthestPoint(vector<vector<int>> &adjList, int size){
        queue<int> queue; 
        vector<bool> visited(size,false) ; 
        int farthestPoint = 0; 
        int queueSize = 1 ; 
        queue.push(0) ; 
        visited[0] = true;
        while(!queue.empty()){
            queueSize = queue.size() ; 
            for(int i = 0 ; i < queueSize ; ++i){
                farthestPoint = queue.front() ; 
                queue.pop() ; 
                for(auto &neighbour : adjList[farthestPoint]){
                    if(!visited[neighbour]){
                        visited[neighbour] = true;
                        queue.push(neighbour) ; 
                    }
                }
            }
        }
        return farthestPoint ; 
    }

    int findDiameter(vector<vector<int>> &adjList, int size, int startingPoint){
        queue<int> queue; 
        vector<bool> visited(size,false) ; 
        int farthestPoint = startingPoint; 
        int queueSize = 1 ; 
        queue.push(startingPoint) ; 
        visited[startingPoint] = true;
        int count = 0 ;
        while(!queue.empty()){
            queueSize = queue.size() ; 
            for(int i = 0 ; i < queueSize ; ++i){
                farthestPoint = queue.front() ; 
                queue.pop() ; 
                for(auto &neighbour : adjList[farthestPoint]){
                    if(!visited[neighbour]){
                        visited[neighbour] = true;
                        queue.push(neighbour) ; 
                    }
                }
            }
            if(!queue.empty())++count;
        }
        return count ; 
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,vector<vector<int>>& edges2) {
        int edges1size = edges1.size();
        int edges2size = edges2.size();
        vector<vector<int>> adjList1(edges1size + 1);
        vector<vector<int>> adjList2(edges2size + 1);
        createAdjList(adjList1, edges1, edges1size );
        createAdjList(adjList2, edges2, edges2size );
        int x = findFarthestPoint(adjList1,edges1size+1);
        x = findDiameter(adjList1,edges1size+1,x) ; 
        int y = findFarthestPoint(adjList2,edges2size+1) ; 
        y = findDiameter(adjList2,edges2size+1,y);

        return max({x,y,int(ceil(x/2.0)+ceil(y/2.0)+1)});
    }
};
