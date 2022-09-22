class Solution
{
public:
    int minPartitions(string s)
    {
        int m = 0;
        for (char c : s)
            m = max(m, c - '0');
        return m;
    }
};