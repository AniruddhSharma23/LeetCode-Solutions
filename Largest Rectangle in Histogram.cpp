class Solution
{
public:
    // function to calculate previous smaller
    vector<int> ps(vector<int> &arr, int n)
    {
        stack<int> st;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[i] <= arr[st.top()])
            {
                st.pop();
            }
            if (st.empty())
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(st.top());
            }
            st.push(i);
        }
        return v;
    }

    // function to calculate next smaller
    vector<int> ns(vector<int> &arr, int n)
    {
        stack<int> st;
        vector<int> v;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[i] <= arr[st.top()])
            {
                st.pop();
            }
            if (st.empty())
            {
                v.push_back(n);
            }
            else
            {
                v.push_back(st.top());
            }
            st.push(i);
        }
        reverse(v.begin(), v.end());
        return v;
    }
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> a = ps(heights, n);
        vector<int> b = ns(heights, n);
        vector<int> c;
        for (int i = 0; i < n; i++)
        {
            c.push_back((b[i] - a[i] - 1) * heights[i]);
        }
        return *max_element(c.begin(), c.end());
    }
};