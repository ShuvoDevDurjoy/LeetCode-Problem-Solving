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
    int minimum = INT_MAX ; 
    // int findingMin(TreeNode *root){
    //     if(root == NULL) return 0 ; 
    //     int l = 1+findingMin(root->left ) ; 
    //     int r = 1+findingMin(root->right) ; 
    //     int m = min(l,r) ; 
    //     minimum = min(minimum , m) ;
    // }
    int minDepth(TreeNode* root) {
        if (root==NULL) return 0 ; 
        else{
            if(root->left==NULL && root->right==NULL) return 1 ; 
            else if(root->left==NULL) return minDepth(root->right)+1 ; 
            else if(root->right==NULL) return minDepth(root->left)+1 ; 
            else return min(minDepth(root->left) , minDepth(root->right))+1 ; 
        }
    }
};
