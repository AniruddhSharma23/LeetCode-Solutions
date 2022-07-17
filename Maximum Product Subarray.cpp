class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int pos_prod = 1, neg_prod = 1, max_prod = 1, n = nums.size();
        for (auto x : nums)
        {
            if (x == 0)
                pos_prod = neg_prod = 0;
            else if (x < 0)
            {
                int temp = pos_prod;
                pos_prod = max(x, neg_prod * x);
                neg_prod = min(temp * x, x);
            }
            else
            {
                neg_prod = min(neg_prod * x, x);
                pos_prod = max(pos_prod * x, x);
            }
            max_prod = max(max_prod, pos_prod);
        }
        return max_prod;
    }
};