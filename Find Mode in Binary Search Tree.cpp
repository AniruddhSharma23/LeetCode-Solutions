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
    void store(TreeNode *root, unordered_map<int, int> &mp)
    {
        if (root != NULL)
        {
            mp[root->val]++;
            store(root->left, mp);
            store(root->right, mp);
        }
    }
    vector<int> findMode(TreeNode *root)
    {
        vector<int> v;
        unordered_map<int, int> mp;
        store(root, mp);
        int m = 0;
        for (auto x : mp)
        {
            m = max(m, x.second);
        }
        for (auto x : mp)
        {
            if (x.second == m)
                v.push_back(x.first);
        }
        return v;
    }
};