class Solution
{
public:
    vector<string> simplifiedFractions(int n)
    {
        vector<string> v;
        if (n == 2)
        {
            return {"1/2"};
        }
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                if (gcd(i, j) == 1 || j == 1)
                {
                    string a = to_string(j) + "/" + to_string(i);
                    v.push_back(a);
                }
            }
        }
        return v;
    }
};