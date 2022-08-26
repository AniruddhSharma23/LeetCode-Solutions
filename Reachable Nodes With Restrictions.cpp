class Solution
{
public:
    void dfs(int &ans, int u, vector<bool> &vis, vector<vector<int>> &graph)
    {
        vis[u] = true;
        ans++;
        for (auto v : graph[u])
            if (vis[v] == false)
                dfs(ans, v, vis, graph);
    }
    int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted)
    {
        vector<vector<int>> graph(n);
        for (auto e : edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n, false);
        for (auto x : restricted)
            vis[x] = true;
        int ans = 0;
        dfs(ans, 0, vis, graph);
        return ans;
    }
};

class Solution
{
public:
    int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted)
    {
        vector<vector<int>> graph(n);
        unordered_set<int> st(begin(restricted), end(restricted));
        for (auto e : edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n, false);
        for (auto x : restricted)
            vis[x] = true;
        int ans = 0;
        queue<int> q;
        q.push(0);
        vis[0] = true;
        while (!q.empty())
        {
            auto u = q.front();
            q.pop();
            if (st.count(u) != 0)
                continue;
            ans++;
            for (auto v : graph[u])
                if (vis[v] == false)
                {
                    vis[v] = true;
                    q.push(v);
                }
        }
        return ans;
    }
};