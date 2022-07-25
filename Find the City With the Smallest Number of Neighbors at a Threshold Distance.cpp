class Solution
{
public:
    typedef pair<int, int> pi;
    int dijkstra(int n, int distanceThreshold, vector<vector<pi>> &graph, int src)
    {

        vector<bool> finalized(n + 1, false);
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        dist[src] = 0;
        pq.push({0, src});
        while (!pq.empty())
        {
            int dist_u = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (finalized[u] == true)
                continue;
            finalized[u] = true;
            for (auto x : graph[u])
            {
                int v = x.first;
                int wt = x.second;
                if (dist_u + wt < dist[v])
                {
                    dist[v] = dist_u + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            if (i != src && dist[i] <= distanceThreshold)
                k++;
        }
        return k;
    }
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<pi>> graph(n + 1);
        for (int i = 0; i < edges.size(); i++)
        {
            auto e = edges[i];
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }
        vector<pi> ans;
        for (int i = 0; i < n; i++)
        {
            ans.push_back({dijkstra(n, distanceThreshold, graph, i), i});
        }
        sort(ans.begin(), ans.end(), [](auto a, auto b)
             { return (a.first != b.first) ? a.first < b.first : a.second > b.second; });
        return ans[0].second;
    }
};