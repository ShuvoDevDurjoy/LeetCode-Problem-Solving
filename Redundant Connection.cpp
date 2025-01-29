class Solution{
    public : 
        int size ;

        vector<int> parent, rank ; 

        void make(){
            parent.resize(size,0);
            rank.resize(size,0);
            for(int i = 0 ; i < size ; ++i){
                parent[i] = i ; 
            }
        }

        int find(int x){
            if(parent[x]!=x){
                parent[x] = find(parent[x]);
            }

            return parent[x];
        }

        bool makeUnion(int x, int y){
            int rootX = find(x);
            int rootY = find(y);
            if(rootX != rootY){
                if(rank[rootX]>rank[rootY]){
                    parent[rootY] = parent[rootX];
                }
                else if(rank[rootX]<rank[rootY]){
                    parent[rootX] = parent[rootY];
                }
                else{
                    parent[rootY] = parent[rootX];
                    rank[rootX]++;
                }
                return true;
            }
            else{
                return false;
            }
        }

        vector<int> findRedundantConnection(vector<vector<int>>& edges) {
            size = edges.size()+1;

            make();
            vector<int> result(2);
            for(int i = 0 ; i < size-1 ; ++i){
                if(!makeUnion(edges[i][0],edges[i][1])){
                    result[0] = edges[i][0];
                    result[1] = edges[i][1];
                }
            }

        return result;

        }

};
