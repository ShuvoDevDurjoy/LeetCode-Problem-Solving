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
    const long long MOD = 1e9 + 7;  
    long long total = 0;
    long long ans = 0;

    int dfsTraversal(TreeNode* root){
        if(root == nullptr) return 0;
        root->val += ((dfsTraversal(root->left)) + (dfsTraversal(root->right)));
        return root->val;
    }

    void dfsFindMax(TreeNode* root){
        if(root == nullptr) return;

        long long cur_ans = (total - root->val) * root->val;
        if(cur_ans > ans){
            ans = cur_ans;
        }

        dfsFindMax(root->left);
        dfsFindMax(root->right);
        
    }
    int maxProduct(TreeNode* root) {
        int rootvalue = dfsTraversal(root);
        total = rootvalue;
        cout<<rootvalue<<endl;
        dfsFindMax(root);
        return ans % MOD;
    }
};
