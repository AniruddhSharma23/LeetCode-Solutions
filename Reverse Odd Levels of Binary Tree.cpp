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
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return root;
        vector<TreeNode *> q1;
        q1.push_back(root);
        int level = 0;
        while (!q1.empty() && q1[0]->left != NULL)
        {
            vector<TreeNode *> q2;
            for (auto &x : q1)
            {
                q2.push_back(x->left);
                q2.push_back(x->right);
            }
            if (level % 2 == 0)
            {
                int i = 0, j = q2.size() - 1;
                while (i < j)
                {
                    swap(q2[i]->val, q2[j]->val);
                    i++;
                    j--;
                }
            }
            swap(q1, q2);
            level++;
        }
        return root;
    }
};