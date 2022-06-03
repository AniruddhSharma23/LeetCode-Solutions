class Solution
{
public:
    vector<int> countPoints(vector<vector<int>> &points, vector<vector<int>> &queries)
    {

        int n = queries.size();
        int m = points.size();
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++)
        {
            int x1 = queries[i][0];
            int y1 = queries[i][1];
            int r = queries[i][2];
            for (int j = 0; j < m; j++)
            {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int k = pow(x1 - x2, 2) + pow(y1 - y2, 2);
                if (k <= (r * r))
                {
                    v[i]++;
                }
            }
        }
        return v;
    }
};