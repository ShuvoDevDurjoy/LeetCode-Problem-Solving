/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
void create(TreeNode *root ,vector<int> &nums, int left , int right){
    if(left<right)
    {
        int mid = (left+right)/2 ; 
        int l = (mid-1+left)/2 ; 
        int r = (mid+1+right)/2 ; 
        if(l<r){
            if(left<=l&&l<mid){
                root->left = new TreeNode(nums[l]) ; 
                create(root->left ,nums, left , mid-1) ; 
            }
            if(mid<r&&r<=right){
                root->right = new TreeNode(nums[r]) ; 
                create(root->right ,nums, mid+1 , right) ; 
            }   
        }
        
    }
}

    

    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) return NULL ; 
        vector<int> nums ; 
        while(head){
            nums.push_back(head->val) ; 
            head = head->next ; 
        }
        int size = nums.size()-1 ; 
    int mid = size/2 ; 
    TreeNode *root = new TreeNode(nums[mid]) ;
    create(root , nums , 0 , size) ;
        return root ; 
    }
};
