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
    void levelTraverse(TreeNode *root , int index , vector<vector<int>> &levels)
    {
        if(root==NULL) return ; 
        if(index==levels.size())
        {
            levels.push_back({}) ; 
        }
        levels[index].push_back(root->val) ; 
        levelTraverse(root->left , index+1 , levels) ; 
        levelTraverse(root->right , index+1 , levels) ; 
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> nums ; 
        levelTraverse(root , 0 , nums) ; 
        for(int i = 1 ; i < nums.size() ; ++i){
            if(i%2==1)
            {
                reverse(nums[i].begin(),nums[i].end()) ; 
            }
        }
        return nums ; 
    }
};
