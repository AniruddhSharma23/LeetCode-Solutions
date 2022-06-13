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
    unordered_map<int, int> mp;
    int preIndex = 0;
    TreeNode *find(vector<int> &preorder, vector<int> &inorder, int is, int ie)
    {
        if (is > ie)
        {
            return NULL;
        }
        int x = preorder[preIndex++];
        TreeNode *root = new TreeNode(x);
        if (is == ie)
            return root;
        int inIndex = mp[x];
        root->left = find(preorder, inorder, is, inIndex - 1);
        root->right = find(preorder, inorder, inIndex + 1, ie);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = inorder.size();
        for (int i = 0; i < n; i++)
        {
            mp[inorder[i]] = i;
        }
        return find(preorder, inorder, 0, n - 1);
    }
};

/*
 * store the index of all the elements of inorder vector in the map
 * Pick an element from Preorder. Increment the Preorder Index Variable (preIndex in below code) to pick the next element in the next recursive call.
 * Create a new tree node root with the data as the picked element.
 * Find the picked element’s index in Inorder using map. Let the index be inIndex.
 * now the elements before this inIndex in inorder will be the left subtree and elements on right of it will be the right subtree of the root node
 * Call the find function for elements before inIndex and make it as a left subtree of root.
 * Call the find function for elements after inIndex and make it as a right subtree of root.
 * return root.
 */
