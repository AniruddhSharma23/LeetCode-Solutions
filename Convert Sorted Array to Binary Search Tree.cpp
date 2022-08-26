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
    TreeNode *convertBST(int l, int r, vector<int> &nums)
    {
        if (r < l)
            return nullptr;
        int m = l + (r - l) / 2;
        TreeNode *root = new TreeNode(nums[m]);
        root->left = convertBST(l, m - 1, nums);
        root->right = convertBST(m + 1, r, nums);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        int n = nums.size();
        return convertBST(0, n - 1, nums);
    }
};