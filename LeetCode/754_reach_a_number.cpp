class Solution
{
public:
    int reachNumber(int target)
    {
        target = abs(target);
        int step = 0, sum = 0;

        while (sum < target)
            sum += ++step;

        int diff = sum - target;

        return diff % 2 == 0 ? step : (step + 1 + step % 2);
    }
};