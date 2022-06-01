class Solution
{
public:
    bool isThree(int n)
    {
        int k = 0;

        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                (i * i != n) ? k += 2 : k++;
            }
        }
        return (k == 3) ? true : false;
    }
};