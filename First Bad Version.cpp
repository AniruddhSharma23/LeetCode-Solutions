// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        long int low = 1;
        long int high = n;

        while (low <= high)
        {
            long mid = (low + high) / 2;
            if (isBadVersion(mid))
            {
                if (!isBadVersion(mid - 1))
                {
                    return mid;
                }
                else
                {
                    high = mid - 1;
                }
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};