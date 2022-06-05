class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        if (num == 1)
            return 1;
        long long l = 1, r = num / 2 + 1;
        while (l <= r)
        {
            long long mid = l + (r - l) / 2;

            long long sq = mid * mid;
            if (sq == num)
                return 1;
            if (sq < num)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return 0;
    }
};