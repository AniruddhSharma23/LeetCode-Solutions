class Solution
{
public:
    int gcd(int a, int b)
    {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }
    int minOperations(vector<int> &nums, vector<int> &numsDivide)
    {
        int n = nums.size(), nd = numsDivide.size();
        sort(nums.begin(), nums.end());
        int g = numsDivide[0];
        for (int i = 0; i < nd; i++)
            g = gcd(g, numsDivide[i]);
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > g)
                return -1;
            if (g % nums[i] == 0)
                return i;
        }
        return -1;
    }
};

// without sort

class Solution
{
public:
    int gcd(int a, int b)
    {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }
    int minOperations(vector<int> &nums, vector<int> &numsDivide)
    {
        int n = nums.size(), nd = numsDivide.size();
        int g = numsDivide[0];
        for (int i = 0; i < nd; i++)
            g = gcd(g, numsDivide[i]);
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto x : nums)
            pq.push(x);
        int count = 0;
        while (!pq.empty())
        {
            auto x = pq.top();
            pq.pop();
            if (x > g)
                return -1;
            if (g % x == 0)
                return count;
            count++;
        }
        return -1;
    }
};