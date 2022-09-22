class Solution
{
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        vector<set<int>> adj(n);
        for (auto &x : roads)
        {
            adj[x[0]].insert(x[1]);
            adj[x[1]].insert(x[0]);
        }
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            v[i] = adj[i].size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    if (adj[i].find(j) != adj[i].end())
                        ans = max(ans, v[i] + v[j] - 1);
                    else
                        ans = max(ans, v[i] + v[j]);
                }
            }
        }
        return ans;
    }
};