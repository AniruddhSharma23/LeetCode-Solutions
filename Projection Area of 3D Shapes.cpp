class Solution
{
public:
    int projectionArea(vector<vector<int>> &grid)
    {
        int k = 0;
        int n = grid.size();

        for (int i = 0; i < n; i++)
        {
            k += *max_element(grid[i].begin(), grid[i].end());
        }
        for (int j = 0; j < n; j++)
        {
            int m = INT_MIN;
            for (int i = 0; i < n; i++)
            {
                m = max(grid[i][j], m);
                if (grid[i][j] != 0)
                {
                    k++;
                }
            }
            k += m;
        }
        return k;
    }
};