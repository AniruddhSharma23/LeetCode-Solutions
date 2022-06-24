#define pr pair<int, int>
class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        priority_queue<pr> pq;
        unordered_map<int, int> mp;
        for (auto x : arr)
            mp[x]++;
        for (auto &x : mp)
            pq.push({x.second, x.first});
        int m = 0;
        int n, k;
        k = n = arr.size();
        while (!pq.empty() && k > n / 2)
        {
            k -= pq.top().first;
            pq.pop();
            m++;
        }
        return m;
    }
};