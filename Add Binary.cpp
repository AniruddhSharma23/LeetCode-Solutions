class Solution
{
public:
    string addBinary(string a, string b)
    {
        int n1 = a.length();
        int n2 = b.length();
        int carry = 0;
        string s = "";
        while (n1 > 0 || n2 > 0)
        {
            int sum = 0;
            if (n1 > 0)
            {
                sum += a[n1 - 1] - '0';
                n1--;
            }
            if (n2 > 0)
            {
                sum += b[n2 - 1] - '0';
                n2--;
            }
            sum += carry;
            switch (sum)
            {
            case 0:
                carry = 0;
                s.push_back('0');
                break;
            case 1:
                carry = 0;
                s.push_back('1');
                break;
            case 2:
                carry = 1;
                s.push_back('0');
                break;
            case 3:
                carry = 1;
                s.push_back('1');
                break;
            }
        }
        if (carry != 0)
        {
            s.push_back('1');
        }
        reverse(s.begin(), s.end());
        return s;
    }
};