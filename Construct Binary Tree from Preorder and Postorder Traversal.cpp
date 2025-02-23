/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int,int> preMaps;
        unordered_map<int,int> postMaps;
        int size = preorder.size();
        for(int i = 0 ; i < size ; ++i){
            preMaps[preorder[i]] = i;
            postMaps[postorder[i]] = i;
        }

        unordered_map<int,bool> visited;
        TreeNode *node = new TreeNode(preorder[0]);
        queue<TreeNode *> q ;
        q.push(node);
        visited[preorder[0]] = true;
        TreeNode *t;
        while(!q.empty()){
            t = q.front();
            q.pop();
            if(preMaps[t->val]+1<size && !visited[preorder[preMaps[t->val]+1]]){
                t->left = new TreeNode(preorder[preMaps[t->val]+1]);
                visited[preorder[preMaps[t->val]+1]] = true;
                q.push(t->left);
            }

            if(postMaps[t->val]-1>=0 && !visited[postorder[postMaps[t->val]-1]]){
                t->right = new TreeNode(postorder[postMaps[t->val]-1]);
                visited[postorder[postMaps[t->val]-1]] = true;
                q.push(t->right);
            }
        }

        return node;
    }
};
