class Solution
{
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {
        int t = minutesToTest / minutesToDie;
        int n = buckets;
        int p = ceil(log(n) / log(t + 1));
        return p;
    }
};