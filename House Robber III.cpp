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
    int rob(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int val = 0;
        if (root->left != NULL)
            val += rob(root->left->left) + rob(root->left->right);
        if (root->right != NULL)
            val += rob(root->right->left) + rob(root->right->right);
        int notrob = rob(root->left) + rob(root->right);
        int rob = val + root->val;
        return max(notrob, rob);
    }
};

// dp:

class Solution
{
public:
    unordered_map<TreeNode *, int> mp;
    int rob(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        if (mp.find(root) != mp.end())
            return mp[root];
        mp[root] = -1;
        int x = rob(root->left) + rob(root->right);
        int y = root->val;
        if (root->left != NULL)
            y += rob(root->left->left) + rob(root->left->right);
        if (root->right != NULL)
            y += rob(root->right->left) + rob(root->right->right);
        mp[root] = max(x, y);
        return mp[root];
    }
};

// space optimized:

class Solution
{
public:
    unordered_map<TreeNode *, int> mp;
    int rob(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        auto ans = dfs(root);
        return max(ans.first, ans.second);
    }
    pair<int, int> dfs(TreeNode *root)
    {
        if (root == NULL)
            return {0, 0};
        auto [leftnotrob, leftrob] = dfs(root->left);
        auto [rightnotrob, rightrob] = dfs(root->right);
        int notrob = max(leftnotrob, leftrob) + max(rightnotrob, rightrob);
        int rob = root->val + leftnotrob + rightnotrob;
        return {notrob, rob};
    }
};
// {notrob, rob}