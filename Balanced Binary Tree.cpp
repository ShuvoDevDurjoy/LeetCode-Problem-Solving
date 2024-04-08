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
    bool check = true ; 
    int checking(TreeNode *root){
        if(check)
        {
        if(root==NULL) return 0 ; 
        else if(root->left==NULL && root->right==NULL) return 1 ; 
        else {
            int left = 1+checking(root->left) ; 
            int right = 1+checking(root->right) ; 
            cout<<"root val : "<<root->val<<endl;
            cout<<"Here left is : "<<left <<endl; 
            cout<<"here right is : "<<right<<endl<<endl;
            if(abs(left-right)>1) check = false ; 
            return max(left,right) ; 
        }
        }
        return 0 ; 
    }
    bool isBalanced(TreeNode* root) {
        checking(root) ; 
        return check ; 
    }
};
