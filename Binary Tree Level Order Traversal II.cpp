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
    void BottomUp(TreeNode *node , int index , vector<vector<int>> &nums){
    if(node==NULL) return ; 
    if(index>=nums.size()) nums.push_back({});
    nums[index].push_back(node->val);
    BottomUp(node->left, index+1, nums);
    BottomUp(node->right , index+1 , nums) ; 
}
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> nums ; 
    BottomUp(root,0,nums) ; 
    reverse(nums.begin(),nums.end());
    return nums ; 
    }
};
