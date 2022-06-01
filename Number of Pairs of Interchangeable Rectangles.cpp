class Solution
{
public:
    long long interchangeableRectangles(vector<vector<int>> &rectangles)
    {
        int n = rectangles.size();
        unordered_map<double, long long> mp;
        for (int i = 0; i < n; i++)
        {
            double k = (double)rectangles[i][0] / (double)rectangles[i][1];
            mp[k]++;
        }
        long long p = 0;
        for (auto x : mp)
        {
            if (x.second > 1)
            {
                p += (long long)x.second * ((long long)(x.second - 1));
            }
        }
        return p / 2;
    }
};