class Solution
{
public:
    int maximumScore(int a, int b, int c)
    {
        priority_queue<int> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        int k = 0;
        int s = a + b + c;
        while (s--)
        {
            int p = pq.top();
            pq.pop();
            int q = pq.top();
            pq.pop();
            if (p == 0 || q == 0)
                break;
            else
            {
                p--;
                q--;
                k++;
                pq.push(p);
                pq.push(q);
            }
        }
        return k;
    }
};