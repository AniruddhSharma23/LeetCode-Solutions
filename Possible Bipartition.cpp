class Solution
{
public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        vector<int> adj[n + 1];
        for (auto &x : dislikes)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<char> color(n + 1, 'w'); // initially all coloured as white
        vector<bool> vis(n + 1, false);
        queue<int> q;
        for (int i = 1; i <= n; i++)
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