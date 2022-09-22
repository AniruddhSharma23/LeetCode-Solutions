class Solution
{
public:
    void dfs(vector<int> adj[], stack<int> &st, vector<bool> &vis, int u)
    {
        vis[u] = true;
        for (auto x : adj[u])
            if (vis[x] == false)
                dfs(adj, st, vis, x);
        st.push(u);
    }
    void dfs2(vector<int> revadj[], vector<bool> &vis, int u)
    {
        vis[u] = true;
        for (auto x : revadj[u])
            if (vis[x] == false)
                dfs(revadj, vis, x);
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<int> adj[n + 1];
        int ans = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (isConnected[i][j] == 1)
                    adj[i + 1].push_back(j + 1);

        // Kosaraju's Algorithm to find the number of strongly connected components

        stack<int> st;
        vector<bool> vis(n + 1, false);
        vector<int> revadj[n + 1];

        // step 1:

        for (int i = 1; i <= n; i++)
            if (vis[i] == false)
                dfs(adj, st, vis, u);

        // step 2:

        for (int i = 1; i <= n; i++)
            for (auto x : adj[i])
                revadj[x].push_back(i);

        // step 3:

        fill(vis.begin(), vis.end(), false);
        while (!st.empty())
        {
            int x = st.top();
            st.pop();
            if (vis[x] == true)
                continue;
            ans++;
            dfs2(revadj, vis, x);
        }
        return ans;
    }
};

// normal dfs:

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
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<int> adj[n + 1];
        int ans = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (isConnected[i][j] == 1)
                    adj[i + 1].push_back(j + 1);
        vector<bool> vis(n + 1, false);
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == false)
            {
                ans++;
                dfs(adj, vis, i);
            }
        }
        return ans;
    }
};