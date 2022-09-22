// dfs-based:
class Solution
{
public:
    void dfs(vector<vector<int>> &grid, int i, int j, int m, int n, int d)
    {
        if (i < 0 || j < 0 || i >= m || j >= n || (grid[i][j] != 0 && grid[i][j] <= d))
            return;
        grid[i][j] = d;
        dfs(grid, i + 1, j, m, n, d + 1);
        dfs(grid, i - 1, j, m, n, d + 1);
        dfs(grid, i, j + 1, m, n, d + 1);
        dfs(grid, i, j - 1, m, n, d + 1);
        return;
    }
    int maxDistance(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = -1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    grid[i][j] = 0;
                    dfs(grid, i, j, m, n, 1);
                }
            }
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] > 1)
                    ans = max(ans, grid[i][j] - 1);
        return ans;
    }
};

// bfs-based:

class Solution
{
public:
    typedef pair<int, int> pi;
    int maxDistance(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = -1;
        queue<pi> q;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                {
                    q.push({i + 1, j});
                    q.push({i - 1, j});
                    q.push({i, j + 1});
                    q.push({i, j - 1});
                }

        int steps = 0;
        while (!q.empty())
        {
            steps++;
            int k = q.size();
            for (int p = 0; p < k; p++)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if (i >= 0 && j >= 0 && i < m && j < n && grid[i][j] == 0)
                {
                    grid[i][j] = steps;
                    q.push({i + 1, j});
                    q.push({i - 1, j});
                    q.push({i, j + 1});
                    q.push({i, j - 1});
                }
            }
        }
        return steps == 1 ? -1 : steps - 1;
    }
};