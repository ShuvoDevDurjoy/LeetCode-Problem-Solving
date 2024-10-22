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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<int> levels;
        vector<long long> levelSum ; 
        queue<TreeNode*> nodes ; 
        nodes.push(root);
        levels.push(1);
        int size = 0;
        while(!nodes.empty()){
            if(size<levels.front()){
                levelSum.push_back(nodes.front()->val);
                size++;
            }else{
                levelSum[levels.front()-1]+=nodes.front()->val;
            }

            if(nodes.front()->left){
                nodes.push(nodes.front()->left);
                levels.push(levels.front()+1);
            }
            if(nodes.front()->right){
                nodes.push(nodes.front()->right);
                levels.push(levels.front()+1);
            }
            levels.pop();
            nodes.pop();
        }

        if(k>size) return -1;
        sort(levelSum.begin(),levelSum.end());
        return levelSum[size-k];
    }
};
