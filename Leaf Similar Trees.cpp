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
    void traverse(TreeNode *root , vector<int> &nums){
        if(root->left==NULL && root->right==NULL) {
            nums.push_back(root->val) ; 
            return ; 
        }
        if(root->left!=NULL)traverse(root->left,nums) ; 
        if(root->right!=NULL)traverse(root->right,nums) ; 
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> root1_leafs ; 
        vector<int> root2_leafs ; 
        traverse(root1,root1_leafs) ; 
        traverse(root2,root2_leafs) ;
        if(root1_leafs.size() == root2_leafs.size())
        {
            for(int i = 0 ; i < root1_leafs.size() ; ++i){
                if(root1_leafs[i]==root2_leafs[i]) continue ; 
                return false ; 
            }
        }
        else {
            return false ; 
        }

        return true ; 
    }
};
