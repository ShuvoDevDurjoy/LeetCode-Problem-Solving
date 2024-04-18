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
    void build(TreeNode *root , int val , int depth)
    {
        if(root==NULL) return ; 
        else {
            if(depth==1){
                TreeNode *nodeleft = new TreeNode(val,root->left,NULL) ; 
                TreeNode *noderight = new TreeNode(val,NULL , root->right) ;
                root->left = nodeleft ; 
                root->right = noderight ; 
                return ;  
            }
            else {
                build(root->left , val , depth-1 ) ; 
                build(root->right , val , depth-1) ; 
            }
        }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root==NULL) return nullptr ; 
        else if(depth==1){
            TreeNode *node = new TreeNode(val,root,nullptr) ; 
            return node ; 
        }
        else {
            build(root,val,depth-1) ;
            return root ;  
        }
    }
};
