class Solution
{
public:
    int minGroups(vector<vector<int>> &intervals)
    {
        vector<int> a; // arrival
        vector<int> d; // departure
        for (auto x : intervals)
        {
            a.push_back(x[0]);
            d.push_back(x[1]);
        }
        sort(a.begin(), a.end());
        sort(d.begin(), d.end());
        int i = 1, j = 0;
        int n = a.size();
        int ans = 1;
        int curr = 1;
        while (i < n && j < n)
        {
            if (a[i] <= d[j])
            {
                i++;
                curr++;
            }
            else
            {
                j++;
                curr--;
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};

// Min-heap:

class Solution
{
public:
    int minGroups(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto x : intervals)
        {
            if (!pq.empty() && pq.top() < x[0])
                pq.pop();
            pq.push(x[1]);
        }
        return pq.size();
    }
};