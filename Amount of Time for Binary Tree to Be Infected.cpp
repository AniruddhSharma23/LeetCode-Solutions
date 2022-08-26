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
    unordered_map<int, vector<int>> graph;
    void buildGraph(TreeNode *root)
    {
        queue<pair<TreeNode *, int>> q;
        q.push({root, -1});
        while (!q.empty())
        {
            auto [node, parent] = q.front();
            q.pop();
            if (parent != -1)
            {
                graph[parent].push_back(node->val);
                graph[node->val].push_back(parent);
            }
            if (node->left != NULL)
                q.push({node->left, node->val});
            if (node->right != NULL)
                q.push({node->right, node->val});
        }
    }
    int amountOfTime(TreeNode *root, int start)
    {
        buildGraph(root);
        queue<int> q;
        q.push(start);
        int t = 0;
        unordered_map<int, bool> vis;
        vis[start] = true;
        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                int u = q.front();
                q.pop();
                for (auto v : graph[u])
                {
                    if (vis[v] == false)
                    {
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
            t++;
        }
        return t - 1;
    }
};