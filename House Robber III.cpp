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
private: 
    pair<int,int> solve(TreeNode* root){
        if(!root) return {0, 0};
        auto [l1, l2] = solve(root->left);
        auto [r1, r2] = solve(root->right);
        int take = root->val + l2 + r2;
        int dtake = l1 + r1;
        return {max(take, dtake), dtake};
    }
public:
    int rob(TreeNode* root) {
        auto [a, b] = solve(root);
        return max(a, b);
    }
};
