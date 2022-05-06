class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int n1 = num1.length() - 1;
        int n2 = num2.length() - 1;
        string s = "";
        bool c = false;

        while (n1 >= 0 || n2 >= 0)
        {
            int k;
            if (n1 >= 0 && n2 >= 0)
            {
                k = num1[n1] - '0' + num2[n2] - '0';
            }
            else if (n1 >= 0 && n2 < 0)
            {
                k = num1[n1] - '0';
            }
            else
            {
                k = num2[n2] - '0';
            }
            if (c == true)
            {
                k++;
            }
            if (k > 9)
            {
                k -= 10;
                c = true;
            }
            else
            {
                c = false;
            }
            s = char(k + '0') + s;
            n1--;
            n2--;
        }
        if (c == true)
        {
            s = "1" + s;
        }
        return s;
    }
};