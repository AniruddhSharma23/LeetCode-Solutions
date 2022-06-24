typedef pair<double, int> pr;
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pr> pq;
        vector<vector<int>> v;
        int n = points.size();
        if (k >= n)
            return points;
        for (int i = 0; i < n; i++)
        {
            int xsq = points[i][0] * points[i][0];
            int ysq = points[i][1] * points[i][1];
            double d = sqrt(xsq + ysq);
            if (pq.size() < k)
                pq.push({d, i});
            else
            {
                if (pq.top().first > d)
                {
                    pq.pop();
                    pq.push({d, i});
                }
            }
        }
        while (!pq.empty())
        {
            int index = pq.top().second;
            v.push_back(points[index]);
            pq.pop();
        }
        return v;
    }
};