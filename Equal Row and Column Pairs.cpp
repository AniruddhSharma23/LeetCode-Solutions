class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int n = grid.size();
        map<vector<int>, int> mp;
        // store the rows in mp:
        for (auto x : grid)
            mp[x]++;
        int ans = 0;
        // rotate the matrix anticlockwise:
        for (auto x : grid)
            reverse(x.begin(), x.end());
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                swap(grid[i][j], grid[j][i]);
        // find the matching pairs:
        for (int i = 0; i < n; i++)
        {
            if (mp.find(grid[i]) != mp.end())
                ans += mp[grid[i]];
        }
        return ans;
    }
};