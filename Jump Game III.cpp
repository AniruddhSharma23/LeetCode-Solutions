class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        int n = arr.size();
        vector<int> adj[n];
        for (int i = 0; i < n; i++)
        {
            int a = i + arr[i];
            int b = i - arr[i];
            if (a >= 0 && a < n)
                adj[i].push_back(a);
            if (b >= 0 && b < n)
                adj[i].push_back(b);
        }
        set<int> st;
        for (int i = 0; i < n; i++)
            if (arr[i] == 0)
                st.insert(i);
        vector<int> vis(n, 0);
        vis[start] = 1;
        queue<int> q;
        q.push(start);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if (st.find(u) != st.end())
                return true;
            for (auto v : adj[u])
            {
                if (vis[v] == false)
                {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
        return false;
    }
};