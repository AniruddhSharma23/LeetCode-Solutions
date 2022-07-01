class Solution
{
public:
    int permutation(int n, int r)
    {
        if (r == 0)
            return 1;
        else
            return n * permutation(n - 1, r - 1);
    }
    int countNumbersWithUniqueDigits(int n)
    {
        int ans = 1;
        for (int i = 0; i < n; i++)
            ans += 9 * permutation(9, i);
        return ans;
    }
};

/*
Approach:

there are 10 possible digits in a number {0,1,2,3,4,5,6,7,8,9}
now,
the permutation is defined as:
    P(n, r) = n * (n - 1) * (n - 2) * ... * (n - r + 1)
Let's analyse some cases:
1. for n=0
    0 ≤ x < 1 with unique digits is 0, A(0) = 1
2. for n=1
0 ≤ x < 10 can be divided into 2 parts
    0 ≤ x < 1 (calculated in 1): A(0) = 1
    1 ≤ x < 10 (all numbers with ONLY 1 digit)
        numbers for this range are all unique
        so A(1) = P(10,1)-1
    so the total ans is A(0)+A(1)
3. for n=2 0 ≤ x < 100 with unique digits can be divided into 3 parts
    0 ≤ x < 1 (calculated in 1): A(0) = 1
    1 ≤ x < 10 (all numbers with ONLY 1 digit): A(1) = P(10,1) - 1
    10 ≤ x < 100 (all numbers with ONLY 2 digits)
        now A(2) = select any 2 numbers out of 10 such that these 2 are different
        A(2) = P(10,2) - P(9,1)
        P(10,2) = we need to choose 2 different numbers out of {0,1,2,3,4,5,6,7,8,9}
        P(9,1) =  and we need to remove the numbers starting with 0
    so the final ans will be A(0)+A(1)+A(2)
now, we can generalise it for n<10:
    A(n) = P(10,n) - P(9,n-1)

    if you closely notice the above permutation formula:
    P(9,n-1) = 9*8*....(9-(n-1)+1)
             = 9*8*....(10-n+1)
    P(10,n) = 10*9*8*...(10-n+1)
            = 10*P(9,n-1)
    So,
    A(n) = 9*P(9,n-1)
    And the final ans will be
    ans  = A(0)+A(1)+...A(n)
*/