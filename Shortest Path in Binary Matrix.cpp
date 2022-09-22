class Solution
{
public:
    bool isSafe(int i, int j, int m, int n)
    {
        if (i < 0 || j < 0 || i >= m || j >= n)
            return false;
        return true;
    }
    typedef pair<int, int> pi;
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        if (grid[0][0] != 0 || grid[m - 1][n - 1] != 0) // base case
            return -1;
        grid[0][0] = 1;
        vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
        queue<pi> q;
        q.push({0, 0});
        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if (i == m - 1 && j == n - 1)
                return grid[i][j];
            for (int z = 0; z < 8; z++)
            {
                int i1 = i + dx[z];
                int j1 = j + dy[z];
                if (isSafe(i1, j1, m, n) == true && grid[i1][j1] == 0)
                {
                    grid[i1][j1] = grid[i][j] + 1;
                    q.push({i1, j1});
                }
            }
        }
        return -1;
    }
};