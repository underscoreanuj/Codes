/**
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by Amazon.
 * Implement a stack that has the following methods:

    push(val), which pushes an element onto the stack
    pop(), which pops off and returns the topmost element of the stack. If there are no elements in the stack, then it should throw an error or return null.
    max(), which returns the maximum value in the stack currently. If there are no elements in the stack, then it should throw an error or return null.

 * Each method should run in constant time.
 * 
 * ref: https://leetcode.com/articles/max-stack/#
 * Online Judge: https://leetcode.com/problems/max-stack/
 * Online Judge: https://leetcode.com/problems/min-stack/
 * 
 */

// solution of https://leetcode.com/problems/max-stack/ | solved on : https://www.lintcode.com/problem/max-stack/description

#include <bits/stdc++.h>

class MaxStack
{
public:
    list<int> S;
    map<int, vector<list<int>::iterator>, greater<int>> mem;

    MaxStack()
    {
        // do intialization if necessary
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number)
    {
        // write your code here
        mem[number].emplace_back(S.emplace(S.end(), number)); // S.emplace returns an iterator to the newly added element unlike emplace_back which returns void
    }

    /*
     * @return: An integer
     */
    int pop()
    {
        // write your code here
        int t = S.back();
        S.pop_back();
        mem[t].pop_back();
        return t;
    }

    /*
     * @return: An integer
     */
    int top()
    {
        // write your code here
        return S.back();
    }

    /*
     * @return: An integer
     */
    int peekMax()
    {
        // write your code here
        return mem.begin()->first;
    }

    /*
     * @return: An integer
     */
    int popMax()
    {
        // write your code here
        int t = mem.begin()->first;
        S.erase(mem[t].back());
        mem[t].pop_back();
        return t;
    }
};

// modified solution of min stack (https://leetcode.com/problems/min-stack/)
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
        int max_element = 0;
        if (this->S.empty())
            max_element = x;
        else
            max_element = max(x, this->S.top().second);

        this->S.push({x, max_element});
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