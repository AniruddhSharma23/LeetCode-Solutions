class Solution
{
public:
    int minReorder(int n, vector<vector<int>> &connections)
    {
        vector<int> adj[n];
        vector<int> back[n];

        for (auto x : connections)
            adj[x[0]].push_back(x[1]);
        for (auto x : connections)
            back[x[1]].push_back(x[0]);

        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0);
        int ans = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            vis[u] = true;
            for (auto v : adj[u])
            {
                if (vis[v] == false)
                {
                    vis[v] = true;
                    ans++;
                    q.push(v);
                }
            }
            for (auto v : back[u])
            {
                if (vis[v] == false)
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        return ans;
    }
};