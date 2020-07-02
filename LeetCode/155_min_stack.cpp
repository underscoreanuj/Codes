class MinStack
{
    stack<pair<int, int>> S;

public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        int min_element = 0;
        if (this->S.empty())
            min_element = x;
        else
            min_element = min(x, this->S.top().second);

        this->S.push({x, min_element});
    }

    void pop()
    {
        this->S.pop();
    }

    int top()
    {
        return this->S.top().first;
    }

    int getMin()
    {
        return this->S.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */