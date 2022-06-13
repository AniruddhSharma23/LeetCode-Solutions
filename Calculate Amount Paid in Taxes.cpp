class Solution
{
public:
    double calculateTax(vector<vector<int>> &brackets, int income)
    {
        double k = 0.00;
        if (income <= 0)
        {
            return k;
        }

        int n = brackets.size();
        if (income < brackets[0][0])
        {
            k += income * brackets[0][1];
        }
        else
        {
            k += brackets[0][0] * brackets[0][1];
        }

        k /= 100.00;
        income -= brackets[0][0];
        if (income <= 0)
        {
            return k;
        }
        for (int i = 1; i < n; i++)
        {
            int d = brackets[i][0] - brackets[i - 1][0];
            double s;
            if (income <= 0)
            {
                break;
            }
            if (income < d)
            {
                s = income * brackets[i][1];
            }
            else
            {
                s = d * brackets[i][1];
            }
            s /= 100.00;
            k += s;
            income -= d;
        }
        return k;
    }
};