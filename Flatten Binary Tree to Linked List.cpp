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
    TreeNode *create(TreeNode *root)
    {
        if (root == NULL)
            return NULL;
        TreeNode *l = create(root->left);
        TreeNode *r = create(root->right);
        if (l == NULL)
        {
            root->right = r;
            root->left = NULL;
        }
        else
        {
            TreeNode *curr = l;
            while (curr->right != NULL)
            {
                curr = curr->right;
            }
            curr->right = r;
            root->right = l;
            root->left = NULL;
        }
        return root;
    }
    void flatten(TreeNode *root)
    {
        if (root == NULL)
            return;
        create(root);
    }
};

/*
we follow a simple recursive approach
now let's suppose there is a function create and with the help of that we got the linked list for the left and right subtree
of the root
let the left and right linked list be l and r respectively
Now as we want the order as the preorder of the tree so it means it will be like root then left subtree then right subtree
So, we check if the left one is null or not
if it is then it means the root->right will be the linked list r only
nd if it is not null then
we traverse to the last node of linked list "l" and set its last node right as the begining of linked list "r"
now the root right will be the linked list "l"
Note that we want left of all the linked list element as NULL (specified in the question statement)
return the root
Base case: if root is null then no linked list will form and hence we return null
*/