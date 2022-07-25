class Solution
{
public:
    typedef pair<int, int> pi;
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pi>> graph(n + 1);
        for (auto t : times)
        {
            graph[t[0]].push_back({t[1], t[2]});
        }
        vector<bool> finalized(n + 1, false);
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0, k});
        dist[k] = 0;
        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            if (finalized[u] == true)
                continue;
            finalized[u] = true;
            for (auto x : graph[u])
            {
                int v = x.first;
                int wt = x.second;
                if (dist[v] > dist[u] + wt)
                {
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        int ans = *max_element(dist.begin() + 1, dist.end());
        return (ans == INT_MAX) ? -1 : ans;
    }
};