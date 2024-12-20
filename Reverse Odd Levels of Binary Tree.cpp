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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<deque<TreeNode*>> queues;
        if(!root->left){
            return root ; 
        }
        queues.push({root->left,root->right});
        deque<TreeNode*> front ; 
        while(!queues.empty()){
            front = queues.front();
            queues.pop(); 
            deque<TreeNode*> temp ; 
            while(!front.empty()){
                TreeNode* node1 = front.front();
                front.pop_front();
                TreeNode* node2 = front.front();
                front.pop_front();
                node1->val += node2->val ; 
                node2->val = node1->val - node2->val;
                node1->val = node1->val - node2->val ; 
                if(node1->left && node1->left->left){
                    temp.push_back(node1->left->left) ; 
                    temp.push_back(node2->right->right) ; 

                    temp.push_back(node1->left->right) ; 
                    temp.push_back(node2->right->left) ; 

                    temp.push_back(node1->right->left) ; 
                    temp.push_back(node2->left->right) ; 

                    temp.push_back(node1->right->right) ; 
                    temp.push_back(node2->left->left) ; 
                }
            }
            if(!temp.empty())
                queues.push(temp);
        }
        return root;
    }
};
