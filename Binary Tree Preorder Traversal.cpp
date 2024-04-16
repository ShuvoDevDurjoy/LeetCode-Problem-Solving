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
    void traverse(TreeNode *root , vector<int> &nums)
    {
        if(root==NULL) return ; 
        nums.push_back(root->val) ; 
        traverse(root->left,nums) ; 
        traverse(root->right,nums) ; 
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nums ; 
        traverse(root , nums) ; 
        return nums ; 
    }
};
