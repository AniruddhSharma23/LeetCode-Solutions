class Solution
{
public:
    int reachNumber(int n)
    {
        n = abs(n);
        int i = 1, s = 0;
        while (s < n)
            s += i++;
        int d = s - n;
        int step = i - 1;
        if (d == 0 || d % 2 == 0)
            return step;
        if (step % 2 == 0)
            return step + 1;
        return step + 2;
    }
};