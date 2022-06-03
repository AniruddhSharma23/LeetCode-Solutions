class Solution
{
public:
    bool isLeap(int n)
    {
        if (n % 4 == 0)
        {
            if (n % 100 == 0)
            {
                if (n % 400 == 0)
                {
                    return true;
                }
            }
            else
            {
                return true;
            }
        }
        return false;
    }
    int dayOfYear(string date)
    {
        int k = 0;

        int v[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

        int m, d, y;
        y = std::stoi(date.substr(0, 4).c_str());
        m = std::stoi(date.substr(5, 2).c_str());
        d = std::stoi(date.substr(8, 2).c_str());

        k = v[m - 1] + d;
        if (isLeap(y) && m > 2)
            k++;

        return k;
    }
};
