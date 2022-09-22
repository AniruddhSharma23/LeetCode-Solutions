/*

color
0: not visited
1: visiting
2: already visited

*/
class Solution
{
public:
    bool dfs(vector<vector<int>> &graph, vector<int> &color, int u)
    {
        if (color[u] > 0)
            return color[i] == 2;
        color[i] = 1;
        for (auto x : graph[u])
        {
            if (color[x] == 1 || dfs(graph, color, x) == false)
                return false;
        }
        color[i] = 2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, 0);
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (dfs(graph, color, i) == true)
                ans.push_back(i);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};