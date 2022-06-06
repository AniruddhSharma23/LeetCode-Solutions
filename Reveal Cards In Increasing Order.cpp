class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        int n = deck.size();
        queue<int> q;
        for (int i = 0; i < n; i++)
            q.push(i);
        vector<int> v(n);
        int k = 0;
        sort(deck.begin(), deck.end());

        while (!q.empty())
        {
            v[q.front()] = deck[k];
            q.pop();
            k++;
            if (!q.empty())
            {
                q.push(q.front());
                q.pop();
            }
        }
        return v;
    }
};