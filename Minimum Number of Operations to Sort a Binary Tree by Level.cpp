class Solution {
public:
    void BFS(vector<vector<int>>& levelValues, vector<unordered_map<int,int>> &maps, TreeNode *root) {
        if (!root) return;
        
        queue<TreeNode*> q;
        int mapIndex = 0 ; 
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;
            maps.push_back({});
            
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = q.front();
                q.pop();
                
                currentLevel.push_back(currentNode->val);
                maps[mapIndex][currentNode->val] = i ; 
                
                if (currentNode->left) {
                    q.push(currentNode->left);
                }
                if (currentNode->right) {
                    q.push(currentNode->right);
                }
            }
            mapIndex++;
            levelValues.push_back(currentLevel);
        }
    }



    int minimumOperations(TreeNode* root) {
        vector<vector<int>> levelValues;
        vector<unordered_map<int,int>> maps ; 
        BFS(levelValues, maps, root);
        
        int size = levelValues.size();
        int levelsize = 0 ; 
        int count = 0 ; 
        for(int i = 0 ; i < size ; ++i){
            levelsize = levelValues[i].size();
            int tempCount = 0 ;
            vector<int> tempVec = levelValues[i] ;
            sort(tempVec.begin(),tempVec.end()) ;  
            for(int j = 0 ; j < levelsize ; ++j){
                if(levelValues[i][j]!=tempVec[j]){
                    levelValues[i][maps[i][tempVec[j]]] = levelValues[i][j]; 
                    maps[i][levelValues[i][j]] = maps[i][tempVec[j]] ; 
                    ++count ; 
                }
            }
        }
        
        return count;
    }
};
