class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        long long n = points.size();
        long long k = 1;
        long long p = 0;
        if (n == 0)
            return 0;
        sort(points.begin(), points.end(), [](auto &a, auto &b)
             { return a[1] < b[1]; });
        for (long long i = 1; i < n; i++)
        {
            if (points[i][0] > points[p][1])
            {
                k++;
                p = i;
            }
        }
        return k;
    }
};