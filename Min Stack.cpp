class MinStack
{
public:
    stack<int> st;
    MinStack()
    {
    }

    void push(int val)
    {
        if (st.empty() || st.top() >= val)
        {
            st.push(val);
            st.push(val);
        }
        else
        {
            int k = st.top();
            st.push(val);
            st.push(k);
        }
    }

    void pop()
    {
        st.pop();
        st.pop();
    }

    int top()
    {
        int t1 = st.top();
        st.pop();
        int t2 = st.top();
        st.push(t1);
        return t2;
    }

    int getMin()
    {
        return st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */