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
    int maxindex = 0 ; 
    void findingView(TreeNode *root , int index , vector<int> &nums) {
        if(root==NULL) return ; 
        if(root->right) { 
            if(index > maxindex) {
                nums.push_back(root->right->val) ; 
                maxindex = max(maxindex , index ) ;  
                findingView(root->right , index+1 , nums ) ;
            }
            else {
                findingView(root->right , index+1 , nums) ; 
            }
        }
        if(root->left)
        {
            cout<<"here max index is : "<<maxindex<<endl;
            cout<<"Here value is : "<<root->left->val<<endl<<endl;
            if(index>maxindex){
                nums.push_back(root->left->val) ; 
                maxindex = max(maxindex , index) ; 
                findingView(root->left , index+1 , nums) ; 
            }
            else {
                findingView(root->left , index+1 , nums ) ; 
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> nums ; 
        if(root==NULL) return nums ; 
        nums.push_back(root->val); 
        findingView(root , 1 , nums) ; 
        return nums ; 
    }
};
