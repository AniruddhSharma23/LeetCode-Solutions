class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int h = accumulate(weights.begin(), weights.end(), 0);
        int l = *max_element(weights.begin(), weights.end());
        int k = -1;

        while (l <= h)
        {
            int d = 1;
            int s = 0;
            int m = l + (h - l) / 2;
            for (auto x : weights)
            {
                s += x;
                if (s > m)
                {
                    d++;
                    s = x;
                }
            }
            if (d <= days)
            {
                h = m - 1;
                k = m;
            }
            else
            {
                l = m + 1;
            }
        }
        return k;
    }
};