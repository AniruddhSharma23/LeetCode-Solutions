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
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> v;
        unordered_map<int, int> mp;
        store(root1, mp);
        store(root2, mp);
        for (auto x : mp)
        {
            while (x.second--)
                v.push_back(x.first);
        }
        sort(v.begin(), v.end());
        return v;
    }
};