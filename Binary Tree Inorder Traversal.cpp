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
    void traversal(TreeNode *root , vector<int> &nums){
        if(root!=NULL){
            traversal(root->left,nums) ; 
            nums.push_back(root->val) ; 
            traversal(root->right,nums) ; 
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nums ;
        traversal(root , nums) ; 
        return nums ;  
    }
};
