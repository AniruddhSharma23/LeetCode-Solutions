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
    int countNodes(TreeNode *root)
    {
        int lh, rh;
        lh = rh = 0;
        TreeNode *curr = root;
        while (curr != NULL)
        {
            lh++;
            curr = curr->left;
        }
        curr = root;
        while (curr != NULL)
        {
            rh++;
            curr = curr->right;
        }
        if (lh == rh)
        {
            return pow(2, lh) - 1;
        }
        else
        {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};

/*
for a complete binary tree, if we traverse from root to the leftmost node and count the number of elements
and similary do for the rightmost node, then the height lh will be equal to rh
so if we have a complete binary tree as a subtree then we don't have to traverse the whole tree to find the
number of nodes we can just use the formula 2^h -1
nd if it isin't a complete binary tree then we recursively call for the left and right subtree
*/