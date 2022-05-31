class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int k = 0;
        k += numBottles; // water intake
        int e = k;       // no of empty bottles
        while (e >= numExchange)
        {
            int p = e / numExchange;
            k += p;
            e -= p * numExchange;
            e += p;
        }
        return k;
    }
};