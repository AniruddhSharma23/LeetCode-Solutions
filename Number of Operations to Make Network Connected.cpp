class Solution
{
public:
    void dfs(vector<int> adj[], vector<bool> &vis, int u)
    {
        vis[u] = true;
        for (auto x : adj[u])
            if (vis[x] == false)
                dfs(adj, vis, x);
    }
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        vector<int> adj[n];
        vector<bool> vis(n, false);
        int cn = connections.size();
        if (n - 1 > cn)
            return -1;
        for (auto x : connections)
        {
            int a = x[0];
            int b = x[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int k = 0;
        for (int i = 0; i < n; i++)
            if (vis[i] == false)
            {
                k++;
                dfs(adj, vis, i);
            }
        return k - 1;
    }
};