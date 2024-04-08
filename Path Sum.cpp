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
    bool check = false ; 
    void findingPath(TreeNode *root , int targetSum){
        if(!check){
            if(root==NULL) return ; 
            else {
                if(targetSum-root->val == 0 && root->left==NULL && root->right==NULL) {
                    check = true ; 
                    return ; 
                }
                findingPath(root->left , targetSum - root->val) ; 
                findingPath(root->right , targetSum - root->val ) ; 
            }
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        findingPath(root , targetSum) ; 
        return check ; 
    }
};
