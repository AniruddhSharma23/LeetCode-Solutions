class Solution
{
public:
    int countEven(int num)
    {
        int t = num;
        int k = 0;
        while (t > 0)
        {
            k += t % 10;
            t /= 10;
        }
        return (k & 1) ? (num - 1) / 2 : num / 2;
    }
};