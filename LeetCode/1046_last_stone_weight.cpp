class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> PQ;
        int larger_stone = 0, next_larger_stone = 0;

        for (int &stone : stones)
            PQ.push(stone);

        while (PQ.size() > 1)
        {
            // since the size is at least 2 there must be at least two stones
            larger_stone = PQ.top();
            PQ.pop();
            next_larger_stone = PQ.top();
            PQ.pop();
            if (larger_stone != next_larger_stone)
                PQ.push(larger_stone - next_larger_stone);
        }

        return PQ.size() == 0 ? 0 : PQ.top();
    }
};