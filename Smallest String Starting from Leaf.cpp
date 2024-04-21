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
    string smallestString ; 
    void DFS(TreeNode *root , string current){
        if(root==NULL) 
        {
            return ; 
        }
        current = char(root->val+'a') + current ; 
        if(root->left==NULL && root->right==NULL)
        {
            if(smallestString =="" || current < smallestString)
            {
                smallestString = current ; 
            }
            return ; 
        }
        if(root->left) DFS(root->left,current) ; 
        if(root->right) DFS(root->right,current) ; 
    }
    string smallestFromLeaf(TreeNode* root) {
        DFS(root,"") ; 
        return smallestString ;  
    }
};
