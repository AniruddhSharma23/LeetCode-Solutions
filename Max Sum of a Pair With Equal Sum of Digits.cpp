class Solution
{
public:
    int digitSum(int n)
    {
        int s = 0;
        while (n > 0)
        {
            s += n % 10;
            n /= 10;
        }
        return s;
    }
    int maximumSum(vector<int> &nums)
    {
        unordered_map<int, priority_queue<int>> mp;
        for (auto x : nums)
        {
            int k = digitSum(x);
            mp[k].push(x);
        }
        int sum = -1;
        for (auto x : mp)
        {
            auto pq = x.second;
            if (pq.size() >= 2)
            {
                int k = pq.top();
                pq.pop();
                k += pq.top();
                pq.pop();
                sum = max(sum, k);
            }
        }
        return sum;
    }
};