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
    int maximum = 0;
    void ZigZag(TreeNode *root , char c , int depth ){
        if(root==NULL) return  ;

        if(c=='l') {
            ZigZag(root->left , 'r' , depth+1) ; 
        }
        else {
            ZigZag(root->right , 'l' , depth+1) ; 
        }

        if(c=='l')
        {
            ZigZag(root->right , 'l',0) ; 
        }
        else{
            ZigZag(root->left , 'r',0) ; 
        }

        maximum = max(depth+1 , maximum) ; 
        
    }
    int longestZigZag(TreeNode* root) {
         vector<vector<int>> nums ; 
       ZigZag(root->left,'r',0) ; 
       ZigZag(root->right , 'l' , 0) ; 
       return maximum ; 
    }
};
