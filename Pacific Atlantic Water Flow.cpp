class Solution
{
public:
    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &v, int i, int j, int m, int n)
    {
        v[i][j] = true;

        if (i - 1 >= 0 && v[i - 1][j] == false && heights[i - 1][j] >= heights[i][j])
            dfs(heights, v, i - 1, j, m, n);

        if (i + 1 < m && v[i + 1][j] == false && heights[i + 1][j] >= heights[i][j])
            dfs(heights, v, i + 1, j, m, n);

        if (j - 1 >= 0 && v[i][j - 1] == false && heights[i][j - 1] >= heights[i][j])
            dfs(heights, v, i, j - 1, m, n);

        if (j + 1 < n && v[i][j + 1] == false && heights[i][j + 1] >= heights[i][j])
            dfs(heights, v, i, j + 1, m, n);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            dfs(heights, pacific, i, 0, m, n);
            dfs(heights, atlantic, i, n - 1, m, n);
        }
        for (int j = 0; j < n; j++)
        {
            dfs(heights, pacific, 0, j, m, n);
            dfs(heights, atlantic, m - 1, j, m, n);
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};