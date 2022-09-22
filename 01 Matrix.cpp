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
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> v(m, vector<int>(n, -1));
        vector<int> dx = {-1, 0, 0, 1};
        vector<int> dy = {0, -1, 1, 0};
        queue<pi> q;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j] == 0)
                {
                    q.push({i, j});
                    v[i][j] = 0;
                }

        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                int i1 = i + dx[k];
                int j1 = j + dy[k];
                if (isSafe(i1, j1, m, n) == true && v[i1][j1] == -1)
                {
                    v[i1][j1] = v[i][j] + 1;
                    q.push({i1, j1});
                }
            }
        }
        return v;
    }
};