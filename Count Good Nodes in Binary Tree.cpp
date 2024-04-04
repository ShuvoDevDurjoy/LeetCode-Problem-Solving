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

    void goodNodeCounter(TreeNode *root , int largest , int &counter){
        if(root->left==NULL && root->right==NULL){
            if(root->val>=largest)
            counter++ ; 
            return ; 
        }

        if(root->val>=largest)
        {
            counter++ ; 
            largest = root->val ; 
        }

        if(root->left!=NULL) goodNodeCounter(root->left,largest,counter) ; 
        if(root->right!=NULL) goodNodeCounter(root->right,largest,counter) ; 
    }
    int goodNodes(TreeNode* root) {
        int counter = 0 ; 
        goodNodeCounter(root , root->val , counter) ; 
        return counter ; 
    }
};
