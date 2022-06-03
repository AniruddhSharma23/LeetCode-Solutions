class Solution
{
public:
    vector<int> solve(vector<int> &code, int k, int n)
    {
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++)
        {
            int x = k;
            int sum = 0;
            int j = i + 1;
            while (x--)
            {

                if (j == n)
                    j = 0;
                sum += code[j];
                j++;
            }
            ans[i] = sum;
        }
        return ans;
    }
    vector<int> decrypt(vector<int> &code, int k)
    {

        int n = code.size();
        if (k == 0)
        {
            vector<int> ans(n, 0);
            return ans;
        }
        if (k > 0)
            return solve(code, k, n);
        else // k<0
        {

            reverse(code.begin(), code.end());
            vector<int> v = solve(code, -k, n);
            reverse(v.begin(), v.end()); // reusing the above function
            return v;
        }
    }
};