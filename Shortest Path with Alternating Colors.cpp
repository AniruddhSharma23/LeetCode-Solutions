/*

color = 2 for red
color = 3 for blue
queue = {node,dist,color}

*/
class Solution
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        vector<vector<pair<int, int>>> graph(n);
        for (auto x : redEdges)
            graph[x[0]].push_back({x[1], 2});
        for (auto x : blueEdges)
            graph[x[0]].push_back({x[1], 3});
        queue<vector<int>> q;
        q.emplace(vector<int>{0, 0, -1});
        vector<int> d(n, -1);

        while (!q.empty())
        {
            auto x = q.front();
            int u = x[0];
            int dist = x[1];
            int color = x[2];
            q.pop();
            d[u] = (d[u] == -1) ? dist : d[u];
            for (auto &k : graph[u])
            {
                int v = k.first;
                int c = k.second;
                if (v != -1 && c != color)
                {
                    q.emplace(vector<int>{v, dist + 1, c});
                    k.first = -1;
                }
            }
        }
        return d;
    }
};