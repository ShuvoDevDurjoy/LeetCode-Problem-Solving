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
    TreeNode *result = nullptr;
    int maxDepthCount = 0;
    int dfs(TreeNode* root, unordered_map<int,int> &maps, int depth){
        if(root==nullptr) return 0;
        if(result != nullptr) return 0;
        if(!root->left && !root->right){
            if(maps[root->val] == depth && maxDepthCount == 1){
                cout<<root->val<<endl;
                result = root;
            }
            return maps[root->val]==depth;
        }
        
        int val = dfs(root->left, maps, depth) + dfs(root->right, maps, depth);
        if(val == maxDepthCount && result==nullptr){
            result = root;
        }
        return val;

    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        queue<TreeNode*> nodes;
        unordered_map<int, int> maps;
        nodes.push(root);
        int depth = 0;
        int depthCount = 0;
        while(!nodes.empty()){
            depth++;
            int size = nodes.size();
            depthCount = 0;
            for(int i = 0; i < size; ++i){
                depthCount++;
                maps[nodes.front()->val] = depth;
                if(nodes.front()->left){
                    nodes.push(nodes.front()->left);
                }
                if(nodes.front()->right){
                    nodes.push(nodes.front()->right);
                }
                nodes.pop();
            }
        }
        maxDepthCount = depthCount;
        dfs(root, maps, depth);
        return result;
    }
};
