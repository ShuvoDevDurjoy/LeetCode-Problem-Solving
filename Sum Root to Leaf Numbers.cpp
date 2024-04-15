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
    int findingSum(TreeNode *root, int sum)
    {
        if(root==NULL) return 0 ; 
        if(root->left==NULL && root->right==NULL) return sum*10+root->val ; 
        else {
            sum = sum*10+root->val ; 
            return findingSum(root->left,sum)+findingSum(root->right , sum) ; 
        }
    }
    int sumNumbers(TreeNode* root) {
        return findingSum(root , 0) ; 
    }
};
