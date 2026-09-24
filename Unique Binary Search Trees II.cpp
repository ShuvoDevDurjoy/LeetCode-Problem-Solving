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
private: 
    vector<TreeNode*> generate(vector<vector<vector<TreeNode*>>> &nmap, int s, int e){
        if(s>e) return {};
        else if(s==e){
            return {new TreeNode(s + 1)};
        }
        if(nmap[s][e].size() != 0){
            return nmap[s][e];
        }
        vector<TreeNode*> result;
        for(int i = s; i <= e; ++i){
            vector<TreeNode*> left = generate(nmap, s, i - 1);
            vector<TreeNode*> right = generate(nmap, i + 1, e);
            if(left.size() && right.size()){
                for(TreeNode* l: left){
                    for(TreeNode* r: right){
                        TreeNode* node = new TreeNode(i + 1);
                        node->left = l;
                        node->right = r;
                        result.push_back(node);
                    }
                }
            }
            else if(left.size()){
                for(TreeNode* l: left){
                    TreeNode* node = new TreeNode(i + 1);
                    node->left = l;
                    node->right = nullptr;
                    result.push_back(node);
                }
            }
            else if(right.size()){
                for(TreeNode* r: right){
                    TreeNode* node = new TreeNode(i + 1);
                    node->right = r;
                    node->left = nullptr;
                    result.push_back(node);
                }
            }
        }
        nmap[s][e] = result;
        return nmap[s][e];
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<vector<TreeNode*>>> dp(n, vector<vector<TreeNode*>>(n));
        return generate(dp, 0, n -1 );
    }
};
