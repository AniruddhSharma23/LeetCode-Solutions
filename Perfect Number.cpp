class Solution
{
public:
    bool checkPerfectNumber(int num)
    {
        vector<int> v;
        for (int i = 1; i * i < num; i++)
        {
            if (num % i == 0)
            {
                v.push_back(i);
                if (i != 1 && i * i != num)
                {
                    v.push_back(num / i);
                }
            }
        }
        int s = accumulate(v.begin(), v.end(), 0);
        return (s == num);
    }
};