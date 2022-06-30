class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        unordered_map<int, int> mp;
        for (auto x : arr)
            mp[x]++;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto &x : mp)
            pq.push(x.second);
        int n = mp.size();
        while (!pq.empty() && k > 0)
        {
            int x = pq.top();
            pq.pop();
            if (x <= k)
            {
                k -= x;
                n--;
            }
            else
                break;
        }
        return n;
    }
};