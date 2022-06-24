class MedianFinder
{
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    double median = 0.0;
    MedianFinder()
    {
    }

    void addNum(int x)
    {
        int m1 = maxheap.size();
        int m2 = minheap.size();
        if (m1 == 0)
        {
            maxheap.push(x);
            median = (double)x;
            return;
        }
        if (m1 > m2)
        {
            int k = maxheap.top();
            if (x < k)
            {
                minheap.push(k);
                maxheap.pop();
                maxheap.push(x);
            }
            else
            {
                minheap.push(x);
            }
            int t1 = maxheap.top();
            int t2 = minheap.top();
            median = (double)((t1 + t2) / 2.0);
        }
        else
        {
            int k = maxheap.top();
            if (x > k)
            {
                minheap.push(x);
                maxheap.push(minheap.top());
                minheap.pop();
            }
            else
            {
                maxheap.push(x);
            }
            median = (double)(maxheap.top());
        }
    }

    double findMedian()
    {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */