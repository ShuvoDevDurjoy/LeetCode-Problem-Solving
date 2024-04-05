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

    void findingSum(TreeNode *root , int index , vector<int> &nums){
        if(root==NULL) return ; 
        if(index >= nums.size()) nums.push_back(0) ; 
        nums[index] += root->val ; 
        findingSum(root->left , index+1 , nums) ; 
        findingSum(root->right , index+1 , nums) ;  
    }
    int maxLevelSum(TreeNode* root) {
        vector<int> nums ; 
        findingSum(root , 0 , nums) ; 
        int maximum = INT_MIN ; 
        int maxindex = 0 ; 
        for(int i = nums.size()-1 ; i>=0 ; --i)
        {
            if(nums[i] >= maximum)
            {
                maxindex = i ;
                maximum = nums[i] ;  
            }
        }
        return maxindex+1 ; 
    }
};
