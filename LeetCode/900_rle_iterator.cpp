// a better solution using vector time: O(N) , space: O(N)

class RLEIterator
{
public:
    vector<int> A;
    int pos;

    RLEIterator(vector<int> &A)
    {
        this->A = A;
        pos = 0;
    }

    int next(int n)
    {
        while (pos < A.size())
        {
            if (n <= A[pos])
            {
                A[pos] -= n;
                if (A[pos] == 0)
                {
                    pos += 2;
                    return A[pos - 1];
                }
                return A[pos + 1];
            }
            else
            {
                n -= A[pos];
                pos += 2;
            }
        }

        return -1;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */

// solution using deque, time: O(N) , space: O(N)

class RLEIterator
{
public:
    deque<int> A;
    RLEIterator(vector<int> &A)
    {
        this->A = deque<int>(A.begin(), A.end());
    }

    int next(int n)
    {
        int result = -1;

        while (A.size() >= 2 && n > A.front())
        {
            n -= A.front();
            A.pop_front();
            A.pop_front();
        }

        A.front() -= n;
        result = A.size() ? A[1] : -1;

        if (A.front() == 0)
        {
            A.pop_front();
            A.pop_front();
        }

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */