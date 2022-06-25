class Solution
{
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
    int scheduleCourse(vector<vector<int>> &courses)
    {
        sort(courses.begin(), courses.end(), comp);
        priority_queue<int> pq;
        int time = 0;
        for (auto x : courses)
        {
            if (x[0] + time <= x[1])
            {
                time += x[0];
                pq.push(x[0]);
            }
            else
            {
                if (!pq.empty() && pq.top() > x[0])
                {
                    time = time - pq.top() + x[0];
                    pq.pop();
                    pq.push(x[0]);
                }
            }
        }
        return pq.size();
    }
};