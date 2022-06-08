/*
**Method:**

* There can be 3 cases:
* Case 1 :
    * If the ticket holders have less tickets to buy than our Kth ticket holder
    * Then, they will have got all the tickets they wanted before kth ticket holder gets all its tickets
* Case 2:
    * if the ticket holders have more tickets to buy than our Kth ticket holder and they are ahead in line(position < k)
    * Then, they will have bought "tickets[k]" tickets before kth ticket holder gets all the tickets it needs
* Case 3:
    * if the ticket holders have more tickets to buy than our Kth ticket holder, and they are behind in line(position > k)
    * Then, they will have bought 1 ticket less than tickets[k] before kth ticket holder gets all the tickets it needs.
*/

class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int n = tickets.size();
        int t = tickets[k];
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            if (tickets[i] < t)
            {
                s += tickets[i];
            }
            else
            {
                if (i <= k)
                {
                    s += t;
                }
                else
                {
                    s += t - 1;
                }
            }
        }
        return s;
    }
};