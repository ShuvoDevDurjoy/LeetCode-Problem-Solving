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

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> nums ; 
        levelTraverse(root , 0 , nums) ; 
        // for(int i = 0 ; i < nums.size() ; ++i){
        //     cout<<"level : "<<i+1<<endl;
        //     for(int j = 0 ; j < nums[i].size() ; ++j)
        //     {
        //         cout<<nums[i][j]<<" " ; 
        //     }
        //     cout<<endl;
        // }
        return nums ; 
    }
};
