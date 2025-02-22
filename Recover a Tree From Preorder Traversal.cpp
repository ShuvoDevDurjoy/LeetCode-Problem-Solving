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
    void solve(TreeNode *t, queue<pair<int,int>> &q, int index){
        if(q.empty()) return ;
        if(q.front().first!=index) return;

        t->left = new TreeNode(q.front().second);
        q.pop();
        solve(t->left, q, index+1);

        if(q.empty()) return ;
        if(q.front().first!=index) return;
        t->right = new TreeNode(q.front().second);
        q.pop();
        solve(t->right, q, index+1);
    }
    TreeNode* recoverFromPreorder(string traversal) {
        queue<pair<int,int>> q;
        int size = traversal.size();
        int sum = 0;
        int n = 0;
        for(int i = 0 ; i < size ; ++i){
            // cout<<sum<<endl;
            if(traversal[i]=='-'){
                if(sum!=0){
                    q.push({n,sum});
                    sum = 0 ; 
                    n = 0;
                }
                n++;
            }
            else{
                sum = sum*10+(traversal[i]-'0');
            }
        }
        q.push({n,sum});

        TreeNode *t = new TreeNode(q.front().second);
        q.pop();

        solve(t,q,1);
        return t;
    }
};
