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
    int postIndex;
    TreeNode *find(vector<int> &postorder, vector<int> &inorder, int is, int ie)
    {
        if (postIndex < 0 || is > ie)
        {
            return NULL;
        }
        int x = postorder[postIndex--];
        TreeNode *root = new TreeNode(x);
        if (is == ie)
            return root;
        int inIndex = mp[x];
        root->right = find(postorder, inorder, inIndex + 1, ie);
        root->left = find(postorder, inorder, is, inIndex - 1);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        postIndex = n - 1;
        for (int i = 0; i < n; i++)
        {
            mp[inorder[i]] = i;
        }
        return find(postorder, inorder, 0, n - 1);
    }
};

/*
 * store the index of all the elements of inorder vector in the map
 * remember that the last element of the postorder array is the root
 * Pick an element from Postorder. Decrement the Postorder Index Variable (postIndex in below code) to pick the next element in the next recursive call.
 * Create a new tree node root with the data as the picked element.
 * Find the picked element’s index in Inorder using map. Let the index be inIndex.
 * now the elements before this inIndex in inorder will be the left subtree and elements on right of it will be the right subtree of the root node
 * Call the find function for elements after inIndex and make it as a right subtree of root.
 * Call the find function for elements before inIndex and make it as a left subtree of root.
 * return root.
 */