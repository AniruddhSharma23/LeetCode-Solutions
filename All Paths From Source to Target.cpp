class Solution
{
public:
    void dfs(vector<vector<int>> &graph, vector<vector<int>> &ans, vector<int> &k, int v, int n)
    {
        k.push_back(v);
        if (v == n - 1)
            ans.push_back(k);
        else
            for (auto x : graph[v])
                dfs(graph, ans, k, x, n);
        k.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> k;
        dfs(graph, ans, k, 0, n);
        return ans;
    }
};