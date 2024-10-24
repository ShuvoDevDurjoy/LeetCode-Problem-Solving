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
class Solution
{
public:
    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        queue<TreeNode *> nodes1;
        queue<TreeNode *> nodes2;
        nodes1.push(root1);
        nodes2.push(root2);
        if (root1 == nullptr && root2 == nullptr)
            return true;
        else if (root1 == nullptr && root2 != nullptr)
            return false;
        else if (root1 != nullptr && root2 == nullptr)
            return false;
        if (root1->val != root2->val)
            return false;
        while (!nodes1.empty() && !nodes2.empty())
        {
            if ((nodes1.front()->left && nodes2.front()->left) && (nodes1.front()->right && nodes2.front()->right))
            {
                if ((nodes1.front()->left->val == nodes2.front()->left->val) && (nodes1.front()->right->val == nodes2.front()->right->val))
                {
                    if (nodes1.front()->left)
                        nodes1.push(nodes1.front()->left);
                    if (nodes1.front()->right)
                        nodes1.push(nodes1.front()->right);
                    if (nodes2.front()->left)
                        nodes2.push(nodes2.front()->left);
                    if (nodes2.front()->right)
                        nodes2.push(nodes2.front()->right);
                    nodes1.pop();
                    nodes2.pop();
                }
                else if ((nodes1.front()->left->val == nodes2.front()->right->val) && (nodes1.front()->right->val == nodes2.front()->left->val))
                {
                    if (nodes1.front()->left)
                        nodes1.push(nodes1.front()->left);
                    if (nodes1.front()->right)
                        nodes1.push(nodes1.front()->right);
                    if (nodes2.front()->right)
                        nodes2.push(nodes2.front()->right);
                    if (nodes2.front()->left)
                        nodes2.push(nodes2.front()->left);
                    nodes1.pop();
                    nodes2.pop();
                }
                else
                {
                    return false;
                }
            }
            else if ((nodes1.front()->left == nullptr && nodes2.front()->right == nullptr && (nodes1.front()->right && nodes2.front()->left)))
            {
                if (nodes1.front()->right->val == nodes2.front()->left->val)
                {
                    if (nodes1.front()->left)
                        nodes1.push(nodes1.front()->left);
                    if (nodes1.front()->right)
                        nodes1.push(nodes1.front()->right);
                    if (nodes2.front()->right)
                        nodes2.push(nodes2.front()->right);
                    if (nodes2.front()->left)
                        nodes2.push(nodes2.front()->left);
                    nodes1.pop();
                    nodes2.pop();
                }
                else
                {
                    return false;
                }
            }
            else if ((nodes1.front()->right == nullptr && nodes2.front()->left == nullptr) && (nodes1.front()->left && nodes2.front()->right))
            {
                if (nodes1.front()->left->val == nodes2.front()->right->val)
                {
                    if (nodes1.front()->left)
                        nodes1.push(nodes1.front()->left);
                    if (nodes1.front()->right)
                        nodes1.push(nodes1.front()->right);
                    if (nodes2.front()->right)
                        nodes2.push(nodes2.front()->right);
                    if (nodes2.front()->left)
                        nodes2.push(nodes2.front()->left);
                    nodes1.pop();
                    nodes2.pop();
                }
                else
                {
                    return false;
                }
            }
            else if ((nodes1.front()->left == nullptr && nodes1.front()->right == nullptr) && (nodes2.front()->left == nullptr && nodes2.front()->right == nullptr))
            {
                nodes1.pop();
                nodes2.pop();
                continue;
            }
            else if ((nodes1.front()->left && nodes2.front()->left) && (!nodes1.front()->right && !nodes2.front()->right))
            {
                if (nodes1.front()->left->val == nodes2.front()->left->val)
                {
                    nodes1.push(nodes1.front()->left);
                    nodes2.push(nodes2.front()->left);
                    nodes1.pop();
                    nodes2.pop();
                }
                else
                {
                    return false;
                }
            }
            else if ((nodes1.front()->right && nodes2.front()->right) && (!nodes1.front()->left && !nodes2.front()->left))
            {
                if (nodes1.front()->right->val == nodes2.front()->right->val)
                {
                    nodes1.push(nodes1.front()->right);
                    nodes2.push(nodes2.front()->right);
                    nodes1.pop();
                    nodes2.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                cout << "returning false from here" << endl;
                if (nodes1.front()->left)
                    cout << "LEft" << endl;
                if (nodes1.front()->right)
                    cout << "node1 right" << endl;
                if (nodes2.front()->left)
                    cout << "node2 left" << endl;
                if (nodes2.front()->right)
                    cout << "node2 right" << endl;
                return false;
            }
        }
        if (nodes1.empty() && !nodes2.empty())
        {
            return false;
        }
        else if (!nodes1.empty() && nodes2.empty())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};
