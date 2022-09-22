class Solution
{
public:
    typedef pair<int, int> pi;
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        vector<int> adj[n];
        for (int i = 0; i < n; i++)
            if (manager[i] != -1)
                adj[manager[i]].push_back(i);

        queue<pi> q; // {the vertex, time taken till now}
        q.push({headID, 0});
        int ans = 0;
        while (!q.empty())
        {
            int nq = q.size();
            for (int i = 0; i < n; i++)
            {
                int u = q.front().first;
                int t = q.front().second;
                q.pop();
                int duration = t + informTime[u];
                ans = max(ans, duration);
                for (auto v : adj[u])
                    q.push({v, duration});
            }
        }
        return ans;
    }
};