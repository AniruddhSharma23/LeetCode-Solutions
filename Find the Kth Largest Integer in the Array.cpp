class Solution
{
public:
    struct cmp
    {
        bool operator()(string a, string b)
        {
            return a.length() == b.length() ? (a > b) : a.length() > b.length();
        }
    };

    string kthLargestNumber(vector<string> &nums, int k)
    {
        priority_queue<string, vector<string>, cmp> pq;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
            if (pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};