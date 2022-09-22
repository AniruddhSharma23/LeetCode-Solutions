class Solution
{
public:
    bool isBipartite(vector<vector<int>> &adj)
    {
        int n = adj.size();
        vector<char> color(n, 'w'); // initially all coloured as white
        vector<bool> vis(n, false);
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == false)
            {
                q.push(i);
                color[i] = 'r';
                while (!q.empty())
                {
                    int u = q.front();
                    q.pop();
                    if (vis[u] == true)
                        continue;
                    vis[u] = true;
                    char c = color[u];
                    for (auto v : adj[u])
                    {
                        if (color[v] == c)
                            return false;
                        color[v] = (c == 'r') ? 'b' : 'r';
                        q.push(v);
                    }
                }
            }
        }
        return true;
    }
};