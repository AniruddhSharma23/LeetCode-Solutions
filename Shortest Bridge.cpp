class Solution
{
public:
    typedef pair<int, int> pi;
    bool isSafe(int i, int j, int m, int n)
    {
        if (i < 0 || j < 0 || i >= m || j >= n)
            return false;
        return true;
    }
    void dfs(vector<vector<int>> &grid, vector<vector<int>> &d, queue<pi> &q, int i, int j, int m, int n)
    {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != 1)
            return;
        grid[i][j] = 2;
        q.push({i, j});
        for (int k = 0; k < 4; k++)
        {
            int i1 = i + d[k][0];
            int j1 = j + d[k][1];
            dfs(grid, d, q, i1, j1, m, n);
        }
        return;
    }
    int shortestBridge(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        queue<pi> q;
        vector<vector<int>> d = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && q.size() == 0)
                    dfs(grid, d, q, i, j, m, n);
            }
        }

        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                int i1 = i + d[k][0];
                int j1 = j + d[k][1];
                if (isSafe(i1, j1, m, n) == true)
                {
                    if (grid[i1][j1] == 1)
                    {
                        return grid[i][j] - 2;
                    }
                    if (grid[i1][j1] == 0)
                    {
                        grid[i1][j1] = grid[i][j] + 1;
                        q.push({i1, j1});
                    }
                }
            }
        }
        return 0;
    }
};