class Solution
{
public:
    int countTriples(int n)
    {
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int s = i * i + j * j;
                int sq = sqrt(s);
                if (sq * sq == s && sq <= n)
                {
                    k++;
                }
            }
        }
        return k;
    }
};