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
    bool flipEquiv(TreeNode *a, TreeNode *b)
    {
        if (a == NULL && b == NULL)
            return true;
        if ((a == NULL && b != NULL) || (a != NULL && b == NULL) || (a->val != b->val))
            return false;
        return ((a->val == b->val) && ((flipEquiv(a->left, b->left) && flipEquiv(a->right, b->right)) || (flipEquiv(a->left, b->right) && flipEquiv(a->right, b->left))));
    }
};

// BFS: Iterative

class Solution
{
public:
    bool isSame(TreeNode *a, TreeNode *b)
    {
        if (a == NULL && b == NULL)
            return true;
        else if (a == NULL || b == NULL || a->val != b->val)
            return false;
        return true;
    }
    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        queue<TreeNode *> q;
        q.push(root1);
        q.push(root2);
        while (!q.empty())
        {
            TreeNode *a = q.front();
            q.pop();
            TreeNode *b = q.front();
            q.pop();
            if (a == NULL && b == NULL)
                continue;
            else if (a == NULL || b == NULL || a->val != b->val)
                return false;
            else if (isSame(a->left, b->left) && isSame(a->right, b->right))
            {
                q.push(a->left);
                q.push(b->left);
                q.push(a->right);
                q.push(b->right);
            }
            else if (isSame(a->left, b->right) && isSame(a->right, b->left))
            {
                q.push(a->left);
                q.push(b->right);
                q.push(a->right);
                q.push(b->left);
            }
            else
                return false;
        }
        return true;
    }
};