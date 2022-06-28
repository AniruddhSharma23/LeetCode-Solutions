class Solution
{
public:
    int maxDistance(vector<int> &colors)
    {
        int n = colors.size();
        int from_first = 0;
        int from_last = n - 1;
        while (colors[0] == colors[from_last])
            from_last--;
        while (colors[n - 1] == colors[from_first])
            from_first++;
        return max(from_last, n - from_first - 1);
    }
};