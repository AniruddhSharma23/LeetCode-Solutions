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
    TreeNode *solve(vector<int> &nums, int start, int end)
    {
        if (start > end)
            return NULL;
        int rv = INT_MIN;
        int i;
        for (int j = start; j <= end; j++)
            if (nums[j] > rv)
            {
                rv = nums[j];
                i = j;
            }
        TreeNode *t = new TreeNode(rv);
        t->left = solve(nums, start, i - 1);
        t->right = solve(nums, i + 1, end);
        return t;
    }
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        int n = nums.size();
        return solve(nums, 0, n - 1);
    }
};