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
    int depth(TreeNode *root , int m){
        if(root==NULL){
            return m ; 
        }
        int left = m +1 ; 
        int right = m + 1 ; 
        left = depth(root->left,left) ; 
        right = depth(root->right,right) ; 
        return max(left,right) ; 
    }
    int maxDepth(TreeNode* root) {
        return depth(root , 0) ; 
    }
};
