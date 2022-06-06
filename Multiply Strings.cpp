class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int n1 = num1.size();
        int n2 = num2.size();
        vector<int> v(n1 + n2, 0);
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                int k = (num1[i] - '0') * (num2[j] - '0');
                v[i + j] += k;
                v[i + j + 1] += v[i + j] / 10;
                v[i + j] %= 10;
            }
        }
        reverse(v.begin(), v.end());
        int z = 0;
        while (z < v.size() && v[z] == 0)
        {
            z++;
        }
        string s = "";
        for (int i = z; i < v.size(); i++)
        {
            s += to_string(v[i]);
        }
        return s;
    }
};