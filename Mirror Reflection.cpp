class Solution
{
public:
    int gcd(int a, int b)
    {
        while (b)
        {
            a %= b;
            swap(a, b);
        }
        return a;
    }
    int mirrorReflection(int p, int q)
    {
        int lcm = p * q / gcd(p, q);
        int a = lcm / p;
        int b = lcm / q;
        return (a % 2 == 0) ? 0 : (b % 2 == 0 ? 2 : 1);
    }
};

/*
**Approach:

* ```ap = bq```
* Case 1:
    * a = even
    * b = odd
    * corner = 0
* Case 2:
    * a = odd
    * b = odd
    * corner = 1
* Case 3:
    * a = odd
    * b = even
    * corner = 2
*/