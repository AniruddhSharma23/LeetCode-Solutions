class Solution
{
public:
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        int m = l.size();
        vector<bool> v(m, true);
        int n = nums.size();

        for (int i = 0; i < m; i++)
        {
            int a = l[i];
            int b = r[i];
            if (b - a < 1)
            {
                v[i] = false;
            }
            else if (b - a == 1)
            {
                v[i] = true;
            }
            else
            {
                vector<int> k;
                for (int j = a; j <= b; j++)
                {
                    k.push_back(nums[j]);
                }
                sort(k.begin(), k.end());
                int d = k[1] - k[0];
                for (int p = 2; p < k.size(); p++)
                {
                    if (k[p] - k[p - 1] != d)
                    {
                        v[i] = false;
                        break;
                    }
                }
            }
        }
        return v;
    }
};