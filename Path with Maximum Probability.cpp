class Solution
{
public:
    typedef pair<double, int> pdi;
    typedef pair<int, double> pid;
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        vector<vector<pid>> graph(n + 1);
        for (int i = 0; i < edges.size(); i++)
        {
            auto e = edges[i];
            graph[e[0]].push_back({e[1], succProb[i]});
            graph[e[1]].push_back({e[0], succProb[i]});
        }
        vector<bool> finalized(n + 1, false);
        priority_queue<pdi> pq;
        vector<double> pb(n + 1, (double)0.0);
        pq.push({(double)1.0, start});
        pb[start] = 1.0;
        while (!pq.empty())
        {
            double pb_u = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (finalized[u] == true)
                continue;
            finalized[u] = true;
            if (u == end)
                return pb_u;
            for (auto x : graph[u])
            {
                int v = x.first;
                double wt = x.second;
                if (pb_u * wt > pb[v])
                {
                    pb[v] = pb_u * wt;
                    pq.push({pb[v], v});
                }
            }
        }
        return 0.0;
    }
};