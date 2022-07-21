class Solution
{
public:
    typedef pair<int, int> pi;
    vector<int> dp;
    int getKth(int lo, int hi, int k)
    {
        dp.assign(1000000, -1);                         // initialize all the values as -1
        priority_queue<pi, vector<pi>, greater<pi>> pq; // min-heap
        for (int i = lo; i <= hi; i++)
        {
            int t = power(i);
            pq.push(make_pair(t, i)); // insert pair {power(i),i}
        }
        while (--k)
            pq.pop();
        int kth_element = pq.top().second;
        return kth_element;
    }

    int power(int x)
    {
        if (dp[x] != -1)
            return dp[x];
        if (x == 1)
            return 0;
        int m = (x % 2 == 0) ? x / 2 : (3 * x) + 1;
        return dp[x] = 1 + power(m);
    }
};

// without priority_queue
class Solution
{
public:
    vector<int> dp;
    int getKth(int lo, int hi, int k)
    {
        dp.assign(1000000, -1); // initialize all the values as -1
        vector<int> v(hi - lo + 1);
        iota(v.begin(), v.end(), lo);
        nth_element(v.begin(), v.begin() + k - 1, v.end(), [](auto &a, auto &b)
                    { return (dp[a] == dp[b] ? a < b : dp[a] < dp[b];) });
        return v[k - 1];
    }
    int power(int x)
    {
        if (dp[x] != -1)
            return dp[x];
        if (x == 1)
            return 0;
        int m = (x % 2 == 0) ? x / 2 : (3 * x) + 1;
        return dp[x] = 1 + power(m);
    }
};

/*
**Approach:**

* store the power of each number from 1 to 1000000 in a dp
* store the pair``` {power(i),i} ```of each i from lo to hi in a min-heap
* now the min-heap will arrange the pairs according to the increasing value of their power(i) and if it is same then the increasing order of i
* the top element of the heap is the smallest
* we want kth element so pop k-1 elements from the heap
* return the kth element
*
* **how to store power in dp?**
    * initializes all values as -1
    * so that if dp[i]!=-1 we will know that it has already been computed and thus simply return its value
    * base case:
        * x==1 : power=0
    * now if
    * x=even
        * move to x/2 i.e ```m=x/2```
    * x=odd
        * move to 3x+1 i.e``` m=3x+1```
    * ```dp[x]= 1+power(m)```
        * +1 because we move 1 step already
*/
/*
**Approach:**

* store the power of each number from 1 to 1000000 in a dp
* now create a vector v of size hi-lo+1 to store the elements from lo to hi
* iota?
    * to store the consecutive values from lo to hi
* nth_element?
    * it will sort the vector array v till the kth element
* compare function?
    * check if dp[a]==dp[b] i.e power(a)==power(b) then we will sort them according to their inc value
    * otherwise sort them acc to increasing value of their power
* return the kth element
*/
