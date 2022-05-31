class Solution
{
public:
    vector<int> distributeCandies(int candies, int num_people)
    {
        vector<int> v(num_people, 0);
        int i = 1;
        int j = 0;
        while (candies > 0)
        {

            int k = min((num_people * j) + i, candies);
            v[i - 1] += k;

            candies -= k;
            i++;
            if (i == num_people + 1)
            {
                i = 1;
                j++;
            }
        }
        return v;
    }
};